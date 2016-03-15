#include<string>
#include"Symbol.hpp"

namespace Temp {
// Метка - точка перехода в коде
//адрес кода для jump
class CLabel {
public:
	// Создать метку с уникальным именем
	CLabel() {
		name = "label" + std::to_string(nextUniqueId);
		++nextUniqueId;
	}
	// Создать метку с заданным именем
	explicit CLabel( std::string name ) {
		this->name = name; 
	}

	const std::string& Name() const { 
		return name;
	}

private:
	// Счётчик для создания уникальных идентификаторов
	static int nextUniqueId;
	std::string name;
};

int CLabel::nextUniqueId = 0;


// Временная переменная
class CTemp {
public:
	// Новая переменная с уникальным именем
	CTemp() {
		name = "temp" + std::to_string(nextUniqueId);
		++nextUniqueId;
	}
	// Новая переменная с заданным именем
	explicit CTemp(const Symbol::CSymbol* symbol ) {
		name = symbol->String();
	}
	~CTemp() {}

	const std::string& Name() const { 
		return name; 
	}

private:
	// Счётчик для создания уникальных имён
	static int nextUniqueId;
	std::string name;
};

int CTemp::nextUniqueId = 0;

} // namespace Temp