#include <iostream>
#include <deque>
#include<tuple>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N, temp;
	cin >> N;
	deque<tuple<long long,long long>>arr;
	cin >> temp;
	arr.push_back(make_tuple(temp,0));
	long long cnt = 0;
	long long H, num;
	for (int i = 1; i < N; i++) {
		cin >> temp;
		int flag = 0;
		while (1) {
			num = 1;
			H = 0;
			if (!arr.empty()) {
				tie(H,num) = arr.back();
				if (H < 0) {
					flag = 1;
					H *= -1;
				}
			}
				
			if (!arr.empty() && temp > H) {
				arr.pop_back();
				cnt++;
			}
			else if (arr.empty() || temp < H) {
				num = 0;
				if (!arr.empty()) {
					cnt++;
					num = 1;
				}
				arr.push_back(make_tuple(temp,num));
				break;
			}
			else if (H == temp) {
				//if(flag==1)
				cnt += num;
				cnt++;
				arr.push_back(make_tuple( - temp,num+1));
				break;
			}
			
		}
	}
	cout << cnt;

	return 0;
}