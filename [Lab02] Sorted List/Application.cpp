#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 3:		// make empty list.
			m_List.MakeEmpty();
			break;
		case 4:		
			SearchItemByBinarySearch();
			break;
		case 5:		
			RetriveRecordByMemberName();
			break;
		case 6:		
			DeleteItem();
			break;
		case 7:		
			ReplaceItem();
			break;
		case 8:		
			ReadDataFromFile();
			break;
		case 9:
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Search item by Name" << endl;
	cout << "\t   6 : Delete item" << endl;
	cout << "\t   7 : Update item" << endl;
	cout << "\t   8 : Get from file" << endl; 
	cout << "\t   9 : Put to file " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddItem()
{
	// [�ۼ�] �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	ItemType data;
	data.SetRecordFromKB();
	int isAdd = m_List.Add(data);
	if (!isAdd) return 0;

	// [�ۼ�] ���� list ���
	DisplayAllItem();
	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;


	// [�ۼ�] list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int location = m_List.GetNextItem(data);
	while (location != -1 && location < m_List.GetLength()) {
		data.DisplayRecordOnScreen();
		cout << '\n';
		location = m_List.GetNextItem(data);
	}
	
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// [�ۼ�] ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	return m_InFile.is_open();
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// [�ۼ�] ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	return m_OutFile.is_open();
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// [�ۼ�] file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename)) return 0;

	// [�ۼ�] ������ ��� ������ �о� list�� �߰�
	m_List.MakeEmpty();
	while (!m_InFile.eof()) {
		data.ReadDataFromFile(m_InFile);
		if (data.GetId() != -1) m_List.Add(data);
	}
	
	m_InFile.close();	// file close

	// [�ۼ�] ���� list ���
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// [�ۼ�] file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename)) return 0;

	// [�ۼ�] list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// [�ۼ�] list�� ��� �����͸� ���Ͽ� ����
	int location = m_List.GetNextItem(data);
	while (location != -1 && location < m_List.GetLength()) {
		data.WriteDataToFile(m_OutFile);
		location = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}



int Application::SearchItemById(){
	ItemType data;
	data.SetIdFromKB();
	if (m_List.Get(data)) { 
		data.DisplayRecordOnScreen();
		return 1;
	}
	return 0;
}


int Application::RetriveRecordByMemberName(){
	ItemType data;
	data.SetNameFromKB();
	if (SearchListByMemberName(data)) {
		data.DisplayRecordOnScreen();
		return 1;
	}
	return 0;
}


int Application::SearchListByMemberName(ItemType& inData){
	ItemType temp;
	m_List.ResetList();
	int cur = m_List.GetNextItem(temp);
	while (cur != -1 && cur < m_List.GetLength()) {
		if (temp.GetName().find(inData.GetName()) != -1) {
			inData = temp;
			return 1;
		}
		cur = m_List.GetNextItem(temp);
	}
	return 0;
}


int Application::DeleteItem(){
	ItemType data;
	data.SetIdFromKB();
	if (m_List.Delete(data)) return 1;
	return 0;
}

int Application::ReplaceItem(){
	ItemType data;
	data.SetRecordFromKB();
	if (m_List.Replace(data)) return 1;
	return 0;
}


int Application::SearchItemByBinarySearch(){
	ItemType data;
	data.SetIdFromKB();
	if (m_List.GetBinarySearch(data)) { 
		data.DisplayRecordOnScreen();
		return 1;
	}
	return 0;
}