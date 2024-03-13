#include <stdio.h>

struct MinMax{
    int min;
    int max;
};



struct MinMax MinMaxDAC(int A[],int i,int j){
    struct MinMax o;
    if(i == j){
        o.min=A[i];
        o.max=A[j];
        return o;
    }
    if((j - i) == 1){
        if (A[i] < A[j]){
            o.min=A[i];
            o.max=A[j];
            return o;
        }
        else{
            o.min=A[j];
            o.max=A[i];
            return o;
        }
    }
    else {
        int mid = i + (j - i) / 2,max=0,min=0;
        struct MinMax L = MinMaxDAC(A, i, mid);
        struct MinMax R = MinMaxDAC(A, mid + 1, j);
        if(L.max > R.max)
            max = L.max;
        else
            max = R.max;
        if(L.min < R.min)
            min = L.min;
        else
            min = R.min;
        o.min=min;
        o.max=max;
        return o;
    }
}

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct MinMax ans = MinMaxDAC(arr,0,n-1);
    printf("Min: %d Max: %d\n",ans.min,ans.max);
}