#include <stdio.h>

#define NUM_DAYS    2
#define NUM_PRAYERS 5

int main() {
    const char *prayers[NUM_PRAYERS] = {
        "الفجر",
        "الظهر",
        "العصر",
        "المغرب",
        "العشاء"
    };

    for (int day = 1; day <= NUM_DAYS; day++) {
        printf("\n=== اليوم %d ===\n", day);

        int completed = 0;

        for (int i = 0; i < NUM_PRAYERS; i++) {
            char answer;
            printf("هل قضيت صلاة %s؟ (y/n): ", prayers[i]);
            scanf(" %c", &answer);

            if (answer == 'y' || answer == 'Y') {
                printf("  [✓] صلاة %s تمت\n", prayers[i]);
                completed++;
            } else {
                printf("  [ ] صلاة %s لم تُقضَ\n", prayers[i]);
            }
        }

        if (completed == NUM_PRAYERS) {
            printf("\n✅ تم يوم! أكملت جميع صلوات اليوم %d.\n", day);
        } else {
            printf("\n⚠️  لم تكتمل صلوات اليوم %d. أُنجز %d من %d صلوات.\n",
                   day, completed, NUM_PRAYERS);
        }
    }

    printf("\n=== انتهى البرنامج ===\n");
    return 0;
}
