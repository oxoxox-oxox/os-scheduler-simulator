#include "scheduler.h"
#include <set>
#include <iostream>

struct VruntimeCompare
{
    bool operator()(const std::shared_ptr<Task> &a,
                    const std::shared_ptr<Task> &b) const
    {
        if (a->vruntime == b->vruntime)
            return a->id < b->id;
        return a->vruntime < b->vruntime;
    }
};

class CFSScheduler : public Scheduler
{
private:
    std::set<std::shared_ptr<Task>, VruntimeCompare> runqueue;
    std::shared_ptr<Task> current;

public:
    void addTask(std::shared_ptr<Task> task) override
    {
        runqueue.insert(task);
    }

    std::shared_ptr<Task> nextTask() override
    {
        if (runqueue.empty())
            return nullptr;

        auto it = runqueue.begin();
        current = *it;
        runqueue.erase(it);
        return current;
    }

    void updateCurrentTask(double real_time) override
    {
        if (!current)
            return;

        current->remainingTime -= real_time;

        current->vruntime += real_time / current->weight;

        if (current->remainingTime > 0)
        {
            runqueue.insert(current);
        }

        current.reset();
    }

    bool hasTasks() const override
    {
        return runqueue.empty();
    }
};
