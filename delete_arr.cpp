/**
 * @file delete.cpp
 * @author Basav Bamrah
 * @brief Delete Elements of array
 * @version 0.1
 * @date 2021-03-19
 * 
 */
#include<iostream>
using namespace std;

int arr[50];    // array of size 50
bool delPos(int pos,int len){      
    if(pos > len){
     cout << "INVALID POSITION" <<endl;             // check the validity of position
     return false;
    }
   for(int i= pos-1 ;i<len ; i++){
       arr[i]=arr[i+1];
   }
   return true;
}// delPos()

 bool delNum(int num, int len){
     
     for(int i=0 ; i<len ; i++){
         if(num==arr[i]) {delPos(i+1,len); 
         return true;}             // find the position of number 
    }
    cout << " NUMBER NOT PRESENT " << endl; 
    return false; 
 }// delNum()

int main(){

    int n=10,p,num,x;
    cout << "enter 10 elaments"<< endl;
    for(int i= 0; i<10 ;i++)
        cin >> arr[i];
    cout << "Press 1 to delete using postion OR 2 to delete by giving the number:"<<endl;   //user choice
    cin >> x;
    if(x==1){
        cout << "enter the number the position: "<< endl;
        cin >> p;
        if(delPos(p,n))
        n--;

    }
    else if(x==2){
        cout << "enter the number the number: "<< endl;
        cin >> num;
        if(delNum(num,n))
        n--;
    }
    else
        cout << "!!! INVALID CHOICE !!!"<<endl;
    
    cout<<"ARRAY AFTER DELETION:\n";
    
    for(int i= 0; i<n ;i++)
        cout << arr[i] << " " ;
    
    cout<<endl;
    return 0;
}//main()