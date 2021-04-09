class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        list<int> ans;
        vector<int> ret;
        sort(deck.begin(), deck.end());

        int size = deck.size();
        ans.push_back(deck[size-1]);
        for(int i  = size -2; i >= 0; i--){
            auto it = ans.end();
            it--;
            ans.push_front(*it);
            ans.pop_back();
            ans.push_front(deck[i]);
        }
        for( int el : ans){
            ret.push_back(el);
        }

        return ret;
    }
    
};
