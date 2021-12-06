//#include "bullet.h"
#include "Header.h"
template <class T>
class Node {
public:
	Node(T newData, Node* pHead);
	T getData();
	Node* getNext();
	void setNext(Node* newNode);
private:
	T Data;
	Node* pNext;
};

template<class T>
Node<T>::Node(T newData, Node* pHead) {
	Data = newData;
	pNext = pHead;
}

template<class T>
inline T Node<T>::getData() {
	return Data;
}

template<class T>
Node<T>* Node<T>::getNext() {
	return pNext;
}

template<class T>
void Node<T>::setNext(Node* newNode) {
	pNext = newNode;
}