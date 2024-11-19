#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H

#include <vector>
#include <memory>
#include "Worker.h"
#include "TaskQueue.h"

class TaskScheduler {
public:
    TaskScheduler(int num_workers);
    void add_task(std::shared_ptr<Task> task);
    void stop();

private:
    TaskQueue task_queue_;
    std::vector<std::shared_ptr<Worker>> workers_;
};

#endif // TASKSCHEDULER_H
