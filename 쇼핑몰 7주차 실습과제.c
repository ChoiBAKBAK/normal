#include <stdio.h>
#include <string.h>

#define MAX_NAME 5
#define MAX_LENGTH 50
#define MAX_PRODUCTS 99

typedef struct {
    int id;
    char name[MAX_LENGTH];
    int quantity;    // 입고량
    float price;     // 판매 가격
    int sales;       // 판매량, 초기값 0
} CHOIJUN;

CHOIJUN CHOI[MAX_PRODUCTS];

int productCount = 0;

void addOrUpdateProduct(int id, const char* name, int quantity, float price) {
    for (int i = 0; i < productCount; i++) {
        if (CHOI[i].id == id) {
            CHOI[i].quantity += quantity;  // 입고량 업데이트
            CHOI[i].price = price;  // 판매가격 업데이트
            printf("상품 ID %d가 업데이트되었습니다.\n", id);
            return;
        }
    }

    // 상품이 없을 때 새로 생성
    if (productCount >= MAX_PRODUCTS) {
        printf("상품 갯수를 초과했습니다. 더 이상 상품을 추가할 수 없습니다.\n");
        return;
    }

    CHOI[productCount].id = id;
    strcpy(CHOI[productCount].name, name);
    CHOI[productCount].quantity = quantity;
    CHOI[productCount].price = price;
    CHOI[productCount].sales = 0;  // 판매량 초기화
    productCount++;
    printf("상품 ID %d가 새로 생성되었습니다.\n", id);
}

void sellProduct(int id, int quantity) {
    for (int i = 0; i < productCount; i++) {
        if (CHOI[i].id == id) {
            if (CHOI[i].quantity < quantity) {
                printf("재고가 부족하여 판매할 수 없습니다. (현재 재고: %d)\n", CHOI[i].quantity);
                return;
            }
            CHOI[i].quantity -= quantity;
            CHOI[i].sales += quantity;  // 판매량 업데이트
            printf("상품 ID %d (%s)가 %d개 판매되었습니다.\n", id, CHOI[i].name, quantity);
            return;
        }
    }
    printf("상품 ID %d가 존재하지 않습니다.\n", id);
}

void display1Status(int id) {
    for (int i = 0; i < productCount; i++) {
        if (CHOI[i].id == id) {
            float totalSales = CHOI[i].price * CHOI[i].sales;
            printf("\n상품 ID: %d\n", CHOI[i].id);
            printf("상품명: %s\n", CHOI[i].name);
            printf("상품가격: %.2f\n", CHOI[i].price);
            printf("입고량: %d\n", CHOI[i].quantity);
            printf("판매량: %d\n", CHOI[i].sales);  // 판매량 출력
            printf("총 판매금액: %.2f\n", totalSales);
            return;
        }
    }
    printf("상품 ID %d가 존재하지 않습니다.\n", id);
}

void displayAllStatus(int *array, int *sellitem, int count, float Allsell, float Allitem, int max, int min, int nummax, int nummin) {
    printf("\n재고수량: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("\n총 판매량: %.0f (판매율 %.2f%%)\n", Allsell, Allsell / Allitem * 100);
    printf("가장 많이 판매된 상품: ID %d,%s, 판매량 %d\n", nummax, CHOI[nummax-1].name, CHOI[nummax-1].sales);
    printf("가장 적게 판매된 상품: ID %d,%s, 판매량 %d\n", nummin, CHOI[nummin-1].name ,CHOI[nummin-1].sales);

    for (int i = 0; i < count; i++) {
        if (array[i] < 3) {
            printf("상품 ID %d: %s 재고부족 (%d)\n", i + 1, CHOI[i].name, array[i]);
        }
    }
}

void function(int *array, int count, int *sellitem, int max, int min, int nummax, int nummin, float Allsell, float Allitem) {
    int choice;
    int i;

    while (1) {
        printf("원하는 메뉴를 입력하세요.:(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료)\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { //입고 메뉴
                int id, quantity;
                float price;
                char name[MAX_LENGTH];

                printf("입고 메뉴 실행\n");
                printf("상품 ID 입력: ");
                scanf("%d", &id);

                if (id < 1 || id > MAX_PRODUCTS) {
                    printf("유효하지 않은 상품 ID입니다.\n");
                    break;
                }

                printf("상품명 입력: ");
                scanf("%s", name);
                printf("입고량 입력: ");
                scanf("%d", &quantity);
                printf("판매가격 입력: ");
                scanf("%f", &price);

                addOrUpdateProduct(id, name, quantity, price);
                break;
            }
            case 2: {  // 판매 메뉴
                int id, quantity;
                printf("판매 상품 ID 입력: ");
                scanf("%d", &id);

                printf("판매량 입력: ");
                scanf("%d", &quantity);

                sellProduct(id, quantity);
                break;
            }
            case 3: {
                int id;
                printf("개별 상품 ID 입력: ");
                scanf("%d", &id);
                display1Status(id);  // 개별 상품 현황 출력
                break;
            }
            case 4: {
                displayAllStatus(array, sellitem, count, Allsell, Allitem, max, min, nummax, nummin);  // 전체 상품 현황 출력
                break;
            }
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
