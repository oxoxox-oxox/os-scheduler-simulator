#include <vector>
#include <memory>
#include "cfs_scheduler.cpp"
#include "task.h"

int main()
{
    CFSScheduler scheduler;

    scheduler.addTask(std::make_shared<Task>(1, "A", 1.0, 10.0));
    scheduler.addTask(std::make_shared<Task>(2, "B", 2.0, 10.0));
    scheduler.addTask(std::make_shared<Task>(3, "C", 1.0, 10.0));

    const double time_slice = 1.0;

    while (!scheduler.hasTasks())
    {
        auto task = scheduler.nextTask();
        if (!task)
            break;

        std::cout << "Running task " << task->name
                  << " vruntime=" << task->vruntime << std::endl;

        scheduler.updateCurrentTask(time_slice);
    }

    return 0;
}