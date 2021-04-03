/**
 * @file hourglass.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/**
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0

1 1 1   1 1 0   1 0 0   0 0 0
  1       0       0       0
1 1 1   1 1 0   1 0 0   0 0 0

0 1 0   1 0 0   0 0 0   0 0 0
  1       1       0       0
0 0 2   0 2 4   2 4 4   4 4 0

1 1 1   1 1 0   1 0 0   0 0 0
  0       2       4       4
0 0 0   0 0 2   0 2 0   2 0 0

0 0 2   0 2 4   2 4 4   4 4 0
  0       0       2       0
0 0 1   0 1 2   1 2 4   2 4 0
total hour glass = 16

*/

#include <iostream>
using namespace std;

int arr[100][100], n;
void input()
{
  cout << "Enter a number:\n";
  cin >> n;
  cout << "Enter " << n * n << " numbers:\n";
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
}

void calc()
{
  int sum = 0, g = 0;
  for (int i = 0; i < n - 2; i++)
  {
    for (int j = 1; j < n - 1; j++)
    {
      sum += arr[i][j - 1] + arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j - 1] + arr[i + 2][j] + arr[i + 2][j + 1];
      // calculating sum of each hour glass and finding the greatest
      if(i==0 && j==1)
      g=sum;
      if (g < sum)
        g = sum;
      sum = 0;
    }
  }
  cout << g << endl;
}
int main()
{
  input();
  calc();
  return 0;
}