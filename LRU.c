#include <stdio.h>

void lru(int pages[], int n, int capacity) {
    int frame[capacity], time[capacity], page_faults = 0;
    
    for (int i = 0; i < capacity; i++)
        frame[i] = -1;
    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                time[j] = i;
                break;
            }
        }
        
        if (!found) {
            int lru = 0;
            for (int j = 1; j < capacity; j++) {
                if (frame[j] == -1 || time[j] < time[lru])
                    lru = j;
            }
            
            frame[lru] = pages[i];
            time[lru] = i;
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
    
    lru(pages, n, capacity);
    
    return 0;
}
