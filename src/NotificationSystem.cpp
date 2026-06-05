#include "NotificationSystem.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

bool NotificationSystem::isOverdue(const Task& task) const {
    if (task.isCompleted()) {
        return false;
    }

    tm deadlineTime = {};
    istringstream ss(task.getDeadline());

    ss >> get_time(&deadlineTime, "%Y-%m-%d %H:%M");

    if (ss.fail()) {
        return false;
    }

    time_t deadline = mktime(&deadlineTime);
    time_t now = time(nullptr);

    return deadline < now;
}

void NotificationSystem::showOverdueTasks(const vector<Task>& tasks) const {
    bool found = false;

    cout << endl;
    cout << "===== Overdue Tasks =====" << endl;

    for (const Task& task : tasks) {
        if (isOverdue(task)) {
            task.display();
            cout << "-------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No overdue tasks." << endl;
    }
}