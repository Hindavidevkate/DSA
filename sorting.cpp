#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(int arr[], int n){
    for(int i = 0; i< n-1;i++){
        for(int j = i+1; j< n;j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n){
    for(int i = 0;i<n-1; i++){
        int smallElement = i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[smallElement]){
                smallElement = j;
            }
            swap(arr[i],arr[smallElement]);
        }
    }
}
void print(int arr[], int n){
    for(int i = 0; i< n;i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}
void insertionSort(int arr[], int n){
    for(int i =1;i<n;i++){
        int curr = arr[i];
        int prev = i -1;
        while(prev >=0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
        }
        arr[prev + 1] = curr;
    }
}
//This is Quick Sort Algorithm 
int partition(int arr[],int st,int end){
    st = 0;
    
    int idx = st-1;
    int pivot = arr[end];
    for(int j = st; j<end;j++){
        if(arr[j] <= pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;

}
void quickSort(int arr[],int st,int end){
    if(st < end){
        int pivotIndex = partition(arr,st,end);
        partition(arr,st,pivotIndex -1);
        partition(arr,pivotIndex +1,end);
    }

}
//This is Merge Sort Algorithm
int merge(vector<int>& ar,int st,int mid,int end){
    vector<int> temp;
    int i=st,j = mid +1;
    while(i<=mid&&j<=end){
        if(ar[i] <= ar[j]){
            temp.push_back(ar[i]);
            i++;
        }
        else{
        temp.push_back(ar[j]);
        j++;
        }

    }
    while (i<=mid)
    {
        temp.push_back(ar[i]);
        i++;
    }
    while (j<=end)
    {
        temp.push_back(ar[j]);
        j++;
    }
    for(int id = 0;id<temp.size() ;id++){
        ar[id+st] = temp[id];
    }
    
    
}
void mergeSort(vector<int>&ar,int st,int end){
    if(st<end){
        int mid = st + (end - st)/2;
    
    
    mergeSort(ar,st,mid);
    mergeSort(ar,mid+1,end);
    merge(ar,st,mid,end);
    }
}
int main(){
    int n = 9;
    int st=0;
    int end=n-1;
    int mid;
    int arr[n] = {98,5,3,6,1,2,1,34,12};
    //this vector is use for only mergee sort
    vector<int> ar = {98,5,3,6,1,2,1,34,12};
    cout<<"Sorted Array Using Bubble Sort : ";
    bubbleSort(arr,n);
    print(arr,n);
    cout<<"This is selection sort Algorithm : ";
    selectionSort(arr,n);
    print(arr,n);
    cout<<"This is insertion sort Algorithm : ";
    insertionSort(arr,n);
    print(arr,n);
    cout<<"This is Quick sort Algorithm : ";
    quickSort(arr,st,end);
    print(arr,n);
    cout<<"This is Merge sort Algorithm : ";
    mergeSort(ar,st,end);
    print(arr,n);
    return 0;
}