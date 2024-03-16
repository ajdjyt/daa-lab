#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Q 8


void printBoard(int board[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

void initBoard(int board[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=0;
        }
    }
}

void findQueen(int board[8][8],int* iptr,int* jptr){
    int i = *iptr, j = *jptr;
    while(board[i][j]!=1){
        for(int k=0;k<8;k++){
            i++;
        }
        j++;
    }
}

int validQueens(int board[8][8],int i, int j){
    //int i=0,j=0;
    //findQueen(board,&i,&j);
    // Vertical
    for(int k=0;k<8;k++){
        if(k==i){
            continue;
        }
        else if(board[k][j]==1){
            return 0;
        }
    }
    // Horizontal
    for(int k=0;k<8;k++){
        if(k==j){
            continue;
        }
        else if(board[i][k]==1){
            return 0;
        }
    }
    // Up Right Diagonal
    for(int k=1;k<8;k++){
        if(((i+k)<=0)||((j+k)>8)){
            continue;
        }
        else if(board[i+k][j+k]==1){
            return 0;
        }
    }
    // Up Left Diagonal
    for(int k=1;k<8;k++){
        if(((j-k)<=0)||((i+k)>8)){
            continue;
        }
        else if(board[i+k][j-k]==1){
            return 0;
        }
    }
    // Down Left Diagonal
    for(int k=1;k<8;k++){
        if(((i-k)<=0)||((i-k)<=0)){
            continue;
        }
        else if(board[i-k][j-k]==1){
            return 0;
        }
    }
    // Down Right Diagonal
    for(int k=1;k<8;k++){
        if(((i-k)<=0)||((j+k)>8)){
            continue;
        }
        else if(board[i-k][j+k]==1){
            return 0;
        }
    }
    return 1;
}

int nQueens(int n, int board[8][8]){
    int k=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=1;
            if (validQueens(board,i,j)){
                k++;
            }
            else{
                board[i][j]=0;
                printBoard(board);
            }
            if (k==n){
                break;
            }
        }
    }
    return k;
}

int main(){
    int board[8][8];
    initBoard(board);
    printBoard(board);
    int n_q;
    printf("Enter the number of queens to place on the board: ");
    scanf("%d",&n_q);
    int k = nQueens(n_q,board);
    printBoard(board);
    printf("Placed %d Queens",k);
    return 0;
}
