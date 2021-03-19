/**
 * @file binarySearch2.cpp
 * @author Basav Bamrah
 * @brief Binary Search program
 * @version 0.1
 * @date 2020-09-10
 * 
 */
#include <iostream>
using namespace std;

int n;
void sort(int arr[]) // Sorting the arrray
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
} // sort

void disp(int arr[]) // Display the array
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
} // disp()

int search(int arr[], int n, int s) // Searching the element
{
    int end = n - 1;
    int start = 0, mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == s)
            return mid;
        else if (arr[mid] < s)
            start = mid + 1;
        else
        {
            end = mid - 1;
        }

        mid = (start + end) / 2;
    }
    return -1;
} // search()

int main()
{
    int s;
    cout << " enter the number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements :" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr);
    cout << "Sorted Array: \n";
    disp(arr);
    cout << "enter the element to be searched: " << endl;
    cin >> s;
    int r = search(arr, n, s);
    if (r == -1)
        cout << "not found" << endl;
    else
        cout << " found at " << r << endl;

    cout << endl;
    return 0;
} // main()