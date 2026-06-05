#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
using namespace std;

int getValidInteger(int min, int max, const string& prompt);
char getValidYesNo(const string& prompt);
string getValidString(const string& prompt, bool canBeEmpty = false);

void pauseForReturn();
void displayMainMenu();
void createTask();
void viewTasks();
void editTask();
void deleteTask();
void manageSubtasks();
void markTaskComplete();
void sortTasks();
void viewOverdueTasks();
void generateSchedule();
void saveTasks();
void loadTasks();
void undoLastAction();

#endif