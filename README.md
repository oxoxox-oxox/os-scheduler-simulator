# os-scheduler-simulator

## General introduction

This repository is a simple simulator that demonstrates the core ideas behind the Linux Completely Fair Scheduler (CFS).

From my point of view, I think the core of CFS_Scheduler can be translated as the following Pseudocode:

``` Pseudocode
while (system is running):
    pick process with minimum vruntime
    run it for a small slice
    update its vruntime
    put it back into ordered structure
```

The original Linux scheduler design document can be found here:

<https://www.kernel.org/doc/html/v6.6/scheduler/sched-design-CFS.html>

---

## How it be designed

The structure of this project is as follows:

```
os-SCHEDULER-SIMULATOR/
├──.vscode/
|  └──c_cpp_properties.json
├──src/
|  ├── main.cpp
|  ├── cfs_scheduler.cpp
|  ├── fifo_scheduler.cpp
|  ├── scheduler.h
|  ├── task.h
|  └── output/
|     └── main.exe
└── README.md
```

---

In the `task.h` I defined the struct of Task to be used in later procedures

and in `scheduler.h` I defined the functions that will be needed while dealing with different tasks

`cfs_scheduler.cpp` implements the scheduling logic defined in `scheduler.h` using a simplified CFS policy.

`fifo_scheduler.cpp` is another moethod to arrange the procedures, but I not make it feasible in main.cpp

`main.cpp` is the main programe that use the class already defined in cfs_scheduler.cpp to simulate the process of computer system

## Build and Run

```bash
g++ -std=c++17 src/*.cpp -o scheduler
./scheduler
```

If you want to use another data to simulate, just change it in the main.cpp

```cpp
    scheduler.addTask(std::make_shared<Task>(1, "A", 1.0, 10.0));
    scheduler.addTask(std::make_shared<Task>(2, "B", 2.0, 10.0));
    scheduler.addTask(std::make_shared<Task>(3, "C", 1.0, 10.0));

    //change the Task to be done and its status
    //you can also add some more Taskby using CTRL+C and CTRL+V if you want.


    const double time_slice = 1.0;

    //change the amount of time system dealed once 
```

**remember to recompile it once you have changed the main.cpp**

---

## Requirements

- A C++17-compatible compiler (e.g. g++)
- (Optional) VSCode for code editing
