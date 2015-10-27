#include "interfaces.hpp"

class Visitor {
public:
	virtual void visit(const Goal* n, int tabsCount);
	virtual void visit(const MainClass* n, int tabsCount);
	virtual void visit(const ClassDeclaration1* n, int tabsCount);
	virtual void visit(const ClassDeclaration2* n, int tabsCount);
	virtual void visit(const ClassDeclarationStar1* n, int tabsCount);
	virtual void visit(const ClassDeclarationStar2* n, int tabsCount);
	virtual void visit(const MethodDeclarationStar1* n, int tabsCount);
	virtual void visit(const MethodDeclarationStar2* n, int tabsCount);
	virtual void visit(const VarDeclaration* n, int tabsCount);
	virtual void visit(const VarDeclarationStar1* n, int tabsCount);
	virtual void visit(const VarDeclarationStar2* n, int tabsCount);
	virtual void visit(const MethodDeclaration1* n, int tabsCount);
};