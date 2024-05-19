
//Task management system 
#include <iostream>
#include <vector>
#include <string>
#include <limits>

class ToDoList {
private:
    struct Task {
        std::string description;
        bool completed = false;
    };
    std::vector<Task> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back({task});
        std::cout << "Task added: " << task << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available in the list .\n";
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i)
            std::cout << i + 1 << ". " << tasks[i].description 
                      << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }

    void markTaskCompleted(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            std::cout << "Task " << taskNumber << " marked as completed.\n";
        } else {
            std::cout << "Invalid task number(not found).\n";
        }
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            std::cout << "Task " << taskNumber << " removed.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        std::cout << "\nTo-Do List Manager\n"
                  << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n"
                  << "4. Remove Task\n5. Exit\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string task;
                std::cout << "Enter the task: ";
                std::getline(std::cin, task);
                toDoList.addTask(task);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                size_t taskNumber;
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> taskNumber;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                toDoList.markTaskCompleted(taskNumber);
                break;
            }
            case 4: {
                size_t taskNumber;
                std::cout << "Enter the task number to remove: ";
                std::cin >> taskNumber;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                toDoList.removeTask(taskNumber);
                break;
            }
            case 5:
                std::cout << "Exiting the to-do list manager.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
