#include<stdio.h>
#include<string.h>
#include<ctype.h>
int front = -1, back = -1;

int isEmpty() {
    if(front == -1 && back == -1) {
        return 1;
    } else {
        return 0;
    }
}
int isFull(int m) {
    if(back == m - 1) {
        return 1;
    } else {
        return 0;
    }
}

void add(int x, int q[], int m) {
    if(isEmpty() == 1) {
        q[0] = x;
        front = 0;
        back = 0;
    } else if (isFull(m) == 1) {
        printf("\nOverflow.");
    } else {
        front = 0;
        back++;
        q[back] = x;
    }

}

int delete(int q[]) {
    if(isEmpty() == 1) {
        printf("\nUnderflow");
        return -1;
    } else {
        int temp = q[front];
        front++;
        return temp;
    }
}

void display(int q[]) {
    if(isEmpty(front, back) == 1) {
        printf("\nUnderflow");
        return;
    } else {
        for(int i=front; i<=back; i++) {
            printf("\n%d", q[i]);
        }
    }
}

int main() {
    int m;
    printf("\nEnter the max size of queue: ");
    scanf("%d", &m);
    int choise, toAdd = 1, front = -1, back = -1, q[20];
    do { 
        printf("\nchoose 1 option: ");
        printf("\n1)Place Order \n2)Display All Ordres \n3)Recieve your order \n4)Exit\n");
        scanf("%d", &choise);
        switch(choise) {
            case 1: add(toAdd, q, m);
                    toAdd++;
                    break;
            case 2: display(q);
                    break;
            case 3: delete(q);
                    break;
            case 4: printf("\nexiting.");
                    break;
            default: printf("\nwrong choice.");
        }

    }while(choise != 4);
    return 0;
}