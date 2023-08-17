#include <stdio.h>
#include <stdlib.h>
#include "array.h"


int main(){
    int size = 0;
    printf("Enter Size of Array");
    scanf("%d", &size);
    Array* arr1 = new Array(size);
    int ch,x, index;
    do {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");

        printf("enter you choice ");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter an element");
                    scanf("%d",&x);
                    arr1->insertSort(x);
                    break;
            case 2: printf("Enter index ");
                    scanf("%d",&index);
                    x=arr1->remove(index);
                    printf("Deleted Element is %d\n",x);
                    break;
            case 3: printf("Enter element to search ");
                    scanf("%d",&x);
                    index=arr1->binarySearch(x);
                    printf("Element index %d",index);
                    break;
            case 4: printf("Sum is %d\n",arr1->sum());
                    break;
            case 5: arr1->display();
        } 
    } while(ch<6);
    return 0;

    
}