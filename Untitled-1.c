#include <stdio.h>

int main() {
    int n, m, pages[100], frames[10], page_faults = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page references: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        frames[i] = -1; // Initialize frames with -1 to represent empty frames.
    }

    printf("\nReference String\tPage Frames\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t", pages[i]);

        int page_found = 0;
        int frame_to_replace = -1;

        for (int j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                page_found = 1;
                break;
            }

            if (frame_to_replace == -1) {
                for (int k = i + 1; k < n; k++) {
                    if (pages[k] == frames[j]) {
                        frame_to_replace = j;
                        break;
                    }
                }
            }
        }

        if (!page_found) {
            if (frame_to_replace != -1) {
                frames[frame_to_replace] = pages[i];
            } else {
                // Find the page that will not be used for the longest time in the future.
                int max_distance = -1;
                for (int j = 0; j < m; j++) {
                    int distance = 0;
                    for (int k = i + 1; k < n; k++) {
                        if (pages[k] == frames[j]) {
                            break;
                        }
                        distance++;
                    }
                    if (distance > max_distance) {
                        max_distance = distance;
                        frame_to_replace = j;
                    }
                }
                frames[frame_to_replace] = pages[i];
            }

            page_faults++;
        }

        for (int j = 0; j < m; j++) {
            printf("%d\t", frames[j]);
        }

        printf("\n");
    }

    printf("Page Faults: %d\n", page_faults);

    return 0;
}
