#pragma once

#include <string>
#include <sys/timeb.h>
#include <time.h>
#include <iostream>
#include <fstream>

class MailContent {
public:
	std::string name;
	std::string title;
	std::string senderMailAddress;
	std::string content;
	std::string label;
	std::string recieveDate;
	MailContent* next;

	MailContent(){
		name = "";
		title = "";
		senderMailAddress = "";
		content = "";
		label = "";
		recieveDate = "";
		next = NULL;
	}

	MailContent(const MailContent& m) {
		name = m.name;
		title = m.title;
		senderMailAddress = m.senderMailAddress;
		content = m.content;
		label = m.label;
		recieveDate = m.recieveDate;
		next = m.next;
	}
	MailContent& operator=(const MailContent& m) {
		name = m.name;
		title = m.title;
		senderMailAddress = m.senderMailAddress;
		content = m.content;
		label = m.label;
		recieveDate = m.recieveDate;
		next = m.next;
		return *this;
	}

	bool operator==(const MailContent& m) {
		return this->recieveDate == m.recieveDate;
	}

	void setTitle(std::string title);

	void setSenderMailAddress(std::string mailAddress);

	void setContent(std::string content);

	void setLabel(std::string label);

	void setRecieveDate(std::string date);

	void setName(std::string name);

	//void setUnread(bool check);

	void cinMail(std::string& data, int flag) {
		switch (flag) {
		case 1:
			std::cout << "Title: ";
			break;
		case 2:
			std::cout << "Mail Address: ";
			break;
		case 3:
			std::cout << "Content: ";
			break;
		case 4:
			std::cout << "Label ";
			break;
		case 5:
			std::cout << "RecieveDate: ";
			break;
		case 6:
			std::cout << "Name: ";
			break;
		}
		std::cin >> data;
		std::cout << std::endl;
	}

	void setMail() {
		std::string title, mailAddress, content, label, recieveDate, name;
		cinMail(name, 6);
		cinMail(title, 1);
		cinMail(mailAddress, 2);
		cinMail(content, 3);
		cinMail(label, 4);
		cinMail(recieveDate, 5);
		

		setTitle(title);
		setSenderMailAddress(mailAddress);
		setContent(content);
		setLabel(label);
		setRecieveDate(recieveDate);
		setName(name);
		//setUnread(check);
	}

	void setdata(MailContent& item) {
		this->name = item.name;
		this->title = item.title;
		this->senderMailAddress = item.senderMailAddress;
		this->content = item.content;
		this->label = item.label;
		this->recieveDate = item.recieveDate;
		this->next = item.next;
	}

	void DisplayonName() {
		std::cout << "\tName   : " << name << std::endl;
	}


	void DisplayonTitle() {
		std::cout << "\tTitle   : " << title << std::endl;
	}

	void DisplayonSenderMailAddress() {
		std::cout << "\tSenderMailAddress   : " << senderMailAddress << std::endl;
	}

	void DisplayonContent() {
		std::cout << "\tContent   : " << content << std::endl;
	}

	void DisplayonLabel() {
		std::cout << "\tlabel   : " << label << std::endl;
	}

	void DisplayonRecieveDate() {
		std::cout << "\tRecieveDate   : " << recieveDate << std::endl;
	}


	void DisplayMailOnScreen() {
		DisplayonName();
		DisplayonTitle();
		DisplayonSenderMailAddress();
		DisplayonContent();
		DisplayonLabel();
		DisplayonRecieveDate();
	}

	std::string getTitle();

	std::string getSenderMailAddress();

	std::string getContent();

	std::string getLabel();

	std::string getRecieveDate();

	std::string getName();

	/*bool getUnread();

	struct _timeb getSendTime() const;*/

	int ReadDataFromFile(std::ifstream& fin);

	int WriteDataToFile(std::ofstream& fout);

	enum RelationType { LESS, GREATER, EQUAL };

	RelationType MailContent::CompareTo(const MailContent& data);

};