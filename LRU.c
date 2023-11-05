#include <stdio.h>

int main() {
    int n, a[50], frame[10], no, count = 0;

    printf("\nENTER THE NUMBER OF PAGES: ");
    scanf("%d", &n);

    printf("ENTER THE PAGE NUMBER: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("ENTER THE NUMBER OF FRAMES: ");
    scanf("%d", &no);

    for (int i = 0; i < no; i++)
        frame[i] = -1;

    printf("\nref string\t page frames\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t", a[i]);
        int in_frame = 0;
        int empty_frame = -1;

        for (int k = 0; k < no; k++) {
            if (frame[k] == a[i]) {
                in_frame = 1;
                break;
            } else if (frame[k] == -1) {
                empty_frame = k;
            }
        }

        if (in_frame == 0) {
            if (empty_frame != -1) {
                frame[empty_frame] = a[i];
            } else {
                int lru_frame = 0;
                int lru_time = i;

                for (int k = 0; k < no; k++) {
                    int last_used = i;
                    for (int j = i - 1; j >= 0; j--) {
                        if (a[j] == frame[k]) {
                            last_used = j;
                            break;
                        }
                    }
                    
                    if (last_used < lru_time) {
                        lru_time = last_used;
                        lru_frame = k;
                    }
                }
                frame[lru_frame] = a[i];
            }

            count++;
            for (int k = 0; k < no; k++)
                printf("%d\t", frame[k]);
        }
        printf("\n");
    }

    printf("Page Fault Is %d", count);
    return 0;
}
