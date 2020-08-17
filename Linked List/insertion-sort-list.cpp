/*
https://www.interviewbit.com/problems/insertion-sort-list/

Sort a linked list using insertion sort.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A){
    vector<ListNode*> store;
    store.push_back(A);
    ListNode* iter=A->next;
    ListNode* prev=A;
    while(iter!=NULL){
        if(iter->val>=prev->val){
            store.push_back(iter);
            prev=iter;
            iter=iter->next;
        }
        else if(iter->val){
            int key=iter->val;
            for(int i=store.size()-1; i>=0; i--){
                if(store[i]->val<=key) break;
                else if(store[i]->val>key){
                    int k=store[i]->val;
                    store[i]->val=key;
                    store[i]->next->val=k;
                }
            }
            store.push_back(iter);
            prev=iter;
            iter=iter->next;
        }
    }
    return A;
}
