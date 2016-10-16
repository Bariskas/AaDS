#pragma once

#include <string>
using namespace std;

template <typename T>
struct StackNode
{
	StackNode<T>(T newVal, StackNode *nextNode) : value(newVal), next(nextNode) {};

	T value;
	struct StackNode *next;
};


template <typename T>
class MyStack
{
private:
	StackNode<T> *m_top;
	T* emptyItem;
public:
	MyStack()
	{
		emptyItem = new T();
		m_top = 0;
	}

	~MyStack()
	{
		while (!Empty()) 
		{
			Pop();
		}
		delete emptyItem;
	}

	void Push(const T& newElement)
	{
		m_top = new StackNode<T>(newElement, m_top);
	}

	T Pop()
	{
		if (!Empty())
		{
			StackNode<T> *topNode = m_top;
			m_top = m_top->next;
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

	bool Empty()
	{
		return (m_top == 0);
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