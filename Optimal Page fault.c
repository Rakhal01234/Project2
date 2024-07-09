#include <stdio.h>

int findOptimal(int pages[], int frame[], int n, int index, int capacity) {
    int pos = -1, farthest = index;
    
    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        
        if (j == n)
            return i;
    }
    
    return (pos == -1) ? 0 : pos;
}

void optimal(int pages[], int n, int capacity) {
    int frame[capacity], page_faults = 0;
    
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
            if (frame[capacity - 1] != -1) {
                int pos = findOptimal(pages, frame, n, i + 1, capacity);
                frame[pos] = pages[i];
            } else {
                for (int j = 0; j < capacity; j++) {
                    if (frame[j] == -1) {
                        frame[j] = pages[i];
                        break;
                    }
                }
            }
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
    
    optimal(pages, n, capacity);
    
    return 0;
}
