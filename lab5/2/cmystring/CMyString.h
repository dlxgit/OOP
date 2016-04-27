#pragma once
#include <string>



class CMyString
{
public:

	// конструктор по умолчанию
	CMyString();

	CMyString(const char * pString);

	// конструктор, инициализирующий строку данными из 
	// символьного массива заданной длины
	CMyString(const char * pString, size_t length);

	// конструкторкопирования
	CMyString(CMyString const & other);

	// перемещающий конструктор (для компиляторов, совместимых с C++11)
	//  реализуется совместно с перемещающим оператором присваивания 
	CMyString(CMyString && other);

	// конструктор, инициализирующий строку данными из 
	// строкистандартнойбиблиотеки C++
	CMyString(std::string const & stlString);

	// деструктор класса - освобождает память, занимаемую символами строки
	~CMyString();

	// возвращает длину строки (без учета завершающего нулевого символа)
	size_t GetLength() const;

	// возвращает указатель на массив символов строки.
	// В конце массива обязательно должен быть завершающий нулевой символ
	// дажееслистрокапустая
	const char * GetStringData() const;

	// возвращает подстроку с заданной позиции длиной не больше length символов
	

	CMyString & CMyString::operator+(const CMyString & right);

	CMyString & CMyString::operator+(const std::string & right);

	CMyString & CMyString::operator+(const char * right);

	CMyString & CMyString::operator+=(const CMyString & right);

	const bool & CMyString::operator==(const CMyString & right)const;

	const bool & CMyString::operator!=(const CMyString & right)const;


private:
	char * m_pStr;
	size_t m_size;
};