#pragma once
#include "ItemType.h"


template <typename T>
class HeapBase {
public:
	HeapBase(int size = 10);
	virtual ~HeapBase();

	bool IsEmpty();
	bool IsFull();

	int GetLength() const;
	void MakeEmpty();
	virtual int Add(T item);
	virtual int Delete(T item);
	virtual T Pop();
	virtual void RetrieveItem(T& item, bool& found);
	virtual void PrintHeap();

	virtual void ReheapDown(int iparent, int ibottom) = 0;
	virtual void ReheapUp(int iroot, int ibottom) = 0;
	virtual void Delete(T item, bool& found, int iparent) = 0;
	virtual void Retrieve(T& item, bool& found, int iparent) = 0;

protected:
	T* m_pHeap;
	int m_iLastNode;
	int m_nMaxSize;
};

template <typename T>
HeapBase<T>::HeapBase(int size) {
	m_nMaxSize = size;
	m_pHeap = new T[m_nMaxSize];
	m_iLastNode = 0;
}

template <typename T>
HeapBase<T>::~HeapBase() {
	delete [] m_pHeap;
}

template <typename T>
bool HeapBase<T>::IsEmpty() {
	return !m_iLastNode;
}

template <typename T>
bool HeapBase<T>::IsFull() {
	return m_nMaxSize == m_iLastNode;
}

template <typename T>
int HeapBase<T>::GetLength() const {
	return m_iLastNode;
}

template <typename T>
void HeapBase<T>::MakeEmpty() {
	while (!m_iLastNode) {
		Pop();
	}
}

template <typename T>
int HeapBase<T>::Add(T item) {
	if (!IsFull()) {
		m_pHeap[m_iLastNode] = item;
		ReheapUp(0, m_iLastNode++);
		return 1;
	}
	return 0;
}

template <typename T>
int HeapBase<T>::Delete(T item) {
	int location = 0;
	while (location < m_iLastNode && item != m_pHeap[location])
		location++;
	if (location < m_iLastNode) {
		m_pHeap[location] = m_pHeap[m_iLastNode--];
		ReheapDown(location, m_iLastNode);
		return 1;
	}
	return 0;
}

template <typename T>
T HeapBase<T>::Pop() {
	// Pop함수 사용 전 IsEmpty 체크
	T item;
	item = m_pHeap[0];
	m_pHeap[0] = m_pHeap[m_iLastNode--];
	ReheapDown(0, m_iLastNode);
	return item;
}

template <typename T>
void HeapBase<T>::RetrieveItem(T& item, bool& found) {

	int location = 0;
	while (location < m_iLastNode && item != m_pHeap[location])
		location++;
	if (location < m_iLastNode) {
		found = true;
		item = m_pHeap[location];
	}
	else {
		found = false;
	}
}

template <typename T>
void HeapBase<T>::PrintHeap() {
	int location = 0;
	while (location < m_iLastNode) {
		m_pHeap[location++].DisplayRecordOnScreen();
	}
}