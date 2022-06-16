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
		case 4:		// [�ۼ�] search item from list.
			SearchData();
			break;
		case 5:		// [�ۼ�] delete item from list
			DeleteItem();
			break;
		case 6:		// [�ۼ�] update item in list
			UpdateItem();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
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
	cout << "\t   1 : Add new item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item" << endl;
	cout << "\t   5 : Delete item" << endl;
	cout << "\t   6 : Update item" << endl;
	cout << "\t   7 : Get from file" << endl; 
	cout << "\t   8 : Put to file " << endl; 
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


int Application::SearchData() {
	int inId;
	ItemType data;
	cout << "ã���� �ϴ� �л� �й��� �Է��ϼ���.";
	cin >> inId;
	data.SetId(inId);
	if (!m_List.Get(data)) {
		cout << "�־��� �л� ������ �����ϴ�." << endl;
		return 0;
	}

	data.DisplayRecordOnScreen();
	return 1;
}


int Application::DeleteItem() {
	int inId;
	ItemType data;
	cout << "�����ϰ��� �ϴ� �л� �й��� �Է��ϼ���.";
	cin >> inId;
	data.SetId(inId);
	if (!m_List.Get(data)) return 0;
	m_List.Delete(data);
	return 1;
}


int Application::UpdateItem() {
	ItemType data;
	data.SetRecordFromKB();
	m_List.Replace(data);
	return m_List.Get(data);
}

