#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100

typedef enum { DOWNLOAD, MUSIC, GAME } TaskType;

typedef struct {
    TaskType type;
    int priority;
    int duration;
} Task;

int front[3], rear[3];
Task queue[3][MAX_QUEUE_SIZE];

void enqueue(Task task) {
    int i = task.type;
    if (rear[i] == MAX_QUEUE_SIZE - 1) {
        printf("Queue Overflow\n");
        exit(1);
    }
    rear[i]++;
    queue[i][rear[i]] = task;
}

Task dequeue(int type) {
    if (front[type] > rear[type]) {
        printf("Queue Underflow\n");
        exit(1);
    }
    Task task = queue[type][front[type]];
    front[type]++;
    return task;
}

int is_empty(int type) {
    return front[type] > rear[type];
}

void simulate_multitasking() {
    int total_time = 0, remaining_tasks = 3;
    while (remaining_tasks > 0) {
        TaskType type;
        if (!is_empty(DOWNLOAD)) {
            type = DOWNLOAD;
        } else if (!is_empty(MUSIC)) {
            type = MUSIC;
        } else if (!is_empty(GAME)) {
            type = GAME;
        } else {
            printf("All tasks completed\n");
            break;
        }

        Task task = dequeue(type);
        int duration = task.duration;
        printf("Executing task %d for %d seconds (priority: %d)\n", type, duration, task.priority);

        total_time += duration;
        int i;
        for (i = 0; i < 3; i++) {
            if (i != type && !is_empty(i)) {
                Task t = dequeue(i);
                enqueue(t);
                printf("Adding remaining task %d (priority: %d) to queue %d\n", t.type, t.priority, t.type);
            }
        }

        remaining_tasks--;
    }
    printf("Total time taken: %d seconds\n", total_time);
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < 10; i++) {
        Task task;
        int r = rand() % 10;
        if (r < 3) {
            task.type = DOWNLOAD;
            task.priority = 3;
        } else if (r < 7) {
            task.type = MUSIC;
            task.priority = 2;
        } else {
            task.type = GAME;
            task.priority = 1;
        }
        task.duration = rand() % 10 + 1;
        enqueue(task);
    }
    simulate_multitasking();
    return 0;
}
