#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(void) {
    int N, M, temp_0;
    cin >> N >> M;
    vector<vector<int>>arr(N + 1);
    vector<int>check(N + 1);
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        int idxx = -1;
        while (temp--) {
            cin >> temp_0;
            if (idxx != -1) {
                arr[idxx].push_back(temp_0);
                check[temp_0] += 1;
            }
            idxx = temp_0;
        }
    }
    deque<int>result;
    deque<int>q;
    for (int i = 1; i < N + 1; i++) {
        if (check[i] == 0) {
            result.push_back(i);
            q.push_back(i);
        }
    }
    while (!q.empty()) {
        int idx = q.front();
        q.pop_front();
        for (auto i : arr[idx]) {
            check[i] -= 1;
            if (check[i] == 0) {
                result.push_back(i);
                q.push_back(i);
            }
        }
    }
    if (result.size() == N) {
        while (!result.empty()) {
            int idx = result.front();
            result.pop_front();
            cout << idx << "\n";
        }
    }
    else {
        cout << 0;
    }

    return 0;
}
