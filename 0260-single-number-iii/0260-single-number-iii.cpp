// Practice
class Solution {
    
public:
    vector<int> singleNumber(vector<int>& nums) {
        const long long xors = accumulate(nums.begin(),nums.end(),0,bit_xor<>());
        const long long lowbit = xors & -xors;
        vector<int> ans(2);

        for(const int num : nums)
        {
            if(num& lowbit)
            {
                ans[0]^=num;
            }else{
                ans[1]^=num;
            }
        }
        return ans;
    }
};