namespace Tree {
	class MOVE;
	class EXP;
	class JUMP;
	class CJUMP;
	class SEQ;
	class LABEL;
	class CONST;
	class NAME;
	class TEMP;
	class BINOP;
	class MEM;
	class CALL;
	class ESEQ;
	class MoveCall;
	class ExpCall;
};

class CIRVisitor {
public:
	virtual void visit(Tree::MOVE* node) = 0;
	virtual void visit(Tree::EXP* node) = 0;
	virtual void visit(Tree::JUMP* node) = 0;
	virtual void visit(Tree::CJUMP* node) = 0;
	virtual void visit(Tree::SEQ* node) = 0;
	virtual void visit(Tree::LABEL* node) = 0;
	virtual void visit(Tree::CONST* node)= 0;
	virtual void visit(Tree::NAME* node) = 0;
	virtual void visit(Tree::TEMP* node) = 0;
	virtual void visit(Tree::BINOP* node) = 0;
	virtual void visit(Tree::MEM* node)= 0;
	virtual void visit(Tree::CALL* node) = 0;
	virtual void visit(Tree::ESEQ* node) = 0;
	virtual void visit(Tree::MoveCall* node) = 0;
	virtual void visit(Tree::ExpCall* node) = 0;
};