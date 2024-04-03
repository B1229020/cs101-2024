#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotte_set[5][7];
}lotto_record_t;

int input(int n){
    printf("請問你要買幾組樂透彩：");
    scanf("%d", &n);
    if (n < 0 || n > 5) {
        return 1;
    }
    return n;
}

void generate_lotto_numbers(int n) {
    FILE *fp;
    fp = fopen("lotto.txt", "w");

    srand(1); // 初始化

    fprintf(fp, "========= lotto649 =========\n");
    for (int i = 1; i <= n; ++i) {
        fprintf(fp, "[%d]: ", i);

        int lotto[7];
        for (int j = 0; j < 7; ++j) {
            lotto[j] = rand() % 69 + 1;
            for (int k = 0; k < j; ++k) {
                if (lotto[j] == lotto[k]) {
                    --j;
                    break;
                }
            }
        }

        for (int j = 0; j < 7; ++j) {
            fprintf(fp, "%02d", lotto[j]);
            if (j != 6) {
                fprintf(fp, " ");
            }
        }
        fprintf(fp, "\n");
    }

    for (int i = n + 1; i <= 5; ++i) {// 補充未使用的行數
        fprintf(fp, "[%d]: __ __ __ __ __ __ __\n", i);
    }
    fprintf(fp, "========= csie@CGU =========\n");

    fclose(fp);
}

void lotto_winning(int *win_num){
    printf("請輸入中獎號碼：");
    scanf("%d %d %d", &win_num[0], &win_num[1], &win_num[2]);
    printf("輸入的中獎號碼為：%02d %02d %02d", win_num[0], win_num[1], win_num[2]);
}

int main() {
    int num_tickets;
    num_tickets = input(num_tickets);

    if(num_tickets >= 1 && num_tickets <= 5){
        generate_lotto_numbers(num_tickets);
    }
    else{
        int win_num[3];
        lotto_winning(win_num);//輸入樂透號碼
    }

    return 0;
}
