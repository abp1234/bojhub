#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
   vector<int>ans;
    
    if(arr.empty()) return ans;
    
    ans.push_back(arr[0]);
    
    for(size_t i = 1; i < arr.size();i++){
        if(arr[i]!=arr[i-1]){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
