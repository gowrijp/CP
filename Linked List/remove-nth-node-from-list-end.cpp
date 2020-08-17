/*
https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* temp=A;
    int sa=0;
    while(temp){
        sa++;
        temp=temp->next;
    }
    int ch=sa-B+1;
    if(B==1 and sa==1){
        A=nullptr;
        return A;
    }
    if(ch==1){
        A=A->next;
        return A;
    }
    
    temp=A;
    if(B>sa){
        A=A->next;
        return A;
    }
    sa=0;
    while(temp){
        sa++;
        if(sa+1==ch){
            temp->next=temp->next->next;
            break;
        }
        else{
            temp=temp->next;
        }
    }
    return A;
}
