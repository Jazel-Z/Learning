class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        checkIfExist1(arr);
        int size = arr.size();
        
        for(int i = 0; i <size; ++i){
            for(int j = 0; j < size; ++j){
                if(arr[i] == 2 * arr[j]){
                    if(i == j) continue;
                    return true;
                }
            }
        }
        
        return false;
    }
    
    
    bool checkIfExist1(vector<int>& arr){
        int size = arr.size();
        std::unordered_set<int> us;
        us.reserve(500);
        us.insert(arr[0]*2);
        
        for(int i = 0; i < size; ++i){
            if(us.find(arr[i]) != us.end() || us.find(arr[i] * 4) != us.end()) return true;
            us.insert(arr[i] * 2);
        }
        return false;
    }
    
};
