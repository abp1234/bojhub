#include <iostream>

using namespace std;

const long long MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    
    while(t--){
        long long n, a1, a2;
        cin>>n>>a1>>a2;
        long long r = n%6;
        long long result = 0;
        
        if(r == 1) result =a1;
        else if(r == 2) result =a1+a2;
        else if(r == 3) result = 2 *a2;
        else if(r == 4) result = 2*a2-a1;
        else if(r == 5) result = a2 -a1;
        else if(r == 0) result = 0;
        
        result = (result%MOD+MOD)%MOD;
        cout << result << "\n";
    }
    return 0;
}