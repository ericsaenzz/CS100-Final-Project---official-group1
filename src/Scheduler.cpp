#include "Scheduler.h"
#include <algorithm>

using namespace std;

vector<Task> Scheduler::generateTodayAgenda(vector<Task> tasks) {
    vector<Task> agenda;

    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].task_status != "complete") {
            agenda.push_back(tasks[i]);
        }
    }

    sort(agenda.begin(), agenda.end(), [](Task a, Task b) {
        if (a.task_dueDate != b.task_dueDate) {
            return a.task_dueDate < b.task_dueDate;
        }

        if (a.task_priority != b.task_priority) {
            return a.task_priority < b.task_priority;
        }

        return a.task_estimatedTime < b.task_estimatedTime;
    });

    return agenda;
}