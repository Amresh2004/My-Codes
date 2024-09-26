#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int data;
	struct queue *next;
} Node;

Node *start = NULL, *last = NULL, *ptr;
int pgfault = 0, n, nof;
int a[80];
int n1, i;

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
    static int cnt = 0;
    int j, farthest = -1, index = -1;
    int future_use[80] = {0};
    
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
    } else {  // Optimal replacement
        // For each page in memory, find out when it will next be used
        temp = start;
        for (int frame_idx = 0; temp != NULL; temp = temp->next, frame_idx++) {
            future_use[frame_idx] = -1; // If a page isn't used in the future, it stays -1
            for (j = i + 1; j < n1; j++) { // Future pages
                if (a[j] == temp->data) {
                    future_use[frame_idx] = j; // Store the future index of when it's used next
                    break;
                }
            }
        }

        // Find the page that will not be used for the longest time
        for (int frame_idx = 0; frame_idx < n; frame_idx++) {
            if (future_use[frame_idx] == -1) {  // This page will never be used again
                farthest = frame_idx;
                break;
            } else if (future_use[frame_idx] > farthest) { // Find the page used farthest in future
                farthest = future_use[frame_idx];
                index = frame_idx;
            }
        }

        // Replace the optimal page
        if (index == -1) {  // If a page will never be used again, replace it
            temp = start;
            start = start->next;
            free(temp);
            last->next = ptr;
            last = ptr;
        } else {
            temp = start;
            Node *prev = NULL;
            for (int idx = 0; idx < index; idx++) { // Traverse to the index that needs to be replaced
                prev = temp;
                temp = temp->next;
            }
            if (prev != NULL) {
                prev->next = temp->next;
            } else {
                start = temp->next;
            }
            free(temp);
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
