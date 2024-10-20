#include <catch2/catch_test_macros.hpp>

#include <print>
#include <ranges>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result{};
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0) {
            int sum = carry;

            if(i >= 0) {
                sum += a[i--] - '0';
            }

            if(j >= 0) {
                sum += b[j--] - '0';
            }

            carry = sum > 1 ? 1 : 0;

            result += std::to_string(sum % 2);
        }

        if(carry) {
            result += std::to_string(carry);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

TEST_CASE( "Test case1", "[add-two-numbers]" ) {

    std::string a = "11";
    std::string b = "1";

    Solution s;

    auto r = s.addBinary(a,b);

    std::println("{}",r);
}
