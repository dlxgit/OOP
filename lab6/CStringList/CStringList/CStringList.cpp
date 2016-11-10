#include "stdafx.h"
#include "CStringList.h"


CStringList::CStringList()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

CStringList::CIterator::CIterator(CStringList::Node * node, bool isReverse)
{
	m_node = node;
	m_isReverse = isReverse;
}

void CStringList::push_back(const std::string & str)
{
	std::unique_ptr<Node> newElement = std::make_unique<Node>(str, m_tail, nullptr);
	if (!empty())
	{
		m_tail->next = std::move(newElement);
		m_tail = m_tail->next.get();
	}
	else
	{
		m_head = std::move(newElement);
		m_tail = m_head.get();
	}
	++m_size;
}

void CStringList::push_front(const std::string & str)
{
	if (!empty())
	{
		std::unique_ptr<Node> newElement = std::make_unique<Node>(str, nullptr, std::move(m_head));
		m_head = std::move(newElement);
		m_head->next->prev = m_head.get();
	}
	else
	{
		std::unique_ptr<Node> newElement = std::make_unique<Node>(str, nullptr, std::move(m_head));
		m_head = std::move(newElement);
		m_tail = m_head.get();
	}

	++m_size;
}

size_t CStringList::size()
{
	return m_size;
}

bool CStringList::empty()
{
	return m_head == nullptr;
}

void CStringList::clear()
{
	while (m_tail)
	{
		m_tail->next = nullptr;
		m_tail = m_tail->prev;
	}
	m_head = nullptr;
	m_size = 0;
}

CStringList::CIterator CStringList::insert(const CIterator & it, const std::string & value)
{

	if (empty() || it == begin())
	{
		push_front(value);
		return begin();
	}


	Node * prevNode = it->prev;
	std::unique_ptr<Node> newNode = std::make_unique<Node>(value, it->prev, std::move(it->prev->next));
	prevNode->next = std::move(newNode);
	++m_size;

	return CIterator(it->prev->next.get());
}

CStringList::CIterator CStringList::erase(const CIterator & it)
{
	if (it == nullptr)
	{
		throw std::out_of_range("Iterator is nullptr");
	}

	if (m_size == 1)
	{
		clear();
		return begin();
	}
	if (it == m_head.get())
	{
		m_head->next->prev = nullptr;
		m_head = std::move(m_head->next);
	}
	else if (it == m_tail)
	{
		m_tail = m_tail->prev;
		m_tail->next = nullptr;
	}
	else
	{
		Node * prevNode = it->prev;
		std::unique_ptr<Node> nextNode = std::move(it->next);
		prevNode->next = std::move(nextNode);
		prevNode->next->prev = prevNode;

		if (it->prev == nullptr)
		{
			m_head = std::move(it->next);
			m_head->prev = nullptr;
		}
	}
	--m_size;
	return it;
}

CStringList::CIterator CStringList::begin()
{
	return CIterator(m_head.get(), false);
}

CStringList::CIterator CStringList::end()
{
	return CIterator(m_tail);
}

CStringList::CIterator CStringList::cbegin() const
{
	return CIterator(m_head.get());
}

CStringList::CIterator CStringList::cend() const
{
	return CIterator(nullptr);
}

CStringList::CIterator CStringList::rbegin()
{
	return CIterator(m_tail, true);
}

CStringList::CIterator CStringList::rend()
{
	return CIterator(m_head->prev, true);
}

std::string CStringList::CIterator::operator * () const
{
	return m_node->data;
}

bool CStringList::CIterator::operator!=(CIterator const & other) const
{
	return m_node != other.m_node;
}

bool CStringList::CIterator::operator==(CIterator const & other) const
{
	return m_node == other.m_node;
}

CStringList::CIterator & CStringList::CIterator::operator++()
{
	m_node = m_isReverse ? m_node->prev : m_node->next.get();
	return *this;
}

CStringList::CIterator & CStringList::CIterator::operator--()
{
	m_node = m_isReverse ? m_node->next.get() :m_node->prev;
	return *this;
}

CStringList::CIterator CStringList::CIterator::operator+(size_t index)
{
	while (index > 0)
	{
		if (m_isReverse)
		{
			m_node = m_node->prev;
		}
		else
		{
			m_node = m_node->next.get();
		}
		
		if (m_node == nullptr)
		{
			throw std::out_of_range("Iterator incrementing is impossible");
		}
		--index;
	}
	return CIterator(m_node);
}

CStringList::Node * CStringList::CIterator::operator->()const
{
	return m_node;
}