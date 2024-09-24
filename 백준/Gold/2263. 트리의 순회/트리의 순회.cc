#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Tree {
	int* ino;
	int* post;
	unordered_map<int, int> pos;

	void pre(int is, int ie, int ps, int pe) {
		if (is > ie || ps > pe) return;

		int root = post[pe];
		cout << root << " ";

		int l = pos[root] - is;
		int r = ie - pos[root];

		pre(is, is + l - 1, ps, ps + l - 1);
		pre(pos[root] + 1, ie, ps + l, pe - 1);
	}
};

int main() {
	int n;
	cin >> n;

	Tree tree;

	tree.ino = new int[n];
	tree.post = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> tree.ino[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> tree.post[i];
	}

	for (int i = 0; i < n; i++) {
		tree.pos[tree.ino[i]] = i;
	}

	tree.pre(0, n - 1, 0, n - 1);

	delete[] tree.ino;
	delete[] tree.post;

	return 0;
}