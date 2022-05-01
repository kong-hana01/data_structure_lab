#include "Queue.h"


/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
bool CircularQueueType::IsFull(){}

/**
*	@brief	Determines whether the queue is empty.
*	@pre	Queue has been initialized.
*	@post	Function value = (queue is empty)
*/
bool CircularQueueType::IsEmpty(){}

/**
*	@brief	Makes the queue empty.
*	@pre	Queue has been initialized.
*	@post	m_iFront¿Í m_iRear is set same value as Constructer.
*/
void MakeEmpty();

/**
*	@brief	Adds newItem to the last of the queue.
*	@pre	Queue has been initialized.
*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
*/
void EnQueue(T item);

/**
*	@brief	Removes first item from the queue.
*	@pre	Queue has been initialized.
*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
*/
void DeQueue(T& item);

/**
*	@brief	Print all the items in the queue on screen
*	@pre	Queue has been initialized.
*	@post	None.
*/
void Print();