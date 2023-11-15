#include <stdio.h>

void merge(int arr[] , int l , int m , int h){

    int i = l;
    int j = m+1;
    int k = l;

    int newArr[h+1];

    while(i <= m && j <= h){
        if(arr[i] <= arr[j]){
            newArr[k] = arr[i];
            i++;
            k++;
        }
        else{
            newArr[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= m){
        newArr[k] = arr[i];
        i++;
        k++;
    }
    while(j <= h){
        newArr[k] = arr[j];
        j++;
        k++;
    }

    for(int i=l ; i<=h ; i++){
        arr[i] = newArr[i];
    }
}

void mergeSort(int arr[] , int l  , int h ){
    if(l<h){
        int m = (l+h)/2;

        mergeSort(arr , l , m);
        mergeSort(arr , m+1 , h);

        merge(arr , l , m , h);

    }
}

void main(){
    int n;
    scanf("%d" , &n);
    int arr[n];
    for(int i=0 ; i<n ; i++){
        scanf("%d" , &arr[i]);
    }

    mergeSort(arr , 0 , n-1);

    for(int i=0 ; i<n ; i++){
        printf("%d " , arr[i]);
    }
    printf("\n");
    
}