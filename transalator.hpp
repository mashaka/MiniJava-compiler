#include "IRTree.hpp"


// using namespace IRTree;
// using namespace Temp;
// using namespace Frame;

class ISubtreeWrapper {
public:
    virtual ~ISubtreeWrapper() { }
    virtual const IExp* ToExp() const = 0;
    virtual const IStm* ToStm() const = 0;
    virtual const IStm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const = 0;
};

class CExpConverter : public ISubtreeWrapper {
public:
    CExpConverter(const IExp* _expr) : expr(_expr) {}

    const IExp* ToExp() const {
        return expr;
    }

    const IStm* ToStm() const {
        return new EXP(expr);
    }

    const IStm* ToConditional(const Temp::CLabel* t,const Temp::CLabel* f) const {
        return new CJUMP(EQ, expr, new CONST(0), f, t);
    }

private:
    const IExp* expr;
};

class CStmConverter : public ISubtreeWrapper {
public:
    CStmConverter(const IStm* _stm): stm(_stm) {}

    const IExp* ToExp() const {
        assert(0);
    }

    const IStm* ToStm() const {
        return stm;
    }

    const IStm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const {
        assert(0);
    }

private:
    const IStm* stm;
};

class CConditionalWrapper : public ISubtreeWrapper {
public:
    const IExp* ToExp() const {
        shared_ptr<CTemp> r = shared_ptr<CTemp>( new Temp::CTemp() );
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

    virtual const IStm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const = 0;

    const IStm* ToStm() const {
        Temp::CLabel* jmp = new Temp::CLabel();
        return new SEQ( ToConditional(jmp, jmp), new LABEL(jmp) );
    }
};

class CRelativeCmpWrapper : public CConditionalWrapper {
public:
    CRelativeCmpWrapper(CJUMP_OP _op, const IExp* _first, const IExp* _second) :
        op(_op), first(_first), second(_second) {}
    const IStm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const {
        return new CJUMP(op, first, second, t, f);
    }
private:
    const IExp* first;
    const IExp* second;
    CJUMP_OP op;
};

class CFromAndConverter : public CConditionalWrapper {
public:
    CFromAndConverter(const IExp* _leftArg, const IExp* _rightArg) :
        leftArg(_leftArg), rightArg(_rightArg) {}
    const IStm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const {
        const Temp::CLabel* z = new Temp::CLabel();
        return new SEQ( new CJUMP(LT, leftArg, new CONST(1), f, z),
            new SEQ(new LABEL(z), new CJUMP(LT, rightArg, new CONST(1), f, t)));
    }
private:
    const IExp* leftArg;
    const IExp* rightArg;
};

class CFromOrConverter : public CConditionalWrapper {
public:
    CFromOrConverter(const IExp* _leftArg, const IExp* _rightArg) : leftArg(_leftArg), rightArg(_rightArg) {}
    const IStm* ToConditional(const Temp::CLabel* t, const Temp::CLabel* f) const {
        const CLabel* z = new CLabel();
        return new SEQ(new CJUMP(GT, leftArg, new CONST(1), t, z),
            new SEQ(new LABEL(z), new CJUMP(LT, rightArg, new CONST(1), f, t)));
    }
private:
    const IExp* leftArg;
    const IExp* rightArg;
};


class Translator : public IVisitor {
public:
    // int tabsCount;
    // Translator() : tabsCount(0) {}

    void visit(const Goal* n){

    }

    void visit(const MainClass* n){

    }

    void visit(const ClassDeclaration1* n){

    }

    void visit(const ClassDeclaration2* n){

    }

    void visit(const ClassDeclarationList* n){

    }

    void visit(const VarDeclaration* n){

    }

    void visit(const VarDeclarationList* n){

    }

    void visit(const MethodDeclaration1* n){

    }

    void visit(const MethodDeclaration2* n){

    }

    void visit(const MethodDeclarationList* n){

    }

    void visit(const CommaTypeIdentifierList* n){

    }

    void visit(const TypeIntArray* n){

    }

    void visit(const TypeBoolean* n){

    }

    void visit(const TypeInt* n){

    }

    void visit(const TypeIdentifier* n){

    }

    void visit(const StatementListBraced* n){

    }

    void visit(const StatementIf* n){

    }

    void visit(const StatementWhile* n){

    }

    void visit(const StatementPrint* n){

    }

    void visit(const StatementIdentifier1* n){

    }

    void visit(const StatementIdentifier2* n){

    }

    void visit(const StatementList* n){

    }

    void visit(const ExpressionBinOp* n){

    }

    void visit(const ExpressionAriOp* n){

    }

    void visit(const ExpressionBracks* n){

    }

    void visit(const ExpressionLength* n){

    }

    void visit(const ExpressionMethod* n){

    }

    void visit(const ExpressionEmptyMethod* n){

    }

    void visit(const ExpressionNum* n){

    }

    void visit(const ExpressionLogOp* n){

    }

    void visit(const ExpressionId* n){

    }

    void visit(const ExpressionThis* n){

    }

    void visit(const ExpressionNew* n){

    }

    void visit(const ExpressionEmptyNew* n){

    }

    void visit(const ExpressionNot* n){

    }

    void visit(const ExpressionParens* n){

    }

    void visit(const CommaExpressionList* n){

    }
};
