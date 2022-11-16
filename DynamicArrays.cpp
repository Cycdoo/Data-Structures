#include<iostream>
using namespace std;

void Display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\n", arr[i]);
    }
}

int Insertion(int arr[], int size, int element, int capacity, int index){
    // code for Insertion
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1; 
}

void Deletion(int arr[], int size, int index)
{
    // code for Deletion
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }  
}

int main() {
	int arr[100] = {7, 8, 11, -7, 28};
    int size = 5, element = 35, index=1;
    Display(arr, size); 
    Insertion(arr, size, element, 100, index);
    size +=1;
    Display(arr, size);
    Deletion(arr, size, index);
     size -=1;
    Display(arr, size);
    return 0;
    
}
//Noriah Mudassir B20102132