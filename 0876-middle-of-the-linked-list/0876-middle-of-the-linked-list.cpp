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

    ListNode* solve(ListNode* head){
        ListNode* temp = head;
        ListNode* ftemp = head;
        //int cnt=0;
        while(temp->next != NULL){
             ftemp= ftemp->next;
             if(temp->next->next != NULL){
             temp = temp->next->next;
             }
             else break;
        }
        return ftemp;
    }

    ListNode* middleNode(ListNode* head) {
        return solve(head);
    }
};