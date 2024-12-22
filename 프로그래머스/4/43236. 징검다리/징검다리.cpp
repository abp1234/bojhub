#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    
    sort(rocks.begin(),rocks.end());
    rocks.push_back(distance);
    
    int low = 1;
    int high = distance;
    int answer = 0;
    
    while(low<=high){
        int mid = (low+high)/2;
        int prev = 0;
        int removeCount = 0;
        
        for(int rock : rocks){
            if(rock - prev < mid){
                removeCount++;
            }else{
                prev = rock;
            }
        }
        
        if(removeCount<=n){
            answer = mid;
            low = mid+1;
        }else{
            high =mid-1;
        }
    }
    
    return answer;
}