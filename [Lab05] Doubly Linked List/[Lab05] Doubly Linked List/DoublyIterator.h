#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	����Ʈ ������.
	*/
	DoublyIterator(const DoublySortedLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList�� ģ�� Ŭ����.


	bool NotNull();
	bool NextNotNull();
	T First();
	T Next();
	DoublyNodeType<T> GetCurrentNode();
private:
	const DoublySortedLinkedList<T>& m_List;
	DoublyNodeType<T>* m_pCurPointer;
};



template <typename T>
bool DoublyIterator<T>::NotNull() {
	return m_pCurPointer;
}


template <typename T>
bool DoublyIterator<T>::NextNotNull() {
	return m_pCurPointer && m_pCurPointer->next;
}

template <typename T>
T DoublyIterator<T>::First() {
	return m_List->next;
}

template <typename T>
T DoublyIterator<T>::Next() {
	if (NotNull()) 	return m_pCurPointer->next;

}

template <typename T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode() {


}


#endif _DOUBLYITERATOR_H