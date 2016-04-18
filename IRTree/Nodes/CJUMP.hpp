#pragma once

#include "StmInterface.hpp"
#include "ExpInterface.hpp"
#include "LabelObj.hpp"
#include "ExpList.hpp"
#include "Print.hpp"

#include <memory>
#include <iostream>

namespace Tree {
    class Print;

    class CJUMP : public Stm {
    public:
        int relop;
        std::shared_ptr<Exp> left, right;
        std::shared_ptr<Temp::Label> iftrue, iffalse;
        static const int EQ = 0, NE = 1, LT = 2, GT = 3, LE = 4, GE = 5,
            ULT = 6, ULE = 7, UGT = 8, UGE = 9;

        CJUMP(int _relop, 
            std::shared_ptr<Exp> _left, 
            std::shared_ptr<Exp> _right, 
            std::shared_ptr<Temp::Label> _iftrue, 
            std::shared_ptr<Temp::Label> _iffalse)
            : relop(_relop), left(_left), right(_right), iftrue(_iftrue), iffalse(_iffalse) {}

        std::shared_ptr<ExpList> kids() {
            return std::make_shared<ExpList>(left, std::make_shared<ExpList>(right, nullptr));
        }

        std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) {
            return std::make_shared<CJUMP>(relop, _kids->head, _kids->tail->head, iftrue, iffalse);
        }

        static int notRel(int _relop) {
            switch (_relop) {
                case EQ:  return NE;
                case NE:  return EQ;
                case LT:  return GE;
                case GE:  return LT;
                case GT:  return LE;
                case LE:  return GT;
                case ULT: return UGE;
                case UGE: return ULT;
                case UGT: return ULE;
                case ULE: return UGT;
                default:
                    std::cerr << "bad relop in CJUMP.notRel" << std::endl;
                    return -1;
            }
        }

        void print(int d = 0) override {
            Print::indent(d); 
            Print::say("CJUMP("); 
            switch(this->relop) {
                case EQ:  Print::say("EQ");  break;
                case NE:  Print::say("NE");  break;
                case LT:  Print::say("LT");  break;
                case GT:  Print::say("GT");  break;
                case LE:  Print::say("LE");  break;
                case GE:  Print::say("GE");  break;
                case ULT: Print::say("ULT"); break;
                case ULE: Print::say("ULE"); break;
                case UGT: Print::say("UGT"); break;
                case UGE: Print::say("UGE"); break;
                default: throw "Wrong CJUMP field";
            }
            Print::sayln(","); 
            this->left->print(d + 1); 
            Print::sayln(",");
            this->right->print(d + 1); 
            Print::sayln(",");
            Print::indent(d+1); 
            Print::say(this->iftrue->toString()); 
            Print::say(",");
            Print::say(this->iffalse->toString()); 
            Print::say(")");
        }
    };
}
