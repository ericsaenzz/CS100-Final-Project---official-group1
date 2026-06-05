#include "NotificationSystem.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

bool NotificationSystem::isOverdue(Task task) {
    if (task.task_status == "complete") {
        return false;
    }

    tm deadlineTime = {};
    istringstream ss(task.task_dueDate);

    ss >> get_time(&deadlineTime, "%Y-%m-%d %H:%M");

    if (ss.fail()) {
        return false;
    }

    time_t deadline = mktime(&deadlineTime);
    time_t now = time(nullptr);

    return deadline < now;
}

void NotificationSystem::showOverdueTasks(vector<Task> tasks) {
    bool found = false;

    cout << "\n===== Overdue Tasks =====" << endl;

    for (size_t i = 0; i < tasks.size(); i++) {
        if (isOverdue(tasks[i])) {
            cout << "Task ID: " << tasks[i].task_id << endl;
            cout << "Title: " << tasks[i].task_title << endl;
            cout << "Description: " << tasks[i].task_desc << endl;
            cout << "Due Date: " << tasks[i].task_dueDate << endl;
            cout << "Status: " << tasks[i].task_status << endl;
            cout << "Priority: " << tasks[i].task_priority << endl;
            cout << "Duration: " << tasks[i].task_duration << " minutes" << endl;
            cout << "Category: " << tasks[i].task_category << endl;
            cout << "Subtasks: " << tasks[i].subtasks.size() << endl;
            cout << "-------------------------" << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "No overdue tasks." << endl;
    }
}
