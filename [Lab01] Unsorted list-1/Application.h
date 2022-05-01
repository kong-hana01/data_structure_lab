#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"

#define FILENAMESIZE 1024

/**
*	아이템을 관리하기위한 어플리케이션 클래스
*/
class Application
{
public:
	/**
	*	디폴트 생성자
	*/
	Application()
	{
		m_Command = 0;
	}
	
	/**
	*	소멸자
	*/
	~Application()	{}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/** [작성]
	*	@brief  주어진 학생 학번을 토대로 리스트에 저장되었는지 확인하여 출력
	*	@pre    리스트가 초기화되어있어야함
	*	@post   학생을 찾으면 학생 정보를 출력하고, 학생을 찾지 못하면 학생을 찾지 못했다는 문구를 출력한다.
	*	@return 학생을 찾았을 경우 1을 리턴하고, 학생을 찾지 못하면 0을 리턴한다.
	*/
	int SearchData();

	/** [작성]
	*	@brief  주어진 학생 학번을 토대로 리스트에 저장된 학생 정보를 삭제
	*	@pre    리스트가 초기화되어있어야함
	*	@post   학생을 찾으면 학생 정보를 삭제하고, 학생을 찾지 못하면 리스트를 그대로 놔둔다.
	*	@return 학생 정보를 삭제했을 경우 1을 리턴하고, 학생 정보를 삭제하지 못하면 0을 리턴한다.
	*/
	int DeleteItem();

	/** [작성]
	*	@brief	주어진 학생 학번을 토대로 리스트에 저장된 학생 정보를 변경
	*	@pre    리스트가 초기화되어있어야함
	*	@post	학생을 찾으면 학생 정보를 변경하고, 학생을 찾지 못하면 리스트를 그대로 놔둔다.
	*	@return	학생 정보를 변경했을 경우 1을 리턴하고, 학생 정보를 변경하지 못하면 0을 리턴한다.
	*/
	int UpdateItem();

	
private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	ArrayList m_List;		///< item list.
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H