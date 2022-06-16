#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "MaxHeap.h"

#define FILENAMESIZE 1024

/**
*	아이템을 관리하기 위한 Application 클래스.
*/
class Application
{
public:
	/**
	*	디폴트 생성자.
	*/
	Application() : m_MaxHeap(), m_Command(0) {};
	//{
	//	m_Command = 0;
	//}

	/**
	*	소멸자.
	*/
	~Application() {}

	/**
	*	@brief	프로그램을 실행한다.
	*	@pre	프로그램이 시작한다.
	*	@post	프로그램이 끝난다.
	*/
	void Run();

	/**
	*	@brief	command를 스크린에 출력하고 키보드로부터 command를 입력받는다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	유저의 command.
	*/
	int GetCommand();

	/**
	*	@brief	새로운 아이템의 정보를 리스트에 추가한다.
	*	@pre	리스트는 초기화되어야 한다.
	*	@post	리스트에 새 아이템의 정보가 추가된다.
	*	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int AddItem();

	/**
	*	@brief	리스트의 모든 아이템 정보들을 스크린에 출력한다.
	*	@pre	없음.
	*	@post	없음.
	*/
	void DisplayAllItem();

	/**
	*	@brief	입력받은 ID로 아이템 정보를 찾아내어 스크린에 출력한다.
	*	@pre	리스트에 아이템들의 정보가 저장되어 있다.
	*	@post	리스트에서 아이템을 찾아 출력한다.
	*	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int SearchItembyID();

	/**
	*	@brief	입력받은 ID로 아이템을 찾아내어 삭제한다.
	*	@pre	리스트에 아이템들의 정보가 저장되어 있다.
	*	@post	리스트에서 아이템을 찾아 삭제한다.
	*	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	*/
	int DeleteItem();


private:
	ifstream m_InFile;		///< 입력 파일 디스크립터.
	ofstream m_OutFile;		///< 출력 파일 디스크립터.
	//DoublySortedLinkedList<ItemType>m_List; ///< 아이템 리스트.
	int m_Command;			///< 현재 command 숫자.
	MaxHeap<ItemType> m_MaxHeap;
};

#endif	// _APPLICATION_H