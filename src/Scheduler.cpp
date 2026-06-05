#include "Scheduler.h"
#include <algorithm>

using namespace std;

vector<Task> Scheduler::generateTodayAgenda(const vector<Task>& tasks) const {
    vector<Task> agenda;

    for (const Task& task : tasks) {
        if (!task.isCompleted()) {
            agenda.push_back(task);
        }
    }

    sort(agenda.begin(), agenda.end(), [](const Task& a, const Task& b) {
        if (a.getDeadline() != b.getDeadline()) {
            return a.getDeadline() < b.getDeadline();
        }

        if (a.getPriority() != b.getPriority()) {
            return a.getPriority() < b.getPriority();
        }

        return a.getEstimatedMinutes() < b.getEstimatedMinutes();
    });

    return agenda;
}