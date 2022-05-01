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

	void Run(); // ���α׷� ���� �� ����

	int GetCommand(); // ��� �Է�

	int AddMail(); // Maillbox�� ���� �߰�

	void DisplayAllMail(); // ��� ���� ����Ʈ ���

	void FindNDisplayMail(); // �־��� �ð� ���ȿ� �� ���� ���

	void DeleteMailsInTimeInterval(); // �־��� �ð� ���ȿ� �� ���� ����

	int OpenInFile(char* fileName); // ���� ����

	int OpenOutFile(char* fileName); // ���� �ݱ�

	int ReadDataFromFile(); // ���Ϸκ��� ���� �ε�

	int WriteDataToFile(); // ���Ͽ� ���� ����

	int UpdateRecentAddress(QItemType Item);

	void DisplayRecentAddress();

	int GetNewAddress();

	//void DisplayMails(std::list<MailContent> mailList, TYPE type);
};