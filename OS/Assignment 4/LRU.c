#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int data;
	struct queue *next;
} Node;

Node *start = NULL, *last = NULL, *ptr;
int pgfault = 0, n, nof;
int a[80];
int n1, i, k, min = 0;

void printUI(int page, int page_fault) {
    printf("\n------------------------------------------------");
    printf("\n Page Request : %2d ", page);
    Node *temp;
    for (temp = start; temp != NULL; temp = temp->next) {
        printf(" |      %2d ", temp->data);
    }
    printf(" |   -->   Page Faults: %d", page_fault);
    printf("\n------------------------------------------------");
}

int search(int page) {
    for (ptr = start; ptr != NULL; ptr = ptr->next) {
        if (page == ptr->data)
            return 1;
    }
    return 0;
}

void addlist(int page) {
    Node *ptr = NULL, *temp, *ptr1 = NULL, *prev = NULL;
    int cnt1 = 1;
    static int cnt = 0;
    int j;

    ptr = (Node *)malloc(sizeof(Node));
    ptr->data = page;
    ptr->next = NULL;

    if (start == NULL) {  // Empty queue
        start = last = ptr;
        cnt++;
    } else if (cnt < n) {  // Less than max frames
        last->next = ptr;
        last = ptr;
        last->next = NULL;
        cnt++;
    } else {  // Replace page using LRU
        min = 0;
        k = 0;

        for (temp = start; temp != NULL; prev = temp, temp = temp->next) {
            for (j = i + 1; j < n1; j++) {
                if (a[j] == temp->data) {
                    k = j;
                    break;
                }
            }
            if (min <= k) {
                min = k;
                ptr1 = temp;
            }
        }

        if (ptr1 == start) {  // If victim page is first
            start = start->next;
            free(ptr1);
            last->next = ptr;
            last = ptr;
        } else if (ptr1 == last) {  // If victim page is last
            last->data = ptr->data;
        } else {  // Victim is in the middle
            prev->next = ptr1->next;
            free(ptr1);
            last->next = ptr;
            last = ptr;
        }
    }
}

void print() {
    Node *ptr;
    printf("\nCurrent Frame: ");
    for (ptr = start; ptr != NULL; ptr = ptr->next)
        printf("%d\t", ptr->data);
    printf("\n\n");
}

int main() {
    printf("\nHow many Frames? ");
    scanf("%d", &n);

    printf("\nEnter the number of pages: ");
    scanf("%d", &n1);

    for (i = 0; i < n1; i++) {
        printf("\nEnter the Page no %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n1; i++) {
        if (search(a[i]) == 0) {
            addlist(a[i]);
            pgfault++;
            printf("\nPage fault Occurs");
            print();
        }
        printUI(a[i], pgfault);
    }
    
    printf("\nTotal number of Page Faults = %d\n", pgfault);
    
    return 0;
}
