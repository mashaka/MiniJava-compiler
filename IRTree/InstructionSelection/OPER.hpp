#pragma once

#include "TempList.hpp"
#include "LabelList.hpp"

#include "Instr.hpp"
#include "Targets.hpp"

#include <memory>
#include <string>


namespace Assem {

class OPER : public Instr {
public:
    std::shared_ptr<Temp::TempList> dst;
    std::shared_ptr<Temp::TempList> src;
    std::shared_ptr<Targets> jump;

    OPER(std::string _assem, std::shared_ptr<Temp::TempList> _dst,
         std::shared_ptr<Temp::TempList> _src, std::shared_ptr<Temp::LabelList> _jump)
        : dst(_dst), src(_src)
    {
        assem = _assem;
        jump = std::make_shared<Targets>(_jump);
    }

    OPER(std::string _assem, std::shared_ptr<Temp::TempList> _dst, std::shared_ptr<Temp::TempList> _src)
        : dst(_dst), src(_src), jump(nullptr)
    {
        assem = _assem;
    }

    std::shared_ptr<Temp::TempList> use() {
        return src;
    }

    std::shared_ptr<Temp::TempList> def() {
        return dst;
    }

    std::shared_ptr<Targets> jumps() {
        return jump;
    }
};

}
