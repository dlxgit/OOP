#include "CMyStack.h"

template <typename T>

CMyStack::CMyStack(const CMyStack<T> & stack)
{

}

CMyStack::CMyStack()
{

}

CMyStack & CMyStack::operator := (const CMyStack & right)
{

}

void CMyStack::Push(const T & t)
{

}

void CMyStack::Pop()
{

}

T CMyStack::GetTop() const
{

}

bool CMyStack::IsEmpty()
{
	return m_size > 0;
}

void CMyStack::Clear()
{

}