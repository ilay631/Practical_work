#include <iostream>
using namespace std;

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
};


int main() {
	BinaryTree tree = BinaryTree();
	for (int i = 0; i < 10; i++) {
		int m;
		cin >> m;
		tree.insert(m);
	}
	tree.NLR();
	tree.LNR();
	tree.LRN();
	tree.remove(5);
	tree.NLR();


	return 0;
}