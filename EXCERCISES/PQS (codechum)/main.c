#include <stdio.h>
#include <stdlib.h>
#include "arrayQueue.h"
#include "types.h"

int main() {
    Queue *rq = initialize();
    Queue *pq = initialize();    
    int num=0;
    int choice;
    
    
    
    while(1) {
        printf("--- Pharmacy Queueing System ---");
        printf("\n1. Enter Regular Queue");
        printf("\n2. Enter Priority Queue");
        printf("\n3. Call Next Customer");
        printf("\n4. Display Queues");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(isFull(rq)) {
                    printf("Regular queue is full. Please try again later.\n\n");
                } else {
                    printf("You have entered the Regular queue. Your number is %d.\n\n", ++num);
                    enqueue(rq, num);
                }
                break;
            case 2:
                if(isFull(pq)) {
                    printf("Priority queue is full. Please try again later.\n\n");
                } else {
                    printf("You have entered the Priority queue. Your number is %d.\n\n", ++num);
                    enqueue(pq, num);
                }
                break;
            case 3:
                if(isEmpty(pq) && isEmpty(rq)) {
                    printf("Cannot dequeue an empty queue.");
                } else if(!isEmpty(pq)) {
                    printf("Calling next customer from Priority Queue. Customer number: %d\n\n", dequeue(pq));
                } else if (isEmpty(pq) && !isEmpty(rq)){
                    printf("Calling next customer from Regular Queue. Customer number: %d\n\n", dequeue(rq));
                }
            break;
            case 4:
            printf("\n-- Current Queue Status --");
            printf("\nRegular Queue:");
                display(rq);
            printf("\nPriority Queue:");
                display(pq);
                printf("\n\n");
            break;
            case 5:
                printf("Exiting program. Goodbye!");
                return 0;
            break;
            default:
            printf("Invalid Choice");
        }
    }

    return 0;
}