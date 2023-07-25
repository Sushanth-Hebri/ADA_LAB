#include <stdio.h>
#include <string.h>

int findMax(int n1, int n2){
   if(n1>n2) {
      return n1;
   } else {
      return n2;
   }
}




int knapsack(int W, int wt[], int val[], int n){
   int K[n+1][W+1];
   for(int i = 0; i<=n; i++) {
      for(int w = 0; w<=W; w++) {
          
        //   if any one of object not selected or weight is zero then no profit
         if(i == 0 || w == 0) {       
            K[i][w] = 0;
            
         }
         
         else if (wt[i-1] <= w) {
            K[i][w] = findMax(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
         } else {
            K[i][w] = K[i-1][w];
         }
      }
   }
   return K[n][W];
}


int main(){
    // profit
   int val[5] = {12,10,20,15}; 
// weight
   int wt[5] = {2,1,3,2};
//   max capacity
   int W = 5;
//   length of array                                 
   int len = sizeof val / sizeof val[0];
   printf("max profit is\n");
   int myprofit=knapsack(W,wt,val,len);
   printf("%d",myprofit);
 
   
}