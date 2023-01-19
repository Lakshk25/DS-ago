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
    ListNode* merge(ListNode* first , ListNode* second){
        if(first == NULL){
            return second;
        }
        if(second == NULL){
            return first;
        }
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(first != NULL && second != NULL){
            if(first -> val < second -> val){
                temp -> next = first;
                temp = first;
                first = first -> next;
            }
            else{
                temp -> next = second;
                temp = second;
                second = second -> next;
            }
        }
        while(first != NULL){
            temp -> next = first;
            temp = first;
            first = first -> next;
        }
        while(second != NULL){
           temp -> next = second;
            temp = second;
            second = second -> next; 
        }
        ans = ans -> next;
        return ans;
    }
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = NULL;
        left = sortList(left);
        right = sortList(right);
        ListNode* ans = merge(left , right);
        return ans;
    }
};