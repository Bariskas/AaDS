#pragma once

typedef struct sll
{
	sll(char newVal) : val(newVal), link(0) {};
	char val;
	struct sll * link;
}  singlyLinkedList;

typedef struct stirngQueue
{
	stirngQueue(string newVal) : val(newVal), link(0) {};
	string val;
	struct stirngQueue * link;
};

class charStack
{
private:
	singlyLinkedList *m_listHead = 0;
public:
	void push(char newElementValue)
	{
		singlyLinkedList* newElement = new singlyLinkedList(newElementValue);
		newElement->link = m_listHead;
		m_listHead = newElement;
	}

	char pop()
	{
		char result;
		if (m_listHead != 0)
		{
			result = (*m_listHead).val;
		}
		m_listHead = m_listHead->link;
		return result;
	}

	char current()
	{
		return (m_listHead == 0 ? '\0' : (*m_listHead).val);
	}

	bool empty()
	{
		return (m_listHead == 0 ? true : false);
	}
};

class charQueue
{
private:
	singlyLinkedList *m_last = 0;
	singlyLinkedList *m_first = 0;
public:
	void push(char newElementValue)
	{
		singlyLinkedList* newElement = new singlyLinkedList(newElementValue);
		m_last->link = newElement;
		m_last = newElement;
	}

	char pop()
	{
		char result;
		if (m_first != 0)
		{
			result = (*m_first).val;
		}
		m_first = m_first->link;
		return result;
	}

	char current()
	{
		return (m_first == 0 ? '\0' : (*m_first).val);
	}

	bool empty()
	{
		return (m_first == 0 ? true : false);
	}
};