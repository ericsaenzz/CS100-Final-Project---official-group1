#include "Scheduler.h"
#include <algorithm>
using namespace std;

vector<Task> Scheduler::generateTodayAgenda(vector<Task> tasks) {
    vector<Task> agenda;
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_status != "complete") {
            agenda.push_back(tasks[i]);
        }
    }
    sort(agenda.begin(), agenda.end(), [](Task a, Task b) {
        if (a.task_dueDate != b.task_dueDate) return a.task_dueDate < b.task_dueDate;
        if (a.task_priority != b.task_priority) return a.task_priority < b.task_priority;
        return a.task_duration < b.task_duration;
    });
    return agenda;
}

vector<Task> Scheduler::generateSchedule(vector<Task> tasks) {
    return generateTodayAgenda(tasks);
}

vector<Task> Scheduler::sortByDeadline(vector<Task> tasks) {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.task_dueDate < b.task_dueDate;
    });
    return tasks;
}

vector<Task> Scheduler::sortByPriority(vector<Task> tasks) {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.task_priority < b.task_priority;
    });
    return tasks;
}

vector<Task> Scheduler::sortByTime(vector<Task> tasks) {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.task_duration < b.task_duration;
    });
    return tasks;
}

vector<Task> Scheduler::sortByStatus(vector<Task> tasks) {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.task_status < b.task_status;
    });
    return tasks;
}

vector<Task> Scheduler::getOverdueTasks(vector<Task> tasks) {
    vector<Task> overdue;
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_status != "complete" && tasks[i].task_dueDate < "06/05/2026") {
            overdue.push_back(tasks[i]);
        }
    }
    return overdue;
}