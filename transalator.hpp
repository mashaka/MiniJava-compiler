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
        n->e1->accept(this); //MainClass
        if(n->e2 != 0) {
            n->e2->accept(this); //ClassDeclarationList
        }
    }

    void visit(const MainClass* n){
        n->e3->accept(this);
    }

    void visit(const ClassDeclaration1* n){
        // 1, 2?
        if(n->e3 != 0){
            n->e3->accept(this); //VarDeclarationList
        }
        if(n->e4 != 0) {
            n->e4->accept(this); //MethodDeclarationList
        }
    }

    void visit(const ClassDeclaration2* n){
        // 1?
        if(n->e2 != 0){
            n->e2->accept(this); //VarDeclarationList
        }
        if(n->e3 != 0) {
            n->e3->accept(this); //MethodDeclarationList
        }
    }

    void visit(const ClassDeclarationList* n){
        n->e1->accept(this); //ClassDeclaration
        if(n->e2 != 0) {
            n->e2->accept(this); //ClassDeclarationList
        }
    }

    void visit(const VarDeclaration* n){
        n->e1->accept(this); //Type
        // 2?
    }

    void visit(const VarDeclarationList* n){
        if(n->e1 != 0) {
            n->e1->accept(this); //VarDeclarationList
        }
        n->e2->accept(this); //VarDeclaration
    }

    void visit(const MethodDeclaration1* n){
        // 2? 4?

        n->e1->accept(this); //Type

        n->e3->accept(this); //Type

        if(n->e5 != 0) {
            n->e5->accept(this); //CommaTypeIdentifierList
        }
        if(n->e6 != 0){
            n->e6->accept(this); //VarDeclarationList
        }
        if(n->e7 != 0) {
            n->e7->accept(this); //StatementList
        }
        
        n->e8->accept(this); //Expression
    }

    void visit(const MethodDeclaration2* n){
        // 2?

        n->e1->accept(this); //Type

        if(n->e3 != 0){
            n->e3->accept(this); //VarDeclarationList
        }
        if(n->e4 != 0) {
            n->e4->accept(this); //StatementList
        }
        n->e5->accept(this); //Expression
    }

    void visit(const MethodDeclarationList* n){
        n->e1->accept(this); //MethodDeclaration
        if(n->e2 != 0) {
            n->e2->accept(this); //MethodDeclarationList
        }
    }

    void visit(const CommaTypeIdentifierList* n){
        // 2?
        n->e1->accept(this); //Type
        if(n->e3 != 0) {
            n->e3->accept(this); //CommaTypeIdentifierList
        }
    }

    void visit(const TypeIntArray* n){

    }

    void visit(const TypeBoolean* n){

    }

    void visit(const TypeInt* n){

    }

    void visit(const TypeIdentifier* n){
        // 1?
    }

    void visit(const StatementListBraced* n){
        if(n->e1 != 0) {
            n->e1->accept(this); //StatementList
        }
    }

    void visit(const StatementIf* n){
        n->e1->accept(this); //Expression
        n->e2->accept(this); //Statement
        n->e3->accept(this); //Statement
    }

    void visit(const StatementWhile* n){
        n->e1->accept(this); //Expression
        n->e2->accept(this); //Statement
    }

    void visit(const StatementPrint* n){
        n->e1->accept(this); //Expression
    }

    void visit(const StatementIdentifier1* n){
        // 1?
        n->e2->accept(this); //Expression
    }

    void visit(const StatementIdentifier2* n){
        // 1?
        n->e2->accept(this); //Expression
        n->e3->accept(this); //Expression
    }

    void visit(const StatementList* n){
        n->e1->accept(this); //Statement
        if(n->e2 != 0) {
            n->e2->accept(this); //StatementList
        }
    }

    void visit(const ExpressionBinOp* n){
        n->e1->accept(this); //Expression
        // 2?
        n->e3->accept(this); //Expression
    }

    void visit(const ExpressionAriOp* n){
        n->e1->accept(this); //Expression
        // 2?
        n->e3->accept(this); //Expression
    }

    void visit(const ExpressionBracks* n){
        n->e1->accept(this); //Expression
        n->e2->accept(this); //Expression
    }

    void visit(const ExpressionLength* n){
        n->e1->accept(this); //Expression
    }

    void visit(const ExpressionMethod* n){
        n->e1->accept(this); //Expression
        // 2?
        n->e3->accept(this); //Expression
        if(n->e4 != 0) {
            n->e4->accept(this); //CommaExpressionList
        }
    }

    void visit(const ExpressionEmptyMethod* n){
        n->e1->accept(this);
        // 2?
    }

    void visit(const ExpressionNum* n){
        // 1?
    }

    void visit(const ExpressionLogOp* n){
        // 1?
    }

    void visit(const ExpressionId* n){
        // 1?
    }

    void visit(const ExpressionThis* n){

    }

    void visit(const ExpressionNew* n){
        n->e1->accept(this);
    }

    void visit(const ExpressionEmptyNew* n){
        // 1?
    }

    void visit(const ExpressionNot* n){
        n->e1->accept(this);
    }

    void visit(const ExpressionParens* n){
        n->e1->accept(this); //Expression
    }

    void visit(const CommaExpressionList* n){
        n->e1->accept(this); //Expression
        if(n->e2 != 0) {
            n->e2->accept(this); //CommaExpressionList
        }
    }
};
