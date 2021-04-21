class Node{
public:
    vector<Node*> next = vector<Node*>(26);
    bool isend = false;
};

class WordDictionary {
public:

    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    void addWord(string word) {
        Node* tmp = root;
        for( char c : word){
            if(tmp->next[c-'a'] == NULL){
                tmp->next[c-'a'] = new Node();
            }
            tmp = tmp->next[c-'a'];
        }
        tmp->isend = true;
    }
    
    bool search(string word) {
        if(word.size() == 0) return true;
        Node* tmp = root;
        for(int i = 0; i < word.size(); i++){
            if(word[i] == '.') {
                bool ret = false;
                for(int j = 0; j < 26;j++){
                    word[i] = 'a'+j;
                    ret |=  search(word);
                }
                return ret;
            }
            if(tmp->next[word[i]-'a'] == NULL){
                return false;
            }
            tmp = tmp->next[word[i]-'a'];
        }
        return tmp->isend? true : false;
    }


private:
    Node* root = new Node();
 
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */