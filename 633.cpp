class Solution {
public:
    bool judgeSquareSum(int c) {
        int max = (int)sqrt(c)+1;
        bool ans = false;
        for(int i =0; i < max; i++){
            int tmp = (int)sqrt(c-i*i);
            if(c == (i*i + tmp*tmp)) ans = true;
        }
        
        return ans;
    }
};
