#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <vector>
#include "Task.h"
using namespace std;

class FileManager {
private:
    string filename = "tasks.txt";

public:
    void saveTasks(vector<Task> tasks) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Could not open file for saving." << endl;
            return;
        }

        for (const Task& task : tasks) {
            file << task.task_id << "|"
                 << task.task_title << "|"
                 << task.task_desc << "|"
                 << task.task_dueDate << "|"
                 << task.task_status << "|"
                 << task.task_priority << "|"
                 << task.task_duration << "|"
                 << task.task_category << "\n";
        }
        file.close();
        cout << "Tasks saved successfully." << endl;
    }

    vector<Task> loadTasks() {
        vector<Task> tasks;
        ifstream file(filename);

        if (!file.is_open()) {
            cout << "No saved tasks found. Starting fresh." << endl;
            return tasks;
        }

        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;

            int id, priority, duration;
            string title, desc, dueDate, status, category;

            size_t pos = 0;
            id = stoi(line.substr(0, line.find("|")));
            pos = line.find("|") + 1;

            size_t next = line.find("|", pos);
            title = line.substr(pos, next - pos);
            pos = next + 1;

            next = line.find("|", pos);
            desc = line.substr(pos, next - pos);
            pos = next + 1;

            next = line.find("|", pos);
            dueDate = line.substr(pos, next - pos);
            pos = next + 1;

            next = line.find("|", pos);
            status = line.substr(pos, next - pos);
            pos = next + 1;

            next = line.find("|", pos);
            priority = stoi(line.substr(pos, next - pos));
            pos = next + 1;

            next = line.find("|", pos);
            duration = stoi(line.substr(pos, next - pos));
            pos = next + 1;

            category = line.substr(pos);

            Task task(id, title, desc, dueDate, status, priority, duration, category);
            tasks.push_back(task);
        }

        file.close();
        cout << "Tasks loaded successfully." << endl;
        return tasks;
    }
};

#endif