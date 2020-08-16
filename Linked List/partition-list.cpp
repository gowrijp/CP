/*
https://www.interviewbit.com/problems/partition-list/

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if(A==nullptr || A->next==nullptr)
        return A;
    vector<int> v1,v2;
    auto curr=A;
    while(curr!=nullptr){
        if(curr->val < B)
            v1.push_back(curr->val);
        else
            v2.push_back(curr->val);
        curr=curr->next;
    }
    curr=A;
    for(int i=0;i<v1.size();i++){
        curr->val=v1[i]; curr=curr->next;
    }
    for(int i=0;i<v2.size();i++){
        curr->val=v2[i]; curr=curr->next;
    }
    return A;
}
