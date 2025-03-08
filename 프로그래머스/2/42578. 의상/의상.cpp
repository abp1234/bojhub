#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int>categoryCount;
    
    for(const auto&cloth:clothes){
        categoryCount[cloth[1]]++;
    }
    
 
    
    for(auto& p :categoryCount){
        answer *=(p.second+1);
    }
    
    
    return answer-1;
}