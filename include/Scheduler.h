#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Task.h"
#include <vector>

using namespace std;

class Scheduler {
public:
    vector<Task> generateTodayAgenda(vector<Task> tasks);
};

#endif