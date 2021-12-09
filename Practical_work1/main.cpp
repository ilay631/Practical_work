#include <iostream>
#include <vector>
using namespace std;


struct QNode {
	int val;
	int prior;
	QNode* next;

	QNode(int _val, int _prior) : val(_val), prior(_prior), next(nullptr) {}

	QNode(int _val, int _prior, QNode* p) : val(_val), prior(_prior), next(p) {}
};


struct PQueue {
	QNode* start = nullptr;

	void queue_push(int val, int prior) {
		if (start == nullptr) {
			start = new QNode(val, prior);
		}
		else {
			QNode* cur = start;
			bool fl = false;
			while (cur->next) {
				if (cur->next->prior > prior) {
					QNode* t = new QNode(val, prior, cur->next);
					cur->next = t;
					fl = true;
					break;
				}
				cur = cur->next;
			}
			if (!fl) {
				QNode* cur = start;
				while (cur->next) {
					cur = cur->next;
				}
				QNode* t = new QNode(val, prior);
				cur->next = t;
			}
		}
	}

	void print() {
		QNode* cur = start;
		while (cur) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};


struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int _value) : value(_value), left(nullptr), right(nullptr) {}

	bool has(int _value) {
		if (value > _value)
			return left != nullptr && left->has(_value);
		else if (value < _value)
			return right != nullptr && right->has(_value);
		return true;
	}

	bool insert(int _value) {
		if (value < _value) {
			if (right == nullptr) {
				right = new	TreeNode(_value);
				return true;
			}
			return right->insert(_value);
		}
		else if (value > _value) {
			if (left == nullptr) {
				left = new TreeNode(_value);
				return true;
			}
			return left->insert(_value);
		}
		return false;
	}

	bool remove(int _value, TreeNode* parent) {
		if (value < _value)
			return right != nullptr && right->remove(_value, this);
		else if (value > _value)
			return left != nullptr && left->remove(_value, this);

		if (left == nullptr && right == nullptr) {
			if (parent->value > value)
				parent->left = nullptr;
			else
				parent->right = nullptr;
			delete this;
			return true;
		}
		else if (left == nullptr || right == nullptr) {
			TreeNode* child;
			if (!left)
				child = right;
			else child = left;

			if (parent->value > value)
				parent->left = child;
			else
				parent->right = child;
			delete this;
			return true;
		}
		else {
			if (right->left == nullptr) {
				right->left = left;
				if (parent->value > value)
					parent->left = right;
				else
					parent->right = right;
				delete this;
				return true;
			}
			else {
				TreeNode* curNode = right;
				TreeNode* curPar = this;
				while (curNode->left) {
					curPar = curNode;
					curNode = curNode->left;
				}
				value = curNode->value;
				curNode->remove(curNode->value, curPar);
				return true;
			}
		}
		return false;
	}

	int height() {
		if (left == nullptr && right == nullptr)
			return 1;
		
		if (left == nullptr || right == nullptr) {
			if (left)
				return left->height() + 1;
			else return right->height() + 1;
		}

		return max(left->height(), right->height()) + 1;
	}

	void NLR() { // Прямой
		cout << value << " ";
		if (left) left->NLR();
		if (right) right->NLR();
	}

	void LNR() { // Поперечный
		if (left) left->NLR();
		cout << value << " ";
		if (right) right->NLR();
	}

	void LRN() { // Обратный
		if (left) left->NLR();
		if (right) right->NLR();
		cout << value << " ";
	}

	void BFS(PQueue* q, int h = 0) {
		q->queue_push(value, h);
		if (left) left->BFS(q, h + 1);
		if (right) right->BFS(q, h + 1);
	}
};


struct BinaryTree {
	int size;
	TreeNode* root;

	BinaryTree() : size(0), root(nullptr) {}

	bool isEmpty() {
		return root == nullptr;
	}

	bool has(int _value) {
		return !isEmpty() && root->has(_value);
	}

	bool insert(int _value) {
		if (!isEmpty()) {
			if (root->insert(_value)) {
				size++;
				return true;
			}
			return false;
		}
		root = new TreeNode(_value);
		size++;
		return true;
	}

	bool remove(int _value) {
		if (root->value == _value) {
			// Удалить корень и полностью пересобрать дерево
		}
		else return !isEmpty() && root->remove(_value, nullptr);
	}

	int height() {
		if (isEmpty())
			return 0;
		else return root->height();
	}

	void NLR() { // Прямой
		root->NLR();
		cout << endl;
	}

	void LNR() { // Поперечный
		root->LNR();
		cout << endl;
	}

	void LRN() { // Обратный
		root->LRN();
		cout << endl;
	}

	void BFS() {
		PQueue* q = new PQueue();
		if (!isEmpty()) {
			root->BFS(q);
		}
		q->print();
	}
};


int main() {
	BinaryTree tree = BinaryTree();
	for (int i = 0; i < 10; i++) {
		int m;
		cin >> m;
		tree.insert(m);
	}
	tree.BFS();

	return 0;
}