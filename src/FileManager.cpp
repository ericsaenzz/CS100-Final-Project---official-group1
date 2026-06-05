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

    for (size_t i = 0; i < tasks.size(); i++) {
        outFile << tasks[i].task_id << "|"
                << tasks[i].task_title << "|"
                << tasks[i].task_desc << "|"
                << tasks[i].task_dueDate << "|"
                << tasks[i].task_status << "|"
                << tasks[i].task_priority << "|"
                << tasks[i].task_duration << "|"
                << tasks[i].task_category << "|";

        for (size_t j = 0; j < tasks[i].subtasks.size(); j++) {
            outFile << tasks[i].subtasks[j].subtask_id << "~"
                    << tasks[i].subtasks[j].subtask_title << "~"
                    << tasks[i].subtasks[j].subtask_desc << "~"
                    << tasks[i].subtasks[j].subtask_status;

            if (j != tasks[i].subtasks.size() - 1) {
                outFile << ";";
            }
        }

        outFile << endl;
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
        string duration;
        string category;
        string subtaskData;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, desc, '|');
        getline(ss, dueDate, '|');
        getline(ss, status, '|');
        getline(ss, priority, '|');
        getline(ss, duration, '|');
        getline(ss, category, '|');
        getline(ss, subtaskData, '|');

        if (id != "" && title != "" && priority != "" && duration != "") {
            Task task(
                stoi(id),
                title,
                desc,
                dueDate,
                status,
                stoi(priority),
                stoi(duration),
                category
            );

            if (subtaskData != "") {
                stringstream subtaskStream(subtaskData);
                string oneSubtask;

                while (getline(subtaskStream, oneSubtask, ';')) {
                    stringstream singleSubtaskStream(oneSubtask);

                    string subtaskId;
                    string subtaskTitle;
                    string subtaskDesc;
                    string subtaskStatus;

                    getline(singleSubtaskStream, subtaskId, '~');
                    getline(singleSubtaskStream, subtaskTitle, '~');
                    getline(singleSubtaskStream, subtaskDesc, '~');
                    getline(singleSubtaskStream, subtaskStatus, '~');

                    if (subtaskId != "" && subtaskTitle != "") {
                        Subtask subtask(
                            stoi(subtaskId),
                            subtaskTitle,
                            subtaskDesc,
                            subtaskStatus
                        );

                        task.subtasks.push_back(subtask);
                    }
                }
            }

            tasks.push_back(task);
        }
    }

    inFile.close();

    cout << "Tasks loaded successfully." << endl;

    return tasks;
}