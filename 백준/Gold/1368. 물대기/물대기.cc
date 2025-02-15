#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include<iostream>
#include <functional>

using namespace std;

struct ED {
	int c;
	int v;
	ED(int _c, int _v):c(_c),v(_v){}
};

struct CP {
	bool operator()(const ED* a, const ED* b) const {
		return a->c > b->c;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	bool* vs = new bool[n + 1];
	memset(vs, 0, sizeof(bool) * (n + 1));

	vector<ED*>* gr = new vector<ED*>[n + 1];

	priority_queue<ED*, vector<ED*>, CP>pq;

	for (int i = 1; i <= n; i++) {
		int cc;
		cin >> cc;
		pq.push(new ED(cc, i));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cc;
			cin >> cc;
			if (i != j) {
				gr[i].push_back(new ED(cc, j));
			}
		}
	}

	long long an = 0;
	int ct = 0;

	ED* cur = pq.top();
	pq.pop();
	vs[cur->v] = true;
	an += cur->c;
	int u = cur->v;
	for (auto& ed : gr[u]) {
		pq.push(ed);
	}

	delete cur;

	while (!pq.empty() && ct < n - 1) {
		cur = pq.top();
		pq.pop();
		if (!vs[cur->v]) {
			vs[cur->v] = true;
			an += cur->c;
			ct++;
			u = cur->v;
			for (auto& ed : gr[u]) {
				if (!vs[ed->v]) {
					pq.push(ed);
				}
			}
		}
	}
	cout << an << "\n";
	for (int i = 1; i <= n; i++) {
		for (auto& ed : gr[i]) {
			delete ed;
		}
	}
	delete[]gr;
	delete[]vs;
	return 0;
}