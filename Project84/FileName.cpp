#include <iostream>
#include <list>
#include <string>

using namespace std;

class ToDoList {
private:
    string task;
    list<ToDoList> subtasks;

public:
   
    ToDoList(const string& task) : task(task) {}

   void addSubtask(const string& subtask) {
        subtasks.push_back(ToDoList(subtask));
    }

   
    void display(int depth = 0) const {
        cout << string(depth, '-') << task << endl;
        for (const auto& subtask : subtasks) {
            subtask.display(depth + 2);
        }
    }
    string getTask() const {
        return task;
    }
};

int main() {
    string taskName;
    cout << "Enter the name of the main task: ";
    getline(cin, taskName);

    ToDoList todoMain(taskName);

    char choice;
    do {
        string subtaskName;
        cout << "Enter the name of the subtask or enter 'done' to finish: ";
        getline(cin, subtaskName);

        if (subtaskName != "done") {
            todoMain.addSubtask(subtaskName);
        }

        cout << "Add another subtask? (y/n): ";
        cin >> choice;
        cin.ignore(); 
    } while (choice == 'y');

    cout << "\n\nYour To-Do List:" << endl;
    todoMain.display();

    return 0;
}