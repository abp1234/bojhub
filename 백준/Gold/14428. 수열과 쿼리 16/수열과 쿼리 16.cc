#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();
int n, m;
vector<long long> arr;
vector<tuple<long long, int>> segtree;

void init() {
    // Initialize leaf nodes
    for (int i = 0; i < n; i++) {
        segtree[n + i] = make_tuple(arr[i], i);
    }
    // Build the tree
    for (int i = n - 1; i >= 1; i--) {
        if (get<0>(segtree[i << 1]) < get<0>(segtree[i << 1 | 1])) {
            segtree[i] = segtree[i << 1];
        } else if (get<0>(segtree[i << 1]) > get<0>(segtree[i << 1 | 1])) {
            segtree[i] = segtree[i << 1 | 1];
        } else { // If values are equal, choose the one with the smaller index
            segtree[i] = get<1>(segtree[i << 1]) < get<1>(segtree[i << 1 | 1]) ? segtree[i << 1] : segtree[i << 1 | 1];
        }
    }
}

void update(int idx, long long x) {
    // Update the value at index `idx`
    segtree[idx + n] = make_tuple(x, idx);
    idx = (idx + n) >> 1;
    while (idx >= 1) {
        if (get<0>(segtree[idx << 1]) < get<0>(segtree[idx << 1 | 1])) {
            segtree[idx] = segtree[idx << 1];
        } else if (get<0>(segtree[idx << 1]) > get<0>(segtree[idx << 1 | 1])) {
            segtree[idx] = segtree[idx << 1 | 1];
        } else { // If values are equal, choose the one with the smaller index
            segtree[idx] = get<1>(segtree[idx << 1]) < get<1>(segtree[idx << 1 | 1]) ? segtree[idx << 1] : segtree[idx << 1 | 1];
        }
        idx >>= 1;
    }
}

pair<int, long long> find_x(int l, int r) {
    l += n;
    r += n;
    int result_idx = INF;
    long long result_min = INF;
    while (l <= r) {
        if (l & 1) {
            if (result_min > get<0>(segtree[l])) {
                result_min = get<0>(segtree[l]);
                result_idx = get<1>(segtree[l]);
            } else if (result_min == get<0>(segtree[l])) { // If minimums are equal, choose the smaller index
                result_idx = min(result_idx, get<1>(segtree[l]));
            }
            l++;
        }
        if (!(r & 1)) {
            if (result_min > get<0>(segtree[r])) {
                result_min = get<0>(segtree[r]);
                result_idx = get<1>(segtree[r]);
            } else if (result_min == get<0>(segtree[r])) { // If minimums are equal, choose the smaller index
                result_idx = min(result_idx, get<1>(segtree[r]));
            }
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return make_pair(result_idx, result_min);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.resize(n);
    segtree.resize(2 * n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init();

    cin >> m;
    int a, b;
    long long c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, c);
        } else {
            pair<int, long long> result = find_x(b - 1, c - 1);
            cout << result.first + 1 << '\n'; // Convert 0-based index to 1-based index
        }
    }
    return 0;
}
