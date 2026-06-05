#ifndef SORTING_FILTERING_H
#define SORTING_FILTERING_H

#include "Task.h"
#include <vector>

using namespace std;

class SortingFiltering {
public:
    vector<Task> sortByDeadline(vector<Task> tasks);
    vector<Task> sortByPriority(vector<Task> tasks);
    vector<Task> sortByEstimatedTime(vector<Task> tasks);
    vector<Task> sortByStatus(vector<Task> tasks);

    vector<Task> filterCompleted(vector<Task> tasks);
    vector<Task> filterIncomplete(vector<Task> tasks);
    vector<Task> filterInProgress(vector<Task> tasks);
};

#endif