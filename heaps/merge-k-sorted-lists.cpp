/*Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    vector<int> v;
    for(ListNode* ptr: A) {
        while(ptr != NULL) {
            v.push_back(ptr -> val);
            ptr = ptr -> next;
        }
    }
    sort(v.begin(),v.end());
    
    ListNode* ans=NULL;// = head;
    ListNode* head=new ListNode(0);
    for(int i: v) {
        ListNode* n = new ListNode(i);
        if(ans==NULL){
            ans=n;
        }
        head -> next = n;
        head = n;
    }
    return ans;
}