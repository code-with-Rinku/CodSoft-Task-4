

#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;

void printTasks(string tasks[], int taskCount) {
    cout << "Tasks to do:" << endl;
    for (int i = 0; i < taskCount; i++) {
        cout << "Task " << i << ": " << tasks[i] << endl;
    }
}

int main() {
    string tasks[MAX_TASKS];
    int taskCount = 0;
    int choice = -1;

    while (choice != 0) {
        cout << "----TO DO LIST---" << endl;
        cout << "1- TO ADD NEW TASK" << endl;
        cout << "2- TO VIEW TASKS" << endl;
        cout << "3- TO DELETE A TASK" << endl;
        cout << "0- EXIT" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                if (taskCount < MAX_TASKS) {
                    cout << "Enter the new task:" << endl;
                    cin.ignore();
                    getline(cin, tasks[taskCount]);
                    taskCount++;
                } else {
                    cout << "Task list is full." << endl;
                }
                break;
            case 2:
                printTasks(tasks, taskCount);
                break;
            case 3: {
                int delTask;
                cout << "Enter the task index to delete (0-" << taskCount - 1 << "):" << endl;
                cin >> delTask;

                if (delTask >= 0 && delTask < taskCount) {
                    for (int i = delTask; i < taskCount - 1; i++) {
                        tasks[i] = tasks[i + 1];
                    }
                    taskCount--;
                } else {
                    cout << "Invalid task index." << endl;
                }
                break;
            }
            case 0:
                cout << "Terminating the program." << endl;
                break;
            default:
                cout << "You entered an invalid value." << endl;
        }
    }

    return 0;
}



