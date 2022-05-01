#pragma once

#include "Mailbox.h"
#include "hQueueType.h"
#include <fstream>

#define FILENAMESIZE 1024
#define MAX_MAIL_BOX 10
using namespace std;

class Application {
	enum TYPE {SEND, RECEIVE};
private:
	User<MailContent> MailBox;
	hQueueType<QItemType> hQueue;
	ifstream m_InFile;
	ofstream m_OutFile;
	int m_Command;

public:
	Application() : m_Command(0), MailBox(MAX_MAIL_BOX), hQueue(MAX_MAIL_BOX/2) {}
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

	//void DisplayMails(std::list<MailContent> mailList, TYPE type);
};