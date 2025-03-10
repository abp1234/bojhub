#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    
    vector<int> days(n,0);
    
    for(int i = 0; i< n; i++){
        int remain = 100-progresses[i];
        int d = (remain+speeds[i]-1)/speeds[i];
        days[i]=d;
    }
    
    int cur = days[0];
    int cnt = 1;
    
    for(int i =1;i<n;i++){
        if(days[i]<=cur){
            cnt++;
        }else{
            answer.push_back(cnt);
            cnt=1;
            cur=days[i];
        }
    }
    
    answer.push_back(cnt);
    
    return answer;
}