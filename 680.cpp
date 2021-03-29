class Solution {
public:
    bool validPalindrome(string s) {
        int size = s.size();
        int mid = size /2 +1;
        
        for(int i = 0; i < mid; i++){
            if(s[i] != s[size-i-1])
                return ispalindrome(s.substr(i+1, size - 2*i - 1)) || ispalindrome(s.substr(i, size - 2*i - 1));
        }
        
        return true;
    }
    
    
    bool ispalindrome(string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] != s[s.size()-i-1]) return false;
        }
        return true;
    }
};
