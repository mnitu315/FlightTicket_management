#ifndef AIRPLANE_SEAT_MANAGEMENT_H
#define AIRPLANE_SEAT_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 100

// Define structure for a seat
struct Seat {
    int seatNumber;
    int flightNumber;
    int booked;
};

// Function prototypes for seat management
void saveToFile(struct Seat seats[], int numSeats);
void loadFromFile(struct Seat seats[], int *numSeats);
void addSeat(struct Seat seats[], int *numSeats);
void deleteSeat(struct Seat seats[], int *numSeats);
void editSeat(struct Seat seats[], int numSeats);
void displaySeats(struct Seat seats[], int numSeats);

#endif 
