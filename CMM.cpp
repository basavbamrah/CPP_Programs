#include <iostream>
#include <climits>
using namespace std;

int s[100][100];

int chainMatrixMultliplication(int p[], int n)
{
    int m[n][n];
    for (int i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n - 1];
}
void disp(int i, int j)
{
    if (i == j)
    {
        cout<< i<<" ";
    }
    else
    {
        cout << "( ";
        disp(i, s[i][j]);
        disp(s[i][j] + 1, j);
        cout << ")";
    }
    
}

int main()
{
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int n = int(sizeof(arr) / sizeof(arr[0]));
    cout<< "Size are:"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i] <<" ";
    cout<<endl;
    
    cout << "MINIMUM COST OF MULTIPLICATION IS:" << chainMatrixMultliplication(arr, n) << endl;
    disp(1, n-1);
    cout << endl;
    return 0;
}
