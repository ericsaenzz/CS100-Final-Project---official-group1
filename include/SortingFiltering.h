#ifndef SORTING_FILTERING_H
#define SORTING_FILTERING_H

#include "Task.h"
#include <vector>

class SortingFiltering {
public:
    std::vector<Task> sortByDeadline(std::vector<Task> tasks) const;
    std::vector<Task> sortByPriority(std::vector<Task> tasks) const;
    std::vector<Task> sortByEstimatedTime(std::vector<Task> tasks) const;
    std::vector<Task> sortByStatus(std::vector<Task> tasks) const;

    std::vector<Task> filterCompleted(const std::vector<Task>& tasks) const;
    std::vector<Task> filterIncomplete(const std::vector<Task>& tasks) const;
};

#endif