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
int ArrayList::Add(ItemType inData)
{
	if(!IsFull())
	{
		m_Array[m_Length] = inData;
		m_Length++;
	}
	else
		return 0;

	return 1;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer ����
	if(m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

int ArrayList::Get(ItemType& data) {
	int location = 0;
	bool found = false;
	while ((location < m_Length) && !found) {
		switch (data.CompareByID(m_Array[location])) {
		case LESS:
		case GREATER: location++;  break;
		case EQUAL:
			found = true;
			data = m_Array[location];
		}
	}
	return found?1:0;
}

void ArrayList::Delete(ItemType data) {
	int location = 0;
	while (location < m_Length && data.CompareByID(m_Array[location]) != EQUAL)
		location++;
	if (location < m_Length)
		m_Array[location] = m_Array[--m_Length];
}

void ArrayList::Replace(ItemType data) {
	int location = 0;
	while (location < m_Length && data.CompareByID(m_Array[location]) != EQUAL)
		location++;
	if (location < m_Length) 
		m_Array[location] = data;
}