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
        int length = 0;
        ListNode* current = head;
        while(current!=nullptr) {
            length++;
            current = current->next;
        }
        cout << "Size of linked list = " << length << "\n";
        if (length == n) {
            return head->next;
        }
        int nodeIndex = length - n;
        current = head;
        for(int i = 0; i < length - 1; i++) {
            if((i + 1) == nodeIndex) {
                current->next = current->next->next;
                break;
            }
            current = current->next;
        }
        return head;
    }
};
