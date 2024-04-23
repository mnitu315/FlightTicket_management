#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buyer.h"

#define MAX_LENGTH 50
typedef struct {
    char CCCD[MAX_LENGTH];
    char name[MAX_LENGTH];
    int sdt[MAX_LENGTH];
    char mail[MAX_LENGTH];
} buyer_tail;

// Nhập thông tin người mua vé
void addBuyer(buyer_tail *AnewBuyer) {
    printf("Nhap so CCCD: ");
    scanf("%d", &AnewBuyer->CCCD);
    printf("Nhap ten nguoi mua ve: ");
    scanf("%*c%19[^\n]", AnewBuyer->name);          //đọc vào cả chuỗi (bao gồm dấu cách), chỉ dừng khi gặp \n
    printf("Nhap so sdt: ");
    scanf("%d", &AnewBuyer->sdt);
    printf("Nhap sdt: ");
    scanf("%*c%19[^\n]", AnewBuyer->mail);
}

// In ra thông tin người mua vé
void displayBuyer(buyer_tail AnewBuyer, int n) {
    printf("     Thong tin cua nguoi mua ve     \n");
    printf("So CCCD: %d\n", AnewBuyer.CCCD);
    printf("Nguoi mua ve: %s\n", AnewBuyer.name);
    printf("So sdt: %d\n", AnewBuyer.sdt);
    printf("Dia chi mail cua nguoi mua ve: %s\n", AnewBuyer.mail);
}

// Cập nhật/Sửa thông tin người mua vé
void changeBuyer(buyer_tail *AnewBuyer) {
    printf("Nhap so CCCD: \n");
    scanf("%d", &AnewBuyer->CCCD);
    printf("Nhap ten nguoi mua ve: \n");
    scanf("*c%19[^\n]", AnewBuyer->name);
    printf("Nhap so sdt: \n");
    scanf("%d", &AnewBuyer->sdt);
    printf("Nhap dia chi mail (neu co): \n");
    scanf("%*c%19[^\n]", AnewBuyer->mail);
}

void writeBuyerFile(char buyer, buyer_tail Buyer[], int n) {
    FILE *fp;
    fp = fopen(buyer, "wb"); //mỗi lần ghi mới lại toàn bộ danh sách người mua vé

    for (int i = 0; i < n; i++) {
        fwrite(&Buyer[i], sizeof(buyer_tail), 1, fp);
    }
    puts("Nhap thong tin nguoi mua ve thanh cong !");
    fclose(fp);
}

void readBuyerFile(char buyer, buyer_tail Buyer[], int *n) {
    FILE *fp;
    fp = fopen(buyer, "rb");
    if (fp == NULL) {
        printf("Cannot open file %s\n", buyer);
        return;
    }

    int i = 0;
    while (!feof(fp)) {
        fread(&Buyer[i], sizeof(buyer_tail), 1, fp);
        if (feof(fp)) {
            break;
        }
        i++;
    }

    *n = i;

    fclose(fp);
}
