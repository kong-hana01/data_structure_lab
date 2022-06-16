#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
*	Relation between two items.
*/
//enum RelationType {LESS, GREATER, EQUAL};


/**
*	item information class.
*/
class QItemType
{
public:

	QItemType(){
		m_name = "";
		m_mailAddress = "";
	}

	//QItemType(const QItemType& q) {
	//	m_name = q.m_name;
	//	m_mailAddress = q.m_mailAddress;
	//}

	~QItemType(){}


	string GetName(){
		return m_name;
	}

	string GetAddress(){
		return m_mailAddress;
	}

	void SetName(string inName){
		m_name = inName;
	}

	void SetAddress(string inAddress){
		m_mailAddress = inAddress;
	}

	void SetRecord(string inName, string inAddress){
		SetName(inName);
		SetAddress(inAddress);
	}

	void DisplayNameOnScreen() {
		cout << "\tName : " << m_name << endl; 
	};

	void DisplayAddressOnScreen() {
		cout << "\tAddress : " << m_mailAddress << endl;
	};

	void DisplayRecordOnScreen(){
		DisplayNameOnScreen();
		DisplayAddressOnScreen();
	};


	void SetNameFromKB() {
		cout << "\tName : ";
		cin >> m_name;
	}

	void SetAddressFromKB() {
		cout << "\tAddress : ";
		cin >> m_mailAddress;
	}
	
	void SetRecordFromKB() {
		SetNameFromKB();
		SetAddressFromKB();
	}

	int ReadDataFromFile(ifstream& fin) {
		fin >> m_name;
		fin >> m_mailAddress;

		return 1;
	}

	int WriteDataToFile(ofstream& fout) {
		fout << m_name;
		fout << m_mailAddress;

		return 1;
	}
	
	//RelationType CompareByID(const QItemType &data) {
	//	if (this->m_mailAddress > data.m_mailAddress)
	//		return GREATER;
	//	else if (this->m_mailAddress < data.m_mailAddress)
	//		return LESS;
	//	else
	//		return EQUAL;
	//}

protected:
	string m_name; // 메일 제목
	string m_mailAddress; // 보내는 사람 메일 주소
};

