#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

int main() {
    int frames[MAX_FRAMES];
    int pageReferences[MAX_FRAMES];
    int n, m, pageFaults = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &m);

    printf("Enter the number of page references: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pageReferences[i]);
    }

    for (int i = 0; i < MAX_FRAMES; ++i) {
        frames[i] = -1; // Initialize all frame values to -1 (indicating empty)
    }

    for (int i = 0; i < n; ++i) {
        bool pageExists = false;
        for (int j = 0; j < m; ++j) {
            if (frames[j] == pageReferences[i]) {
                pageExists = true;
                break;
            }
        }

        if (!pageExists) {
            ++pageFaults;
            int replaceIndex = -1;
            int farthestUse = -1;

            for (int j = 0; j < m; ++j) {
                int k;
                for (k = i + 1; k < n; ++k) {
                    if (frames[j] == pageReferences[k]) {
                        if (k > farthestUse) {
                            farthestUse = k;
                            replaceIndex = j;
                        }
                        break;
                    }
                }
                if (k == n) {
                    replaceIndex = j;
                    break;
                }
            }
            frames[replaceIndex] = pageReferences[i];
        }

        printf("Page References: ");
        for (int j = 0; j < m; ++j) {
            if (frames[j] == -1)
                printf(" - ");
            else
                printf(" %d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}