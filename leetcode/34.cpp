class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return vector<int>{-1,-1};
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        int lower,upper;
        lower = upper = it - nums.begin();

        if(it != nums.end() && *it == target){
            for(int i = 1; it+i != nums.end(); i ++){
                if(*(it+i) == target){
                    upper++;
                }
            }
        }else return vector<int>{-1,-1};
        return vector<int>{lower, upper};
        
    }
};
