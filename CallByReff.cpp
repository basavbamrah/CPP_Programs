#include<iostream>
using namespace std;

void callByReff(int *a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

void callByVal(int a, int b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}

int main()
{
    int a,b;

    cout<< "Enter the two numbers:\n";
    cin >> a>>b;
    callByVal(a,b);
    cout<< "Number after call by Value: a= "<< a <<" b= "<< b<<endl;
    callByReff(&a,&b);
     cout<< "Number after call by refference: a= "<< a <<" b= "<< b<<endl;
}