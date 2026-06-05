#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Task.h"
#include <vector>

class Scheduler {
public:
    std::vector<Task> generateTodayAgenda(const std::vector<Task>& tasks) const;
};

#endif