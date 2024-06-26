#include <iostream>
#include <vector>
#include <tuple>
#include<algorithm>
#include <queue>
#include<limits>
using namespace std;
const int INF = numeric_limits<int>::max();
vector<int>cost_target;
int boss(int A) {
	if (cost_target[A] != A) 
		cost_target[A] = boss(cost_target[A]);
	return cost_target[A];

}
int union0(int A, int B) {
	int left = boss(A);
	int right = boss(B);
	if (left != right) {
		cost_target[right] = left;
		
		return 1;
	}
	else {
		return 0;
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int A, B, C;
	vector<tuple<int,int,int>>arr;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		arr.emplace_back(C,A - 1, B-1); 
	}
	sort(arr.begin(),arr.begin()+M);
	int result = 0;
	int cost, start, end;
	cost_target.resize(N);
	
	for (int i = 0; i < N; i++) {
		cost_target[i] = i;
	}
	if (N != 2) {
		for (int i = 0; i < M; i++) {
			tie(cost, start, end) = arr[i];
			if (union0(start, end) == 1) {
				result += cost;
				vector<int>check;
				check.push_back(boss(cost_target[0]));
				int flag = 1;
				for (int j = 1; j < N; j++) {
					int temp = boss(cost_target[j]);
					if (check.size() == 1 && check[0] != temp) {
						check.push_back(temp);
					}
					else if (temp != check[0] && temp != check[1]) {
						flag = 0;
						break;
					}
				}
				if (flag == 1)break;
			}
		}
	}
	
	
	
	cout << result;
	return 0;
}