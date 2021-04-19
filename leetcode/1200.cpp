class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<pair<int, int>> foo;
        sort(arr.begin(), arr.end());
        for(int i = 0; i <arr.size() -1; i++){
            foo.push_back(make_pair(abs(arr[i] - arr[i+1]), i));
        }
        sort(foo.begin(), foo.end());
        int mini = foo[0].first;
        for(int i =0; i < foo.size(); i++){
            if(foo[i].first == mini){
                ans.push_back({arr[foo[i].second],arr[foo[i].second+1]});
            }else{
                break;
            }
        }

        return ans;
    }  
};