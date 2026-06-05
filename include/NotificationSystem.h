#ifndef NOTIFICATION_SYSTEM_H
#define NOTIFICATION_SYSTEM_H

#include "Task.h"
#include <vector>

class NotificationSystem {
public:
    void showOverdueTasks(const std::vector<Task>& tasks) const;
    bool isOverdue(const Task& task) const;
};

#endif