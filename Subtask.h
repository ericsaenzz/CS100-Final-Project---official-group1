#ifndef SUBTASK_H
#define SUBTASK_H
#include <string>
using namespace std;

class Subtask {
public:
    int subtask_id;
    string subtask_title;
    string subtask_desc;
    string subtask_status;

    Subtask() {
        subtask_id = 0;
        subtask_title = "";
        subtask_desc = "";
        subtask_status = "incomplete";
    }

    Subtask(int id, string title, string desc, string status) {
        subtask_id = id;
        subtask_title = title;
        subtask_desc = desc;
        subtask_status = status;
    }
};

#endif