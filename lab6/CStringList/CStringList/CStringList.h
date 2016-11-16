#pragma once
#include <string>
#include <memory>

class CStringList
{
public:
	struct Node {
		Node(const std::string & data, Node * prev, std::unique_ptr<Node> && next)
			: data(data), prev(prev), next(std::move(next))
		{
		}
		std::string data;
		Node * prev;
		std::unique_ptr<Node> next;
	};

	CStringList();
	~CStringList();
	 
	class CIterator : std::iterator<std::bidirectional_iterator_tag, std::string>
	{
		friend class CStringList;
	public:
		CIterator(CStringList::Node * node, bool isReverse = false);
		CIterator() = default;
		std::string & operator * () const;
		bool operator!=(CIterator const & other) const;
		bool operator==(CIterator const & other) const;
		CIterator & operator++();
		CIterator & operator--();
		CIterator operator+(size_t index);
		std::string * operator->()const;
	private:
		CStringList::Node * m_node = nullptr;
		bool m_isReverse = false;
	};

	class CConstIterator : std::iterator<std::bidirectional_iterator_tag, std::string>
	{
		friend class CStringList;
	public:
		CConstIterator(CStringList::Node * node, bool isReverse = false);
		CConstIterator() = default;
		const std::string & operator * () const;
		bool operator!=(CConstIterator const & other) const;
		bool operator==(CConstIterator const & other) const;
		const std::string * operator->()const;
	private:
		CStringList::Node * m_node = nullptr;
		bool m_isReverse = false;
	};
	
	void Push_back(const std::string & str);
	void Push_front(const std::string & str);
	size_t Size() const;
	bool Empty() const;
	void Clear();
	CStringList::CIterator Insert(const CStringList::CIterator & it, const std::string & value);
	CStringList::CIterator Erase(const CStringList::CIterator & it);
	CStringList::CIterator begin() const;
	CStringList::CIterator end() const;
	const CStringList::CConstIterator Cbegin() const;
	const CStringList::CConstIterator Cend() const;
	CStringList::CIterator Rbegin() const;
	CStringList::CIterator Rend() const;
	const CStringList::CConstIterator Rcbegin() const;
	const CStringList::CConstIterator Rcend() const;

private:
	size_t m_size;
	std::unique_ptr<Node> m_head = nullptr;
	Node * m_tail = nullptr;
};

CStringList::CIterator operator++(CStringList::CIterator& i, int);
CStringList::CIterator operator--(CStringList::CIterator& i, int);