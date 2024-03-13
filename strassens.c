#include<stdio.h>

void strassens(int x[2][2],int y[2][2],int z[2][2]){
   int m1, m2, m3, m4 , m5, m6, m7;
   m1= (x[0][0] + x[1][1]) * (y[0][0] + y[1][1]);
   m2= (x[1][0] + x[1][1]) * y[0][0];
   m3= x[0][0] * (y[0][1] - y[1][1]);
   m4= x[1][1] * (y[1][0] - y[0][0]);
   m5= (x[0][0] + x[0][1]) * y[1][1];
   m6= (x[1][0] - x[0][0]) * (y[0][0]+y[0][1]);
   m7= (x[0][1] - x[1][1]) * (y[1][0]+y[1][1]);
   z[0][0] = m1 + m4- m5 + m7;
   z[0][1] = m3 + m5;
   z[1][0] = m2 + m4;
   z[1][1] = m1 - m2 + m3 + m6;
   return;
}

void printMatrix(int matrix[2][2]){
   printf("\n");
   for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
         printf("%d ",matrix[i][j]);
      }
      printf("\n");
   }
}

void inputMatrix(int matrix[2][2]){
   printf("Enter values for a matrix: ");
   for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
         scanf("%d",&matrix[i][j]);
      }
   }
}

int main(){
   int x[2][2],y[2][2],z[2][2];
   inputMatrix(x);
   inputMatrix(y);
   strassens(x,y,z);
   printf("The first matrix is: ");
   printMatrix(x);
   printf("The second matrix is: ");
   printMatrix(y);
   printf("Product achieved using Strassen's algorithm: ");
   printMatrix(z);
   return 0;
}