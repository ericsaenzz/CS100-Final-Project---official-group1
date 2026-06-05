#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
#include <algorithm>
#include "Task.h"
#include "DateHelper.h"
using namespace std;

class Scheduler {
public:
    vector<Task> sortByDeadline(vector<Task> tasks) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.task_dueDate < b.task_dueDate;
        });
        return tasks;
    }

    vector<Task> sortByPriority(vector<Task> tasks) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.task_priority > b.task_priority;
        });
        return tasks;
    }

    vector<Task> sortByTime(vector<Task> tasks) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.task_duration < b.task_duration;
        });
        return tasks;
    }

    vector<Task> sortByStatus(vector<Task> tasks) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.task_status < b.task_status;
        });
        return tasks;
    }

    vector<Task> generateSchedule(vector<Task> tasks) {
        vector<Task> schedule = tasks;

        sort(schedule.begin(), schedule.end(), [](const Task& a, const Task& b) {
            if (a.task_dueDate != b.task_dueDate) {
                return a.task_dueDate < b.task_dueDate;
            }
            if (a.task_priority != b.task_priority) {
                return a.task_priority > b.task_priority;
            }
            return a.task_duration < b.task_duration;
        });

        return schedule;
    }

    vector<Task> getOverdueTasks(vector<Task> tasks) {
        vector<Task> overdue;
        for (const Task& task : tasks) {
            if (DateHelper::isOverdue(task.task_dueDate) && task.task_status != "complete") {
                overdue.push_back(task);
            }
        }
        return overdue;
    }
};

#endif