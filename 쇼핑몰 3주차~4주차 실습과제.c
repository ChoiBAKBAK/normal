#include <stdio.h>
#include <string.h>

#define MAX_NAME 5
#define MAX_LENGTH 50

typedef struct {
    int id;
    char name[MAX_LENGTH];
} CHOIJUN;

CHOIJUN CHOINAME[MAX_NAME];

void ItemName() {
    for(int i = 0; i < MAX_NAME; i++) {
        CHOINAME[i].id = i + 1;
        printf("ID %d 상품명: ", CHOINAME[i].id);
        scanf("%s", CHOINAME[i].name);
    }
}

void displayNAME(int *array, int *sellitem, int count, float Allsell, float Allitem, int max, int min, int nummax, int nummin) {
    printf("\n재고수량: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    printf("\n총 판매량: %.0f (판매율 %.2f%%)\n", Allsell, Allsell / Allitem * 100);
    printf("가장 많이 판매된 상품: ID %d,%s, 판매량 %d\n", nummax,CHOINAME[nummax-1].name, max);
    printf("가장 적게 판매된 상품: ID %d,%s, 판매량 %d\n", nummin,CHOINAME[nummin-1].name ,min);

    for (int i = 0; i < count; i++) {
        if (array[i] < 3) {
            printf("상품 ID %d: %s 재고부족 (%d)\n", i + 1, CHOINAME[i].name, array[i]);
        }
    }
}

void function(int *array, int count, int *sellitem, int max, int min, int nummax, int nummin, float Allsell, float Allitem) {
    int choice;
    int i;

    while (1) {
        printf("원하는 메뉴를 입력하세요.:(1. 입고, 2. 판매, 3. 상품현황, 4.상품명 입력, 5. 종료)\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n");
                int stockChoice;
                scanf("%d", &stockChoice);
                if (stockChoice == 1) {
                    int total;
                    printf("전체 입고 수량 입력: ");
                    scanf("%d", &total);
                    for (i = 0; i < count; i++) {
                        array[i] += total;  
                    }
                } else if (stockChoice == 2) {
                    int itemIndex, quantity;
                    printf("상품 ID 입력: ");
                    scanf("%d", &itemIndex);
                    printf("입고 수량 입력: ");
                    scanf("%d", &quantity);
                    if (itemIndex > 0 && itemIndex <= count) {
                        array[itemIndex - 1] += quantity;  
                    } else {
                        printf("유효하지 않은 상품 ID입니다.\n");
                    }
                }
                break;
            case 2:
                printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n");
                int stockChoice1;
                scanf("%d", &stockChoice1);
                if (stockChoice1 == 1) {
                    int total1;
                    printf("전체 판매 수량 입력: ");
                    scanf("%d", &total1);
                    for (i = 0; i < count; i++) {
                        array[i] -= total1;  
                    }
                } else if (stockChoice1 == 2) {
                    int itemIndex1, quantity1;
                    printf("판매상품 ID 입력: ");
                    scanf("%d", &itemIndex1);
                    printf("판매 수량 입력: ");
                    scanf("%d", &quantity1);
                    if (itemIndex1 > 0 && itemIndex1 <= count) {
                        array[itemIndex1 - 1] -= quantity1;
                    }
                }
                break;
            case 3:
                displayNAME(array, sellitem, count, Allsell, Allitem, max, min, nummax, nummin);
                break;
            case 4:
                ItemName();
                break;
            case 5:
                printf("프로그램 종료.\n");
                return;  
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
}

int main() {
    int array[99];
    int sellitem[99];
    int count = 0;
    int max = 0;
    int min = 1;
    int nummax = 0;
    int nummin = 0;
    float Allsell = 0;
    float Allitem = 0;
    int i = 0;

    printf("상품 개수(종류) 입력:");
    scanf("%d", &count);
    printf("상품 별 입고 수량 입력:");
    for (i = 0; i < count; i++) {
        scanf("%d", &array[i]);
    }
    printf("상품 별 판매수량 입력:");
    for (i = 0; i < count; i++) {
        scanf("%d", &sellitem[i]);
    }

    for (i = 0; i < count; i++) Allitem += array[i];
    for (i = 0; i < count; i++) if (sellitem[i] > max) max = sellitem[i];
    for (i = 0; i < count; i++) {
        nummax++;
        if (max == sellitem[i]) {
            break;
        }
    }
    for (i = 0; i < count; i++) if (sellitem[i] < min) min = sellitem[i];
    for (i = 0; i < count; i++) {
        nummin++;
        if (min == sellitem[i]) {
            break;
        }
    }
    for (i = 0; i < count; i++) array[i] -= sellitem[i];
    printf("\n재고수량: ");
    for (i = 0; i < count; i++)
        printf("%d ", array[i]);
    for (i = 0; i < count; i++) Allsell += sellitem[i];
    printf("\n총 판매량 : %2.0f(판매율 %0.2f)", Allsell, Allsell / Allitem * 100);
    printf("\n가장 많이 판매된 상품 : ID %d, 판매량 %d\n가장 적게 판매된 상품 : ID %d, 판매량 %d", nummax, max, nummin, min);
    for (i = 0; i < count; i++) {
        if (array[i] < 3) {
            printf("\n상품 ID %d : 재고부족(%d)\n", i + 1, array[i]);
        }
    }

    function(array, count, sellitem, max, min, nummax, nummin, Allsell, Allitem);
    return 0;
}
