#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    Task(const std::string& desc) : description(desc), completed(false) {}

    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task newTask(description);
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
    }

    void markCompleted(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Marked task as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            cout << "Removed task: " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main() {
    ToDoList todoList;
    char choice;

    do {
        cout << "\nToDo List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                cout << "Enter task description: ";
                cin.ignore();
                string description;
                getline(cin, description);
                todoList.addTask(description);
                break;
            }

            case '2':
                todoList.viewTasks();
                break;

            case '3': {
                cout << "Enter task index to mark as completed: ";
                size_t index;
                cin >> index;
                todoList.markCompleted(index - 1);
                break;
            }

            case '4': {
                cout << "Enter task index to remove: ";
                size_t removeIndex;
                cin >> removeIndex;
                todoList.removeTask(removeIndex - 1);
                break;
            }

            case '5':
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }

    } while (choice != '5');

    return 0;
}
