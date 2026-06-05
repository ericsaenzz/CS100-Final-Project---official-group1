#include <gtest/gtest.h>
#include "../include/Task.h"
#include "../include/TaskManager.h"

// Test Task creation
TEST(TaskTest, CreateTask) {
    Task task(1, "Test Task", "Description", "12/30/2026", "incomplete", 5, 60, "Work");

    EXPECT_EQ(task.task_id, 1);
    EXPECT_EQ(task.task_title, "Test Task");
    EXPECT_EQ(task.task_desc, "Description");
    EXPECT_EQ(task.task_dueDate, "12/30/2026");
    EXPECT_EQ(task.task_status, "incomplete");
    EXPECT_EQ(task.task_priority, 5);
    EXPECT_EQ(task.task_duration, 60);
    EXPECT_EQ(task.task_category, "Work");
}

// Test default Task constructor
TEST(TaskTest, DefaultConstructor) {
    Task task;

    EXPECT_EQ(task.task_id, 0);
    EXPECT_EQ(task.task_title, "");
    EXPECT_EQ(task.task_status, "incomplete");
    EXPECT_EQ(task.task_priority, 3);
    EXPECT_EQ(task.task_duration, 0);
}

// Test Subtask creation
TEST(SubtaskTest, CreateSubtask) {
    Subtask subtask(1, "Subtask 1", "Do this", "incomplete");

    EXPECT_EQ(subtask.subtask_id, 1);
    EXPECT_EQ(subtask.subtask_title, "Subtask 1");
    EXPECT_EQ(subtask.subtask_desc, "Do this");
    EXPECT_EQ(subtask.subtask_status, "incomplete");
}

// Test Subtask completion check
TEST(TaskTest, AllSubtasksComplete) {
    Task task(1, "Parent Task", "Test", "12/30/2026", "incomplete", 5, 60, "Work");

    // Initially no subtasks, should be complete
    EXPECT_TRUE(task.allSubtasksComplete());

    // Add a subtask
    Subtask sub(1, "Sub 1", "Test", "incomplete");
    task.subtasks.push_back(sub);

    // Now should not be complete
    EXPECT_FALSE(task.allSubtasksComplete());

    // Mark subtask as complete
    task.subtasks[0].subtask_status = "complete";

    // Now should be complete
    EXPECT_TRUE(task.allSubtasksComplete());
}

// Test TaskManager creation
TEST(TaskManagerTest, CreateAndRetrieveTasks) {
    TaskManager manager;
    Task task(1, "Task 1", "Desc", "12/30/2026", "incomplete", 5, 60, "Work");

    manager.createTask(task);
    vector<Task> tasks = manager.getTask();

    EXPECT_EQ(tasks.size(), 1);
    EXPECT_EQ(tasks[0].task_title, "Task 1");
}

// Test TaskManager delete
TEST(TaskManagerTest, DeleteTask) {
    TaskManager manager;
    Task task1(1, "Task 1", "Desc", "12/30/2026", "incomplete", 5, 60, "Work");
    Task task2(2, "Task 2", "Desc", "12/31/2026", "incomplete", 4, 45, "Work");

    manager.createTask(task1);
    manager.createTask(task2);

    EXPECT_EQ(manager.getTask().size(), 2);

    manager.deleteTask(1);

    EXPECT_EQ(manager.getTask().size(), 1);
    EXPECT_EQ(manager.getTask()[0].task_id, 2);
}

// Test TaskManager update status
TEST(TaskManagerTest, UpdateTaskStatus) {
    TaskManager manager;
    Task task(1, "Task 1", "Desc", "12/30/2026", "incomplete", 5, 60, "Work");

    manager.createTask(task);
    manager.taskStatus(1, "complete");

    vector<Task> tasks = manager.getTask();
    EXPECT_EQ(tasks[0].task_status, "complete");
}
