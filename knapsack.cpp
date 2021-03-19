/**
 * @file knapsack.cpp
 * @author Basav Bamrah
 * @brief knapscak using greedy approach sort using weight and using value.
 * @version 0.1
 * @date 2021-03-15
 */
#include <iostream>
#include <string.h>
using namespace std;

char item[100][25], fset1[100][25],fset2[100][25]; // 2d arrays to store the item
int arr[100], vl[100], n;         // arr is to store the wt of item and vl for its value
int mwt = 0, mvl = 0;             // mwt stores the max. wt of sack and mvl the total value

void sortwt() // function to sort according wt.
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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
        cout << arr[i] << "  " << item[i] << "  " << vl[i] << endl;
        ;
    }
    cout << endl;
}

void sortvl() // function to sort according value.
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vl[j] > vl[j + 1])
            {
                int temp = vl[j];
                vl[j] = vl[j + 1];
                vl[j + 1] = temp;

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

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
        cout << arr[i] << "  " << item[i] << "  " << vl[i] << endl;
        ;
    }
    cout << endl;
}

void calc(int mwt,char fset[][25]) // fun to calculate the sack wt.
{
    int t = n;
    int i = 0;

    while (mwt >= arr[i] && t > 0)
    {
        mwt -= arr[i];
        mvl += vl[i];
        strcpy(fset[i], item[i]);
        i++;
        t--;
    }
    cout << endl
         << "Left weight: " << mwt << endl;
    cout << "Value in the sack: " << mvl << endl;
}
void disp()
{
    cout << "SET 2 according to wt.:\n";
    for (int i = 0; i < n; i++) // display the content of sack
    {
        cout << " " << fset1[i] << " ";
    }

    cout << "\nSET 2 according to value:\n";
    for (int i = 0; i < n; i++) // display the content of sack
    {
        cout << " " << fset2[i] << " ";
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
    sortwt();
    calc(mwt,fset1);
    sortvl();
    calc(mwt,fset2);
    disp();

    cout << endl;
    return 0;
}

/*

set and disp function to be debugged*/