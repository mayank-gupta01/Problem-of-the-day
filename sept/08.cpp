/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;

        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }

        int avg = (len/k), rem = len%k;

        temp = head;
        while(k--){
            int number=avg;
            if(rem){
                number++;
                rem--;
            }

            if(number){
                ans.push_back(temp);
                ListNode* prev = temp;
                while(temp && number--){
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = NULL;
            }
            else{
                ans.push_back(NULL);
            }
        }

        return ans;
    }
};