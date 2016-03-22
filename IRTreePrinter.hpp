#pragma once

#include "IRTree.hpp"
#include "visitor.hpp"

static const char * ArithmeticOpStrings[] = { "+", "-", "*", "/", "&&", "||", "<<", ">>", "!" };
static const char * CJumpOpStrings[] = { "=", "!=", "<", ">", "<=", ">=", "u<", "u<=", "u>", "u>=" };

using namespace IRTree;

class CIRVisitor {
public:
  virtual void visit(const IRTree::MOVE* node) const = 0;
  virtual void visit(const IRTree::EXP* node) const = 0;
  virtual void visit(const IRTree::JUMP* node) const = 0;
  virtual void visit(const IRTree::CJUMP* node) const = 0;
  virtual void visit(const IRTree::SEQ* node) const = 0;
  virtual void visit(const IRTree::LABEL* node) const  = 0;
  virtual void visit(const IRTree::CONST* node)const = 0;
  virtual void visit(const IRTree::NAME* node) const= 0;
  virtual void visit(const IRTree::TEMP* node) const = 0;
  virtual void visit(const IRTree::BINOP* node) const = 0;
  virtual void visit(const IRTree::MEM* node)const = 0;
  virtual void visit(const IRTree::CALL* node) const = 0;
  virtual void visit(const IRTree::ESEQ* node)const = 0;

};

class CIRPrinter: public CIRVisitor {
    bool withoutSEQ;
public:
    CIRPrinter(bool _withoutSEQ) : withoutSEQ(_withoutSEQ) {}
    virtual void visit(const MOVE* node) const {
        print_tabs(counter++);
        cout << "MOVE" << endl;
        node->dst->accept(this);
        node->src->accept(this);
        --counter;
    }

    virtual void visit(const EXP* node) const {
        print_tabs(counter++);
        cout << "EXP" << endl;
        node->exp->accept(this);
        --counter;
    }

    virtual void visit(const JUMP* node) const {
        print_tabs(counter++);
        cout << "JUMP "<< node->target->Name() << endl;
        if (node->exp != 0)
            node->exp->accept(this);
        --counter;
    }

    virtual void visit(const CJUMP* node) const {
        print_tabs(counter++);
        cout << "CJUMP " << CJumpOpStrings[node->relop] << " " <<
            node->iftrue->Name()<< " " << node->iffalse->Name() << " " << endl;
        node->left->accept(this);
        node->right->accept(this);
        --counter;
    }

    virtual void visit(const SEQ* node) const {
        if (!withoutSEQ){
            print_tabs(counter++);
            cout << "SEQ" << endl;
        }
        node->left->accept(this);
        node->right->accept(this);
        if (!withoutSEQ)
            --counter;
    }

    virtual void visit(const LABEL* node) const {
        print_tabs(counter++);
        cout << "LABEL "<< node->label->Name() << endl;
        --counter;
    }

    virtual void visit(const CONST* node) const {
        print_tabs(counter++);
        cout << "CONST " << node->value << endl;
        --counter;
    }

    virtual void visit(const NAME* node) const {
        print_tabs(counter++);
        cout << "NAME " << node->label->Name() << endl;
        --counter;
    }

    virtual void visit(const TEMP* node) const {
        print_tabs(counter++);
        cout << "TEMP " << node->temp->Name() << endl;
        //node->temp->accept(this);
        --counter;
    }

    virtual void visit(const BINOP* node) const {
        print_tabs(counter++);
        cout << "BINOP " << ArithmeticOpStrings[node->binop] << endl;
        node->left->accept(this);
        node->right->accept(this);
        --counter;
    }

    virtual void visit(const MEM* node) const {
        print_tabs(counter++);
        cout << "MEM" << endl;
        node->exp->accept(this);
        --counter;
    }

    virtual void visit(const CALL* node) const {
        print_tabs(counter++);
        cout << "CALL" << endl;
        node->func->accept(this);
        shared_ptr<ExpList> cur = node->args;
        while(cur){
            cur->head->accept(this);
            cur = cur->tail;
        }
        --counter;
    }

    virtual void visit(const ESEQ* node) const {
        print_tabs(counter++);
        cout << "ESEQ" << endl;
        node->stm->accept(this);
        node->exp->accept(this);
        --counter;
    }

private:
  mutable int counter = 0;
    void print_tabs(int num) const {
      for (int i = 0; i < num; i++)
        cout << "| ";
    }
};