#pragma once

#include <string>
#include <list>
#include "MailContent.h"
#include <iostream>
template<typename T>
class User {
private:
	std::string name;
	std::string mailAddress;
	T* receiveMailList;
	int maxLength;
	int length;

	//MailContent* sendMailList;
	//int sendMailLength;


public:
	User() {
		name = "";
		mailAddress = "";
		maxLength = 0;
		//sendMailLength = 0;
		length = 0;
	}
	User(const User& src) {
		std::cout << "copy constructor" << std::endl;
		this->name = src.name;
		this->mailAddress = src.mailAddress;
		this->receiveMailList = src.receiveMailList;
		this->maxLength = src.maxLength;
		this->length = src.length;

		//this->sendMailList = src.sendMailList;
		//this->sendMailLength = src.sendMailLength;
		

		/*
		std::list<MailContent>::iterator it = src.sendMailList.begin();
		while (it != src.sendMailList.end()) {
			this->sendMailList.push_back(*it);
		}

		it = src.receiveMailList.begin();
		while (it != src.receiveMailList.end()) {
			this->receiveMailList.push_back(*it);
		}*/
	}

	User(int maxMailBox) {
		name = "ÃÖÇÑºó";
		mailAddress = "";
		receiveMailList = new MailContent[maxMailBox];
		maxLength = maxMailBox;
		length = 0;

		//sendMailList = new MailContent[maxMailBox];
		//sendMailLength = 0;
		
	}

	~User() {
		delete[] receiveMailList;

		//delete[] sendMailList;
	}

	void setName(std::string name) {
		this->name = name;
	}

	void setMailAddress(std::string mailAddress) {
		this->mailAddress = mailAddress;
	}

	std::string getName() {
		return this->name;
	}

	std::string getMailAddress() {
		return this->mailAddress;
	}

	//std::list<MailContent> getSendMailList() {
	//	return this->sendMailList;
	//}

	//std::list<MailContent> getReceiveMailList() {
	//	return this->receiveMailList;
	//}

	int addReceiveMail(MailContent mail) {
		if (length + 1 >= maxLength) return 0;
		int m_CurPointer = GetBinarySearch(mail);
		for (int i = length++; i > m_CurPointer; i--) {
			receiveMailList[i] = receiveMailList[i - 1];
		}
		receiveMailList[m_CurPointer] = mail;
		return 1;
	}

	//void addSendMail(MailContent mail) {
	//	if (sendMailLength + 1 < maxLength) sendMailList[sendMailLength++] = mail;
	//}

	//void MakeSendMailboxEmpty() {

	//}

	void MakeEmpty() {
		delete[] receiveMailList;
		receiveMailList = new MailContent[maxLength];
		length = 0;
	}

	int GetLength() {
		return length;
	}

	void DisplayAllMail() {
		for (int i = 0; i < length; i++) {
			receiveMailList[i].DisplayMailOnScreen();
		}
	}


	int GetBinarySearch(MailContent& mail) {
		int start = 0, end = length-1;
		int m_CurPointer = 0;
		bool found = false;
		while (start <= end && !found) {
			int mid = (start + end) / 2;
			switch (mail.CompareByDate(receiveMailList[mid])) {
			case MailContent::LESS:
				end--;
				break;
			case MailContent::GREATER:
				start++;
				m_CurPointer = m_CurPointer < mid+1? mid+1 : m_CurPointer;
				break;
			case MailContent::EQUAL:
				found = true;
				mail = receiveMailList[mid];
				m_CurPointer = mid;
			}
		}
		return m_CurPointer;
	}

	int WriteMailToFile(std::ofstream & fout) {
		fout << name << std::endl;
		fout << mailAddress << std::endl;
		for (int i = 0; i < length; i++) {
			receiveMailList[i].WriteDataToFile(fout);
		}
		return 1;
	}
	
	int ReadMailToFile(std::ifstream& fin) {
		MailContent mail;
		fin >> name;
		fin >> mailAddress;
		MakeEmpty();
		while (!fin.eof()) {
			mail.ReadDataFromFile(fin);
			if (mail.getRecieveDate() != "") addReceiveMail(mail);
		}
		return 1;
	}

	int MailBoxFindNDisplayMail(std::string start, std::string end) {
		for (int i = 0; i < length; i++) {
			if (receiveMailList[i].getRecieveDate() > end) break;
			if (receiveMailList[i].getRecieveDate() >= start) {
				receiveMailList[i].DisplayMailOnScreen();
			}
		}
		return 1;
	}

	int MailBoxDeleteMailsInTimeInterval(std::string start, std::string end) {
		int startidx = length, cnt = 0;
		for (int i = 0; i < length; i++) {
			if (receiveMailList[i].getRecieveDate() > end) break;
			if (receiveMailList[i].getRecieveDate() >= start) {
				startidx = startidx > i ? i : startidx;
				cnt++;
			}
		}
		for (int i = startidx; i + cnt < length; i++) {
			receiveMailList[i] = receiveMailList[i + cnt];
		}
		length -= cnt;
		return 1;
	}
};