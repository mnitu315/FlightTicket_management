#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char diemden[50];
	char diemdi[50];
	char thoigiankhoihanh[20];
	char thoigianhacanh[20];
	char hanghangkhong[30];
	int thoigianbay;
	char trangthai[30];

}Flight ; 
  
  
  
void addFlight(Flight flights[],int* currentFlightID){
	printf("Enter the flight's departure point:");
	gets(&flights[*currentFlightID].diemden);
	printf("Enter the flight's destination:");
	gets(&flights[*currentFlightID].diemdi);
	printf("Enter the flight's departure time: ");
	gets(&flights[*currentFlightID].thoigiankhoihanh);
	printf("Enter the flight's landing time: ");
	gets(&flights[*currentFlightID].thoigianhacanh);
	printf("Enter the flight's airline brand: ");
	gets(&flights[*currentFlightID].hanghangkhong);
	printf("Enter the flight's status: ");
	gets(&flights[*currentFlightID].trangthai);
	(*currentFlightID)++;
	
	
}


void changeFlight(Flight flights[]){
	int index;
    printf("Enter flight's ID to change: ");
    scanf("%d", &index);
	printf("Enter the flight's departure point:");
	gets(&flights[index].diemden);
	printf("Enter the flight's destination:");
	gets(&flights[index].diemdi);
	printf("Enter the flight's departure time: ");
	gets(&flights[index].thoigiankhoihanh);
	printf("Enter the flight's landing time: ");
	gets(&flights[index].thoigianhacanh);
	printf("Enter the flight's airline brand: ");
	gets(&flights[index].hanghangkhong);
	printf("Enter the flight's status: ");
	gets(&flights[index].trangthai);
	
}

void deleteFlight(Flight flights[],int *totalFlight){
	int choice;
    printf("Enter flight's ID to delete: ");
    scanf("%d", &choice);
	int i;	
    for ( i = choice; i < *totalFlight - 1; i++)
    {
        strcpy(flights[i].diemden, flights[i + 1].diemden);
        strcpy(flights[i].diemdi, flights[i + 1].diemdi);
        strcpy(flights[i].thoigiankhoihanh, flights[i + 1].thoigiankhoihanh);
        strcpy(flights[i].thoigianhacanh, flights[i + 1].thoigianhacanh);
        strcpy(flights[i].hanghangkhong, flights[i + 1].hanghangkhong);
        flights[i].thoigianbay = flights[i + 1].thoigianbay;
        strcpy(flights[i].trangthai, flights[i + 1].trangthai);
    }

    (*totalFlight)--;
}

  
  void showflights(Flight flights[], int index){
  	printf("Diem den:%s\n",flights[index].diemden);
	printf("Diem di:%s\n",flights[index].diemdi);
	printf("Thoi gian khoi hanh:%s\n",flights[index].thoigiankhoihanh);
	printf("Thoi gian ha canh:%s\n",flights[index].thoigianhacanh);
	printf("Hang hang khong:%s\n",flights[index].hanghangkhong);
	printf("Thoi gian bay:%d\n",flights[index].thoigianbay);	
  	
}
  
  
  	
int main(){
	int currentFlightID = 0;
	Flight flights[100];
	addFlight(flights, &currentFlightID);
	showflights(flights, 0);
	
			
		
	return 0;
} 
