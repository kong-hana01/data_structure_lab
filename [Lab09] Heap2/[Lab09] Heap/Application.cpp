#include "Application.h"


// ���α׷��� �����Ű�� �Լ�
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// ���� �������� �߰��Ѵ�.
			AddItem();
			break;
		case 2:		// ID�� �̿��Ͽ� ������ �������� ã�� �����Ѵ�.
			DeleteItem();
			break;
		case 3:		// ��ũ���� ���� ��� ������ ������ ����Ѵ�.
			DisplayAllItem();
			break;
		case 4:		// ID�� �̿��Ͽ� ������ �������� ã�´�.
			SearchItembyID();
			break;
		
		case 0:		// ���α׷��� ������.
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}


// ��ũ���� command�� ����ϰ� Ű����κ��� command�� �Է¹޴´�.
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


// ���� ���ο� ������ ������ �߰��Ѵ�.
int Application::AddItem()
{
	// �Է¹��� ���ڵ带 ���� add, ���� full�� ���� add���� �ʰ� 0�� ����
	if (m_MaxHeap.IsFull())
	{
		cout << "Heap is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();

	m_MaxHeap.Add(item);

	//// ���� �� ���
	DisplayAllItem();

	return 1;
}


// ��ũ���� ���� ��� ������ �������� ����Ѵ�.
void Application::DisplayAllItem()
{
	cout << "\t\tNow Items\t\t" << endl;
	m_MaxHeap.PrintHeap();
}


// �Է¹��� ID�� ������ ������ ã�Ƴ��� ��ũ���� ����Ѵ�.
int Application::SearchItembyID()
{
	ItemType data;
	bool found = false;
	int root = 0;

	data.SetIdFromKB(); // Ű����κ��� ID�� �Է¹޴´�.
	
	m_MaxHeap.Retrieve(data, found, root);
	if (!found)
		cout << "\tNo match. Try Again." << endl; // ���� ��ġ�ϴ� �������� ���� ��� ��õ� ���� ���
	else
		data.DisplayRecordOnScreen(); //���� ��ġ�ϴ� �������� �߰��ϸ� �� �������� ��� ������ ���

	return 1;
}
	

// �Է¹��� ID�� �������� ã�Ƴ��� �� �������� ��� ������ ������ �����Ѵ�.
int Application::DeleteItem()
{
	if (m_MaxHeap.IsEmpty() == true) // ���� ����� �� �����͸� ���� �߰��϶�� ���� ���
	{
		cout << "\tData is Empty. Add new data and Try again." << endl;
		return 0;
	}
	ItemType data;
	bool found = false;
	int root = 0;

	data.SetIdFromKB(); // Ű����κ��� ID�� �Է¹޴´�.

	m_MaxHeap.Delete(data, found, root);
	if (!found)
		cout << "\tNo match. Try Again." << endl; // ���� ��ġ�ϴ� �������� ���� ��� ��õ� ���� ���
	else {
		cout << "\tDelete compelete." << endl; // ���� �Ϸ� ���� ���
		DisplayAllItem();
	}

	
	return 1;
}
