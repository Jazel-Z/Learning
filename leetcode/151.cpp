class Solution {
public:
    string reverseWords(string s) {
        vector<string> tmp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                bool found = false;
                for(int j = i+1; j < s.size();j++){
                    if(s[j] == ' '){
                        found = true;
                        tmp.push_back(s.substr(i,j-i));
                        i=j;
                        break;
                    }
                }

                if(!found){
                    tmp.push_back(s.substr(i,s.size()-i));
                    i=s.size();
                }
            }
        }

        string ans = tmp[tmp.size()-1];
        for(int i =  tmp.size()-2; i > -1; i--){
            ans += " ";
            ans += tmp[i];
        }

        return ans;
    }
};