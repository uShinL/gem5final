#include <stdlib.h>  // malloc 所需
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void quickSort(int number[], int left, int right) { 
    if(left < right) { 
        int s = number[(left+right)/2]; 
        int i = left - 1; 
        int j = right + 1; 

        while(1) { 
            while(number[++i] < s) ;   
            while(number[--j] > s) ;   
            if(i >= j) 
                break; 
            SWAP(number[i], number[j]);  
        } 

        quickSort(number, left, i-1);   
        quickSort(number, j+1, right);  
    } 
}

int main(){
    int size = 100000;
    int* arr = (int*)malloc(sizeof(int) * size);  // 🔧 用 heap 配陣列

    for (int i = 0; i < size; i++){
        arr[i] = rand() % size + 1;
    }

    quickSort(arr, 0, size-1);

    free(arr);  // 🔚 用完記得釋放
}


