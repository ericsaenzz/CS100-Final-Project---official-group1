#include "SortingFiltering.h"
#include <algorithm>

using namespace std;

vector<Task> SortingFiltering::sortByDeadline(vector<Task> tasks) const {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getDeadline() < b.getDeadline();
    });

    return tasks;
}

vector<Task> SortingFiltering::sortByPriority(vector<Task> tasks) const {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getPriority() < b.getPriority();
    });

    return tasks;
}

vector<Task> SortingFiltering::sortByEstimatedTime(vector<Task> tasks) const {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getEstimatedMinutes() < b.getEstimatedMinutes();
    });

    return tasks;
}

vector<Task> SortingFiltering::sortByStatus(vector<Task> tasks) const {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.isCompleted() < b.isCompleted();
    });

    return tasks;
}

vector<Task> SortingFiltering::filterCompleted(const vector<Task>& tasks) const {
    vector<Task> completedTasks;

    for (const Task& task : tasks) {
        if (task.isCompleted()) {
            completedTasks.push_back(task);
        }
    }

    return completedTasks;
}

vector<Task> SortingFiltering::filterIncomplete(const vector<Task>& tasks) const {
    vector<Task> incompleteTasks;

    for (const Task& task : tasks) {
        if (!task.isCompleted()) {
            incompleteTasks.push_back(task);
        }
    }

    return incompleteTasks;
}