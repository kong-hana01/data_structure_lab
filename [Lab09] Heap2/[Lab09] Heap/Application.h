#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "MaxHeap.h"

#define FILENAMESIZE 1024

/**
*	�������� �����ϱ� ���� Application Ŭ����.
*/
class Application
{
public:
	/**
	*	����Ʈ ������.
	*/
	Application() : m_MaxHeap(), m_Command(0) {};
	//{
	//	m_Command = 0;
	//}

	/**
	*	�Ҹ���.
	*/
	~Application() {}

	/**
	*	@brief	���α׷��� �����Ѵ�.
	*	@pre	���α׷��� �����Ѵ�.
	*	@post	���α׷��� ������.
	*/
	void Run();

	/**
	*	@brief	command�� ��ũ���� ����ϰ� Ű����κ��� command�� �Է¹޴´�.
	*	@pre	����.
	*	@post	����.
	*	@return	������ command.
	*/
	int GetCommand();

	/**
	*	@brief	���ο� �������� ������ ����Ʈ�� �߰��Ѵ�.
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@post	����Ʈ�� �� �������� ������ �߰��ȴ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int AddItem();

	/**
	*	@brief	����Ʈ�� ��� ������ �������� ��ũ���� ����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*/
	void DisplayAllItem();

	/**
	*	@brief	�Է¹��� ID�� ������ ������ ã�Ƴ��� ��ũ���� ����Ѵ�.
	*	@pre	����Ʈ�� �����۵��� ������ ����Ǿ� �ִ�.
	*	@post	����Ʈ���� �������� ã�� ����Ѵ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int SearchItembyID();

	/**
	*	@brief	�Է¹��� ID�� �������� ã�Ƴ��� �����Ѵ�.
	*	@pre	����Ʈ�� �����۵��� ������ ����Ǿ� �ִ�.
	*	@post	����Ʈ���� �������� ã�� �����Ѵ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int DeleteItem();


private:
	ifstream m_InFile;		///< �Է� ���� ��ũ����.
	ofstream m_OutFile;		///< ��� ���� ��ũ����.
	//DoublySortedLinkedList<ItemType>m_List; ///< ������ ����Ʈ.
	int m_Command;			///< ���� command ����.
	MaxHeap<ItemType> m_MaxHeap;
};

#endif	// _APPLICATION_H