namespace Frame {
// Переменная фрейма
class IAccess {
	//хранит адрес ввиде смещения и номера переменной
public:
	virtual ~IAccess() {}
};

// Класс-контейнер с платформо-зависимой информацией о функции
class CFrame {
public:
	CFrame( const Symbol::CSymbol* name, int formalsCount );
	// Доступ к формальным параметрам
	int FormalsCount() const { 
		return formals.size(); 
	}
	const IAccess* Formal( size_t index ) const;

private:
	// ...
};
}

namespace Temp {
// Метка - точка перехода в коде
//адрес кода для jump
class CLabel {
public:
	// Создать метку с уникальным именем
	CLabel();
	// Создать метку с заданным именем
	explicit CLabel( ... );

	const std::string& Name() const { return name; }

private:
	// Счётчик для создания уникальных идентификаторов
	static int nextUniqueId;
	std::string name;
};


// Временная переменная
class CTemp {
public:
	// Новая переменная с уникальным именем
	CTemp();
	// Новая переменная с заданным именем
	explicit CTemp(const Symbol::CSymbol* symbol );
	~CTemp();

	const std::string& Name() const { return name; }

private:
	// Счётчик для создания уникальных имён
	static int nextUniqueId;
	std::string name;
};
} // namespace Temp

