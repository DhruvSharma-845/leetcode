#include <my_calendar_III.h>

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(MY_Calendar_III, BasicAssertions) {
  MyCalendarThree mct;
  
  EXPECT_EQ(1, mct.book(10, 20));
  EXPECT_EQ(1, mct.book(50, 60));
  EXPECT_EQ(2, mct.book(10, 40));
  EXPECT_EQ(3, mct.book(5, 15));
  EXPECT_EQ(3, mct.book(5, 10));
  EXPECT_EQ(3, mct.book(25, 55));
}