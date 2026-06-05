#include <gtest/gtest.h>
#include "../include/Scheduler.h"
#include "../include/Task.h"
#include <vector>

using namespace std;

// Test sorting by deadline
TEST(SchedulerTest, SortByDeadline) {
    Scheduler scheduler;
    vector<Task> tasks;

    tasks.push_back(Task(1, "Task 1", "Desc", "12/31/2026", "incomplete", 5, 60, "Work"));
    tasks.push_back(Task(2, "Task 2", "Desc", "12/25/2026", "incomplete", 4, 45, "Work"));
    tasks.push_back(Task(3, "Task 3", "Desc", "12/28/2026", "incomplete", 3, 30, "Work"));

    vector<Task> sorted = scheduler.sortByDeadline(tasks);

    EXPECT_EQ(sorted[0].task_id, 2);  // 12/25
    EXPECT_EQ(sorted[1].task_id, 3);  // 12/28
    EXPECT_EQ(sorted[2].task_id, 1);  // 12/31
}

// Test sorting by priority
TEST(SchedulerTest, SortByPriority) {
    Scheduler scheduler;
    vector<Task> tasks;

    tasks.push_back(Task(1, "Task 1", "Desc", "12/30/2026", "incomplete", 3, 60, "Work"));
    tasks.push_back(Task(2, "Task 2", "Desc", "12/30/2026", "incomplete", 5, 45, "Work"));
    tasks.push_back(Task(3, "Task 3", "Desc", "12/30/2026", "incomplete", 1, 30, "Work"));

    vector<Task> sorted = scheduler.sortByPriority(tasks);

    EXPECT_EQ(sorted[0].task_priority, 5);
    EXPECT_EQ(sorted[1].task_priority, 3);
    EXPECT_EQ(sorted[2].task_priority, 1);
}

// Test sorting by time
TEST(SchedulerTest, SortByTime) {
    Scheduler scheduler;
    vector<Task> tasks;

    tasks.push_back(Task(1, "Task 1", "Desc", "12/30/2026", "incomplete", 5, 120, "Work"));
    tasks.push_back(Task(2, "Task 2", "Desc", "12/30/2026", "incomplete", 4, 30, "Work"));
    tasks.push_back(Task(3, "Task 3", "Desc", "12/30/2026", "incomplete", 3, 60, "Work"));

    vector<Task> sorted = scheduler.sortByTime(tasks);

    EXPECT_EQ(sorted[0].task_duration, 30);
    EXPECT_EQ(sorted[1].task_duration, 60);
    EXPECT_EQ(sorted[2].task_duration, 120);
}

// Test schedule generation (deadline -> priority -> time)
TEST(SchedulerTest, GenerateSchedule) {
    Scheduler scheduler;
    vector<Task> tasks;

    // Same deadline, different priorities
    tasks.push_back(Task(1, "Task 1", "Desc", "12/30/2026", "incomplete", 2, 60, "Work"));
    tasks.push_back(Task(2, "Task 2", "Desc", "12/30/2026", "incomplete", 5, 45, "Work"));
    tasks.push_back(Task(3, "Task 3", "Desc", "12/30/2026", "incomplete", 3, 30, "Work"));

    vector<Task> scheduled = scheduler.generateSchedule(tasks);

    // Should be sorted by priority (highest first)
    EXPECT_EQ(scheduled[0].task_priority, 5);
    EXPECT_EQ(scheduled[1].task_priority, 3);
    EXPECT_EQ(scheduled[2].task_priority, 2);
}
