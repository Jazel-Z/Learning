class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int one = 0,flips = 0;
        int size = S.size();
        
        for(int i = 0; i < size; ++i){
            if(S[i] == '1'){
                one++;
            }else{
                flips++;
            }
            
            flips = min(flips,one);
        }
        
        return flips;
    }
};
