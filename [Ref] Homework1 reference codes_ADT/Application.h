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