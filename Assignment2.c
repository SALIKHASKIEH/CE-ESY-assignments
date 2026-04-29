#include <stdio.h>
#include <string.h>

#define NUM_PRAYERS 5
#define NUM_DAYS 2

const char *prayerNames[NUM_PRAYERS] = {
    "الفجر",
    "الظهر",
    "العصر",
    "المغرب",
    "العشاء"
};

void printStatus(int done[NUM_PRAYERS]) {
    printf("\n--- حالة الصلوات ---\n");
    for (int i = 0; i < NUM_PRAYERS; i++) {
        printf("[%s] %s\n", done[i] ? "X" : " ", prayerNames[i]);
    }
    printf("--------------------\n");
}

int allDone(int done[NUM_PRAYERS]) {
    for (int i = 0; i < NUM_PRAYERS; i++) {
        if (!done[i]) return 0;
    }
    return 1;
}

int main() {
    for (int day = 1; day <= NUM_DAYS; day++) {
        int done[NUM_PRAYERS] = {0};
        int remaining = NUM_PRAYERS;

        printf("\n========== اليوم %d ==========\n", day);

        while (remaining > 0) {
            printStatus(done);
            printf("\nاختر رقم الصلاة لتأديتها (1-%d): ", NUM_PRAYERS);

            int choice;
            if (scanf("%d", &choice) != 1) {
                printf("ادخل رقماً صحيحاً.\n");
                while (getchar() != '\n');
                continue;
            }

            if (choice < 1 || choice > NUM_PRAYERS) {
                printf("الرجاء إدخال رقم بين 1 و%d.\n", NUM_PRAYERS);
                continue;
            }

            int idx = choice - 1;
            if (done[idx]) {
                printf("صلاة %s تم أداؤها مسبقاً.\n", prayerNames[idx]);
            } else {
                done[idx] = 1;
                remaining--;
                printf("تم تأدية صلاة %s ✓\n", prayerNames[idx]);
            }
        }

        printStatus(done);
        printf("\n🎉 تم قضاء جميع صلوات اليوم %d!\n", day);
    }

    printf("\n✅ تم الانتهاء من قضاء صلوات اليومين. جزاك الله خيراً!\n");
    return 0;
}
