#include <iostream>
#include <vector>
using namespace std;


struct HashTable {
	int tableSize;
	int length = 0;
	vector <vector <int>> table;

	HashTable(int size) : tableSize(size), table(size) {}

	int myHash(int num) {
		return num % tableSize;
	}

	bool empty() {
		return length == 0;
	}

	int size() {
		return length;
	}

	void add(int num) {
		int key = myHash(num);
		table[key].push_back(num);
		length++;
	}

	void del(int num) {
		int key = myHash(num);
		auto iter = table[key].cbegin();
		for (int i = 0; i < table[key].size(); i++) {
			if (table[key][i] == num) {
				length--;
				table[key].erase(iter + i);
				break;
			}
		}
	}
	 
	bool find(int num) {
		int key = myHash(num);
		for (int n : table[key]) {
			if (n == num)
				return true;
		}
		return false;
	}

	int count(int num) {
		int key = myHash(num);
		int k(0);
		for (int n : table[key]) {
			if (n == num)
				k++;
		}
		return k;
	}

	void print() {
		for (int i = 0; i < tableSize; i++) {
			for (int n : table[i]) {
				cout << n << " ";
			}
		}
	}
};


HashTable createTable() {
	int size;
	cout << "Input table size ";
	cin >> size;
	HashTable table = HashTable(size);
	int n;
	cout << "Input number of elements ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		table.add(num);
	}
	return table;
}


int main() {

}
