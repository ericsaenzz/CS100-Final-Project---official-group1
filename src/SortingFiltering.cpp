#include "SortingFiltering.h"
#include <algorithm>

using namespace std;

vector<Task> SortingFiltering::sortByDeadline(vector<Task> tasks) {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.task_dueDate < b.task_dueDate;
    });

    return tasks;
}

vector<Task> SortingFiltering::sortByPriority(vector<Task> tasks) {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.task_priority < b.task_priority;
    });

    return tasks;
}

vector<Task> SortingFiltering::sortByEstimatedTime(vector<Task> tasks) {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.task_estimatedTime < b.task_estimatedTime;
    });

    return tasks;
}

vector<Task> SortingFiltering::sortByStatus(vector<Task> tasks) {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.task_status < b.task_status;
    });

    return tasks;
}

vector<Task> SortingFiltering::filterCompleted(vector<Task> tasks) {
    vector<Task> result;

    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_status == "complete") {
            result.push_back(tasks[i]);
        }
    }

    return result;
}

vector<Task> SortingFiltering::filterIncomplete(vector<Task> tasks) {
    vector<Task> result;

    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_status == "incomplete") {
            result.push_back(tasks[i]);
        }
    }

    return result;
}

vector<Task> SortingFiltering::filterInProgress(vector<Task> tasks) {
    vector<Task> result;

    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_status == "in progress") {
            result.push_back(tasks[i]);
        }
    }

    return result;
}