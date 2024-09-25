class TrieNode{
    public:
        TrieNode* children[26] = {};
        int cnt = 0;
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string str){
        TrieNode* node = root;
        for(auto it: str){
            int idx = it - 'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node->children[idx]->cnt = node->children[idx]->cnt + 1;
            node = node->children[idx];
        }
    }

    int findPrefix(string str){
        int res = 0;
        TrieNode* node = root;
        for(auto it: str){
            int idx = it - 'a';
            res += node->children[idx]->cnt;

            node = node->children[idx];
        }

        return res;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int>ans(n,1);
        Trie trie;
        for(auto word: words){
            trie.insert(word);
        }
        
        for(int i=0;i<n;i++){
            int res = trie.findPrefix(words[i]);
            ans[i] = res;
        }
        return ans;
    }
};