#include "Application.h"


// 프로그램을 실행시키는 함수
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 힙에 아이템을 추가한다.
			AddItem();
			break;
		case 2:		// ID를 이용하여 힙에서 아이템을 찾아 삭제한다.
			DeleteItem();
			break;
		case 3:		// 스크린에 힙의 모든 아이템 정보를 출력한다.
			DisplayAllItem();
			break;
		case 4:		// ID를 이용하여 힙에서 아이템을 찾는다.
			SearchItembyID();
			break;
		
		case 0:		// 프로그램을 끝낸다.
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}


// 스크린에 command를 출력하고 키보드로부터 command를 입력받는다.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Display item" << endl;
	cout << "\t   4 : Search item" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// 힙에 새로운 아이템 정보를 추가한다.
int Application::AddItem()
{
	// 입력받은 레코드를 힙에 add, 힙이 full일 경우는 add하지 않고 0을 리턴
	if (m_MaxHeap.IsFull())
	{
		cout << "Heap is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();

	m_MaxHeap.Add(item);

	//// 현재 힙 출력
	DisplayAllItem();

	return 1;
}


// 스크린에 힙의 모든 아이템 정보들을 출력한다.
void Application::DisplayAllItem()
{
	cout << "\t\tNow Items\t\t" << endl;
	m_MaxHeap.PrintHeap();
}


// 입력받은 ID로 아이템 정보를 찾아내어 스크린에 출력한다.
int Application::SearchItembyID()
{
	ItemType data;
	bool found = false;
	int root = 0;

	data.SetIdFromKB(); // 키보드로부터 ID를 입력받는다.
	
	m_MaxHeap.Retrieve(data, found, root);
	if (!found)
		cout << "\tNo match. Try Again." << endl; // 힙에 일치하는 아이템이 없는 경우 재시도 문구 출력
	else
		data.DisplayRecordOnScreen(); //힙에 일치하는 아이템을 발견하면 그 아이템의 모든 정보를 출력

	return 1;
}
	

// 입력받은 ID로 아이템을 찾아내어 그 아이템의 모든 정보를 힙에서 삭제한다.
int Application::DeleteItem()
{
	if (m_MaxHeap.IsEmpty() == true) // 힙이 비었을 때 데이터를 새로 추가하라는 문구 출력
	{
		cout << "\tData is Empty. Add new data and Try again." << endl;
		return 0;
	}
	ItemType data;
	bool found = false;
	int root = 0;

	data.SetIdFromKB(); // 키보드로부터 ID를 입력받는다.

	m_MaxHeap.Delete(data, found, root);
	if (!found)
		cout << "\tNo match. Try Again." << endl; // 힙에 일치하는 아이템이 없는 경우 재시도 문구 출력
	else {
		cout << "\tDelete compelete." << endl; // 삭제 완료 문구 출력
		DisplayAllItem();
	}

	
	return 1;
}
