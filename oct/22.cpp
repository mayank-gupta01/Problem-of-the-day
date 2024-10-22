/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>sums;
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            for(int i=0;i<size;i++){
                auto temp = q.front();
                q.pop();

                sum += temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            sums.push_back(sum);
        }

        sort(sums.begin(), sums.end());
        int n = sums.size();
        if(n < k) return -1;
        return sums[n-k];
    }
};