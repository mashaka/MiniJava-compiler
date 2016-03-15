#include "IRTree.hpp"


class ISubtreeWrapper {
public:
    virtual ~ISubtreeWrapper() { }
    virtual const IRTree::Exp* ToExp() const = 0;
    virtual const IRTree::Stm* ToStm() const = 0;
    virtual const IRTree::Stm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const = 0;
};

class CExpConverter : public ISubtreeWrapper {
public:
    CExpConverter(const IRTree::Exp* _expr) : expr(_expr) {}

    const IRTree::Exp* ToExp() const {
        return expr;
    }

    const IRTree::Stm* ToStm() const {
        return new EXP(expr);
    }

    const IRTree::Stm* ToConditional(const Temp::CLabel* t,const Temp::CLabel* f) const {
        return new CJUMP(EQ, expr, new CONST(0), f, t);
    }

private:
    const IRTree::Exp* expr;
};

class CStmConverter : public ISubtreeWrapper {
public:
    CStmConverter(const IRTree::Stm* _stm): stm(_stm) {}

    const IRTree::Exp* ToExp() const {
        assert(0);
    }

    const IRTree::Stm* ToStm() const {
        return stm;
    }

    const IRTree::Stm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const {
        assert(0);
    }

private:
    const IRTree::Stm* stm;
};

class CConditionalWrapper : public ISubtreeWrapper {
public:
    const IRTree::Exp* ToExp() const {
        Temp::CTemp* r = new Temp::CTemp();
        Temp::CLabel* t = new Temp::CLabel();
        Temp::CLabel* f = new Temp::CLabel();
        return new ESEQ(
               new SEQ( new MOVE( new TEMP(r), new CONST(1) ),
               new SEQ( ToConditional(t, f),
               new SEQ( new LABEL(f),
               new SEQ( new MOVE( new TEMP(r), new CONST(0) ),
                         new LABEL(t) ) ) ) ),
               new TEMP(r) );
    }

    virtual const IRTree::Stm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const = 0;

    const IRTree::Stm* ToStm() const {
        Temp::CLabel* jmp = new Temp::CLabel();

        return new SEQ( ToConditional(jmp, jmp), new LABEL(jmp) );
    }
};

class CRelativeCmpWrapper : public CConditionalWrapper {
public:
    CRelativeCmpWrapper(CJUMP_OP op, const IRTree::Exp* _first, const IRTree::Exp* _second) : first(_first), second(_second) {}
    const IRTree::Stm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const {
        return new CJUMP(op, first, second, t, f);
    }
private:
    const IRTree::Exp* first;
    const IRTree::Exp* second;
    CJUMP_OP op;
};

class CFromAndConverter : public CConditionalWrapper {
public:
    CFromAndConverter(const IRTree::Exp* _leftArg, const IRTree::Exp* _rightArg) : leftArg(_leftArg), rightArg(_rightArg) {}
    const IRTree::Stm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const {
        const Temp::CLabel* z = new Temp::CLabel();
        return new SEQ( new CJUMP(LT, leftArg, new CONST(1), f, z),
            new SEQ(new LABEL(z), new CJUMP(LT, rightArg, new CONST(1), f, t)));
    }
private:
    const IRTree::Exp* leftArg;
    const IRTree::Exp* rightArg;
};

class CFromOrConverter : public CConditionalWrapper {
public:
    CFromOrConverter(const IRTree::Exp* _leftArg, const IRTree::Exp* _rightArg) : leftArg(_leftArg), rightArg(_rightArg) {}
    const IRTree::Stm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const {
        const CLabel* z = new CLabel();
        return new SEQ(new CJUMP(GT, leftArg, new CONST(1), t, z),
            new SEQ(new LABEL(z), new CJUMP(LT, rightArg, new CONST(1), f, t)));
    }
private:
    const IRTree::Exp* leftArg;
    const IRTree::Exp* rightArg;
};



class CTranslator: public CVisitor {
    CStorage* symbolsStorage;
    CTable table;
    SymbolsTable::CClassInfo* current_class;
    SymbolsTable::CMethodInfo* current_method;
    CFrame* current_frame;
    std::shared_ptr<ISubtreeWrapper> current_node;
    std::vector<const INode*> trees;

    IRTree::Exp* findByName(const CSymbol* name){
        try{
            return current_frame->getLocal(current_method->getLocalIndex(name))->getExp();
        }
        catch (std::out_of_range* oor){
            delete oor;
            try{
                return current_frame->getFormal(current_method->getFormalIndex(name))->getExp();
            }
            catch (std::out_of_range* oor){
                delete oor;
                try{
                    return current_frame->getVar(current_class->getVarIndex(name))->getExp();
                }
                catch (std::out_of_range* oor){
                    cout<<oor->what()<< " "<<name->getString()<<endl;
                }
            }
        }
    }
public:
    CTranslator(CStorage* _symbols, CTable& _table):
        symbolsStorage(_symbols), table(_table),
        current_class(&table.classInfo[0]),
        current_method(&table.classInfo[0].methods[0])
    {}


};
