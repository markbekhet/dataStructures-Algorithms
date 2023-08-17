#include "array.h"
#include <stdio.h>
#include <stdlib.h>

void Array::insert(int index, int x){
    if(index >= 0 && index <= len){
        for(int i = len; i>index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        len++;   
    }
    
}

Array::Array(int size){
    this->size = size;
    A = new int[size];
    len = 0;
}

Array::~Array(){
    delete[] A;
}

void Array::append(int x){
    if(len< size){
        A[len++] = x;
    }
}

void Array::display(){
    for(int i = 0; i< len; i++){
        printf("%d,", A[i]);
    }
}

int Array::remove(int index){
    if(index >= 0 && index < len){
        int x = A[index];
        for(int i = index; i< len - 1; i++){
            A[i] = A[i+1];
        }
        len--;
        return x;
    }
    return 0;
}

void swap(int* x, int* y){
    int temp = *x;
    *x= *y;
    *y = temp;
}

int Array::linearSearch(int key){
    for(int i = 0; i< len; i++){
        if(key == A[i]){

            //Transposition
            swap(&A[i], &A[i-1]);
            return i;
        }
    }
    return -1;
}

int Array::binarySearch(int key){
    return binarySearchHelper(key, 0, len-1);
}

int Array::binarySearchHelper(int key, int low, int high){
    while(low <= high){
        int mid = (low+ high)/2;
        if(key == A[mid]){
            return mid;
        }
        else if(key > A[mid]){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}

int Array::get(int index){
    if(index >= 0 && index < len){
        return A[index];
    }
    return -1;
}

void Array::set(int index, int value){
    if(index >= 0 && index < len){
        A[index] = value;
    }
}

int Array::max(){
    int max = A[0];
    for(int i = 1; i< len; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int Array::min(){
    int min = A[0];
    for(int i = 1; i< len; i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Array::sum(){
    int t = 0;
    for(int i = 0; i< len; i++){
        t += A[i];
    }
    return t;
}

float Array::avg(){
    return sum()/len;
}

void Array::reverse(){
    for(int i = 0, j= len-1; i<j; i++,j--){
        swap(&A[i], &A[j]);
    }
}

void Array::insertSort(int x){
    if(len == size){
        return;
    }
    int i = len -1;
    while(i>=0 && A[i]> x){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    len++;

}

bool Array::isSorted(){
    for(int i = 0; i< len;i++){
        if(A[i]>A[i+1]) return false;
    }
    return true;
}

void Array::rearrange(){
    int i, j;
    i = 0;
    j = len - 1;
    while(i< j){
        while(A[i] < 0) i++;
        while(A[j] > 0) j--;
        if(i< j) swap(&A[i], &A[j]);
    }
}

Array* Array::merge(Array* arr){
    Array* merge = new Array(size + arr->size);
    int i = 0, j = 0, k = 0;
    while(i<len && j< arr->len){
        if(A[i] < arr->A[j]){
            merge->A[k++] = A[i++];
        }
        else{
            merge->A[k++] = arr->A[j++];
        }
    }
    for(; i< len; i++){
        merge->A[k++] = A[i];
    }
    for(; j< arr->len; j++){
        merge->A[k++] = arr->A[j];
    }
    merge->len = len + arr->len;
    merge->size =size + arr->size;
    return merge;
}


Array* Array::uni(Array* arr){
    Array* merge = new Array(size + arr->size);
    int i = 0, j = 0, k = 0;
    while(i<len && j< arr->len){
        if(A[i] < arr->A[j]){
            merge->A[k++] = A[i++];
        }
        else if(arr->A[j]< A[i]){
            merge->A[k++] = arr->A[j++];
        }
        else{
            merge->A[k++] = arr->A[j++];
            i++;
        }
    }
    for(; i< len; i++){
        merge->A[k++] = A[i];
    }
    for(; j< arr->len; j++){
        merge->A[k++] = A[j];
    }
    merge->len = k;
    merge->size =size + arr->size;
    return merge;
}


Array* Array::inter(Array* arr){
    Array* merge =new Array(size + arr->size);
    int i = 0, j = 0, k = 0;
    while(i<len && j< arr->len){
        if(A[i] < arr->A[j]){
            i++;
        }
        else if(A[i] > arr->A[j]){
            j++;
        }
        else{
            merge->A[k++] = arr->A[j++];
            i++;
        }
    }
    merge->len = k;
    merge->size =size + arr->size;
    return merge;
}


Array* Array::diff(Array* arr){
    Array* merge = new Array(size + arr->size);
    int i = 0, j = 0, k = 0;
    while(i<len && j< arr->len){
        if(A[i] < arr->A[j]){
            merge->A[k++] = A[i++];
        }
        else if(arr->A[j]< A[i]){
            j++;
        }
        else{
            j++;
            i++;
        }
    }
    for(; i< len; i++){
        merge->A[k++] = A[i];
    }
    merge->len = k;
    merge->size =size + arr->size;
    return merge;
}

void Array::findMissingElementSortedArray(){
    int diff = A[0]- 0;
    for(int i = 1; i< len; i++){
        if(A[i]-i != diff){
            while(diff< A[i]-i){
                printf("%d\n", i+ diff);
                diff++;
            }
        }
    }
}


/*
    For unsorted Arrays the solution is hashing
*/
void Array::findMissingElementUnsortedArray(int low, int high, int len){
    int* hashArray = new int[high];
    for(int i = 0; i< len; i++){
        hashArray[A[i]] = 1;
    }
    for(int i = low; i<= high; i++){
        if(hashArray[i] == 0) printf("%d\n", i);
    }
}

void Array::findDup(int high){
    int* hashArray = new int[high];
    for(int i = 0; i< len; i++){
        hashArray[A[i]]++;
    }

    for(int i = 0; i< high; i++){
        if(hashArray[i] > 1){
            printf("%d is duplicated %d times", i, hashArray[i]);
        }
    }
}

void Array::findSumUnsorted(int k){
    int* hashArray = new int[max()];
    for(int i = 0; i< len; i++){
        if(hashArray[k-A[i]]==1){
            printf("Key pair found with value %d and %d \n", k-A[i], A[i]);
        }
        hashArray[A[i]]++;
    }
}

void Array::findSumSorted(int k){
    int i = 0;
    int j = len-1;
    while(i != j){
        if(A[i] + A[j] > k){
            j--;
        }
        else if(A[i] + A[j] < k){
            i++;
        }
        else{
            printf("Key pair found with value %d and %d \n",A[i], A[j]);
            i++;
            j--;
        }
    }
}