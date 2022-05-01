#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

enum RelationType { LESS, GREATER, EQUAL };

/**
*	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
    bool operator>(NodeType node) {
        return this -> data > node.data;
    }
    bool operator<(NodeType node) {
        return this->data < node.data;
    }

    RelationType CompareTo(const NodeType& node) {
        if (*this > node)
            return GREATER;
        else if (*this < node)
            return LESS;
        else
            return EQUAL;
    }

};



/**
*	Simple unsorted list class for managing items.
*/
template <typename T>
class LinkedList
{
public:
	/**
	*	default constructor.
	*/
	LinkedList();

	/**
	*	destructor.
	*/
	~LinkedList();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& item);

private:
	NodeType<T>* m_pList;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};


// Class constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int LinkedList<T>::Add(T item)
{
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T>* node = new NodeType<T>;
    NodeType<T>* pre;
    NodeType<T>* now;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
    {
        now = pre = m_pList;
        bool moreToSearch = (now != NULL);
        // 현재 탐색 중인 노드와의 값 비교를 통해 위치 선정
        while (moreToSearch)
        {
            switch (node->CompareTo(*now)) {
            case LESS:
            case EQUAL:
                moreToSearch = false;
                break;
            case GREATER:
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

	m_nLength++;
	return 1;
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int LinkedList<T>::Get(T& item)
{
    NodeType<T>* node = new NodeType<T>;
	bool moreToSearch, found;
	NodeType<T>* now;
    NodeType<T>* pre;

	pre = now = m_pList;
    node->data = item;
    node->next = NULL;
	found = false;
	moreToSearch = (now != NULL);

    // 현재 탐색 중인 값과 주어진 값을 비교
	while (moreToSearch && !found)
	{
        switch (node->CompareTo(*now)) {
        // 탐색 중인 값 찾을 경우엔 found = true 후 탐색 종료
        case EQUAL:
            found = true;
        // 탐색 중인 값이 더 크지만 주어진 값을 찾지 못한 경우에는 탐색 종료
        case LESS:
            moreToSearch = false;
            break;
        // 주어진 값이 탐색 중인 값보다 더 큰 경우에는 탐색 진행
        case GREATER:
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


// Initializes current pointer for an iteration through the list.
template <typename T>
void LinkedList<T>::ResetList()
{
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void LinkedList<T>::GetNextItem(T & item)
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
	item = m_pCurPointer->data;
}


#endif	// LINKED_LIST
