// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
       if(!head) return NULL;

       if(!head->next)
       return new TreeNode(head->val);

        ListNode* prev = NULL; // node lưu slow trước đó
        ListNode* slow = head; // node dùng để xác định node giữa
        ListNode* fast = head; // fast dùng để đi đến cuối node
        while(fast && fast->next) //xét fast không null
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev) prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);

        root->left = sortedListToBST(head);

        root->right = sortedListToBST(slow->next);
        return root;
    }
};