#pragma once

template<typename T>
/*
�	����������� �������� �� ������� �����
�	������������ �������� � ������� �����
�	����������� �������� � ������� �����
�	���������� � ���, ���� �� ����.
�	����������� ����������� �����(�������� ���� ��� ���������) ��� ������ ������ Clear.
�	����������� ����������� � �������� ������������
�	������������ ����������� � ������������ �������� ������������
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
