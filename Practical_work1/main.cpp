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
		return !isEmpty() && root->remove(_value, root);
	}
};


int main() {

	return 0;
}