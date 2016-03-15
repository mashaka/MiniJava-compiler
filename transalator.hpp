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

    void visit(const CProgramRuleNode* node){
        node->mainClass->accept(this);
        if (node->decl != 0)
            node->decl->accept(this);
    }

    void visit(const CMainClassDeclarationRuleNode* node){
        node->stmt->accept(this);
        // TODO: realize
    }

    void visit(const CDeclarationsListNode* node){
        if (node->decl != 0)
            node->decl->accept(this);
        if (node->cl != 0)
            node->cl->accept(this);
    }

    void visit(const CClassDeclarationRuleNode* node){
        current_class = &table.getClassInfo(node->ident);
        if (node->extDecl != 0)
            node->extDecl->accept(this);
        if (node->vars != 0)
            node->vars->accept(this);
        node->method->accept(this);
    }

    void visit(const CExtendDeclarationRuleNode* node){
        // TODO: realize
    }

    void visit(const CVarDeclarationsListNode* node){
        if (node->list != 0)
            node->list->accept(this);
        node->item->accept(this);
    }

    void visit(const CMethodDeclarationsListNode* node){
        if (node->list != 0)
            node->list->accept(this);
        node->item->accept(this);
    }

    void visit(const CVarDeclarationRuleNode* node){
    }

    void visit(const CMethodDeclarationRuleNode* node){
        current_method = &(current_class->getMethodInfo(node->ident));
        current_frame = new CFrame(node->ident);
        current_frame->allocFormal(); // this
        for (int i = 0; i < current_method->params.size(); i++){
            current_frame->allocFormal();
        }
        for (int i = 0; i < current_method->vars.size(); i++){
            current_frame->allocLocal();
        }
        for (int i = 0; i < current_class->vars.size(); i++){
            current_frame->allocVar();
        }
        node->type->accept(this);
        if (node->param_arg != 0)
            node->param_arg->accept(this);

        if (node->method_body != 0)
            node->method_body->accept(this);
        const IRTree::Stm* arg1 = current_node->ToStm();

        node->return_exp->accept(this);
        const IRTree::Exp* arg2 = current_node->ToExp();
        const IRTree::Exp* res = new ESEQ(arg1, arg2);
        trees.push_back(res);

        delete current_frame;
    }

    void visit(const CVarsDecListNode* node){
        if (node->list != 0)
            node->list->accept(this);
        if (node->next != 0)
            node->next->accept(this);
    }

    void visit(const CVarsDecFirstNode* node){
        if (node->first != 0)
          node->first->accept(this);
    }

    void visit(const CStatsFirstNode* node){
        if (node->stm != 0)
            node->stm->accept(this);
    }

    void visit(const CStatsListNode* node){
        if (node->list != 0)
            node->list->accept(this);
        if (node->stm != 0)
            node->stm->accept(this);
    }

    void visit(const CMethodBodyVarsNode* node){
        if (node->vars != 0)
            node->vars->accept(this);
    }

    void visit(const CMethodBodyStatsNode* node){
        node->stats->accept(this);
    }

    void visit(const CMethodBodyAllNode* node){
        node->vars->accept(this);
        node->stats->accept(this);
    }

    void visit(const CParamArgListNode* node){
        node->params->accept(this);
    }

    void visit(const CParamsOneNode* node){
        if (node->param != 0)
            node->param->accept(this);
    }

    void visit(const CParamsTwoNode* node){
        if (node->first != 0)
            node->first->accept(this);
        if (node->second != 0)
            node->second->accept(this);
    }

    void visit(const CParamRuleNode* node){
        node->type->accept(this);
    }

    void visit(const CTypeRuleNode* node){
    }

    void visit(const CNumerousStatementsNode* node){
        // TODO: SEQ
        if (node->statements != 0)
            node->statements->accept(this);
        node->statement->accept(this);
    }

    void visit(const CBracedStatementNode* node){
        if (node->statements != 0)
            node->statements->accept(this);
    }

    //TODO
    void visit(const CIfStatementNode* node){
        node->expression->accept(this);
        const CLabel* t = new CLabel();
        const CLabel* f = new CLabel();
        const CLabel* e = new CLabel();
        const IRTree::Stm* stm = current_node->ToConditional(t, f);

        node->thenStatement->accept(this);

        const IRTree::Stm* thenStatement = current_node->ToStm();
        thenStatement = new SEQ( new SEQ( new LABEL(t), thenStatement ), new JUMP(e) );
        if (node->elseStatement != 0){
            node->elseStatement->accept(this);
        }
        const IRTree::Stm* elseStatement = current_node->ToStm();
        elseStatement = new SEQ( new SEQ( new LABEL(f), elseStatement ), new LABEL(e) );

        const IRTree::Stm* res = new SEQ( new SEQ( stm, thenStatement ), elseStatement );
        current_node = std::shared_ptr<CStmConverter>( new CStmConverter(res) );
    }

    void visit(const CWhileStatementNode* node){
        node->expression->accept(this);

        const IRTree::Exp* expr = current_node->ToExp();
        node->statement->accept(this);
        const IRTree::Stm* statement = current_node->ToStm();
        const CLabel* f = new CLabel();
        const CLabel* t = new CLabel();

        const IRTree::Stm* res = new SEQ(new SEQ(new SEQ(new SEQ(
                              new CJUMP(EQ, expr, new CONST(0), f, t),
                              new LABEL(t)),
                              statement),
                              new CJUMP(EQ, expr, new CONST(0), f, t)),
                              new LABEL(f));

        current_node = std::shared_ptr<CStmConverter>(new CStmConverter(res));
    }

    void visit(const CPrintStatementNode* node){
        // TODO: print
        node->expression->accept(this);
    }

    void visit(const CAssignStatementNode* node){
        node->expression->accept(this);
        const IRTree::Stm* res = new MOVE( findByName(node->identifier), current_node->ToExp() );
        current_node = std::shared_ptr<CStmConverter>(new CStmConverter(res));
    }
    void visit(const CInvokeExpressionStatementNode* node){
        node->firstexpression->accept(this);
        node->secondexpression->accept(this);
    }

    void visit(const CInvokeExpressionNode* node){
        node->firstExp->accept(this);
        node->secondExp->accept(this);
    }

    void visit(const CLengthExpressionNode* node){
        node->expr->accept(this);
    }

    void visit(const CArithmeticExpressionNode* node) {
        node->firstExp->accept(this);
        const IRTree::Exp* arg1 = current_node->ToExp();
        node->secondExp->accept(this);
        const IRTree::Exp* arg2 = current_node->ToExp();
        const IRTree::Exp* res;
        const CConditionalWrapper* converter;
        switch (node->opType) {
            case AND_OP:
                converter = new CFromAndConverter(
                    arg1,
                    arg2);
                res = converter->ToExp();
                delete converter;
                break;
            case OR_OP:
                converter = new CFromOrConverter(
                    arg1,
                    arg2);
                res = converter->ToExp();
                delete converter;
                break;
            default:
                res = new BINOP(node->opType,
                    arg1,
                    arg2);
                break;
        }

        current_node = std::shared_ptr<CExpConverter>(new CExpConverter(res));
    }

    void visit(const CUnaryExpressionNode* node){
        node->expr->accept(this);
        const IRTree::Exp* arg = current_node->ToExp();
        const IRTree::Exp* res;// = new BINOP(node->op, new CONST(0), arg);
        current_node = std::shared_ptr<CExpConverter>(new CExpConverter(res));
    }

    void visit(const CCompareExpressionNode* node){
        node->firstExp->accept(this);
        const IRTree::Exp* arg1 = current_node->ToExp();
        node->secondExp->accept(this);
        const IRTree::Exp* arg2 = current_node->ToExp();

        const CConditionalWrapper* cmpWrapper = new CRelativeCmpWrapper(LT,
            arg1, arg2);
        current_node = std::shared_ptr<CExpConverter>(new CExpConverter(cmpWrapper->ToExp()));

    }

    void visit(const CNotExpressionNode* node){
        node->expr->accept(this);
    }

    void visit(const CNewArrayExpressionNode* node){
        node->expr->accept(this);
    }

    void visit(const CNewObjectExpressionNode* node){
    }

    void visit(const CIntExpressionNode* node) {
        current_node = std::shared_ptr<CExpConverter>(
            new CExpConverter(new CONST(node->value)));
    }

    void visit(const CBooleanExpressionNode* node){
    }

    void visit(const CIdentExpressionNode* node){
        IRTree::Exp* result = findByName(node->name);
        current_node = std::shared_ptr<CExpConverter>(new CExpConverter(result));
    }

    void visit(const CThisExpressionNode* node){
        current_node = std::shared_ptr<CExpConverter>(
            new CExpConverter(current_frame->getFormal(0)->getExp()));
    }

    void visit(const CParenExpressionNode* node){
        node->expr->accept(this);
    }

    void visit(const CInvokeMethodExpressionNode* node){
        node->expr->accept(this);
        if (node->args != 0)
            node->args->accept(this);
    }

    void visit(const CFewArgsExpressionNode* node){
        node->expr->accept(this);
    }

    void visit(const CListExpressionNode* node){
        node->prevExps->accept(this);
        node->nextExp->accept(this);
    }

    void visit(const CLastListExpressionNode* node){
        node->expr->accept(this);
    }
};
