class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* nodenext=NULL;
        ListNode* prevnode = NULL;
        int count=0;
        while(curr!=NULL && count<k){
            nodenext = curr->next;
            curr->next = prevnode;
            prevnode = curr;
            curr = nodenext;
            count++;
        }
        if(count!=k){
            ListNode* t = prevnode;
            prevnode = NULL;
            while(t!=NULL){
                nodenext = t->next;
                t->next = prevnode;
                prevnode = t;
                t = nodenext;
            }
            return prevnode;
        }
        if(nodenext!=NULL){
            ListNode* rest_head = reverseKGroup(nodenext , k);
            head->next = rest_head;
        }
        return prevnode;
    }
};