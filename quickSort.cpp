#include <iostream>
using namespace std;


void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int partition(int arr[],int low,int high){
  
  int pivot=arr[high];
  int i=low-1;
  for(int j=low;j<high;j++){
    if(arr[j]<pivot){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return i+1;

}
void quickSort(int arr[],int start,int end){
  if(end<=start){
    return;
  }
  int pivot=partition(arr,start,end);
  quickSort(arr,start,pivot-1);
  quickSort(arr,pivot+1,end);
}

int main() {
   int arr[10]={2,9,1,5,3,4,8,6,7};
   int n=sizeof(arr)/sizeof(arr[0]);
   quickSort(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
}
