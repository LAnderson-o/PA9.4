#include "TemplateNode.h"

template <class T>
class List {
public:
	List();

	void insertAtFront(T newData);
	void insertAtBack(T newData);
	T deleteAtFront();
	T deleteAtBack();
	void reverse();

private:
	Node<T>* pHead;
	Node<T>* pTail;
};

template <class T>
List<T>::List() {
	pHead = nullptr;
	pTail = nullptr;
}

template <class T>
void List<T>::insertAtFront(T newData) {
	if (pHead == pTail) {
		if (pHead == nullptr) {
			pTail = pHead = new Node<T>(newData, nullptr);
		}
		else {
			pHead = new Node<T>(newData, pTail);
		}
	}
	else {
		Node<T>* temp = pHead;
		pHead = new Node<T>(newData, temp);
	}
}

template <class T>
void List<T>::insertAtBack(T newData) {
	if (pHead == pTail) {
		if (pHead == nullptr) {
			pTail = pHead = new Node<T>(newData, nullptr);
		}
		else {
			pTail = new Node<T>(newData, nullptr);
			pHead->setNext(pTail);
		}
	}
	else {
		Node<T>* temp = new Node<T>(newData, nullptr);
		pTail->setNext(temp);
		pTail = temp;
	}
}

template <class T>
T List<T>::deleteAtFront() {
	T data;
	if (pHead == pTail) {
		if (pHead != nullptr) {
			data = pHead->getData();
			pTail = pHead = nullptr;
		}
	}
	else {
		data = pHead->getData();
		pHead = pHead->getNext();
	}
	return data;
}

template <class T>
T List<T>::deleteAtBack() {
	T data;
	if (pHead == pTail) {
		if (pHead != nullptr) {
			data = pHead->getData();
			pTail = pHead = nullptr;
		}
	}
	else {
		data = pTail->getData();
		Node<T>* curr = pHead;
		Node<T>* curr2 = curr->getNext();
		while (curr2->getNext() != nullptr) {
			curr = curr->getNext();
			curr2 = curr2->getNext();
		}
		pTail = curr;
		pTail->setNext(nullptr);
	}
	return data;
}

template <class T>
void List<T>::reverse() {
	Node<T>* curr = pHead;
	Node<T>* next = curr->getNext();
	Node<T>* prev = nullptr;
	if (pHead != pTail) {
		while (curr != nullptr) {
			if (prev != nullptr) {
				curr->setNext(prev);
				if (prev == pHead)
					prev->setNext(nullptr);
			}
			prev = curr;
			curr = next;
			if (curr != nullptr)
				next = next->getNext();
		}
		pTail = pHead;
		pHead = prev;
	}
}