//
// Created by Dhruv Sharma on 10/05/25.
//

#include "search_suggestion_system.h"

#include <gtest/gtest.h>

TEST(SearchSuggestionSystem, Assertion1) {
    Solution s;
    std::vector<std::vector<std::string>> suggestions{
        {"mobile","moneypot","monitor"},
        {"mobile","moneypot","monitor"},
        {"mouse","mousepad"},
        {"mouse","mousepad"},
        {"mouse","mousepad"}
    };
    std::vector<std::string> products{"mobile","mouse","moneypot","monitor","mousepad"};
    EXPECT_EQ(s.suggestedProducts(products, std::string{"mouse"}), suggestions);
}