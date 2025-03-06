#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int N = info.size();
    int threshA = n;
    int threshB = m;
    
    vector<vector<bool>> dp(threshA, vector<bool>(threshB, false));
    dp[0][0]=true;
    
    for(int i = 0; i < N; i++){
        vector<vector<bool>> newdp(threshA, vector<bool>(threshB,false));
        for(int a = 0; a< threshA;a++){
            for(int b = 0; b < threshB; b++){
                if(dp[a][b]){
                    int na = a + info[i][0];
                    int nb = b;
                    if(na<threshA){
                        newdp[na][nb]=true;
                    }
                    na = a;
                    nb = b + info[i][1];
                    if(nb<threshB){
                        newdp[na][nb]=true;
                    }
                }
            }
        }
        dp=move(newdp);
    }
   answer = numeric_limits<int>::max();
    for (int a = 0; a < threshA; a++) {
        for (int b = 0; b < threshB; b++) {
            if (dp[a][b]) {
                answer = min(answer, a);
            }
        }
    }
    
    return (answer == numeric_limits<int>::max()) ? -1 : answer;
}