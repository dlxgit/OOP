#pragma once
#include <memory>
#include <stdexcept> 

template <typename T>

class CMyList
{
public:
	struct Node 
	{
		Node(std::unique_ptr<T> && data, Node * prev, std::unique_ptr<Node> && next)
			: data(std::move(data)), prev(prev), next(std::move(next))
		{
		}
		std::unique_ptr<T> data;
		Node * prev;
		std::unique_ptr<Node> next;
	};

	CMyList()
	{
		m_head = nullptr;
		m_tail = nullptr;
		m_size = 0;
	}

	CMyList(const CMyList & other) : m_head(other.m_head.get())
	{
  		this->m_tail = other.m_tail;
  		this->m_size = other.m_size;
	}

	~CMyList()
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
	
	CMyList & operator =(const CMyList & other)
	{
		if (std::addressof(other) != this)
		{
			CMyList tmpCopy(other);
			std::swap(m_head, tmpCopy.m_head);
			std::swap(m_size, tmpCopy.m_size);
			std::swap(m_tail, tmpCopy.m_tail);
		}
		return *this;
	}

private:
	size_t m_size;
	std::unique_ptr<Node> m_head = nullptr;
	Node * m_tail = nullptr;
	 
public:
	class CIterator : std::iterator<std::bidirectional_iterator_tag, T>
	{
		friend class CMyList;
	public:
		CIterator(Node * node, bool isReverse = false)
		{
			m_node = node;
			m_isReverse = isReverse;
		}

		CIterator() = default;

		T & operator * () const
		{
			return *(m_node->data);
		}

		bool operator!=(CIterator const & other) const
		{
			return m_node != other.m_node;
		}

		bool operator==(CIterator const & other) const
		{
			return m_node == other.m_node;
		}

		CIterator & operator++()
		{
			if (m_node->next == nullptr)
			{
				*this = CIterator(&Node(nullptr, m_node, nullptr));
				return *this;
			}
			m_node = m_isReverse ? m_node->prev : m_node->next.get();
			return *this;
		}

		CIterator & operator--()
		{
			m_node = m_isReverse ? m_node->next.get() : m_node->prev;
			return *this;
		}

		CIterator operator+(int index)
		{
			size_t nIterations = abs(index);
			while (nIterations > 0)
			{
				if (m_isReverse && index > 0 || !m_isReverse && index < 0)
				{
					m_node = m_node->prev;
				}
				else
				{
					m_node = m_node->next.get();
				}
				--nIterations;

				if (m_node == nullptr)
				{
					throw std::out_of_range("Iterator incrementing is impossible");
				}
			}
			return CIterator(m_node);
		}

		CIterator operator++(int)
		{
			CIterator oldValue = *this;
			++(*this);
			return oldValue;
		}

		CIterator operator--(int)
		{
			CIterator oldValue = *this;
			--(*this);
			return oldValue;
		}

		T * operator->()const
		{
			return m_node->data.get();
		}

	private:
		Node * m_node = nullptr;
		bool m_isReverse = false;
	};

	class CConstIterator : std::iterator<std::bidirectional_iterator_tag, T>
	{
		friend class CMyList;
	public:
		CConstIterator() = default;
		CConstIterator(Node * node, bool isReverse = false)
		{
			m_node = node;
			m_isReverse = isReverse;
		}
	
		const T & operator * () const
		{
			return *(m_node->data);
		}

		bool operator!=(CConstIterator const & other) const
		{
			return m_node != other.m_node;
		}

		bool operator==(CConstIterator const & other) const
		{
			return m_node == other.m_node;
		}

		CConstIterator & operator++()
		{
			m_node = m_isReverse ? m_node->prev : m_node->next.get();
			return *this;
		}

		CConstIterator & operator--()
		{
			m_node = m_isReverse ? m_node->next.get() : m_node->prev;
			return *this;
		}

		CConstIterator operator+(int index)
		{
			size_t nIterations = abs(index);
			while (nIterations > 0)
			{
				if (m_isReverse && index > 0 || !m_isReverse && index < 0)
				{
					m_node = m_node->prev;
				}
				else
				{
					m_node = m_node->next.get();
				}
				--nIterations;

				if (m_node == nullptr)
				{
					throw std::out_of_range("Iterator incrementing is impossible");
				}
			}
			return CConstIterator(m_node);
		}

		CConstIterator operator++(int)
		{
			CConstIterator oldValue = *this;
			++(*this);
			return oldValue;
		}

		CConstIterator operator--(int)
		{
			CConstIterator oldValue = *this;
			--(*this);
			return oldValue;
		}

		const T * operator->()const
		{
			return m_node->data.get();
		}

	private:
		Node * m_node = nullptr;
		bool m_isReverse = false;
	};
	
	void PushBack(const T & elem)
	{
		std::unique_ptr<Node> newElement = std::make_unique<Node>(std::make_unique<T>(elem), m_tail, nullptr);
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

	void PushFront(const T & elem)
	{
		if (!Empty())
		{
			std::unique_ptr<Node> newElement = std::make_unique<Node>(std::make_unique<T>(elem), nullptr, std::move(m_head));
			m_head = std::move(newElement);
			m_head->next->prev = m_head.get();
		}
		else
		{
			std::unique_ptr<Node> newElement = std::make_unique<Node>(std::make_unique<T>(elem), nullptr, std::move(m_head));
			m_head = std::move(newElement);
			m_tail = m_head.get();
		}

		++m_size;
	}

	size_t Size() const
	{
		return m_size;
	}

	bool Empty() const
	{
		return m_head == nullptr;
	}

	void Clear()
	{
		while (m_tail)
		{
			m_tail->next = nullptr;
			m_tail = m_tail->prev;
		}
		m_head = nullptr;
		m_size = 0;
	}

	CIterator Insert(const CIterator & it, const T & value)
	{

		if (Empty() || it == begin())
		{
			PushFront(value);
			return begin();
		}

		Node * prevNode = it.m_node->prev;
		std::unique_ptr<Node> newNode = std::make_unique<Node>(std::make_unique<T>(value), it.m_node->prev, std::move(it.m_node->prev->next));
		prevNode->next = std::move(newNode);
		++m_size;

		return CIterator(it.m_node->prev->next.get());
	}
	
	CIterator Erase(const CIterator & it)
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
		}
		--m_size;
		return it;
	}

	CIterator begin() const
	{
		return CIterator(m_head.get(), false);
	}

	CIterator end() const
	{
		return CIterator(&Node(nullptr, m_tail, nullptr));
	}

	CConstIterator Cbegin() const
	{
		return CConstIterator(m_head.get());
	}

	CConstIterator Cend() const
	{
		return CConstIterator(m_tail);
	}

	CIterator Rbegin() const
	{
		return CIterator(m_tail, true);
	}

	CIterator Rend() const
	{
		return CIterator(m_head.get(), true);
	}

	const CConstIterator Crbegin() const
	{
		return CConstIterator(m_tail, true);
	}

	const CConstIterator Crend() const
	{
		return CConstIterator(m_head->prev, true);
	}
};