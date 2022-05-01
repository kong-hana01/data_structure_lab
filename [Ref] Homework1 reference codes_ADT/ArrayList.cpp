#include "ArrayList.h"


// Make list empty.
void ArrayList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int ArrayList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool ArrayList::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int ArrayList::Add(Mail inData)
{
	if(!IsFull())
	{
		ResetList();
		Mail dummy = inData;
		GetBinarySearch(dummy);
		for (int i = m_Length++; i > m_CurPointer+1; i--) {
			m_Array[i] = m_Array[i - 1];
		}
		m_Array[m_CurPointer+1] = inData;
		return 1;
	}
	return 0;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(Mail& data)
{
	m_CurPointer++;	// list pointer 증가
	if(m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

int ArrayList::Get(Mail& data) {
	int location = 0;
	bool found = false;
	while ((location < m_Length) && !found) {
		switch (data.CompareByID(m_Array[location])) {
		case LESS:
		case GREATER: location++;  break;
		case EQUAL:
			found = true;
			data = m_Array[location];
			m_CurPointer = location;
		}
	}
	return found?1:0;
}

int ArrayList::Delete(Mail data) {
	if (GetBinarySearch(data)) {
		for (int i = m_CurPointer; i < m_Length-1; i++) {
			m_Array[i] = m_Array[i + 1];
		}
		m_Length--;
		return 1;
	}
	return 0;
}

int ArrayList::Replace(Mail data) {
	Mail dummy = data;
	if (GetBinarySearch(dummy)) {
		m_Array[m_CurPointer] = data;
		return 1;
	}
	return 0;
}

int ArrayList::GetBinarySearch(Mail& data) {
	int start = 0, end = m_Length-1;
	bool found = false;
	ResetList();
	while (start <= end && !found) {
		int mid = (start + end) / 2;
		switch (data.CompareByID(m_Array[mid])) {
		case LESS: 
			end--; 
			m_CurPointer = m_CurPointer > mid ? mid : m_CurPointer;
			break;
		case GREATER: 
			start++; 
			m_CurPointer = m_CurPointer < mid ? mid : m_CurPointer;
			break;
		case EQUAL:
			found = true;
			data = m_Array[mid];
			m_CurPointer = mid;
		}
	}
	return found ? 1 : 0;
}