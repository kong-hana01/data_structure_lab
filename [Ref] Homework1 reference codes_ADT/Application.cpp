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
			AddMail();
			break;
		case 2:		// display all the records in list on screen.
			DisplayAllMail();
			break;
		case 3:		// make empty list.
			MailBox.MakeEmpty();
			break;
		case 4:		
			FindNDisplayMail();
			break;
		case 5:		
			DeleteMailsInTimeInterval();
			break;
		case 6:		
			ReadDataFromFile();
			break;
		case 7:
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
	cout << "\t   1 : Add Mail" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty Mailbox" << endl;
	cout << "\t   4 : display mails in the given time interval" << endl;
	cout << "\t   5 : delete mails in the given time interval" << endl;
	cout << "\t   6 : load list data from a file." << endl;
	cout << "\t   7 : save list data into a file." << endl;
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddMail()
{
	// [작성] 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	MailContent mail;
	mail.setMail();
	//data.SetRecordFromKB(); // 메일 불러오기
	int isAdd = MailBox.addReceiveMail(mail);
	if (!isAdd) return 0;

	// [작성] 현재 list 출력
	DisplayAllMail();
	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllMail()
{
	cout << "\n\tCurrent MailBox" << endl;
	MailBox.DisplayAllMail();

	// [작성] list의 모든 데이터를 화면에 출력
	//MailBox.ResetList();
	//int location = MailBox.GetNextItem(mail);
	//while (location != -1 && location < MailBox.GetLength()) {
	//	mail.DisplayMailOnScreen();
	//	cout << '\n';
	//	location = MailBox.GetNextItem(mail);
	//}
	
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// [작성] 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	return m_InFile.is_open();
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// [작성] 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	return m_OutFile.is_open();
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	MailContent mail;	// 읽기용 임시 변수
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// [작성] file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename)) return 0;
	
	MailBox.ReadMailToFile(m_InFile);
	m_InFile.close();	// file close

	// [작성] 현재 list 출력
	DisplayAllMail();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// [작성] file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename)) return 0;

	// [작성] list의 모든 데이터를 파일에 쓰기
	MailBox.WriteMailToFile(m_OutFile);

	m_OutFile.close();	// file close

	return 1;
}


//
//int Application::SearchItemById(){
//	ItemType data;
//	data.SetIdFromKB();
//	if (m_List.Get(data)) { 
//		data.DisplayRecordOnScreen();
//		return 1;
//	}
//	return 0;
//}
//
//
//int Application::RetriveRecordByMemberName(){
//	ItemType data;
//	data.SetNameFromKB();
//	if (SearchListByMemberName(data)) {
//		data.DisplayRecordOnScreen();
//		return 1;
//	}
//	return 0;
//}
//
//
//int Application::SearchListByMemberName(ItemType& inData){
//	ItemType temp;
//	m_List.ResetList();
//	int cur = m_List.GetNextItem(temp);
//	while (cur != -1 && cur < m_List.GetLength()) {
//		if (temp.GetName().find(inData.GetName()) != -1) {
//			inData = temp;
//			return 1;
//		}
//		cur = m_List.GetNextItem(temp);
//	}
//	return 0;
//}

//
//int Application::DeleteItem(){
//	ItemType data;
//	data.SetIdFromKB();
//	if (m_List.Delete(data)) return 1;
//	return 0;
//}
//
//int Application::ReplaceItem(){
//	ItemType data;
//	data.SetRecordFromKB();
//	if (m_List.Replace(data)) return 1;
//	return 0;
//}
//
//
//int Application::SearchItemByBinarySearch(){
//	ItemType data;
//	data.SetIdFromKB();
//	if (m_List.GetBinarySearch(data)) { 
//		data.DisplayRecordOnScreen();
//		return 1;
//	}
//	return 0;
//}

void Application::FindNDisplayMail() {
	string start, end;
	cout << "시작 시간을 입력해주세요(YYYYMMDDTTMMSS): \n";
	cin >> start;
	cout << "끝 시간을 입력해주세요(YYYYMMDDTTMMSS): \n";
	cin >> end;
	MailBox.MailBoxFindNDisplayMail(start, end);
}

void Application::DeleteMailsInTimeInterval() {
	string start, end;
	cout << "시작 시간을 입력해주세요(YYYYMMDDTTMMSS): \n";
	cin >> start;
	cout << "끝 시간을 입력해주세요(YYYYMMDDTTMMSS): \n";
	cin >> end;
	MailBox.MailBoxDeleteMailsInTimeInterval(start, end);
}