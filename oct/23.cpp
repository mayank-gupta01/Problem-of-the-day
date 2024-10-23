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
    void findLevelSum(TreeNode* root, vector<long long>&sums){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            for(int i=0;i<size;i++){
                auto temp = q.front();
                q.pop();

                sum+=temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            sums.push_back(sum);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<long long>sums;
        findLevelSum(root, sums);

        // for(int i=0;i<sums.size();i++){
        //     cout<<sums[i]<<endl;
        // }

        queue<pair<TreeNode*, int>>q;
        q.push({root, root->val});
        int level = 0;
        while(!q.empty()){
            int size =  q.size();
            //  cout<<"size: "<<size<<endl;
            
            for(int i=0;i<size;i++){
                auto temp = q.front();
                q.pop();

                TreeNode* node = temp.first;

                // cout<<"sums[level] "<<sums[level]<<", temp.second "<<temp.second<<endl;
                node->val = sums[level] - temp.second;
                //childrens
                int childSum = 0;
                if(node->left) childSum += node->left->val;
                if(node->right) childSum += node->right->val;
                // cout<<"childSum "<<childSum<<endl;

                if(node->left) q.push({node->left, childSum});
                if(node->right) q.push({node->right, childSum});

                
            }
            level++;
        }

        return root;
    }
};