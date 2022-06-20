#include "AddrItemType.h"


void AddrItemType::setName(std::string name) {
	this->name = name;
}

void AddrItemType::setaddress(std::string mailAddress) {
	this->address = mailAddress;
}


std::string AddrItemType::getName() {
	return name;
}

std::string AddrItemType::getaddress() {
	return address;
}


int AddrItemType::ReadDataFromFile(std::ifstream& fin)
{
	fin >> name;
	fin >> address;

	return 1;
};

int AddrItemType::WriteDataToFile(std::ofstream& fout)
{
	fout << name << std::endl;
	fout << address << std::endl;
	fout << std::endl;
	return 1;
}



AddrItemType::RelationType AddrItemType::CompareTo(const AddrItemType& mail)
{
	if (this->address > mail.address)
		return GREATER;
	else if (this->address < mail.address)
		return LESS;
	else
		return EQUAL;
}