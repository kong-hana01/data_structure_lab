#pragma once

#include "HeapBase.hpp"

template <typename T>
class MaxHeap : public HeapBase<T> {
public:
	MaxHeap();
	MaxHeap(int size);
	~MaxHeap();

	virtual void ReheapDown(int iparent, int ibottom);
	virtual void ReheapUp(int iroot, int ibottom);
	virtual void Delete(T item, bool& found, int iparent);
	virtual void Retrieve(T& item, bool& found, int iparent);
};

template <typename T>
MaxHeap<T>::MaxHeap() : HeapBase<T>() {}

template <typename T>
MaxHeap<T>::MaxHeap(int size) : HeapBase<T>(size) {}

template <typename T>
MaxHeap<T>::~MaxHeap() { }

template <typename T>
void MaxHeap<T>::ReheapDown(int iparent, int ibottom) {
	int maxChild, rightChild, leftChild;
	leftChild = iparent * 2 + 1;
	rightChild = iparent * 2 + 2;
	if (leftChild <= ibottom) {
		if (leftChild == ibottom) {
			maxChild = leftChild;
		}
		else {
			maxChild = this->m_pHeap[leftChild] < this->m_pHeap[rightChild] ? rightChild : leftChild;
		}
		if (this->m_pHeap[iparent] < this->m_pHeap[maxChild]) {
			T item = this->m_pHeap[iparent];
			this->m_pHeap[iparent] = this->m_pHeap[maxChild];
			this->m_pHeap[maxChild] = item;
			ReheapDown(maxChild, ibottom);
		}
	}
}

template <typename T>
void MaxHeap<T>::ReheapUp(int iroot, int ibottom) {
	int parent;

	if (ibottom > iroot) {
		parent = (ibottom - 1) / 2;
		if (this->m_pHeap[parent] < this->m_pHeap[ibottom]) {
			T item = this->m_pHeap[parent];
			this->m_pHeap[parent] = this->m_pHeap[ibottom];
			this->m_pHeap[ibottom] = item;
			ReheapDown(iroot, parent);
		}
	}
}

template <typename T>
void MaxHeap<T>::Delete(T item, bool& found, int iparent) {
	if (found) return;

	if (iparent < this->m_iLastNode) {
		if (item == this->m_pHeap[iparent]) {
			found = true;
			this->m_pHeap[iparent] = this->m_pHeap[--(this->m_iLastNode)];
			ReheapDown(iparent, this->m_iLastNode);
		}
		else {
			int  rightChild, leftChild;
			leftChild = iparent * 2 + 1;
			rightChild = iparent * 2 + 2;
			Delete(item, found, leftChild);
			Delete(item, found, rightChild);
		}
	}
}

template <typename T>
void MaxHeap<T>::Retrieve(T& item, bool& found, int iparent) {
	if (found) return;

	if (iparent < this->m_iLastNode){
		if (item == this->m_pHeap[iparent]) {
			found = true;
			item = this->m_pHeap[iparent];
		}
		else {
			int  rightChild, leftChild;
			leftChild = iparent * 2 + 1;
			rightChild = iparent * 2 + 2;
			Retrieve(item, found, leftChild);
			Retrieve(item, found, rightChild);
		}
	}
}