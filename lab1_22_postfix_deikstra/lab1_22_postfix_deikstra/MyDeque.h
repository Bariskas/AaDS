#pragma once

using namespace std;

template <typename T>
struct DequeNode
{
	DequeNode<T>(T newVal, DequeNode *nextNode, DequeNode *prevNode) 
		: value(newVal), next(nextNode), prev(prevNode) {};

	T value;
	struct DequeNode *next;
	struct DequeNode *prev;
};


template <typename T>
class MyDeque
{
private:
	DequeNode<T> *m_top;
	DequeNode<T> *m_back;
	T* emptyItem;
public:
	MyDeque()
	{
		emptyItem = new T();
		m_top = nullptr;
		m_back = nullptr;
	}

	~MyDeque()
	{
		while (!Empty())
		{
			PopTop();
		}
		delete emptyItem;
	}

	void PushTop(const T& newElement)
	{
		auto newNode = new DequeNode<T>(newElement, nullptr, m_top);
		if (m_back == nullptr || m_top == nullptr)
		{
			m_back = newNode;
			m_top = newNode;
		}
		else
		{
			m_top->next = newNode;
			m_top = newNode;
		}
	}

	void PushBack(const T& newElement)
	{
		auto newNode = new DequeNode<T>(newElement, m_back, nullptr);
		if (m_back == nullptr || m_top == nullptr)
		{
			m_back = newNode;
			m_top = newNode;
		}
		else
		{
			m_back->prev = newNode;
			m_back = newNode;
		}
	}

	T PopTop()
	{
		if (!Empty())
		{
			DequeNode<T> *topNode = m_top;
			m_top = m_top->prev;
			T data = move(topNode->value);
			delete topNode;
			return data;
		}
		throw "Empty Stack";
	}

	T PopBack()
	{
		if (!Empty())
		{
			DequeNode<T> *topNode = m_back;
			m_back = m_back->next;
			T data = move(topNode->value);
			delete topNode;
			return data;
		}
		throw "Empty Stack";
	}

	const T& Top()
	{
		return !Empty() ? m_top->value : *emptyItem;
	}

	const T& Back()
	{
		return !Empty() ? m_back->value : *emptyItem;
	}

	bool Empty()
	{
		return (m_top == nullptr || m_back == nullptr);
	}
};

//class charQueue
//{
//private:
//	singlyLinkedList *m_last = 0;
//	singlyLinkedList *m_first = 0;
//public:
//	void push(char newElementValue)
//	{
//		singlyLinkedList* newElement = new singlyLinkedList(newElementValue);
//		m_last->link = newElement;
//		m_last = newElement;
//	}
//
//	char pop()
//	{
//		char result;
//		if (m_first != 0)
//		{
//			result = (*m_first).val;
//		}
//		m_first = m_first->link;
//		return result;
//	}
//
//	char current()
//	{
//		return (m_first == 0 ? '\0' : (*m_first).val);
//	}
//
//	bool empty()
//	{
//		return (m_first == 0 ? true : false);
//	}
//};