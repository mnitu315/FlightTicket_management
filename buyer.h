#pragma once

// cấu trúc người mua vé
#define MAX_LENGTH 50
typedef struct {
    char CCCD[MAX_LENGTH];
    char name[MAX_LENGTH];
    int sdt[MAX_LENGTH];
    char mail[MAX_LENGTH];
} buyer_detail;

void addBuyer(buyer_detail *AnewBuyer);

void displayBuyer(buyer_detail Buyer[], int n);

void changeBuyer(buyer_detail *AnewBuyer);

void WriteBuyerFile(char buyer, buyer_detail Buyer[], int n);

void ReadBuyerFile(char buyer, buyer_detail Buyer[], int *n);