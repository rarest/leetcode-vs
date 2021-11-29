/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode preHead, *phead = &preHead, * l1 = list1, *l2 = list2;
        while (l1 && l2)
        {
            if(l1->val <= l2->val){
                phead->next = l1;
                l1 = l1->next;
            }else {
                phead->next = l2;
                l2 = l2->next;
            }
            phead = phead->next;
        }
        phead->next = l1?l1:l2;
        return preHead.next;        
    }
};
// @lc code=end

