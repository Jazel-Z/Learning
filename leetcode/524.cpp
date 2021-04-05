class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int ans = s.size() + 1;
        int strsize = 0; 
        
        for(int i = 0; i < dictionary.size(); i++){
            int num = 0;
            if(dictionary[i].size() > s.size()) continue;
            
            for(int j = 0; j < s.size(); j++){
                num += s[j] == dictionary[i][num] ? 1 : 0;
            }  
            if(num == dictionary[i].size() && ((dictionary[i].size() > strsize) || ((dictionary[i].size() == strsize) && dictionary[i] < dictionary[ans]))){
                ans = i;
                strsize = dictionary[i].size();
            }
        }
        
        if(ans > s.size()) return "";
        else return dictionary[ans];
        
    }
};
