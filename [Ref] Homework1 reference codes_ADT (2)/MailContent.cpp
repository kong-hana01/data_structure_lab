#include "MailContent.h"


void MailContent::setTitle(std::string title) {
	this->title = title;
}

void MailContent::setSenderMailAddress(std::string mailAddress) {
	this->senderMailAddress = mailAddress;
}

void MailContent::setContent(std::string content) {
	this->content = content;
}

void MailContent::setLabel(std::string label) {
	this->label = label;
}

void MailContent::setRecieveDate(std::string date) {
	this->recieveDate = date;
}

void MailContent::setName(std::string name) {
	this->name = name;
}

//void MailContent::setUnread(bool check) {
//	this->unread = check;
//}



std::string MailContent::getTitle() {
	return title;
}

std::string MailContent::getSenderMailAddress() {
	return senderMailAddress;
}

std::string MailContent::getContent() {
	return content;
}

std::string MailContent::getLabel() {
	return label;
}

//bool MailContent::getUnread() {
//	return unread;
//}
//
//struct _timeb MailContent::getSendTime() const {
//	return sendTime;
//}

std::string MailContent::getRecieveDate() {
	return recieveDate;
}

std::string MailContent::getName() {
	return name;
}

int MailContent::ReadDataFromFile(std::ifstream& fin)
{
	fin >> name;
	fin >> title;
	fin >> senderMailAddress;
	fin >> content;
	fin >> label;
	fin >> recieveDate;
	/*fin >> unread;
	fin >> sendTime.time;
	fin >> sendTime.millitm;
	fin >> sendTime.timezone;
	fin >> sendTime.dstflag;*/
	return 1;
};

int MailContent::WriteDataToFile(std::ofstream& fout)
{
	fout << name << std::endl;
	fout << title << std::endl;
	fout << senderMailAddress << std::endl;
	fout << content << std::endl;
	fout << label << std::endl;
	fout << recieveDate << std::endl;
	//fout << unread;
	//fout << sendTime.time;
	//fout << sendTime.millitm;
	//fout << sendTime.timezone;
	//fout << sendTime.dstflag;
	fout << std::endl;
	return 1;
}



MailContent::RelationType MailContent::CompareTo(const MailContent& mail)
{
	if (this->recieveDate > mail.recieveDate)
		return GREATER;
	else if (this->recieveDate < mail.recieveDate)
		return LESS;
	else
		return EQUAL;
}