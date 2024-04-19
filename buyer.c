#include <stdio.h>
#include <string.h>

struct Nguoimuave {
    int CCCD;
    char name[50];
    int sdt;
    char mail[50];

};
typedef struct Nguoimuave buyer;

void addPurchaser(buyer *a) {
    printf("Nhap so CCCD: ");
    scanf("%d", &a->CCCD);
    getchar();
    printf("Nhap ten nguoi mua ve: ");
    fgets(a->name, sizeof(a->name), stdin);
    printf("Nhap so sdt: ");
    scanf("%d", &a->sdt);
    getchar();
    printf("Nhap dia chi mail (neu co): ");
    fgets(a->mail, sizeof(a->mail), stdin);
}

void displayPurchaser(buyer a) {
    printf("     Thong tin cua nguoi mua ve     \n");
    printf("So CCCD: %d\n", a.CCCD);
    printf("Nguoi mua ve: %s\n", a.name);
    printf("So sdt: %d\n", a.sdt);
    printf("Dia chi mail cua nguoi mua ve: %s\n", a.mail);
}

void changePurchaser(buyer *a) {
    printf("Nhap so CCCD: \n");
    scanf("%d", &a->CCCD);
    getchar();
    printf("Nhap ten nguoi mua ve: \n");
    fgets(a->name, sizeof(a->name), stdin);
    printf("Nhap so sdt: \n");
    scanf("%d", &a->sdt);
    getchar();
    printf("Nhap dia chi mail (neu co): \n");
    fgets(a->mail, sizeof(a->mail), stdin);
}
int main () {
    buyer a;
    int option;
    option = 0;
    do {
        printf("1. Vui long nhap thong tin nguoi mua ve \n");
        printf("2. Thay doi thong tin nguoi mua ve \n");
        printf("3. Thong tin nguoi mua ve da cap nhat \n");
        printf("4. Exit \n");
        printf("Choose your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Nhap thong tin nguoi mua ve\n");
                addPurchaser(&a);
                break;
            case 2:
                printf("Thay doi thong tin nguoi mua ve\n");
                changePurchaser(&a);
                break;
            case 3:
                printf("Thong tin nguoi mua ve da cap nhat\n");
                displayPurchaser(a);
                break;
            case 4:
                printf("Thong tin da duoc cap nhat \n");
                break;
            default:
                printf ("Invaild option\n");
                break;
        }
    } while (option != 4);
    return 0;
}

