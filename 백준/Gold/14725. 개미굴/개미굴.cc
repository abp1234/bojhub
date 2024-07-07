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



/*
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct TrieNode {
	map<string, TrieNode*> children;
	bool isEndOfWord;

	TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
	TrieNode* root;

public:
	Trie() {
		root = new TrieNode();
	}

	~Trie() {
		deleteTrie(root);
	}

	void insert(vector<string>& words) {
		TrieNode* current = root;
		for (const string& word : words) {
			if (current->children.find(word) == current->children.end()) {
				current->children[word] = new TrieNode();
			}
			current = current->children[word];
		}
		current->isEndOfWord = true;
	}

	void deleteTrie(TrieNode* node) {
		for (auto& child : node->children) {
			deleteTrie(child.second);
		}
		delete node;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, k;
	string str;
	cin >> N;

	Trie trie;
	for (int i = 0; i < N; i++) {
		cin >> k;
		vector<string> words;
		for (int j = 0; j < k; j++) {
			cin >> str;
			words.push_back(str);
		}
		trie.insert(words);
	}

	return 0;
}

struct Trie {
	bool finish;
	Trie* next[26];

	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0')
			finish = true;
		else {
			int curr = *key - 'A';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}

	Trie* find(const char* key) {
		if (*key == '\0')return this;
		int curr = *key - 'A';
		if (next[curr] == NULL)return NULL;
		return next[curr]->find(key + 1);
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, k;
	string str;
	cin >> N;

	Trie* root = new Trie();
	for (int i = 0; i < N; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> str;
			root->insert(str.c_str());
		}
	}

	delete root;
	return 0;
}*/
