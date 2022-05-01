#pragma once

#include <string>
#include <sys/timeb.h>
#include <time.h>
#include <iostream>
#include <fstream>

class MailContent {
private:
	std::string title;
	std::string senderMailAddress;
	std::string content;
	std::string label;
	std::string recieveDate;

	//bool unread;

	//struct _timeb sendTime;

public:
	MailContent(){
		title = "";
		senderMailAddress = "";
		content = "";
		label = "";
		std::string recieveDate = "";
		//unread = true;

		//_ftime_s(&sendTime); // send 보낸 시간 저장

	}

	void setTitle(std::string title);

	void setSenderMailAddress(std::string mailAddress);

	void setContent(std::string content);

	void setLabel(std::string label);

	void setRecieveDate(std::string date);

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
		}
		std::cin >> data;
		std::cout << std::endl;
	}

	void setMail() {
		std::string title, mailAddress, content, label, recieveDate;
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
		//setUnread(check);
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

	//void DisplayonUnread() {
	//	std::cout << "\tunread   : " << unread << std::endl;
	//}


	void DisplayMailOnScreen() {
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


	/*bool getUnread();

	struct _timeb getSendTime() const;*/

	int ReadDataFromFile(std::ifstream& fin);

	int WriteDataToFile(std::ofstream& fout);

	enum RelationType { LESS, GREATER, EQUAL };

	RelationType MailContent::CompareByDate(const MailContent& data);

};