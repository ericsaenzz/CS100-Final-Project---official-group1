cat > include/Scheduler.h << 'EOF'
#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Task.h"
#include <vector>
using namespace std;
class Scheduler {
public:
    vector<Task> generateTodayAgenda(vector<Task> tasks);
    vector<Task> generateSchedule(vector<Task> tasks);
    vector<Task> sortByDeadline(vector<Task> tasks);
    vector<Task> sortByPriority(vector<Task> tasks);
    vector<Task> sortByTime(vector<Task> tasks);
    vector<Task> sortByStatus(vector<Task> tasks);
    vector<Task> getOverdueTasks(vector<Task> tasks);
};
#endif
EOF