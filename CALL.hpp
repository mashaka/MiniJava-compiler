#pragma once

#include "ExpInterface.hpp"
#include "ExpList.hpp"

#include <memory>

namespace Tree {
	class CALL : public Exp {
	public:
		std::shared_ptr<Exp> func;
		std::shared_ptr<ExpList> args;

		CALL(std::shared_ptr<Exp> _func, std::shared_ptr<ExpList> _args) 
			: func(_func), args(_args) {}

		std::shared_ptr<ExpList> kids() {
			return std::make_shared<ExpList>(func, args);
		}
		std::shared_ptr<Exp> build(std::shared_ptr<ExpList> _kids) {
			return std::make_shared<CALL>(_kids.head, _kids.tail);
		}
	  
	};
}
