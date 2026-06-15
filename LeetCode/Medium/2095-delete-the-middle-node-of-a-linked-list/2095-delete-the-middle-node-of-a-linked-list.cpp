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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        int sz = 0;
        ListNode* temp = head;
        while(temp != NULL){
            sz++;
            temp = temp->next;
        }
        temp = head;
        //int cnt = 0;
        int cnt = sz/2;
        for(int i=0;i<cnt-1;i++){
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};