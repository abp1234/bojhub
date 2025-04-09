#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int time =0;time<24;time++){
        while(!pq.empty()&&pq.top()<=time){
                pq.pop();
            
        }    

        int required = players[time];
        int nowServer = pq.size();
        int need = required - nowServer*m;

        if (need > 0) {
        
            for (int j = 0; j < need/m; j++) {
                pq.push(time + k);
                answer++;
            }
        }
        
    }
    
    return answer;
}