#pragma once

#include "SortedLinkedList.h"
#include "hQueueType.h"
#include <fstream>

#define FILENAMESIZE 1024
#define MAX_MAIL_BOX 10
using namespace std;

class Application {
	enum TYPE {SEND, RECEIVE};
private:
	SortedLinkedList<MailContent> m_mailBox;
	SortedLinkedList<AddrItemType> m_addressBook;
	SortedLinkedList<MailContent> m_trashBin;
	SortedLinkedList<MailContent> tempList;
	hQueueType<QItemType> m_recentMailBox;
	ifstream m_InFile;
	ofstream m_OutFile;
	int m_Command;

public:
	Application() : m_Command(0), m_mailBox(), m_addressBook(), m_trashBin(), tempList(), m_recentMailBox(MAX_MAIL_BOX/2) {}
	~Application() {}

	void Run(); // 프로그램 시작 시 동작

	int GetCommand(); // 명령 입력

	int AddMail(); // Maillbox에 메일 추가

	void DisplayAllMail(); // 모든 메일 리스트 출력

	void FindNDisplayMail(); // 주어진 시간 동안에 온 메일 출력

	void DeleteMailsInTimeInterval(); // 주어진 시간 동안에 온 메일 삭제

	int OpenInFile(char* fileName); // 파일 열기

	int OpenOutFile(char* fileName); // 파일 닫기

	int ReadDataFromFile(); // 파일로부터 메일 로드

	int WriteDataToFile(); // 파일에 메일 저장

	int UpdateRecentAddress(QItemType Item);

	void DisplayRecentAddress();

	int GetNewAddress();

	int AddAddress(QItemType QItem);

	AddrItemType SearchAddress();

	int DeleteAddress();

	void DisplayAllAddress();

	int AddToTrashBin(MailContent m);

	int DeleteFromTrashBin(MailContent m);

	int AddToMailBox(MailContent m);

	int DeleteFromMailBox(MailContent m);

	int DeleteMail();

	int RestoreMail();

	void DisplayAllTrashBin();

//	DisplayByName();
};