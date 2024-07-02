#include <iostream>
#include <set>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int G, P, temp;
	cin >> G >> P;
	int cnt=0;
	multiset<int>search;
	for (int i = 0; i < G; i++) {
		search.insert(i+1);
	}
	for (int i = 0; i < G; i++) {
		cin >> temp;
		auto idx=search.upper_bound(temp);
		int j = 0;
		if (idx == search.begin()) {
			break;
		}
			
		else {
			search.erase(--idx);
			cnt++;
		}
	}
	cout << cnt ;
	return 0;
}