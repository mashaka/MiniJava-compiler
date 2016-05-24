#pragma once

#include "LabelObj.hpp"
#include "TempList.hpp"

#include "Instr.hpp"
#include "Targets.hpp"

#include <memory>
#include <string>


namespace Assem {

class LABEL : public Instr {
public:
    std::shared_ptr<Temp::Label> label;

    LABEL(std::string _assem, std::shared_ptr<Temp::Label> _label)
        : label(_label)
    {
        assem = _assem;
    }

    std::shared_ptr<Temp::TempList> use() {
        return nullptr;
    }

    std::shared_ptr<Temp::TempList> def() {
        return nullptr;
    }

    std::shared_ptr<Targets> jumps() {
        return nullptr;
    }
};

}
