#pragma once

#include <string>
#include <list>
#include "MailContent.h"
#include "AddrItemType.h"
#include <iostream>
template<typename T>
class SortedLinkedList {
private:
	std::string m_name;
	std::string m_mailAddress;
	T* m_pCurPointer;
	T* m_pList;
	int m_length;
	int maxLength;

public:
	SortedLinkedList() {
		m_name = "";
		m_mailAddress = "";
		m_length = 0;
		m_pList = NULL;
		m_pCurPointer = NULL;
	}

	//SortedLinkedList(int maxMailBox) {
	//	m_name = "최한빈";
	//	m_mailAddress = "";
	//	m_pList = new MailContent[maxMailBox];
	//	maxLength = maxMailBox;
	//	m_length = 0;
	//}

	~SortedLinkedList() {
		MakeEmpty();
	}

	void setName(std::string name) {
		this->m_name = name;
	}

	void setMailAddress(std::string mailAddress) {
		this->m_mailAddress = mailAddress;
	}

	std::string getName() {
		return this->m_name;
	}

	std::string getMailAddress() {
		return this->m_mailAddress;
	}


	int addMail(T& item) {

		// 리스트 초기화
		ResetList();

		// 리스트에 추가할 새로운 item과 이전 item을 가리킬 포인터 선언
		T* node = new T;
		T* pre;
		T* now;
		T dummy;
		bool bFound = false;

		// node 객체에 입력받은 데이터 설정 및 초기화
		node->setdata(item);

		// list 에 node 가 존재하지 않는 경우
		if (!m_length) m_pList = node;

		// list 에 node 가 하나 이상 존재하는 경우
		else
		{
			now = pre = m_pList;
			bool moreToSearch = (now != NULL);
			// 현재 탐색 중인 노드와의 값 비교를 통해 위치 선정
			while (moreToSearch)
			{
				switch (node->CompareTo(*now)) {
				case T::LESS:
				case T::EQUAL:
					moreToSearch = false;
					break;
				case T::GREATER:
					pre = now;
					now = now->next;
					moreToSearch = (now != NULL);
					break;
				}
			}
			// 가장 작은 값인 경우 맨 앞에 삽입
			if (pre == now) {
				node->next = pre;
				m_pList = node;
			}
			// 그 외의 경우에는 적절한 위치에 데이터 삽입
			else {
				pre->next = node;
				node->next = now;
			}
		}
		m_length++;
		return 1;
	}


	void MakeEmpty() {
		T* tempPtr;

		while (m_pList != NULL)
		{
			tempPtr = m_pList;
			m_pList = m_pList->next;
			delete tempPtr;
		}

		m_length = 0;
	}

	int DeleteItem(int idx) {
		if (idx >= m_length) return 0;
		T* location;
		T* prevLoc;
		prevLoc = m_pList;
		if (idx == 0) {
			location = m_pList->next;
			m_pList = location;
			delete prevLoc;
		}
		else {
			for (int i = 0; i < idx - 1; i++)
				prevLoc = prevLoc->next;
			location = prevLoc->next;
			prevLoc->next = location->next;
			delete location;
		}
		m_length--;
		return 1;
	}

	int GetLength() {
		return m_length;
	}

	void ResetList()
	{
		// current pointer 초기화
		m_pCurPointer = NULL;
	}

	void GetNextItem(T& item)
	{
		// current pointer 이 NULL이라면 처음 node를 가리킴.
		if (m_pCurPointer == NULL)
		{
			m_pCurPointer = m_pList;
		}
		else
			//current position 을 다음 노드로 이동
			m_pCurPointer = m_pCurPointer->next;

		//item 에 current position 의 info 를 삽입
		item = *m_pCurPointer;
	}

	//void DisplayAllMail() {
	//	for (int i = 0; i < m_length; i++) {
	//		m_pList[i].DisplayMailOnScreen();
	//	}
	//}

	template <typename T>
	int Get(T item)
	{
		T* node = new T;
		bool moreToSearch, found;
		T* now;
		T* pre;

		pre = now = m_pList;
		node->setdata(item);
		found = false;
		moreToSearch = (now != NULL);

		// 현재 탐색 중인 값과 주어진 값을 비교
		while (moreToSearch && !found)
		{
			switch (node->CompareTo(*now)) {
				// 탐색 중인 값 찾을 경우엔 found = true 후 탐색 종료
			case T::EQUAL:
				found = true;
				// 탐색 중인 값이 더 크지만 주어진 값을 찾지 못한 경우에는 탐색 종료
			case T::LESS:
				moreToSearch = false;
				break;
				// 주어진 값이 탐색 중인 값보다 더 큰 경우에는 탐색 진행
			case T::GREATER:
				pre = now;
				now = now->next;
				moreToSearch = (now != NULL);
				break;
			}
		}

		if (found)
			return 1;
		else
			return 0;
	}




	//int GetBinarySearch(MailContent& mail) {
	//	int start = 0, end = m_length-1;
	//	int m_CurPointer = 0;
	//	bool found = false;
	//	while (start <= end && !found) {
	//		int mid = (start + end) / 2;
	//		switch (mail.CompareByDate(m_pList[mid])) {
	//		case MailContent::LESS:
	//			end--;
	//			break;
	//		case MailContent::GREATER:
	//			start++;
	//			m_CurPointer = m_CurPointer < mid+1? mid+1 : m_CurPointer;
	//			break;
	//		case MailContent::EQUAL:
	//			found = true;
	//			mail = m_pList[mid];
	//			m_CurPointer = mid;
	//		}
	//	}
	//	return m_CurPointer;
	//}

//	int WriteMailToFile(std::ofstream & fout) {
//		fout << m_name << std::endl;
//		fout << m_mailAddress << std::endl;
//		for (int i = 0; i < m_length; i++) {
//			m_pList[i].WriteDataToFile(fout);
//		}
//		return 1;
//	}
//	
//	int ReadMailToFile(std::ifstream& fin) {
//		MailContent mail;
//		fin >> m_name;
//		fin >> m_mailAddress;
//		MakeEmpty();
//		while (!fin.eof()) {
//			mail.ReadDataFromFile(fin);
//			if (mail.getRecieveDate() != "") addMail(mail);
//		}
//		return 1;
//	}
//
//	int MailBoxFindNDisplayMail(std::string start, std::string end) {
//		for (int i = 0; i < m_length; i++) {
//			if (m_pList[i].getRecieveDate() > end) break;
//			if (m_pList[i].getRecieveDate() >= start) {
//				m_pList[i].DisplayMailOnScreen();
//			}
//		}
//		return 1;
//	}
//
//	int MailBoxDeleteMailsInTimeInterval(std::string start, std::string end) {
//		int startidx = m_length, cnt = 0;
//		for (int i = 0; i < m_length; i++) {
//			if (m_pList[i].getRecieveDate() > end) break;
//			if (m_pList[i].getRecieveDate() >= start) {
//				startidx = startidx > i ? i : startidx;
//				cnt++;
//			}
//		}
//		for (int i = startidx; i + cnt < m_length; i++) {
//			m_pList[i] = m_pList[i + cnt];
//		}
//		m_length -= cnt;
//		return 1;
//	}

};