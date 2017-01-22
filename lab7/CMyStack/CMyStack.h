#pragma once

template<typename T>
/*
Х	¬талкивание элемента на вершину стека
Х	¬ыталкивание элемента с вершины стека
Х	¬озвращение элемента с вершины стека
Х	»нформацию о том, пуст ли стек.
Х	¬озможность опустошени€ стека(удалени€ всех его элементов) при помощи метода Clear.
Х	 онструктор копировани€ и оператор присваивани€
Х	 оснструктор перемещени€ и перемещающий оператор присваивани€
*/

class CMyStack
{
public:
	CMyStack(const CMyStack & stack);
	CMyStack();
	
	CMyStack & operator := (const CMyStack & right);

	void Push(const T & t);
	void Pop();
	T GetTop() const;
	bool IsEmpty();
	void Clear();
	
private:
	size_t m_size;
	T * m_pTop;
};
