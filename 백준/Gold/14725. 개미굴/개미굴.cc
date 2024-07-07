#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct MapNode;
using MapTree = map<string, MapNode>;
struct MapNode {
	MapTree children;
};

void printTree(const MapTree& tree, int depth = 0) {
	vector<string> keys;
	for (const auto& pair : tree) {
		keys.push_back(pair.first);
	}
	sort(keys.begin(), keys.end());

	for (const auto& key : keys) {
		cout << string(depth * 2, '-') << key << endl;
		printTree(tree.at(key).children, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	MapTree TrieMap;

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		MapTree* currentMapPtr = &TrieMap;

		for (int j = 0; j < k; j++) {
			string str;
			cin >> str;

			if (currentMapPtr->find(str) == currentMapPtr->end()) {
				(*currentMapPtr)[str] = MapNode();
			}

			currentMapPtr = &((*currentMapPtr)[str].children);
		}
	}

	printTree(TrieMap);

	return 0;
}
