#include <iostream>
#include <climits>
using namespace std;

int arr[5][5] = {
    {0, 20, 19, 25, 22},
    {20, 0, 21, 23, 21},
    {19, 21, 0, 21, 20},
    {25, 23, 21, 0, 22},
    {22, 21, 20, 22, 0}};
int Calc(int pos)
{
    int sum = 0;
    bool visited[5] = {};
    int c = 0;
    int min = INT_MAX;
    visited[pos - 1] = true;
    int i = pos - 1;
    while (i < 5)
    {
        int p;
        if (c >= 5)
        {
            sum += arr[p][pos - 1];
            break;
        }

        for (int j = 0; j < 5; j++)
        {
            if (i != j && !(visited[j]))
                if (min > arr[i][j])
                {
                    min = arr[i][j];
                    p = j;
                }
        }

        sum += arr[i][p];
        visited[p] = true;
        c++;
        min = INT_MAX;
        i = p;
    }
    return sum;
}
int main()
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    int cost[5];
    for (int i = 0; i < 5; i++)
    {
        cost[i] = Calc(i + 1);
    }
    int min = cost[0];
    int p;
    for (int i = 0; i < 5; i++)
    {
        if (min > cost[i])
        {
            min = cost[i];
            p = i;
        }
    }
    cout << "min cost = " << cost[p - 1] << " From Node " << p;

    cout << endl;
    return 0;
}
