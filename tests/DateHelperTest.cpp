#include <gtest/gtest.h>
#include "../include/DateHelper.h"

// Test valid date format
TEST(DateHelperTest, ValidDateFormat) {
    EXPECT_TRUE(DateHelper::isValidDate("12/30/2026"));
    EXPECT_TRUE(DateHelper::isValidDate("01/01/2024"));
    EXPECT_TRUE(DateHelper::isValidDate("12/25/2025"));
}

// Test invalid date format
TEST(DateHelperTest, InvalidDateFormat) {
    EXPECT_FALSE(DateHelper::isValidDate("13/30/2026"));  // Invalid month
    EXPECT_FALSE(DateHelper::isValidDate("12/32/2026"));  // Invalid day
    EXPECT_FALSE(DateHelper::isValidDate("12-30-2026"));  // Wrong separator
    EXPECT_FALSE(DateHelper::isValidDate("2026/12/30"));  // Wrong order
    EXPECT_FALSE(DateHelper::isValidDate("12/30/20"));    // Invalid year
}

// Test date with leading zeros
TEST(DateHelperTest, LeadingZeros) {
    EXPECT_TRUE(DateHelper::isValidDate("01/05/2026"));
    EXPECT_TRUE(DateHelper::isValidDate("06/15/2026"));
    EXPECT_FALSE(DateHelper::isValidDate("1/5/2026"));    // Missing leading zeros
}

// Test overdue detection (relative to system time)
TEST(DateHelperTest, IsOverdue) {
    // Past date should be overdue
    EXPECT_TRUE(DateHelper::isOverdue("01/01/2020"));

    // Future date should not be overdue
    EXPECT_FALSE(DateHelper::isOverdue("12/31/2030"));
}

// Test days until due calculation
TEST(DateHelperTest, DaysUntilDue) {
    // This test is relative to current system date
    // We'll just verify it doesn't crash and returns a non-negative value
    int days = DateHelper::daysUntilDue("12/31/2030");
    EXPECT_GE(days, 0);  // Should be non-negative for future date
}

// Test edge case: February dates
TEST(DateHelperTest, FebruaryDates) {
    EXPECT_TRUE(DateHelper::isValidDate("02/28/2026"));
    EXPECT_TRUE(DateHelper::isValidDate("02/29/2024"));  // Leap year
}
