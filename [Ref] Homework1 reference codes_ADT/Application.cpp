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
			m_mailBox.MakeEmpty();
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
		case 8:
			DisplayRecentAddress();
			break;
		case 9:
			GetNewAddress();
			break;
		case 10:
			SearchAddress();
			break;
		case 11:
			DeleteAddress();
			break;
		case 12:
			DisplayAllAddress();
			break;
		case 13:
			DisplayAllTrashBin();
			break;
		case 14:
			RestoreMail();
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
	cout << "\t   8 : display recent mails" << endl;
	cout << "\t   9 : Add New Mail Address." << endl;
	cout << "\t   10 : Search Address." << endl;
	cout << "\t   11 : Delete Address." << endl;
	cout << "\t   12 : Display Address." << endl;
	cout << "\t   13 : Display trash bin." << endl;
	cout << "\t   14 : Restore Mail." << endl;
	cout << "\t   0 : Quit" << endl; 
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

//
// ������
//

int Application::AddMail()
{
	MailContent mail;
	mail.setMail();
	//data.SetRecordFromKB(); // ���� �ҷ�����
	int isAdd = m_mailBox.addMail(mail);
	if (!isAdd) return 0;

	QItemType QItem;
	QItem.SetName(mail.getName());
	QItem.SetAddress(mail.getSenderMailAddress());
	UpdateRecentAddress(QItem);

	// [�ۼ�] ���� list ���
	cout << "All Mails" << endl;
	DisplayAllMail();

	cout << endl << "Recent Mails" << endl;
	DisplayRecentAddress();

	cout << endl << "All AddressBook" << endl;
	DisplayAllAddress();
	return 1;
}


void Application::DisplayAllMail()
{
	cout << "\n\tCurrent MailBox" << endl;
	MailContent data;

	m_mailBox.ResetList();	// ����Ʈ �ʱ�ȭ
	// list�� ��� �����͸� ȭ�鿡 ���
	for (int i = 0; i < m_mailBox.GetLength(); i++)
	{
		m_mailBox.GetNextItem(data);
		data.DisplayMailOnScreen();
	}
}


int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// [�ۼ�] ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	return m_InFile.is_open();
}


int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// [�ۼ�] ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	return m_OutFile.is_open();
}

int Application::ReadDataFromFile()
{	
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// [�ۼ�] file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename)) return 0;
	MailContent mail;	// �б�� �ӽ� ����
	
	m_mailBox.MakeEmpty();
	//string temp;
	//m_InFile >> temp;
	//m_mailBox.setName(temp);
	//m_InFile >> temp;
	//m_mailBox.setMailAddress(temp);
	while (!m_InFile.eof()) {
		mail.ReadDataFromFile(m_InFile);
		if (mail.getRecieveDate() != "") m_mailBox.addMail(mail);
	}

	//m_mailBox.ReadMailToFile(m_InFile);
	m_InFile.close();	// file close

	// [�ۼ�] ���� list ���
	DisplayAllMail();

	return 1;
}

int Application::WriteDataToFile()
{
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// [�ۼ�] file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename)) return 0;
	MailContent mail;

	//m_OutFile << m_mailBox.getName() << std::endl;
	//m_OutFile << m_mailBox.getMailAddress() << std::endl;
	// [�ۼ�] list�� ��� �����͸� ���Ͽ� ����
	m_mailBox.ResetList();
	for (int i = 0; i < m_mailBox.GetLength(); i++)
	{
		m_mailBox.GetNextItem(mail);
		mail.WriteDataToFile(m_OutFile);
	}
	//m_mailBox.WriteMailToFile(m_OutFile);

	m_OutFile.close();	// file close

	return 1;
}

void Application::FindNDisplayMail() {
	string start, end;
	cout << "���� �ð��� �Է����ּ���(YYYYMMDDTTMMSS): \n";
	cin >> start;
	cout << "�� �ð��� �Է����ּ���(YYYYMMDDTTMMSS): \n";
	cin >> end;
	
	MailContent mail;
	m_mailBox.ResetList();	// ����Ʈ �ʱ�ȭ
	for (int i = 0; i < m_mailBox.GetLength(); i++){
		m_mailBox.GetNextItem(mail);
		if (mail.getRecieveDate() > end) break;
		if (mail.getRecieveDate() >= start) {
			mail.DisplayMailOnScreen();
			}
		}

}

void Application::DeleteMailsInTimeInterval() {
	string start, end;
	cout << "���� �ð��� �Է����ּ���(YYYYMMDDTTMMSS): \n";
	cin >> start;
	cout << "�� �ð��� �Է����ּ���(YYYYMMDDTTMMSS): \n";
	cin >> end;
	int cnt = 0, idx = m_mailBox.GetLength();
	MailContent mail;
	m_mailBox.ResetList();	// ����Ʈ �ʱ�ȭ
	for (int i = 0; i < m_mailBox.GetLength(); i++) {
		m_mailBox.GetNextItem(mail);
		if (mail.getRecieveDate() > end) break;
		if (mail.getRecieveDate() >= start) {
			idx = idx < i ? idx : i;
			cnt++;
			mail.next = NULL;
			AddToTrashBin(mail);
		}
	}
	for (int i = 0; i < cnt; i++){
		m_mailBox.DeleteItem(idx);
	}
}

//
// �ֱ� ������
//

int Application::UpdateRecentAddress(QItemType Item) {
	m_recentMailBox.DeleteItem(Item);
	m_recentMailBox.EnQueue(Item);
	return 1;
}

void Application::DisplayRecentAddress() {
	m_recentMailBox.DisplayAllItems();
}

int Application::GetNewAddress() {
	DisplayRecentAddress();

	QItemType QItem;
	//QItem.SetName(m_mailBox.getName());
	QItem.SetNameFromKB();
	QItem.SetAddressFromKB();
	
	return AddAddress(QItem);
}

//
// �ּҷ�
//

int Application::AddAddress(QItemType QItem) {
	UpdateRecentAddress(QItem);

	AddrItemType AItem;	
	AItem.setaddress(QItem.GetAddress());
	AItem.setName(QItem.GetName());

	return m_addressBook.addMail(AItem);
}

AddrItemType Application::SearchAddress() {
	AddrItemType item;
	string temp;
	cout << "�ּҸ� �Է��ϼ���." << endl;
	cin >> temp;
	item.setaddress(temp);
	if (m_addressBook.Get(item)) {
		cout << "�ּҰ� �ֽ��ϴ�." << endl;
	}
	else {
		cout << "�ּҰ� �����ϴ�." << endl;
	}
	return item;
}

int Application::DeleteAddress() {
	string address;
	cout << "�ּҸ� �Է����ּ���: \n";
	cin >> address;

	int cnt = 0, idx = m_addressBook.GetLength();
	AddrItemType data;
	m_addressBook.ResetList();	// ����Ʈ �ʱ�ȭ
	for (int i = 0; i < m_addressBook.GetLength(); i++) {
		m_addressBook.GetNextItem(data);
		if (data.getaddress() == address) {
			idx = idx < i ? idx : i;
			cnt++;
		}
	}
	AddrItemType mail;
	for (int i = 0; i < cnt; i++)
		m_addressBook.DeleteItem(idx);
	return 1;
}

void Application::DisplayAllAddress() {
	cout << "\n\tCurrent Address" << endl;
	AddrItemType data;

	m_addressBook.ResetList();	// ����Ʈ �ʱ�ȭ
	// list�� ��� �����͸� ȭ�鿡 ���
	for (int i = 0; i < m_addressBook.GetLength(); i++) {
		m_addressBook.GetNextItem(data);
		data.DisplayMailOnScreen();
	}
}

//
// ������
//

int Application::AddToTrashBin(MailContent m) {
	return m_trashBin.addMail(m);
}

int Application::DeleteFromTrashBin(MailContent m) {
	int cnt = 0, idx = m_trashBin.GetLength();
	MailContent data;
	m_trashBin.ResetList();	// ����Ʈ �ʱ�ȭ
	for (int i = 0; i < m_trashBin.GetLength(); i++) {
		m_trashBin.GetNextItem(data);
		if (data == m) {
			AddToMailBox(data);
			m_trashBin.DeleteItem(i);
			return 1;
		}
	}
	return 0;
}


int Application::AddToMailBox(MailContent m) {
	return m_mailBox.addMail(m);
}

int Application::DeleteFromMailBox(MailContent m) {
	int cnt = 0, idx = m_mailBox.GetLength();
	MailContent data;
	m_mailBox.ResetList();	// ����Ʈ �ʱ�ȭ
	for (int i = 0; i < m_mailBox.GetLength(); i++) {
		m_mailBox.GetNextItem(data);
		if (data == m) {
			AddToTrashBin(data);
			m_mailBox.DeleteItem(idx);
			return 1;
		}
	}
	return 0;
}

int Application::DeleteMail() {
	MailContent mail;
	mail.setMail();
	return DeleteFromMailBox(mail);
}


int Application::RestoreMail() {
	MailContent mail;
	mail.setMail();
	return DeleteFromTrashBin(mail);
}

void Application::DisplayAllTrashBin() {
	cout << "\n\tCurrent Address" << endl;
	MailContent data;

	m_trashBin.ResetList();	// ����Ʈ �ʱ�ȭ
	// list�� ��� �����͸� ȭ�鿡 ���
	for (int i = 0; i < m_trashBin.GetLength(); i++) {
		m_trashBin.GetNextItem(data);
		data.DisplayMailOnScreen();
	}
}



//int Application::DisplayByName() {
//	MailContent mail;
//}