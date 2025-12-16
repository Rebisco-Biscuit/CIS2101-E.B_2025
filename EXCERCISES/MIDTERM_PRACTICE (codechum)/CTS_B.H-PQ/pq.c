#include <stdio.h>
#include <stdlib.h>
#include "types.h"

// Write your functions here
void initQueue(PriorityQueue *pq) {
    pq->size = 0;
    pq->capacity = MAX_PROCESSES;

    printf("\n--- Scheduler Queue initialized with capacity %d. ---\n",
           pq->capacity);
}

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && pq->heap[index].priority > pq->heap[parent].priority) {
        swap(&pq->heap[index], &pq->heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(PriorityQueue *pq, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size &&
        pq->heap[left].priority > pq->heap[largest].priority) {
        largest = left;
    }

    if (right < pq->size &&
        pq->heap[right].priority > pq->heap[largest].priority) {
        largest = right;
    }

    if (largest != index) {
        swap(&pq->heap[index], &pq->heap[largest]);
        heapifyDown(pq, largest);
    }
}

void insertProcess(PriorityQueue *pq, Process newProcess) {
    if (pq->size >= pq->capacity) {
        printf("Queue full. Can't insert process %d\n", newProcess.pid);
        return;
    }

    pq->heap[pq->size] = newProcess;
    pq->size++;
    heapifyUp(pq, pq->size - 1);

    printf("-> ENQUEUED: Process ID %d (Priority: %d)\n",
           newProcess.pid,
           newProcess.priority);
}


Process extractMax(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue empty. Nothing to extract.\n");
        Process empty = { -1, -1 };
        return empty;
    }

    Process maxProcess = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);

    return maxProcess;
}
