#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto it: nums){
            st.insert(it);
        }

        //skip head which are present in st
        ListNode* temp = head;
        while(temp!=NULL && st.find(temp->val) != st.end()){
            temp = temp->next;
        }

        if(!temp) return NULL;
        head = temp;

        //remove mid and tail elements
        ListNode* prev;
        while(temp!= NULL){

            if(st.find(temp->val) != st.end()){
                prev->next = temp->next;
            }else{
                prev = temp;
            }

            temp = temp->next;
        }

        return head;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();