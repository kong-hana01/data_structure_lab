#pragma once

#include <string>
#include <time.h>
#include <iostream>
#include <fstream>

class AddrItemType {
public:
	std::string name;
	std::string address;
	AddrItemType* next;

	AddrItemType() {
		name = "";
		address = "";
		next = NULL;
	}

	AddrItemType(const AddrItemType& a) {
		name = a.name;
		address = a.address;
		next = a.next;
	}

	AddrItemType& operator=(const AddrItemType& a) {
		name = a.name;
		address = a.address;
		next = a.next;
		return *this;
	}

	void setName(std::string name);

	void setaddress(std::string mailAddress);


	void cinMail(std::string& data, int flag) {
		switch (flag) {
		case 1:
			std::cout << "Name: ";
			break;
		case 2:
			std::cout << "address: ";
			break;
		}
		std::cin >> data;
		std::cout << std::endl;
	}

	void setMail() {
		std::string name, mailAddress;
		cinMail(name, 1);
		cinMail(mailAddress, 2);
		setName(name);
		setaddress(mailAddress);
	}

	void setdata(AddrItemType& item) {
		this->name = item.name;
		this->address = item.address;
		this->next = item.next;
	}

	void DisplayonName() {
		std::cout << "\tName   : " << name << std::endl;
	}

	void DisplayonAddress() {
		std::cout << "\tMailAddress   : " << address << std::endl;
	}


	void DisplayMailOnScreen() {
		DisplayonName();
		DisplayonAddress();
	}

	std::string getName();

	std::string getaddress();


	int ReadDataFromFile(std::ifstream& fin);

	int WriteDataToFile(std::ofstream& fout);

	enum RelationType { LESS, GREATER, EQUAL };

	RelationType AddrItemType::CompareTo(const AddrItemType& data);

};