#include <stdio.h>
#define SIZE 100

int binarySearch(int A[] , int l , int h , int k){
    if(l<=h){
        int m = (l+h)/2;
        printf("%d\n",A[m]);
        if(A[m] == k)
            return 1;
        else if(A[m] > k)
            binarySearch(A , l , m-1 , k);
        else
            binarySearch(A , m+1 , h , k);
    }
    else
        return 0;
}

void main(){
    int A[SIZE];
    int n , k;
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
        scanf("%d" , &A[i]);
    scanf("%d" , &k);
    int search = binarySearch(A,0,n-1,k);
    if(search == 1)
        printf("True\n");
    else
        printf("False\n");
}