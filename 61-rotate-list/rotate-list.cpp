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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || k==0 || !head->next) return head;

        ListNode*last=head;
        int length=1;
        while(last->next)
        {
            last=last->next;
            length++;
        }

        k=k%length;
        if(k==0) return head;

        ListNode * dummy=head;

        for(int i=0;i<length-k-1;i++)
        {
            dummy=dummy->next;
        }

        ListNode*newHead=dummy->next;
        dummy->next=NULL;
        last->next=head;

        return newHead;
    

    }
};