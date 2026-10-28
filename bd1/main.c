/* APL121 Бие даалт №1 - Сэдэв: Голч дүн (GPA)
 * Дүрэм (README-д мөн бич):
 *  A: 90-100 -> 4.0 | B: 80-89.99 -> 3.0 | C: 70-79.99 -> 2.0
 *  D: 60-69.99 -> 1.0 | F: 0-59.99 -> 0.0
 *  Хичээлийн тоо 3..8, кредит 1..6, оноо 0..100
 *  "Тэргүүний" нөхцөл: голч >= 3.5 && F дүнгүй
 */
#include <stdio.h>

int main(void)
{
    int n, i, rank, best, failCount = 0, totalCredit = 0;
    char name[8][20];
    double score[8], point[8], weighted = 0.0, gpa;
    int credit[8], used[8] = {0};
    char grade[8];

    /* ---- 7. Оролтын шалгалт: do-while ---- */
    do {
        printf("Хичээлийн тоо (3-8): ");
        scanf("%d", &n);
        if (n < 3 || n > 8)
            printf("  Буруу утга! 3-8 хооронд оруулна уу.\n");
    } while (n < 3 || n > 8);

    /* ---- 1. Оролт (scanf) ---- */
    for (i = 0; i < n; i++) {
        printf("\n%d-р хичээл\n", i + 1);
        printf("  Нэр (зайгүй): ");
        scanf("%19s", name[i]);

        do {
            printf("  Кредит (1-6): ");
            scanf("%d", &credit[i]);
            if (credit[i] < 1 || credit[i] > 6)
                printf("  Буруу утга! 1-6 хооронд оруулна уу.\n");
        } while (credit[i] < 1 || credit[i] > 6);

        do {
            printf("  Оноо (0-100): ");
            scanf("%lf", &score[i]);
            if (score[i] < 0 || score[i] > 100)
                printf("  Буруу утга! 0-100 хооронд оруулна уу.\n");
        } while (score[i] < 0 || score[i] > 100);

        /* ---- 3. Нөхцөл: else-if шат ---- */
        /* ---- 5. Дэд алгоритм: оноо -> үсэг, point (Flowgorithm-д Function) ---- */
        if (score[i] >= 90)      { grade[i] = 'A'; point[i] = 4.0; }
        else if (score[i] >= 80) { grade[i] = 'B'; point[i] = 3.0; }
        else if (score[i] >= 70) { grade[i] = 'C'; point[i] = 2.0; }
        else if (score[i] >= 60) { grade[i] = 'D'; point[i] = 1.0; }
        else                     { grade[i] = 'F'; point[i] = 0.0; failCount++; }

        /* ---- 2. Арифметик: жигнэсэн нийлбэр ---- */
        weighted    += point[i] * credit[i];
        totalCredit += credit[i];
    }
    gpa = weighted / totalCredit;

    /* ---- 4. Давталт + хүснэгт (>= 5 мөр боломжтой) ---- */
    printf("\n========== ДҮНГИЙН ХУУДАС ==========\n");
    printf("%-3s %-10s %6s %6s %6s\n", "No", "Course", "Score", "Grade", "Credit");
    for (i = 0; i < n; i++)
        printf("%-3d %-10s %6.2f %6c %6d\n",
               i + 1, name[i], score[i], grade[i], credit[i]);

    printf("\nНийт кредит: %d\n", totalCredit);
    printf("Жигнэсэн голч (GPA): %.2f\n", gpa);

    /* ---- 2. Логик үйлдэл: && ---- */
    if (gpa >= 3.5 && failCount == 0)
        printf("Үнэлгээ: Тэргүүний оюутан\n");
    else
        printf("Үнэлгээ: Хэвийн\n");

    /* ---- 6. Хайлт: давталтаар хамгийн өндөр 3 оноог олох ---- */
    printf("\nХамгийн өндөр 3 дүн:\n");
    for (rank = 1; rank <= 3; rank++) {
        best = -1;
        for (i = 0; i < n; i++)
            if (!used[i] && (best == -1 || score[i] > score[best]))
                best = i;
        used[best] = 1;
        printf("  %d. %-10s %6.2f\n", rank, name[best], score[best]);
    }

    return 0;
}
