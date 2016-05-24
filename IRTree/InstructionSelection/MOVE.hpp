#pragma once

#include "TempObj.hpp"
#include "TempList.hpp"

#include "Instr.hpp"
#include "Targets.hpp"

#include <memory>
#include <string>


namespace Assem {

class MOVE : public Instr {
public:
    std::shared_ptr<Temp::Temp> dst;
    std::shared_ptr<Temp::Temp> src;

    MOVE(std::string _assem, std::shared_ptr<Temp::Temp> _dst, std::shared_ptr<Temp::Temp> _src)
        : dst(_dst), src(_src)
    {
        assem = _assem;
    }

    std::shared_ptr<Temp::TempList> use() {
        return std::make_shared<Temp::TempList>(src, nullptr);
    }

    std::shared_ptr<Temp::TempList> def() {
        return std::make_shared<Temp::TempList>(dst, nullptr);
    }

    std::shared_ptr<Targets> jumps() {
        return nullptr;
    }
};

}
