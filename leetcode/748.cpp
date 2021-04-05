class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        char tar[7];
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < licensePlate.size(); i++){
            if(licensePlate[i] >= 'a' && licensePlate[i] <= 'z'){
                tar[cnt++] = licensePlate[i];
            }

            if(licensePlate[i] >= 'A' && licensePlate[i] <= 'Z'){
                tar[cnt++] = licensePlate[i] +32;
            }
        }
        int minlen = 20;
        for(int i = 0; i < words.size(); i++){
            vector<bool> used(15,false);
            bool found = true;
            for(int j = 0; j < cnt; j++){
                for(int k =0; k < words[i].size(); k++){
                    if(tar[j] == words[i][k]){
                        if(used[k]) {
                            if(k == words[i].size()-1) found = false;
                            continue;
                        }
                        else used[k] = true;
                        break;
                    }else{
                        if(k == words[i].size()-1)
                        found = false;
                    }
                }
            }

            if(found && minlen > words[i].size()){
                minlen = words[i].size();
                ans = i;
            }
        }



        return words[ans];
    }
};
