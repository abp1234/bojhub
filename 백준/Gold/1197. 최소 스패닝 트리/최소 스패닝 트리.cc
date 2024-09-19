#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v, weight;
	bool operator<(const Edge& other) const {
		return weight < other.weight;
	}
};

vector<int> parent;

int get_parent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = get_parent(parent[x]);
}

void union_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool same_parent(int a, int b) {
	return get_parent(a) == get_parent(b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<Edge> edges(E);
	for (int i = 0; i < E; ++i) {
		cin >> edges[i].u >> edges[i].v >> edges[i].weight;
	}

	sort(edges.begin(), edges.end());

	parent.resize(V + 1);
	for (int i = 1; i <= V; ++i) {
		parent[i] = i;
	}

	int answer = 0;
	for (const auto& edge : edges) {
		if (!same_parent(edge.u, edge.v)) {
			union_parent(edge.u, edge.v);
			answer += edge.weight;
		}
	}

	cout << answer << '\n';
	return 0;
}

