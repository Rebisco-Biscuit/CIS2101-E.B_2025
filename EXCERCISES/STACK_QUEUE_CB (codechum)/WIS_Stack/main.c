#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "arrayStack.h"

int main() {
    Stack stack[3];
    
    for(int i=0; i<3; i++) {
        initializeStack(&stack[i]);
      }

    int choice;
    int fullCtr=0;
    
    while(1) {
        printf("--- Warehouse Inventory Management System ---\n");
        printf("1. Push a container\n");        
        printf("2. Pop a container\n");
        printf("3. Check if a container exists\n");
        printf("4. Display all stacks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
    
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                int value;
                printf("Enter container ID to push: ");
                scanf("%d", &value);
                if(fullCtr < 3) {
                    if(isFull(&stack[fullCtr])) {
                        ++fullCtr;
                    }
                        push(&stack[fullCtr], value);
                        printf("Container %d pushed successfully.\n", value);                           
                }
            break;
            
            case 2:
                if(isEmpty(&stack[fullCtr]) == 1 && fullCtr == 0) {
                    printf("Error: All stacks are empty. Cannot pop container.\n");
                } else if (fullCtr > 0){
                    printf("Container %d popped successfully.\n", pop(&stack[fullCtr]));                    
                    pop(&stack[fullCtr]);
                    if(isEmpty(&stack[fullCtr])) {
                      fullCtr--;          
                    }
                } else if(fullCtr == 0 && isEmpty(&stack[fullCtr]) == 0) {
                    printf("Container %d popped successfully.\n", pop(&stack[fullCtr]));
                }
                break;
                
            case 3:
                int check;
                printf("Enter container ID to check: ");
                scanf("%d", &check);
                
                int fCtr = fullCtr;
                bool found = false;
                
                while (fCtr >= 0) {
                    bool isFound = findContainer(&stack[fCtr], check);
                    if (isFound) {
                        printf("Container %d exists in a stack.\n", check);
                        found = true;
                        break;
                    }
                    fCtr--;
                }
            
                if (!found) {
                    printf("Container %d does not exist in any stack.\n", check);
                }
                break;

            case 4:
                for(int i=0; i<3; i++) {
                    printf("\n--- Stack %d ---", i+1);
                    displayStack(&stack[i]);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting program.");
                return 0;
            default:
                printf("Invalid choice.");
        }
        printf("\n");
    }

    return 0;
}