#include "scheduler.h"
#include <queue>

class FIFOScheduler : public Scheduler
{
private:
    std::queue<std::shared_ptr<Task>> queue;

public:
    void addTask(std::shared_ptr<Task> task) override{
        queue.push(task);
    }

    std::shared_ptr<Task> nextTask() override {
        if(queue.empty()) return nullptr;
        auto task = queue.front();
        queue.pop();
        return task;
    }

    void updateCurrentTask(double /*real_time*/) override {
        // FIFO model don't care about vruntime
    }

    bool hasTasks() const override {
        return !queue.empty();
    }

};

