#include <iostream>
#include <vector>
#include <algorithm>
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


struct GNode {
	int id;
	vector<int> adjacents;
	vector<int> weights;
	bool weightsSorted = false;
	vector<vector<int>> edges;

	void sortWeights() {
		weightsSorted = true;
		for (int i = 0; i < weights.size(); i++) {
			for (int j = i + 1; j < weights.size(); j++) {
				if (weights[i] > weights[j]) {
					swap(weights[i], weights[j]);
					swap(adjacents[i], adjacents[j]);
				}
			}
		}
		for (int i = 0; i < adjacents.size(); i++) {
			edges.push_back({ adjacents[i], weights[i] });
		}
	}

	vector<vector<int>>* findMinimumEdge() {
		if (!weightsSorted)
			sortWeights();
		return &edges;
	}

	void addEdge(int adj, int w) {
		adjacents.push_back(adj);
		weights.push_back(w);
	}
};


struct Graph {
	vector<GNode> nodes;
	vector<GNode> tree;
	vector<vector<int>> edges;

	void PrimaAlgorithm() {
		if (!nodes.empty()) {
			tree.push_back(nodes[0]);
			for (int k = 0; k < nodes.size() - 1; k++) {
				int m = pow(2, 31) - 1;
				int sn;
				int fn;
				for (int i = 0; i < tree.size(); i++) {
					vector<vector<int>> edges = *tree[i].findMinimumEdge();
					for (int j = 0; j < edges.size(); j++) {
						int an = edges[j][0];
						int w = edges[j][1];
						if (!findNode(an)) {
							if (w < m) {
								m = w;
								sn = tree[i].id;
								fn = an;
							}
						}
					}
				}
				tree.push_back(*getNode(fn));
				edges.push_back({ sn, fn });
			}
		}
	}

	GNode* getNode(int _id) {
		for (int i = 0; i < nodes.size(); i++) {
			if (nodes[i].id == _id)
				return &nodes[i];
		}
	}

	bool findNode(int _id) {
		for (int i = 0; i < tree.size(); i++) {
			if (tree[i].id == _id)
				return true;
		}
		return false;
	}
};


Graph* createGraph() {
	int k;
	cout << "Input number of nodes" << endl;
	cin >> k;
	Graph* g = new Graph;
	for (int i = 1; i <= k; i++) {
		GNode* n = new GNode;
		n->id = i;
		g->nodes.push_back(*n);
	}
	cout << "Input edges (to finish enter 0 0 0)" << endl;
	int st, en, w;
	while (1) {
		cin >> st >> en >> w;
		if (st == 0 && en == 0 && w == 0)
			break;
		g->getNode(st)->addEdge(en, w);
		g->getNode(en)->addEdge(st, w);
	}
	return g;
}


int main() {
	Graph g = *createGraph();
	g.PrimaAlgorithm();
	for (int i = 0; i < g.edges.size(); i++) {
		cout << g.edges[i][0] << " " << g.edges[i][1] << endl;
	}


	return 0;
}