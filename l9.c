#include <stdio.h>

#define MAX_FRAMES 10

int main() {
    int frames[MAX_FRAMES], page[MAX_FRAMES];
    int num_frames, num_pages, page_faults = 0, frame_index = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the sequence of page references:\n");
    for (int i = 0; i < num_pages; i++)
        scanf("%d", &page[i]);

    for (int i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1; // Initialize frames with -1 indicating an empty frame

    printf("\nFIFO Page Replacement Algorithm:\n");
    printf("Page Reference\t Page Frames\t\t\t Page Faults\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < num_pages; i++) {
        int page_found = 0;
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == page[i]) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            printf("%d\t\t ", page[i]);
            if (frame_index < num_frames) {
                frames[frame_index++] = page[i];
            } else {
                for (int j = 0; j < num_frames - 1; j++)
                    frames[j] = frames[j + 1];
                frames[num_frames - 1] = page[i];
            }
            page_faults++;
            for (int j = 0; j < num_frames; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
            }
            printf("\t\t\t\t %d\n", page_faults);
        } else {
            printf("%d\t\t No Page Fault\t\t\t\t %d\n", page[i], page_faults);
        }
    }  

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}