#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 10
#define MAX_SEATS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int booked;
} Seat;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int numSeats;
    Seat seats[MAX_SEATS];
} Flight;

Flight flights[MAX_FLIGHTS];
int numFlights = 0;

void createFlight() {
    if (numFlights >= MAX_FLIGHTS) {
        printf("Khong the tao them chuyen bay. Da qua gioi han.\n");
        return;
    }
    Flight newFlight;
    printf("Nhap ID chuyen bay: ");
    scanf("%d", &newFlight.id);
    printf("Nhap ten chuyen bay: ");
    scanf("%s", newFlight.name);
    printf("Nhap so ghe: ");
    scanf("%d", &newFlight.numSeats);

    int i;
    for (i = 0; i < newFlight.numSeats; i++) {
        newFlight.seats[i].id = i + 1;
        strcpy(newFlight.seats[i].name, "Co san");
        newFlight.seats[i].booked = 0;
    }

    flights[numFlights++] = newFlight;
    printf("Tao chuyen bay thanh cong.\n");
}

void displayFlights() {
    printf("Chuyen bay:\n");
    int i;
    for (i = 0; i < numFlights; i++) {
        printf("ID: %d, Ten: %s, Ghe ngoi: %d\n", flights[i].id, flights[i].name, flights[i].numSeats);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Tao chuyen bay\n");
        printf("2. Hien chuyen bay\n");
        printf("3. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFlight();
                break;
            case 2:
                displayFlights();
                break;
            case 3:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Nhap lai lan nua.\n");
        }
    } while (choice != 3);

    return 0;
}

