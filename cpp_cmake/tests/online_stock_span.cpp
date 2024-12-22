#include <online_stock_span.h>

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(OnlineStockSpan, BasicAssertions1) {
    StockSpanner   s;
    EXPECT_EQ(s.next(100), 1);
    EXPECT_EQ(s.next(80), 1);
    EXPECT_EQ(s.next(60), 1);
    EXPECT_EQ(s.next(70), 2);
    EXPECT_EQ(s.next(60), 1);
    EXPECT_EQ(s.next(75), 4);
    EXPECT_EQ(s.next(85), 6);
}