#include <stdio.h>
#include <stdlib.h>

#define N 10

struct house{

   double area[N];
   double bedrooms[N];
   double floors[N];
   double bathrooms[N];
   double amenities[N];
   double garden[N];
   double renovated[N];
   double furniture[N];
   double criminality[N];
   double price[N];
};


struct apartment{

   double areaAp[N];
   double bedroomsAp[N];
   double parkingAreaAp[N];
   double bathroomsAp[N];
   double amenitiesAp[N];
   double floorNumberAp[N];
   double renovatedAp[N];
   double furnitureAp[N];
   double criminalityAp[N];
   double priceAp[N];
};

void readLine(FILE *file, double arr[]) {
    for (int i = 0; i < N; i++) {
        fscanf(file, "%lf", &arr[i]);
    }
}


double meanCalculator(double *arr, int n){
  double sum = 0;
  for(int i = 0; i<n; i++){
    sum+=arr[i];
  }
    return sum/n;
}

double slopeCalculator(double arrX[],double arrY[], double meanX, double meanY){

double numerator, denominator;
double sum1=0;
double sum2=0;

for(int i = 0; i<N; i++){

    numerator = (arrX[i]-meanX)*(arrY[i]-meanY);
    sum1+=numerator;
    
}

for(int i = 0; i<N; i++){

    denominator = (arrX[i]-meanX)*(arrX[i]-meanX); 
    sum2+=denominator;    
}

if (denominator == 0) {
        
        return 0;
    }

return sum1/sum2;

}


double interceptCalculator(double meanY, double meanX, double b1){
int b0 = meanY-(b1*meanX);

return b0;
}

// Implementation of Queue Data Structure

struct QueueNode{
   double value;
   struct QueueNode* next;
};

struct queue{
    struct QueueNode *head;
    struct QueueNode *tail;
};

void initializingQueue(struct queue *myQueue){
     myQueue->tail = myQueue->head = NULL;
}

int isEmpty(struct queue *myQueue){
    return myQueue->head == NULL;
}

void insert(struct queue *myQueue, double data){

   struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    
    if(0 == newNode){
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->value = data;
    newNode->next = NULL;

    if(isEmpty(myQueue)){
        myQueue->head = myQueue->tail = newNode;
    }
    else{
        myQueue->tail->next = newNode;
        myQueue->tail = newNode;
    }

}


double delete(struct queue *myQueue)
{

    if (isEmpty(myQueue)) {
        printf("Queue is empty\n");
        return -1; // Return a special value to indicate an empty queue
    }

    double data = myQueue->head->value;

     struct QueueNode* temp = myQueue->head;
    myQueue->head = myQueue->head->next;

     if (0 == myQueue->head)
         myQueue->tail = NULL;


    free(temp);

    return data;
}

void printQueue(struct queue *myQueue){

     if (isEmpty(myQueue)) {
        printf("Queue is empty\n");
        return;
    }

struct QueueNode* currentNode = myQueue->head;
    while (0 != currentNode) {
        printf("%lf ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");


}

void freeQueue(struct queue *myQueue){
    while(!isEmpty(myQueue)){
        delete(myQueue);
    }

}
