#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }

    return pos;
}

void LRU(int pages[], int n, int frames) {
    int frame[frames], time[frames], page_faults = 0, i, j;

    // Initialize frames and access time
    for (i = 0; i < frames; ++i) {
        frame[i] = -1; // Initializing frames with -1, indicating empty frame
        time[i] = 0;   // Initializing access time for LRU
    }

    printf("\nLRU Page Replacement Algorithm:\n");

    for (i = 0; i < n; ++i) {
        int flag = 0; // Flag to indicate if page is already in frame

        // Check if page is already in frame
        for (j = 0; j < frames; ++j) {
            if (frame[j] == pages[i]) {
                time[j] = i + 1; // Update access time for recently used page
                flag = 1;
                break;
            }
        }

        // Page replacement if not in frame
        if (flag == 0) {
            int pos = findLRU(time, frames); // Find the least recently used page
            frame[pos] = pages[i];          // Replace the least recently used page
            time[pos] = i + 1;              // Update access time for the replaced page
            page_faults++;
        }

        printf("\nAfter page %d: ", pages[i]);

        // Display the current state of frames
        for (j = 0; j < frames; ++j) {
            printf("%d\t", frame[j]);
        }
    }

    printf("\n\nTotal Page Faults: %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES], n, frames;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference sequence: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    LRU(pages, n, frames);

    return 0;
}