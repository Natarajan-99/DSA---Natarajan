#include <iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr,int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    int j;
    for(j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;//swapping
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}
void quicksort(vector<int> &arr,int low,int high)
{
    int k;
    if(low<high)
    {
        k=partition(arr,low,high);
        quicksort(arr,0,k-1);
        quicksort(arr,k+1,high);
    }

}
int main()
{
    vector<int> arr={1,9,8,3,5,10,6,7};
    quicksort(arr,0,arr.size()-1);
    for(int i:arr)
    {

        cout<<i<<" ";
    }
    return 0;
}
