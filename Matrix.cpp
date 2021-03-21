/**
 * @file Matrix.cpp
 * @author Basav Bamrah
 * @brief ADdition, multiplication of 2 matrix
 * @version 0.1
 * @date 2021-03-21
 * 
 */

#include<iostream>
using namespace std;


int main(){
     int sum=0;
    int m=3,n=3;
    int arr1[m][n],arr2[m][n], arr4[m][n];
    cout << "Enter "<< m*n << " elements in first array:"<< endl;
    for(int i= 0; i<m;i++)
        for(int j=0;j<n;j++)
            cin >> arr1[i][j];
 
    cout << "Enter "<< m*n << " elements in Second array:"<< endl;
    
     for(int i= 0; i<m;i++)
        for(int j=0;j<n;j++)
            cin >> arr2[i][j];

    int arr3[3][3];
    for(int i= 0; i<3;i++)
        for(int j=0;j<3;j++)
            arr3[i][j]= arr1[i][j]+arr2[i][j];
        
    cout <<"Matrix After Addition:"<< endl;
    for(int i= 0; i<3;i++)
       {
           for(int j=0;j<3;j++)
           cout <<  arr3[i][j]<< " ";
            cout << endl;
       }
       
    int a=0;
     for(int i= 0; i<m;i++){
         
         for(int j=0;j<n;j++){            
            
            for(int k=0;k<n;k++)
            {
            sum+=arr1[a][k]*arr2[k][j];
            }
            arr4[i][j]= sum ;
            sum=0;
         }
         a++;
     }
    cout << "Matrix After MUltiplication:\n";
     for(int i= 0; i<m;i++)
       {
           for(int j=0;j<n;j++)
           cout <<  arr4[i][j]<< " ";
            cout << endl;
       }

    return 0;
}
        