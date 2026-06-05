#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

FileManager::FileManager(string file) {
    filename = file;
}

void FileManager::saveTasks(vector<Task> tasks) {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Could not open file for saving." << endl;
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        outFile << tasks[i].task_id << "|"
                << tasks[i].task_title << "|"
                << tasks[i].task_desc << "|"
                << tasks[i].task_dueDate << "|"
                << tasks[i].task_status << "|"
                << tasks[i].task_priority << "|"
                << tasks[i].task_estimatedTime << endl;
    }

    outFile.close();

    cout << "Tasks saved successfully." << endl;
}

vector<Task> FileManager::loadTasks() {
    vector<Task> tasks;
    ifstream inFile(filename);

    if (!inFile) {
        cout << "No saved file found. Starting fresh." << endl;
        return tasks;
    }

    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string id;
        string title;
        string desc;
        string dueDate;
        string status;
        string priority;
        string estimatedTime;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, desc, '|');
        getline(ss, dueDate, '|');
        getline(ss, status, '|');
        getline(ss, priority, '|');
        getline(ss, estimatedTime, '|');

        if (id != "" && title != "" && priority != "" && estimatedTime != "") {
            Task task(
                stoi(id),
                title,
                desc,
                dueDate,
                status,
                stoi(priority),
                stoi(estimatedTime)
            );

            tasks.push_back(task);
        }
    }

    inFile.close();

    cout << "Tasks loaded successfully." << endl;

    return tasks;
}