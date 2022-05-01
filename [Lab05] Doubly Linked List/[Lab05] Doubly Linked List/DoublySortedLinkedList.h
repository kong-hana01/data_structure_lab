#pragma once
#ifndef _DOUBLYSORTEDLINKEDLIST_H
#define _DOUBLYSORTEDLINKEDLIST_H

#include "ItemType.h"
#include "DoublyIterator.h"

#define min ItemType(INT_MIN)
#define max ItemType(INT_MAX)

template<typename T>
class DoublyIterator;

/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< �� ����� ������.
	DoublyNodeType* prev; ///< ����� ���� ����Ű�� ������.
	DoublyNodeType* next; ///< ����� ������ ����Ű�� ������.
};

/**
*	���ĵ� �����Ḯ��Ʈ Ŭ����
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; ///< DoublyIterator�� ģ�� Ŭ����.
public:
	/**
	*	����Ʈ ������.
	*/
	DoublySortedLinkedList() { 
		m_pFirst = new DoublyNodeType<T>;
		m_pLast = new DoublyNodeType<T>;
		m_pFirst->data = min;
		m_pLast->data = max;
		
		m_pFirst->next = m_pLast;
		m_pLast->prev = m_pFirst;
		m_nLength = 0;
	}

	/**
	*	�Ҹ���.
	*/
	~DoublySortedLinkedList() {
		MakeEmpty();
		delete m_pFirst;
		delete m_pLast;
	}

	/**
	*	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	������� �ƴ����� �˷��ش�.
	*	@return	��������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	���� á���� �ƴ����� �˷��ش�.
	*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsFull();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	int Add(T item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*/
	void Delete(T item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*/
	void Replace(T item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T& item);

private:
	DoublyNodeType<T>* m_pFirst; ///< �ּҰ��� ������ ����Ʈ�� �� ó��.
	DoublyNodeType<T>* m_pLast; ///< �ִ��� ������ ����Ʈ�� �� ��.
	int m_nLength; ///< ����Ʈ�� ����.
};

template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty() {
	return m_nLength == 0 ? true : false;
}

/**
*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
*	@post	���� á���� �ƴ����� �˷��ش�.
*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
*/
template <typename T>
bool DoublySortedLinkedList<T>::IsFull() {
	DoublyNodeType<T>* tempNode = new DoublyNodeType<T>;
	if (tempNode == NULL) return true;
	delete tempNode;
	return false;
}

/**
*	@brief	����Ʈ�� ����.
*	@pre	����.
*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
*/
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty() {
	while (!IsEmpty()) {
		DoublyNodeType<T>* location = m_pFirst->next;
		location->prev->next = location->next;
		location->next->prev = location->prev;
		location->data.DisplayRecordOnScreen();
		delete location;
		m_nLength--;
		
	}
}

/**
*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
*	@pre	����.
*	@post	����Ʈ�� ���̸� ��ȯ.
*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
*/
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const {
	return m_nLength;
}

/**
*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
*	@pre	item�� �Է¹޴´�.
*	@post	�������� ����Ʈ�� �߰��Ѵ�.
*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
*/
template <typename T>
int DoublySortedLinkedList<T>::Add(T item) {
	if (IsFull()) return 0;
	DoublyNodeType<T>* location = m_pFirst;
	bool found = false;
	while (!found) {
		switch (item.CompareByID(location->data)) {
		case LESS:
			found = true;
			break;
		case GREATER:
			location = location->next;
			break;
		case EQUAL:
			return 0;
		}
	}
	DoublyNodeType<T>* NewNode = new DoublyNodeType<T>;
	NewNode->data = item;
	NewNode->next = location;
	NewNode->prev = location->prev;
	location->prev->next = NewNode;
	location->prev = NewNode;
	m_nLength++;
	return 1;
}

/**
*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
*	@pre	item�� �Է¹޴´�.
*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
*/
template <typename T>
void DoublySortedLinkedList<T>::Delete(T item) {
	DoublyNodeType<T>* location = m_pFirst;
	bool found = false;
	while (!found) {
		switch (item.CompareByID(location->data)) {
		case EQUAL:
			location->next->prev = location->prev;
			location->prev->next = location->next;
			delete location;
			m_nLength--;
		case LESS:
			found = true;
			break;
		case GREATER:
			location = location->next;
			break;
		}
	}
}

/**
*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
*	@pre	item�� �Է¹޴´�.
*	@post	���ο� ������ ��ü�ȴ�.
*/
template <typename T>
void DoublySortedLinkedList<T>::Replace(T item) {
	DoublyNodeType<T>* location = m_pFirst;
	bool found = false;
	while (!found) {
		switch (item.CompareByID(location->data)) {
		case EQUAL:
			location->data = item;
		case LESS:
			found = true;
			break;
		case GREATER:
			location = location->next;
			break;
		}
	}
}

/**
*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
*	@pre	item�� �Է¹޴´�.
*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
*/
template <typename T>
int DoublySortedLinkedList<T>::Get(T& item) {
	DoublyNodeType<T>* location = m_pFirst;
	bool found = false;
	while (!found) {
		switch (item.CompareByID(location->data)) {
		case LESS:
			found = true;
			break;
		case GREATER:
			location = location->next;
			break;
		case EQUAL:
			item = location->data;
			return 1;
		}
	}
	return 0;
}


#endif _DOUBLYSORTEDLINKEDLIST_H