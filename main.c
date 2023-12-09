#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <stdbool.h>


#define N 10
 
//Declaring Functions of the Program
double meanCalculator(double *arr, int n);
void readLine(FILE *file, double arr[]);
double slopeCalculator(double arrX[],double arrY[], double meanX, double meanY);
double interceptCalculator(double meanY, double meanX, double b1);

//Declaring Functions of Queue Data Structure
void initializingQueue(struct queue *myQueue);
int isEmpty(struct queue *myQueue);
void insert(struct queue *myQueue, double data);
double delete(struct queue *myQueue);
void printQueue(struct queue *myQueue);
void freeQueue(struct queue *myQueue);


int main() {

    FILE *characteristics = fopen("Characteristics.txt", "r");
    FILE *prices = fopen("Prices.txt", "r");
    
    if (0 == characteristics || 0 == prices){
    printf("Error: Could not open the file.\n");
    return 1;
}    



  struct house myHouse;

readLine(characteristics, myHouse.area);
readLine(characteristics, myHouse.bedrooms);
readLine(characteristics, myHouse.floors);
readLine(characteristics, myHouse.bathrooms);
readLine(characteristics, myHouse.amenities);
readLine(characteristics, myHouse.garden);
readLine(characteristics, myHouse.renovated);
readLine(characteristics, myHouse.furniture);
readLine(characteristics, myHouse.criminality);
readLine(prices, myHouse.price);

struct apartment myApartment;

readLine(characteristics, myApartment.areaAp);
readLine(characteristics, myApartment.bedroomsAp);
readLine(characteristics, myApartment.parkingAreaAp);
readLine(characteristics, myApartment.bathroomsAp);
readLine(characteristics, myApartment.amenitiesAp);
readLine(characteristics, myApartment.floorNumberAp);
readLine(characteristics, myApartment.renovatedAp);
readLine(characteristics, myApartment.furnitureAp);
readLine(characteristics, myApartment.criminalityAp);
readLine(prices, myApartment.priceAp);

//Calculating Values then Storing in Queue
double meanArea = meanCalculator(myHouse.area, N);
double meanBedrooms = meanCalculator(myHouse.bedrooms, N);
double meanFloors = meanCalculator(myHouse.floors, N);
double meanBathrooms = meanCalculator(myHouse.bathrooms, N);
double meanAmenities = meanCalculator(myHouse.amenities, N);
double meanGarden = meanCalculator(myHouse.garden, N);
double meanRenovated = meanCalculator(myHouse.renovated, N);
double meanFurniture = meanCalculator(myHouse.furniture, N);
double meanCriminality = meanCalculator(myHouse.criminality, N);
double meanPrices = meanCalculator(myHouse.price, N);

double meanAreaAp = meanCalculator(myApartment.areaAp, N);
double meanBedroomsAp = meanCalculator(myApartment.bedroomsAp, N);
double meanParkingAp = meanCalculator(myApartment.parkingAreaAp, N);
double meanBathroomsAp = meanCalculator(myApartment.bathroomsAp, N);
double meanAmenitiesAp = meanCalculator(myApartment.amenitiesAp, N);
double meanFloorAp = meanCalculator(myApartment.floorNumberAp, N);
double meanRenovatedAp = meanCalculator(myApartment.renovatedAp, N);
double meanFurnitureAp = meanCalculator(myApartment.furnitureAp, N);
double meanCriminalityAp = meanCalculator(myApartment.criminalityAp, N);
double meanPricesAp = meanCalculator(myApartment.priceAp, N);


struct queue means;
struct queue meansAp;
initializingQueue(&means);
initializingQueue(&meansAp);

insert(&means, meanArea);
insert(&means, meanBedrooms);
insert(&means, meanParkingAp);
insert(&means, meanBathroomsAp);
insert(&means, meanAmenitiesAp);
insert(&means, meanFloorAp);
insert(&means, meanRenovatedAp);
insert(&means, meanFurnitureAp);
insert(&means, meanCriminalityAp);
insert(&means, meanPricesAp);


insert(&meansAp, meanAreaAp);
insert(&meansAp, meanBedroomsAp);
insert(&meansAp, meanParkingAp);
insert(&meansAp, meanBathroomsAp);
insert(&meansAp, meanAmenitiesAp);
insert(&meansAp, meanFloorAp);
insert(&meansAp, meanRenovatedAp);
insert(&meansAp, meanFurnitureAp);
insert(&meansAp, meanCriminalityAp);
insert(&meansAp, meanPricesAp);

double b0,b1,b2,b3,b4,b5,b6,b7,b8,b9;
double b0A,b1A,b2A,b3A,b4A,b5A,b6A,b7A,b8A,b9A;

b1 = slopeCalculator(myHouse.area, myHouse.price, meanArea, meanPrices);
b0 = interceptCalculator(meanPrices, meanArea, b1);
b2 = slopeCalculator(myHouse.bedrooms, myHouse.price, meanBedrooms, meanPrices);
b3 = slopeCalculator(myHouse.floors, myHouse.price, meanFloors, meanPrices);
b4 = slopeCalculator(myHouse.bathrooms, myHouse.price, meanBathrooms, meanPrices);
b5 = slopeCalculator(myHouse.amenities, myHouse.price, meanAmenities, meanPrices);
b6 = slopeCalculator(myHouse.garden, myHouse.price, meanGarden, meanPrices);
b7 = slopeCalculator(myHouse.renovated, myHouse.price, meanRenovated, meanPrices);
b8 = slopeCalculator(myHouse.furniture, myHouse.price, meanFurniture, meanPrices);
b9 = slopeCalculator(myHouse.criminality, myHouse.price, meanCriminality, meanPrices);

b1A = slopeCalculator(myApartment.areaAp, myApartment.priceAp, meanAreaAp, meanPricesAp);
b0A = interceptCalculator(meanPricesAp, meanAreaAp, b1A);
b2A = slopeCalculator(myApartment.bedroomsAp, myApartment.priceAp, meanBedroomsAp, meanPrices);
b3A = slopeCalculator(myApartment.parkingAreaAp, myApartment.priceAp, meanFloorAp, meanPrices);
b4A = slopeCalculator(myApartment.bathroomsAp, myApartment.priceAp, meanBathroomsAp, meanPrices);
b5A = slopeCalculator(myApartment.amenitiesAp, myApartment.priceAp, meanAmenitiesAp, meanPrices);
b6A = slopeCalculator(myApartment.floorNumberAp, myApartment.priceAp, meanFloorAp, meanPrices);
b7A = slopeCalculator(myApartment.renovatedAp, myApartment.priceAp, meanRenovatedAp, meanPrices);
b8A = slopeCalculator(myApartment.furnitureAp, myApartment.priceAp, meanFurnitureAp, meanPrices);
b9A = slopeCalculator(myApartment.criminalityAp, myApartment.priceAp, meanCriminalityAp, meanPrices);


struct queue slopes;
initializingQueue(&slopes);
insert(&slopes, b0);
insert(&slopes, b1);
insert(&slopes, b2);
insert(&slopes, b3);
insert(&slopes, b4);
insert(&slopes, b5);
insert(&slopes, b6);
insert(&slopes, b7);
insert(&slopes, b8);
insert(&slopes, b9);


struct queue slopesAp;
initializingQueue(&slopesAp);
insert(&slopesAp, b0A);
insert(&slopesAp, b1A);
insert(&slopesAp, b2A);
insert(&slopesAp, b3A);
insert(&slopesAp, b4A);
insert(&slopesAp, b5A);
insert(&slopesAp, b6A);
insert(&slopesAp, b7A);
insert(&slopesAp, b8A);
insert(&slopesAp, b9A);




fclose(characteristics);
fclose(prices);
//Freeing dynamically created memory space
freeQueue(&means);
freeQueue(&slopes);
freeQueue(&meansAp);
freeQueue(&slopesAp);
  
    

//Asking user to Enter Data
struct house userHouse;
struct apartment userApartment;

printf("Please Choose a House or an Apartment (1-House, 2-Apartment)\n");

int choice;
scanf("%d", &choice);
long priceOfApartment = 0;
long priceOfHouse = 0;


while (1){

 



switch (choice)
{

case 1:

printf("Please Enter The Area of The House.\n");
scanf("%lf", &userHouse.area[0]);
printf("Please Enter The Number of Bedrooms of The House.\n");
scanf("%lf", &userHouse.bedrooms[0]);
printf("Please Enter The Number of Floors of The House.\n");
scanf("%lf", &userHouse.floors[0]);
printf("Please Enter The Number of Bathrooms of The House.\n");
scanf("%lf", &userHouse.bathrooms[0]);


while(1){
printf("Please Rate from 1 to 5 The Amenities of The House.\n");
scanf("%lf", &userHouse.amenities[0]);

if(userHouse.amenities[0] < 1 || userHouse.amenities[0] > 5){
printf("Invalid Number!\n");
}
else{
break;
}
}



while (1){
printf("Please Enter Whether The House Has a Garden or Not (1-yes, 0-no).\n");
scanf("%lf", &userHouse.garden[0]);

if(userHouse.garden[0] != 1 && userHouse.garden[0] != 0){
printf("Invalid Number!\n");
}
else{
break;
}
}

while (1){

printf("Please Enter Whether The House is Renovated or Not (1-yes, 0-no).\n");
scanf("%lf", &userHouse.renovated[0]);

if(userHouse.renovated[0] != 1 && userHouse.renovated[0] != 0){
printf("Invalid Number!\n");
}
else{
break;
}
}


while (1){
printf("Please Enter Whether The House Has Furniture or Not (1-yes, 0-no).\n");
scanf("%lf", &userHouse.furniture[0]);


if(userHouse.furniture[0] != 1 && userHouse.furniture[0] != 0){
printf("Invalid Number!\n");
}
else{
break;
}
}

while(1){
printf("Please Rate from 1 to 5 The Degree of Criminality of The Place The House is Located.\n");
scanf("%lf", &userHouse.criminality[0]);

if(userHouse.criminality[0] < 1 || userHouse.criminality[0] > 5){
printf("Invalid Number!\n");
}
else{
break;
}
}

             

priceOfHouse = 5*b0 + (b1*userHouse.area[0])+(b2*userHouse.bedrooms[0])+(b3*userHouse.floors[0])+(b4*userHouse.bathrooms[0])+(b5*userHouse.amenities[0])+(b6*userHouse.garden[0])+(b7*userHouse.renovated[0])+ (b8*userHouse.furniture[0])+(b9*userHouse.criminality[0]);
priceOfHouse = priceOfHouse - (priceOfHouse % 1000);
printf("The approximate price of the house is: %ld $\n", priceOfHouse);
printf("For Additional Information Please Check Output.exe File\n");


FILE *outputFile = fopen("Output.txt", "w");



if(0 == outputFile){
    printf("Failed to open the file");
    return 1;
}

fprintf(outputFile, "Here are The Characteristics of The House\n\n");
fprintf(outputFile, "Area      Bedrooms   Floors   Bathrooms   Amenities   Garden   Renovated   Furniture   Criminality\n");
fprintf(outputFile, "%.1f    %.1f      %.1f       %.1f       %.1f       %.1f      %.1f         %.1f                 %.1f \n\n\n\n", userHouse.area[0],
                                                                                                                 userHouse.bedrooms[0],
                                                                                                                 userHouse.floors[0],
                                                                                                                 userHouse.bathrooms[0],
                                                                                                                 userHouse.amenities[0],
                                                                                                                 userHouse.garden[0],
                                                                                                                 userHouse.renovated[0],
                                                                                                                 userHouse.furniture[0],
                                                                                                                 userHouse.criminality[0]
                                                                                                                );


fprintf(outputFile, "Considering the Characteristics of The house The Approximate Price Will Be: %ld $\n\n", priceOfHouse);
fprintf(outputFile, "Thank You For Using PropertyValuator\n");

fclose(outputFile);
break;

case 2:

printf("Please Enter The Area of The Apartment.\n");
scanf("%lf", &userApartment.areaAp[0]);
printf("Please Enter The Number of Bedrooms of The Apartment.\n");
scanf("%lf", &userApartment.bedroomsAp[0]);

while (1){
printf("The Apartment Has a Parking Area or Not (1-yes, 0-no).\n");
scanf("%lf", &userApartment.parkingAreaAp[0]);

if(userApartment.parkingAreaAp[0] != 1 && userApartment.parkingAreaAp[0] != 0){
printf("Invalid Number!\n");
}
else{
break;
}
}

printf("Please Enter The Number of Bathrooms of The Apartment.\n");
scanf("%lf", &userApartment.bathroomsAp[0]);

while(1){

printf("Please Rate from 1 to 5 The Amenities of The Apartment.\n");
scanf("%lf", &userApartment.amenitiesAp[0]);

if(userApartment.amenitiesAp[0] < 1 || userApartment.amenitiesAp[0] > 5){
printf("Invalid Number!\n");
}
else{
break;
}
}

printf("Please Enter The Number of Floor Where The Apartment Is.\n");
scanf("%lf", &userApartment.floorNumberAp[0]);

while(1){

printf("Please Enter Whether The Apartment is Renovated or Not (1-yes, 0-no).\n");
scanf("%lf", &userApartment.renovatedAp[0]);
if(userApartment.renovatedAp[0] != 1 && userApartment.renovatedAp[0] != 0){
printf("Invalid Number!\n");
}
else{
break;
}
}

while(1){
printf("Please Enter Whether The Apartment Has Furniture or Not (1-yes, 0-no).\n");
scanf("%lf", &userApartment.furnitureAp[0]);
if(userApartment.furnitureAp[0] != 1 && userApartment.furnitureAp[0] != 0){
printf("Invalid Number!\n");
}
else{
break;
}
}

while(1){

printf("Please Rate from 1 to 5 The Degree of Criminality of The Place The Apartment is Located.\n");
scanf("%lf", &userApartment.criminalityAp[0]);

if(userApartment.criminalityAp[0] < 1 || userApartment.criminalityAp[0] > 5){
printf("Invalid Number!\n");
}
else{
break;
}
}






//Calculating the prices

priceOfApartment = b0A/5 + (b1A*userApartment.areaAp[0])+(b2A*userApartment.bedroomsAp[0])+(b3A*userApartment.parkingAreaAp[0])+(b4A*userApartment.bathroomsAp[0])+(b5A*userApartment.amenitiesAp[0])+(b6A*userApartment.floorNumberAp[0])+(b7A*userApartment.renovatedAp[0])+ (b8A*userApartment.furnitureAp[0])+(b9A*userApartment.criminalityAp[0]);
priceOfApartment = priceOfApartment-(priceOfApartment % 1000);
printf("The approximate price of the apartment is: %ld $\n", priceOfApartment);
printf("For Additional Information Please Check Output.exe File\n");

//This part creates a file and writes information about the property
FILE *outputfile = fopen("Output.txt", "w");



if(0 == outputfile){
    printf("Failed to open the file");
    return 1;
}

fprintf(outputfile, "Here are The Characteristics of The House\n\n");
fprintf(outputfile, "Area      Bedrooms   Parking   Bathrooms   Amenities   Floor   Renovated   Furniture   Criminality\n");
fprintf(outputfile, "%.1f          %.1f     %.1f      %.1f        %.1f          %.1f      %.1f             %.1f          %.1f \n\n\n\n", userApartment.areaAp[0],
                                                                                                                 userApartment.bedroomsAp[0],
                                                                                                                 userApartment.parkingAreaAp[0],
                                                                                                                 userApartment.bathroomsAp[0],
                                                                                                                 userApartment.amenitiesAp[0],
                                                                                                                 userApartment.floorNumberAp[0],
                                                                                                                 userApartment.renovatedAp[0],
                                                                                                                 userApartment.furnitureAp[0],
                                                                                                                 userApartment.criminalityAp[0]
                                                                                                                );


fprintf(outputfile, "Considering the Characteristics of The Apartment The Approximate Price Will Be: %ld $\n\n", priceOfApartment);
fprintf(outputfile, "Thank You For Using PropertyValuator\n");

fclose(outputfile);
break;

default:


printf("Invalid choice. Please enter 1 or 2.\n");
scanf("%d", &choice);
break;


}

if(choice == 1 || choice == 2)
break;

}

printf("Press Enter to Exit the Program...\n");

getchar();
getchar();
   



return 0;


}