#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    int time;
} Job;

int front = -1, rear = -1;
Job queue[MAX_SIZE];

void enqueue(Job job) {
    if ((front == 0 && rear == MAX_SIZE - 1) || rear == (front - 1) % (MAX_SIZE - 1)) {
        printf("Queue is full.\n");
        exit(1);
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = job;
}

Job dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        exit(1);
    }
    Job job = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
    return job;
}

int main() {
    int n, total_time = 0;
    printf("Enter the time quantum: ");
    scanf("%d", &n);
    Job jobs[] = {{1, 10}, {2, 8}, {3, 6}}; // Array of jobs with their respective IDs and processing times
    int num_jobs = sizeof(jobs) / sizeof(jobs[0]); // Get the number of jobs
    for (int i = 0; i < num_jobs; i++) {
        enqueue(jobs[i]);
        total_time += jobs[i].time;
    }
    int time_passed = 0;
    while (front != -1) {
        Job current_job = dequeue();
        printf("Processing job %d for %d seconds.\n", current_job.id, n);
        current_job.time -= n;
        time_passed += n;
        if (current_job.time > 0) {
            enqueue(current_job);
        } else {
            printf("Job %d completed at time %d.\n", current_job.id, time_passed);
        }
    }
    printf("Total time taken to complete all jobs: %d seconds.\n", total_time);
    return 0;
}
