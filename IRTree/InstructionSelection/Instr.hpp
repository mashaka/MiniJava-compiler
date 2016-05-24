#pragma once

#include "TempList.hpp"
#include "TempMap.hpp"
#include "LabelList.hpp"

#include "InstrList.hpp"
#include "Targets.hpp"

#include <memory>
#include <string>
#include <sstream>


namespace Assem {

class Instr {
public:
    std::string assem;

    virtual std::shared_ptr<Temp::TempList> use();
    virtual std::shared_ptr<Temp::TempList> def();
    virtual std::shared_ptr<Targets> jumps();

    std::string format(std::shared_ptr<Temp::TempMap> m) {
        std::shared_ptr<Temp::TempList> dst = def();
        std::shared_ptr<Temp::TempList> src = use();
        std::shared_ptr<Targets> j = jumps();
        std::shared_ptr<Temp::LabelList> jump = (j == nullptr) ? nullptr : j->labels;

        std::ostringstream s;
        int len = assem.length();
        for (int i = 0; i < len; i++) {
            if (assem[i] == '`') {
                switch(assem[++i]) {
                    case 's': {
                        int n = assem[++i] - '0';
                        s << m->tempMap(nthTemp(src, n));
                        break;
                    }
                    case 'd': {
                        int n = assem[++i] - '0';
                        s << m->tempMap(nthTemp(dst, n));
                        break;
                    }
                    case 'j': {
                        int n = assem[++i] - '0';
                        s << nthLabel(jump, n)->toString();
                        break;
                    }
                    case '`': {
                        s << '`';
                        break;
                    }
                    default: throw "bad Assem format";
                }
            } else {
                s << assem[i];
            }
        }

        return s.str();
    }

private:
    std::shared_ptr<Temp::Temp> nthTemp(std::shared_ptr<Temp::TempList> l, int i) {
        if (i == 0) {
            return l->head;
        } else {
            return nthTemp(l->tail, i - 1);
        }
    }

    std::shared_ptr<Temp::Label> nthLabel(std::shared_ptr<Temp::LabelList> l, int i) {
        if (i == 0) {
            return l->head;
        } else {
            return nthLabel(l->tail, i - 1);
        }
    }
};

}
