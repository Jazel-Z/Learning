class Solution {
public:
    
    vector<string> val = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        helper(digits,0,"");
        return ans;
    }

    void helper(string digits, int num, string tar){
        if(num == digits.size()) { ans.push_back(tar);  return ;}

        for(int i = 0; i < val[digits[num]-'2'].size(); i++){
            helper(digits, num+1, tar+val[digits[num]-'2'][i]);
        }

    }

};