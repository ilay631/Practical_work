#include <iostream>
using namespace std;


struct Node {
	int value;
	Node* next;

	Node(int _val) : value(_val), next(nullptr) {}
};


struct SinglyLinkedList {
	Node* startPtr;

	SinglyLinkedList() : startPtr(nullptr) {}

	SinglyLinkedList(Node* p) : startPtr(p) {}

	bool isEmpty() {
		return startPtr == nullptr;
	}

	Node* getLast() {
		Node* p = startPtr;
		while (p->next != nullptr) {
			p = p->next;
		}
		return p;
	}

	void append(int _val) {
		Node* p = new Node(_val);
		if (isEmpty()) {
			startPtr = p;
			return;
		}
		getLast()->next = p;
	}

	Node* get(int ind) {
		Node* p = startPtr;
		for (int i = 0; i < ind; i++) {
			p = p->next;
			if (p == nullptr)
				return p;
		}
		return p;
	}

	void print() {
		Node* p = startPtr;
		while (p != nullptr) {
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}

	Node* find(int _val) {
		Node* p = startPtr;
		while (p && p->value != _val)
			p = p->next;
		if (p && p->value == _val)
			return p;
		else
			return nullptr;
	}

	void remove(int _val) {
		if (isEmpty())
			return;
		Node* p = startPtr;
		if (p->value == _val) {
			startPtr = p->next;
			delete p;
			return;
		}
		while (p && p->next && p->next->value != _val) {
			p = p->next;
		}
		if (p->next == nullptr)
			return;
		else {
			Node* p1 = p->next->next;
			delete p->next;
			p->next = p1;
		}
	}
};


SinglyLinkedList createList() {
	cout << "Input number of elements" << endl;
	int length;
	cin >> length;
	cout << "Input 1 element" << endl;
	int n;
	cin >> n;
	Node* curNode = new Node(n);
	SinglyLinkedList list = SinglyLinkedList{ curNode };
	for (int i = 1; i < length; i++) {
		cout << "Input " << i + 1 << " element" << endl;
		cin >> n;
		Node* newNode = new Node(n);
		curNode->next = newNode;
		curNode = newNode;
	}

	return list;
}


int main() {
	SinglyLinkedList list = createList();

	list.print();
	list.append(100);
	list.print();
	cout << list.get(1)->value;
	cout << list.find(5);
	cout << endl;
	list.remove(5);
	list.print();

	return 0;
}