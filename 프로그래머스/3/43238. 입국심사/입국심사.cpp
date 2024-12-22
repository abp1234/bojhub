#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = *max_element(times.begin(), times.end()) * (long long)n;
    long long answer = right;
    
    while(left <= right){
        long long mid = (left+right)/2;
        long long peopleProcessed = 0;
        
        for(int time : times){
            peopleProcessed += mid/ time;
            if(peopleProcessed >= n) break;
        }
        
        if(peopleProcessed >=n){
            answer = mid;
            right = mid - 1;
        }else{
            left =mid+1;
        }
    }

    return answer;
}