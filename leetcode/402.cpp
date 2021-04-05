class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int size = num.size();
        for(int i = 0; i < size; ++i){
            while(ans.size() > 0 && k > 0 && ans.back() > num[i]){
                ans.pop_back();
                k--;
            }
            if(ans.size() > 0 || num[i] != '0'){
                ans.push_back(num[i]);
            }
        }
        
        while(k > 0 && ans.size() > 0){
            ans.pop_back();
            k--;
        }
        
        return ans.size() == 0 ? "0" : ans;
    }
};
