#include "stdafx.h"
#include "CStringList.h"

#include <boost/test/output/compiler_log_formatter.hpp>


CStringList::CStringList()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_size = 0;
}

CStringList::~CStringList()
{
	if (m_head == nullptr)
	{
		return;
	}

	while (m_head.get() != m_tail)
	{
		m_tail = m_tail->prev;
		m_tail->next = nullptr;
	}
	m_head = nullptr;
}


void CStringList::Push_back(const std::string & str)
{
	std::unique_ptr<Node> newElement = std::make_unique<Node>(str, m_tail, nullptr);
	if (!Empty())
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

void CStringList::Push_front(const std::string & str)
{
	if (!Empty())
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

size_t CStringList::Size() const
{
	return m_size;
}

bool CStringList::Empty() const
{
	return m_head == nullptr;
}

void CStringList::Clear()
{
	while (m_tail)
	{
		m_tail->next = nullptr;
		m_tail = m_tail->prev;
	}
	m_head = nullptr;
	m_size = 0;
}

CStringList::CIterator CStringList::Insert(const CStringList::CIterator & it, const std::string & value)
{

	if (Empty() || it == begin())
	{
		Push_front(value);
		return begin();
	}


	Node * prevNode = it.m_node->prev;
	std::unique_ptr<Node> newNode = std::make_unique<Node>(value, it.m_node->prev, std::move(it.m_node->prev->next));
	prevNode->next = std::move(newNode);
	++m_size;

	return CStringList::CIterator(it.m_node->prev->next.get());
}

CStringList::CIterator CStringList::Erase(const CStringList::CIterator & it)
{
	if (it == nullptr)
	{
		throw std::out_of_range("Iterator is nullptr");
	}
	if (m_size == 1)
	{
		Clear();
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
		Node * prevNode = it.m_node->prev;
		std::unique_ptr<Node> nextNode = std::move(it.m_node->next);
		prevNode->next = std::move(nextNode);
		prevNode->next->prev = prevNode;

		if (it.m_node->prev == nullptr)
		{
			m_head = std::move(it.m_node->next);
			m_head->prev = nullptr;
		}
	}
	--m_size;
	return it;
}

CStringList::CIterator CStringList::begin() const
{
	return CStringList::CIterator(m_head.get(), false);
}

CStringList::CIterator CStringList::end() const
{
	return CStringList::CIterator(m_tail->next.get());
}

const CStringList::CConstIterator CStringList::Cbegin() const
{
	return CStringList::CConstIterator(m_head.get());
}

const CStringList::CConstIterator CStringList::Cend() const
{
	return CStringList::CConstIterator(nullptr);
}

CStringList::CIterator CStringList::Rbegin() const
{
	return CStringList::CIterator(m_tail, true);
}

CStringList::CIterator CStringList::Rend() const
{
	return CStringList::CIterator(m_head->prev, true);
}

const CStringList::CConstIterator CStringList::Rcbegin() const
{
	return CStringList::CConstIterator(m_tail, true);

}

const CStringList::CConstIterator CStringList::Rcend() const
{
	return CStringList::CConstIterator(m_head->prev, true);
}

CStringList::CIterator::CIterator(CStringList::Node * node, bool isReverse)
{
	m_node = node;
	m_isReverse = isReverse;
}


std::string & CStringList::CIterator::operator * () const
{
	return (*m_node).data;
}


CStringList::CIterator & CStringList::CIterator::operator++()
{
	m_node = m_isReverse ? m_node->prev : m_node->next.get();
	return *this;
}

CStringList::CIterator & CStringList::CIterator::operator--()
{
	m_node = m_isReverse ? m_node->next.get() : m_node->prev;
	return *this;
}

CStringList::CIterator operator++(CStringList::CIterator& i, int)
{
	CStringList::CIterator oldValue = i;
	++i;
	return oldValue;
}

CStringList::CIterator operator--(CStringList::CIterator& i, int)
{
	CStringList::CIterator oldValue = i;
	--i;
	return oldValue;
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
	return CStringList::CIterator(m_node);
}

std::string * CStringList::CIterator::operator->() const
{
	return &m_node->data;
}

bool CStringList::CIterator::operator!=(CStringList::CIterator const & other) const
{
	return m_node != other.m_node;
}

bool CStringList::CIterator::operator==(CStringList::CIterator const & other) const
{
	return m_node == other.m_node;
}


CStringList::CConstIterator::CConstIterator(CStringList::Node * node, bool isReverse)
{
	m_node = node;
	m_isReverse = isReverse;
}


const std::string & CStringList::CConstIterator::operator * () const
{
	return m_node->data;
}

bool CStringList::CConstIterator::operator!=(CStringList::CConstIterator const & other) const
{
	return m_node != other.m_node;
}

bool CStringList::CConstIterator::operator==(CStringList::CConstIterator const & other) const
{
	return m_node == other.m_node;
}

const std::string * CStringList::CConstIterator::operator->()const
{
	return &m_node->data;
}