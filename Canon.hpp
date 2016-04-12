#pragma once

#include "TEMP.hpp"
#include "CALL.hpp"
#include "MOVE.hpp"
#include "CONST.hpp"
#include "ESEQ.hpp"
#include "NAME.hpp"
#include "EXP.hpp"
#include "SEQ.hpp"
#include "StmInterface.hpp"
#include "StmList.hpp"
#include "ExpList.hpp"

#include <memory>

namespace Canon{

class MoveCall : public Tree::Stm {
public:
  MoveCall(std::shared_ptr<Tree::TEMP> _destination, std::shared_ptr<Tree::CALL> _source) 
    : destination(_destination), source(_source) {}

  std::shared_ptr<Tree::ExpList> kids() {
    return source->kids();
  }
  std::shared_ptr<Tree::Stm> build(std::shared_ptr<Tree::ExpList> kids) {
    return std::make_shared<Tree::MOVE>(destination, source->build(kids));
  }

private:
  std::shared_ptr<Tree::TEMP> destination;
  std::shared_ptr<Tree::CALL> source;
};

//------------------------------------------------------------------------------------

class ExpCall : public Tree::Stm {
public:
  
  ExpCall(std::shared_ptr<Tree::CALL> _call) 
    : call(_call) {}

  std::shared_ptr<Tree::ExpList> kids() {
    return call->kids();
  }
  std::shared_ptr<Tree::Stm> build(std::shared_ptr<Tree::ExpList> kids) {
    return std::make_shared<Tree::EXP>(call->build(kids));
  }

private:
  std::shared_ptr<Tree::CALL> call;
};

//------------------------------------------------------------------------------------------- 
  
class StmExpList {
public:
    StmExpList(std::shared_ptr<Tree::Stm> _stm, std::shared_ptr<Tree::ExpList> _exp) 
      : stm(_stm), exp(_exp) {}

private:
    std::shared_ptr<Tree::Stm> stm;
    std::shared_ptr<Tree::ExpList> exp;
};

//--------------------------------------------------------------------------------------------

class Canon {
public:
  static std::shared_ptr<Tree::StmList> linearize(std::shared_ptr<Tree::Stm> s) {
    return linear(do_stm(s), nullptr);
  }

private:
    static bool isNop(std::shared_ptr<Tree::Stm> a) {
      if(std::shared_ptr<Tree::EXP> e = std::dynamic_pointer_cast<Tree::EXP>(a)) {
        if(std::shared_ptr<Tree::CONST> c = std::dynamic_pointer_cast<Tree::CONST>(e->exp)) {
          return true;
        }
        else {
          return false;
        }
      }
      else {
        return false;
      }
    }

    static std::shared_ptr<Tree::Stm> seq(
        std::shared_ptr<Tree::Stm> a, std::shared_ptr<Tree::Stm> b) {
        if (isNop(a)) {
          return b;
        }
        else if (isNop(b)) {
          return a;
        }
        else {
          return std::make_shared<Tree::SEQ>(a, b);
        }
    }

    static bool commute(std::shared_ptr<Tree::Stm> a, std::shared_ptr<Tree::Exp> b) {
        if(isNop(a)) {
          return true;
        }
        if(std::shared_ptr<Tree::NAME> n = std::dynamic_pointer_cast<Tree::NAME>(b)){
          return true;
        }
        if(std::shared_ptr<Tree::CONST> c = std::dynamic_pointer_cast<Tree::CONST>(b)){
          return true;
        }
        return false;
    }

    static std::shared_ptr<Tree::Stm> do_stm(std::shared_ptr<Tree::SEQ> s) { 
        return seq(do_stm(s->left), do_stm(s->right));
    }

    static std::shared_ptr<Tree::Stm> do_stm(std::shared_ptr<Tree::MOVE> s) {
        if(std::shared_ptr<Tree::TEMP> t = std::dynamic_pointer_cast<Tree::TEMP>(s->dst)) {
          if(std::shared_ptr<Tree::CALL> c = std::dynamic_pointer_cast<Tree::CALL>(s->src)) {
            return reorder_stm(std::make_shared<MoveCall>(t, c);
          }
        }
        if(std::shared_ptr<Tree::ESEQ> e = std::dynamic_pointer_cast<Tree::ESEQ>(s->dst)) {
          return do_stm(std::make_shared<Tree::SEQ>(e->stm,
            std::make_shared<Tree::MOVE>(e->exp,
                s->src)));
        }
        return reorder_stm(s);
    }

    static std::shared_ptr<Tree::Stm> do_stm(std::shared_ptr<Tree::EXP> s) { 
        if (std::shared_ptr<Tree::CALL> e = std::dynamic_pointer_cast<Tree::CALL>(s->exp)){
            return reorder_stm(std::make_shared<ExpCall>(e);
        }
        return reorder_stm(s);
    }

    static std::shared_ptr<Tree::Stm> do_stm(std::shared_ptr<Tree::Stm> s) {
       if (std::shared_ptr<Tree::SEQ> e = std::dynamic_pointer_cast<Tree::SEQ>(s)) {
          return do_stm(e);
       }
       if (std::shared_ptr<Tree::MOVE> e = std::dynamic_pointer_cast<Tree::MOVE>(s)) {
          return do_stm(e);
       }
       if (std::shared_ptr<Tree::EXP> e = std::dynamic_pointer_cast<Tree::EXP>(s)) {
          return do_stm(e);
       }
       return reorder_stm(s);
    }

 static std::shared_ptr<Tree::Stm> reorder_stm(std::shared_ptr<Tree::Stm> s) {
     std::shared_ptr<StmExpList> x = reorder(s->kids());
     return seq(x->stm, s->build(x->exps));
 }

 static std::shared_ptr<Tree::ESEQ> do_exp(std::shared_ptr<Tree::ESEQ> e) {
      std::shared_ptr<Tree::Stm> stms = do_stm(e->stm);
      std::shared_ptr<Tree::ESEQ> b = do_exp(e->exp);
      return std::make_shared<Tree::ESEQ>(seq(stms, b->stm), b->exp);
  }

 static std::shared_ptr<Tree::ESEQ> do_exp (std::shared_ptr<Tree::Exp> e) {
      if (std::shared_ptr<Tree::ESEQ> es = std::dynamic_pointer_cast<Tree::ESEQ>(e)) {
        return do_exp(es);
      }
      return reorder_exp(e);
 }
         
 static std::shared_ptr<Tree::ESEQ> reorder_exp (std::shared_ptr<Tree::Exp> e) {
     std::shared_ptr<StmExpList> x = reorder(e->kids());
     return std::make_shared<Tree::ESEQ>(x->stm, e->build(x->exps));
 }

 static std::shared_ptr<StmExpList> nopNull = std::make_shared<StmExpList>(
    std::make_shared<Tree::EXP>(std::make_shared<Tree::CONST>(0)), nullptr);

 static std::shared_ptr<tmExpList> reorder(std::shared_ptr<Tree::ExpList> exps) {
     if (exps == nullptr) {
        return nopNull;
     }    
     else {
        std::shared_ptr<Tree::Exp> a = exps->head;
        if (std::shared_ptr<Tree::CALL> c = std::dynamic_pointer_cast<Tree::CALL>(a)) {
            std::shared_ptr<Temp::Temp> t = std::make_shared<Temp::Temp>();
            std::shared_ptr<Tree::Exp> e = std::make_shared<Tree::ESEQ>(
              std::make_shared<Tree::MOVE>(std::make_shared<Tree::TEMP(t), a),
				      std::make_shared<Tree::TEMP(t));
            return reorder(std::make_shared<Tree::ExpList>(e, exps->tail));
       } else {
            std::shared_ptr<Tree::ESEQ> aa = do_exp(a);
            std::shared_ptr<StmExpList> bb = reorder(exps->tail);
            if (commute(bb->stm, aa->exp))
                return std::make_shared<StmExpList>(seq(aa->stm, bb->stm), 
            		    std::make_shared<Tree::ExpList>(aa->exp, bb->exps));
            else {
                    std::shared_ptr<Temp::Temp> t = std::make_shared<Temp::Temp>();
                    return std::make_shared<StmExpList>(
                      seq(aa->stm, 
                        seq(std::make_shared<Tree::MOVE>(
                          std::make_shared<Tree::TEMP>(t), aa->exp), bb->stm)),
                      std::make_shared<Tree::ExpList>(
                        std::make_shared<Tree::TEMP>(t), bb->exps));
            }
       }
     }
 }
        
 static std::shared_ptr<Tree::StmList> linear(std::shared_ptr<Tree::SEQ> s, std::shared_ptr<Tree::StmList> l) {
      return linear(s->left, linear(s->right, l));
 }
 static std::shared_ptr<Tree::StmList> linear(std::shared_ptr<Tree::Stm> s, std::shared_ptr<Tree::StmList> l) {
      if (std::shared_ptr<Tree::SEQ> c = std::dynamic_pointer_cast<Tree::SEQ>(s)) {
        return linear(c, l);
      }
      return std::make_shared<Tree::StmList>(s, l);
 }

 
};

}
