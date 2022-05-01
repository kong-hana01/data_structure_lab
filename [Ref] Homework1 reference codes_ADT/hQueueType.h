#pragma once

#include "QItemType.h"
#include <iostream>
using namespace std;

#define maxQueue 10


template <typename T>
class hQueueType
{
public:

	hQueueType() {
		m_nMaxQueue = maxQueue + 1;
		m_iRear = m_nMaxQueue - 1;
		m_iFront = m_nMaxQueue - 1;
		m_pItems = new T[m_nMaxQueue];
	}

	hQueueType(int max) {
		m_nMaxQueue = max + 1;
		m_iRear = m_nMaxQueue -1;
		m_iFront = m_nMaxQueue -1;
		m_pItems = new T[m_nMaxQueue];
	}


	~hQueueType() {
		delete[] m_pItems;
	}



	bool IsFull() {
		return (m_iRear + 1) % m_nMaxQueue == m_iFront;
	}


	bool IsEmpty() {
		return m_iRear == m_iFront;
	}


	void MakeEmpty() {
		m_iRear = m_nMaxQueue - 1;
		m_iFront = m_nMaxQueue - 1;
	}


	void EnQueue(T item) {
		if (IsFull()) DeQueue();
		m_iRear = (m_iRear + 1) % m_nMaxQueue;
		m_pItems[m_iRear] = item;
	}

	void DeQueue() {
		if (!IsEmpty()) m_iFront = (m_iFront + 1) % m_nMaxQueue;
	}


	void DisplayAllItems() {
		if (!IsEmpty())  {
			int front = (m_iFront + 1) % m_nMaxQueue;
			while (true) {
				m_pItems[front].DisplayRecordOnScreen();
				if (front == m_iRear) break;
				front = (front + 1) % m_nMaxQueue;
			}
			cout << endl;
		}
	}

	int IsItInQueue(T item) {
		if (!IsEmpty()) {
			int front = (m_iFront + 1) % m_nMaxQueue;
			while (front != m_iRear) {
				if (m_pItems[front].GetAddress() == item.GetAddress()) return 1;
				front = (front + 1) % m_nMaxQueue;
			}
		}
		return 0;
	}

	int DeleteItem(T item) {
		if (!IsEmpty()) {
			int front = (m_iFront + 1) % m_nMaxQueue;
			bool found = false;
			while (front != m_iRear) {
				if (!found) {
					if (m_pItems[front].GetAddress() == item.GetAddress()) {
						m_pItems[front] = m_pItems[front + 1];
						found = true;
					};
				}
				else {
					m_pItems[front] = m_pItems[front + 1];
				}
				front = (front + 1) % m_nMaxQueue;
			}
			if (found)
				m_iRear = m_iRear == 0 ? m_nMaxQueue - 1 : m_iRear - 1;
			cout << m_iRear;
			return int(found);
		}
		return 0;
	}

private:
	int m_iFront;	//index of one infront of the first element.
	int m_iRear;	//index of the last element.
	int m_nMaxQueue;	//max size of the queue.
	T* m_pItems;	//pointer for dynamic allocation.
};