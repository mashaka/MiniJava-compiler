#pragma once

#include "ExpList.hpp"
#include <memory>

namespace Tree {
	class Exp {
	public:
		virtual std::shared_ptr<ExpList> kids();
		virtual std::shared_ptr<Exp> build(std::shared_ptr<ExpList> kids);
	};
}