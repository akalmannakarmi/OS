#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define N 10 // Maximum number of philosophers

pthread_mutex_t forks[N];
pthread_t philosophers[N];

void *philosopher(void *arg) {
    int id = *((int *) arg);
    int left_fork = id;
    int right_fork = (id + 1) % N;

    while (1) {
        // Try to pick up left fork
        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d picked up left fork\n", id);

        // Try to pick up right fork
        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d picked up right fork\n", id);

        // Eating
        printf("Philosopher %d is eating\n", id);
        sleep(1); // Simulate eating

        // Put down right fork
        pthread_mutex_unlock(&forks[right_fork]);
        printf("Philosopher %d put down right fork\n", id);

        // Put down left fork
        pthread_mutex_unlock(&forks[left_fork]);
        printf("Philosopher %d put down left fork\n", id);

        // Thinking
        printf("Philosopher %d is thinking\n", id);
        sleep(1); // Simulate thinking
    }
}

int main() {
    int num_philosophers;

    printf("Enter the number of philosophers (maximum %d): ", N);
    scanf("%d", &num_philosophers);

    if (num_philosophers < 2 || num_philosophers > N) {
        printf("Invalid number of philosophers.\n");
        return 1;
    }

    // Initialize mutexes for forks
    for (int i = 0; i < num_philosophers; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < num_philosophers; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&philosophers[i], NULL, philosopher, id);
    }

    // Join philosopher threads
    for (int i = 0; i < num_philosophers; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes for forks
    for (int i = 0; i < num_philosophers; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}