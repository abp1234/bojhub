#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    set<int> uniqueTypes(nums.begin(),nums.end());
    
    int allowed = nums.size()/2;
    
    return min((int)uniqueTypes.size(),allowed);
    
}