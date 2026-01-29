#include <iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>arr,int tar,int st,int end){
    int mid = st + (end - st)/2;
    if(st <= end){
        if(arr[mid] == tar){
            return mid;
        }
        if(arr[mid] < tar){
            return binarySearch(arr, tar,mid + 1,end);

        }
        if(arr[mid] > tar){
            return binarySearch(arr, tar,st,mid+1);
        }
    }
    return -1;


}
int main(){
    vector<int> arr = {1, 3 ,5,6,7};
    int tar = 5;
    cout<<binarySearch(arr, tar,0,arr.size());
    return 0;
}