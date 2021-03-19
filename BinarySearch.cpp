#include<iostream>
using namespace std;


int search(int arr[],int n,int s){

    int end=n-1;
    int start=0, mid=(start+end)/2;
    while (start<=end)
    {
        if(arr[mid]==s)
        return mid;
        else if (arr[mid]<s)
        start=mid+1;
        else
        {
            end=mid-1;
        }
        
        mid=(start+end)/2;
    }

    return -1;  
   
}

int main()
{
    int s,arr[5];
   
    cout <<"Enter 5 elements :"<<endl;
    for(int i=0;i<5;i++)
    cin >> arr[i];

    cout <<"enter the element to be searched: "<< endl;
    cin>> s;
    int r=search(arr,5,s);
    if(r==-1)
    cout << "not found"<<endl;
    else
    {
        cout <<" found at "<< r<<endl;
    }
    return 0;
}