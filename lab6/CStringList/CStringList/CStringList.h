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

	class CIterator : std::iterator<std::bidirectional_iterator_tag, std::string>
	{
		friend class CStringList;
		CIterator(Node * node, bool isReverse = false);
	public:
		CIterator() = default;
		std::string operator * () const;
		bool operator!=(CIterator const & other) const;
		bool operator==(CIterator const & other) const;
		CIterator & operator++();
		CIterator & operator--();
		CIterator operator+(size_t index);
		Node * operator->()const;
	private:
		Node * m_node = nullptr;
		bool m_isReverse = false;
	};

	CStringList();

	void push_back(const std::string & str);
	void push_front(const std::string & str);
	size_t size();
	bool empty();
	void clear();
	CIterator insert(const CIterator & it, const std::string & value);
	CIterator erase(const CIterator & it);
	CIterator begin();
	CIterator end();
	CIterator rbegin();
	CIterator rend();
	CIterator cbegin() const;
	CIterator cend() const;
private:
	size_t m_size;
	std::unique_ptr<Node> m_head = nullptr;
	Node * m_tail = nullptr;
};