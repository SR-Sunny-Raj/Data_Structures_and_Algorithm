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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1=head,*ptr2=head;
        for(int i=0;i<n;i++){
            ptr1=ptr1->next;
        }
        if(ptr1==NULL){
            head=head->next;
            delete ptr2,ptr1;
        }else{
            while(ptr1->next!=NULL){
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            ListNode *temp=ptr2->next;
            ptr2->next=ptr2->next->next;
            delete temp,ptr2,ptr1;
        }
        return head;
    }
};
