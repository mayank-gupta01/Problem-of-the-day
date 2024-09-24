class TrieNode{
    public:
        TrieNode* children[10];

        TrieNode() {
            for(int i=0;i<10;i++){
                children[i] = NULL;
            }
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode();
        }

        void insert(int num){
            TrieNode* node = root;
            string str = to_string(num);
            
            for(auto digit: str){
                int idx = digit - '0';
                if(!node->children[idx]){
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
        }

        int lenOfPrefix(int num){
            TrieNode* node = root;
            int len = 0;
            string str = to_string(num);

            for(auto digit : str){
                int idx = digit-'0';
                if(node->children[idx]){
                    len++;
                    node = node->children[idx];
                }
                else break;
            }

            return len;
        }

};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        int ans = 0;
        for(auto it: arr1){
            trie.insert(it);
        }

        for(auto it: arr2){
            int res = trie.lenOfPrefix(it);
            ans = max(ans, res);
        }

        return ans;
    }
};