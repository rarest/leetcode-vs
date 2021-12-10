/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

    std::pair<ListNode*, ListNode*>reverse(ListNode *head, ListNode* tail){
        ListNode * prev = tail->next;
        ListNode * cur = head;
        while (prev != tail)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return {tail, head};        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode hair(0, head);
      ListNode *pre = &hair;
      while (head)
      {
          ListNode *tail = pre;
          for(int i = 0; i < k; ++i) {
              tail = tail->next;
              if(!tail) {
                  return hair.next;
              }
          }
          ListNode *next = tail->next;
          std::pair<ListNode*, ListNode*> nodes = reverse(head, tail);
          pre->next = nodes.first;
          nodes.second->next = next;
          pre = nodes.second;
          head = next;
      }
      return hair.next;
    }
};
// @lc code=end

