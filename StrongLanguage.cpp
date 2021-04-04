#include <iostream>
using namespace std;

int main() {
	
	int n,k,t;
        cout<< "Enter a number:\n";
	cin>>t;
	for(int i=0;i<t;i++)
	{
            cout<<" Enter the length of string and least number of consecutive *:\n";
	    cin>> n;
	    cin>>k;
	    string s;
            cout<<"Enter the String:\n";
	    cin>>s;
	    int c=0,f=0;
	    for(int j=0;j<s.length();j++)
	    {
	        if(s[j]=='*'){
	        c++;
	        }
	        else{
	        c=0;}
	        if(c==k)
	        {
	            f=1;
	            break;
	        }
	    }
	    if(f==1)
	    cout<<"Yes"<<endl;
	    else
	    cout<<"no"<<endl;
	}
	return 0;
}
