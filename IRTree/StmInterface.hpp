#pragma once

#include "ExpList.hpp"
#include <memory>

namespace Tree {
	class Stm : public std::enable_shared_from_this<Stm> {
	public:
		virtual std::shared_ptr<ExpList> kids() = 0;
		virtual std::shared_ptr<Stm> build(std::shared_ptr<ExpList> _kids) = 0;

		virtual print(Stm stm, int d = 0) = 0;
	};
}
