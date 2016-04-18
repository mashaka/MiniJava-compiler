#pragma once

#include "ExpList.hpp"
#include <memory>

namespace Tree {
	class ExpList;

	class Exp {
	public:
		virtual std::shared_ptr<ExpList> kids() = 0;
		virtual std::shared_ptr<Exp> build(std::shared_ptr<ExpList> kids) = 0;

		virtual void print(int d = 0) = 0;
	};
}