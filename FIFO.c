#include <stdio.h>

void fifo(int pages[], int n, int capacity) {
    int frame[capacity], index = 0, page_faults = 0;
    
    for (int i = 0; i < capacity; i++)
        frame[i] = -1;
    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % capacity;
            page_faults++;
        }
        
        // Print frame content for visualization
        printf("Frame: ");
        for (int j = 0; j < capacity; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    
    printf("Page Faults: %d\n", page_faults);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    
    fifo(pages, n, capacity);
    
    return 0;
}
