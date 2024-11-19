#include "TaskScheduler.h"
#include <iostream>
#include <chrono>

void example_task(int id) {
    std::cout << "Task " << id << " is starting." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Task " << id << " has completed." << std::endl;
}

int main() {
    TaskScheduler scheduler(4); // 4 worker threads

    for (int i = 0; i < 10; ++i) {
        scheduler.add_task(std::make_shared<Task>([i]() { example_task(i); }));
    }

    scheduler.stop();
    std::cout << "All tasks are completed." << std::endl;

    return 0;
}
