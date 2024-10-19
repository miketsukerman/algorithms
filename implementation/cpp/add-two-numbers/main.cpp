#include <catch2/catch_test_macros.hpp>

#include <print>

struct ListNode;

using ListNodePtr = std::shared_ptr<ListNode>;


struct ListNode {

    int val;
    
    ListNodePtr next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNodePtr next) : val(x), next(next) {}

    ListNodePtr append(int x) {
        next = std::make_shared<ListNode>(x);
        return next;
    }

    void dump() {
        auto tmp = next;

        std::println("{}", val);

        while (tmp != nullptr) {
            std::println("{}", tmp->val);

            tmp = tmp->next;
        }
    }
};

class Solution {
public:

    ListNodePtr addTwoNumbers(ListNodePtr l1, ListNodePtr l2) {
        const auto head = std::make_shared<ListNode>(0);
        auto tail = head;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;

            int sum = v1 + v2 + carry;
            carry = sum / 10;

            auto newNode = std::make_shared<ListNode>(sum % 10);
            tail->next = newNode;
            tail = tail->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        return head->next;
    }
};

TEST_CASE( "Test case1", "[add-two-numbers]" ) {

    auto list1 = std::make_shared<ListNode>(1);
    auto list2 = std::make_shared<ListNode>(3);

    list1->append(2)->append(3);
    list2->append(2)->append(1);

    Solution solution;

    auto res = solution.addTwoNumbers(list1, list2);

    res->dump();
}
