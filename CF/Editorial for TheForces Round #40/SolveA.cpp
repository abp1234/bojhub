#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        for (int i = n + 1; i <= 2 * n; i++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
