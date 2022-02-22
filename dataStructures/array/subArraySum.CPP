#include <iostream>
using namespace std;

void subArraySum(int arr[], int n)
{
    int sum;
    int arr1[] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
                cout << arr[k] << ",";
            }
            cout << " sum = "<< sum;
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {-10, 15, 20, -25, 30, 35, 40, -45, 50, 55, -60, 65, 70, -50, 48, 36, 15};
    int n = sizeof(arr) / sizeof(int);
    subArraySum(arr, n);
    return 0;
}