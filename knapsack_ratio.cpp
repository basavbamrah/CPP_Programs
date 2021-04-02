
#include <iostream>
#include <string.h>
using namespace std;

char item[100][25], fset1[100][25]; // 2d arrays to store the item
int arr[100], vl[100], n;         // arr is to store the wt of item and vl for its value
float ratio[100];
float mwt = 0, mvl = 0;             // mwt stores the max. wt of sack and mvl the total value

void sort() 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                float t = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = t;

                temp = vl[j];
                vl[j] = vl[j + 1];
                vl[j + 1] = temp;
                char it[25];
                strcpy(it, item[j]);
                strcpy(item[j], item[j + 1]);
                strcpy(item[j + 1], it);
            }
        }
    }
    cout << "Final items after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   " << item[i] << "   " << vl[i] << "   "<<ratio[i]<<endl;
    }
    cout << endl;
}
void calc(int mwt,char fset[][25]) 
{
    int t = n;
    int i = 0;

    for (int i = 0; i < n; i++)
    {
        ratio[i]=(float)vl[i]/arr[i];
    }
    sort();

    while (mwt >= arr[i] && t > 0)
    {
        mwt -= arr[i];
        mvl += vl[i];
        strcpy(fset[i], item[i]);
        i++;
        t--;
    }
    if(mwt<arr[i])
    {
        float rt=(float)mwt/arr[i];
        float temp = vl[i]*rt;
        mvl+=temp;
        strcpy(fset[i],item[i]);
        mwt=0;
    }
    cout << endl << "Left weight: " << mwt << endl;
    cout << "Value in the sack: " << mvl << endl;
}
void disp()
{
    cout << "SET :\n";
    for (int i = 0; i < n; i++) // display the content of sack
    {
        cout << " " << fset1[i] << " ";
    }
}

int main()
{

    cout << "Enter the total number of items\n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter an item name,weight and value:\n";
        cin >> ws;
        cin.getline(item[i], 24);
        cin >> arr[i];
        cin >> vl[i];
    }
    cout << "Enter the max wt;\n";
    cin >> mwt;
    calc(mwt,fset1);
    disp();
    cout << endl;
    return 0;
}
