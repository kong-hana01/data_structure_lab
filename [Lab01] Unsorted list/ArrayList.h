#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 5

/**
*	array based simple unsorted list.
*/
class ArrayList
{
public:
	/**
	*	default constructor.
	*/
	ArrayList()
	{
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~ArrayList()	{}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(ItemType data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized. 
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(ItemType& data);

	/** [작성]
	*	@brief	전달받은 학생 학번에 대한 정보를 찾음
	*	@pre	아이템 타입이 초기화되어야한다.
	*	@post	전달받은 학생 정보를 찾으면 데이터에 값을 저장하고, 그렇지 않으면 값을 바꾸지 않는다.
	*	@param  데이터    찾고자하는 학생의 학번이 있는 아이템 타입의 데이터
	*	@return 찾았을 경우 1을, 못찾았을 경우 0을 리턴한다.
	*/
	int Get(ItemType& data);

	/** [작성]
	*	@brief 전달받은 학생 학번에 대한 정보를 삭제
	*	@pre   아이템 타입이 초기화되어야한다.
	*	@post  전달받은 학생 학번에 대한 정보를 지운다.
	*	@param 데이터    삭제하고자하는 학생의 학번이 있는 아이템 타입의 데이터
	*	@return 없음
	*/
	void Delete(ItemType data);

	/** [작성]
	*	@brief 전달받은 학생 학번에 대한 정보를 변경
	*	@pre   아이템 타입이 초기화되어야한다.
	*	@post  전달받은 학생 학번에 대한 정보를 변경한다.
	*	@param 데이터    변경하고자하는 학생의 학번이 있는 아이템 타입의 데이터
	*	@return 없음
	*/
	void Replace(ItemType data);

private:
	ItemType m_Array[MAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif	// _UNSORTEDLIST_H