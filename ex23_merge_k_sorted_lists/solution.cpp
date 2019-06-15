/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNodeComparator
{
    bool operator()(ListNode* l1, ListNode* l2) const
    {
        return l1->val > l2->val; // no nullptr checks since we won't insert nulls
    }
};

class Solution {
public:
    // Runtime nlgn, space linear - Copy the nodes into a priority queue reassemble after
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        // Push all nodes into the queue
        std::priority_queue<ListNode*, std::vector<ListNode*>, ListNodeComparator> queue;
        for (auto node : lists)
        {
            while (node != nullptr)
            {
                queue.push(node);
                node = node->next;
            }
        }
        
        ListNode* out = nullptr, *runner = nullptr;
        while (!queue.empty())
        {
            auto tmp = queue.top();
            queue.pop();
            
            if (out == nullptr)
            {
                out = tmp;
                runner = tmp;
            }
            else
            {
                runner->next = tmp;
                runner = runner->next;
            }
            
            tmp->next = nullptr;
        }
        
        return out;
    }
#if 0
    // Runtime quadratic, space constant - we'll traverse the vector of nodes to find the next minimum element
    // pop it off and into our output list. This assumes no extra data structures are allowed. If we want to go
    // faster then we can use other data structures.
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty())
            return nullptr;
        
        ListNode* out(nullptr), *next(nullptr);
        
        while (true)
        {
            int min_val = std::numeric_limits<int>::max();
            int min_val_idx = -1; // used to signal the end condition
            
            for (int i = 0; i < lists.size(); ++i)
            {
                if (lists[i] == nullptr)
                    continue;
                
                if (lists[i]->val < min_val)
                {
                    min_val = lists[i]->val;
                    min_val_idx = i;
                }
            }
            
            if (min_val_idx == -1)
                break; // we're done all input lists are nullptrs
            
            auto least_node = lists[min_val_idx];
            lists[min_val_idx] = lists[min_val_idx]->next;
            
            // First node in our output list
            if (out == nullptr)
            {
                out = least_node;
                next = least_node;
            }
            else
            {
                next->next = least_node;
                next = next->next;
            }
        }
        
        return out;
    }
#endif
};