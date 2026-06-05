#ifndef NOTIFICATION_SYSTEM_H
#define NOTIFICATION_SYSTEM_H

#include "Task.h"
#include <vector>

using namespace std;

class NotificationSystem {
public:
    bool isOverdue(Task task);
    void showOverdueTasks(vector<Task> tasks);
};

#endif
