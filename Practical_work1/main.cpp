#include <iostream>
#include <string>
using namespace std;


struct Node {
	int value;
	Node* next;

	Node(int _val) : value(_val), next(nullptr) {}

	Node(int _val, Node* p) : value(_val), next(p) {}
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

	int getLength() {
		Node* p = startPtr;
		if (isEmpty())
			return 0;
		int k = 1;
		while (p->next != nullptr) {
			p = p->next;
			k++;
		}

		return k;
	}
};


SinglyLinkedList createList() {
	SinglyLinkedList list = SinglyLinkedList{};
	cout << "Input number of elements" << endl;
	int length;
	cin >> length;
	if (length > 0) {
		cout << "Input elements" << endl;
		int n;
		cin >> n;
		list.append(n);
		for (int i = 1; i < length; i++) {
			cin >> n;
			list.append(n);
		}
	}

	return list;
}


void changeList(SinglyLinkedList* list) {
	Node* p = list->startPtr;
	while (p) {
		if (p->value % 2 == 0)
			p->value /= 2;
		else
			p->value = p->value * 3 - 1;
		p = p->next;
	}
}


void reverseList(SinglyLinkedList* list) {
	Node* curNode = list->startPtr;
	if (list->isEmpty())
		return;
	Node* nextNode = curNode->next;
	curNode->next = nullptr;
	while (nextNode) {
		if (nextNode->next) {
			Node* t = nextNode->next;
			nextNode->next = curNode;
			curNode = nextNode;
			nextNode = t;
		}
		else {
			nextNode->next = curNode;
			list->startPtr = nextNode;
			curNode = nextNode;
			nextNode = nullptr;
		}

	}

}


bool canSortedIfTwoElementsRemoved(SinglyLinkedList* list) {
	int increases(0);
	int decreases(0);
	int length = list->getLength();
	if (length < 2) {
		return true;
	}
	else {
		Node* p = list->startPtr;
		while (p && p->next) {
			if (p->value >= p->next->value)
				increases++;
			if (p->value <= p->next->value)
				decreases++;
			p = p->next;
		}

		if (length - increases <= 2 || length - decreases <= 2)
			return true;
		else return false;
	}
}


struct Stack {
	Node* startPtr;

	Stack() : startPtr(nullptr) {}

	Stack(Node* p) : startPtr(p) {}

	bool isEmpty() {
		return startPtr == nullptr;
	}

	Node* add(int _val) {
		Node new_ = Node(_val, startPtr);
		startPtr = &new_;
	}

	Node* get() {
		Node* t = startPtr;
		startPtr = startPtr->next;
		return t;
	}

	void print() {
		Node* p = startPtr;
		while (p != nullptr) {
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}

	int getLength() {
		Node* p = startPtr;
		if (isEmpty())
			return 0;
		int k = 1;
		while (p->next != nullptr) {
			p = p->next;
			k++;
		}

		return k;
	}
};


struct DoubleNode {
	int value;
	DoubleNode* next;
	DoubleNode* prev;

	DoubleNode(int _val) : value(_val), next(nullptr), prev(nullptr) {}

	DoubleNode(int _val, DoubleNode* _next, DoubleNode* _prev) : value(_val), next(_next), prev(_prev) {}
};


struct DoubleLinkedList {
	DoubleNode* start;
	DoubleNode* end;

	DoubleLinkedList() : start(nullptr), end(nullptr) {}

	DoubleLinkedList(DoubleNode* ptr) : start(ptr), end(ptr) {}

	bool isEmpty() {
		return start == nullptr;
	}

	void append(int _val) {
		DoubleNode* p = new DoubleNode(_val, nullptr, end);
		if (isEmpty()) {
			start = p;
			end = p;
		}
		else {
			end->next = p;
			end = p;
		}
	}

	void print() {
		DoubleNode* p = start;
		while (p != nullptr) {
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}

	void remove(int _val) {
		if (isEmpty())
			return;
		DoubleNode* p = start;
		if (p->value == _val) {
			start = p->next;
			delete p;
			return;
		}
		while (p && p->next && p->next->value != _val) {
			p = p->next;
		}
		if (p->next == nullptr)
			return;
		else {
			DoubleNode* p1 = p->next->next;
			delete p->next;
			p->next = p1;
		}
	}

	DoubleNode* get(int ind) {
		DoubleNode* p = start;
		for (int i = 0; i < ind; i++) {
			p = p->next;
			if (p == nullptr)
				return p;
		}
		return p;
	}
};


DoubleLinkedList createDoubleList() {
	DoubleLinkedList list = DoubleLinkedList{};
	cout << "Input number of elements" << endl;
	int length;
	cin >> length;
	if (length > 0) {
		cout << "Input elements" << endl;
		int n;
		cin >> n;
		list.append(n);
		for (int i = 1; i < length; i++) {
			cin >> n;
			list.append(n);
		}
	}

	return list;
}


int main() {
	DoubleLinkedList list = createDoubleList();

	list.print();
	list.append(1000);
	list.print();
	list.remove(1000);
	list.print();

	return 0;
}
