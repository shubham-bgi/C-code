#include <iostream>
using namespace std;

void bruteForceSubArraySum(int arr[], int n)
{
    int sum;
    int largestSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            largestSum = max(largestSum, sum);
        }
    }
    cout << "Largest Sum = " << largestSum;
}

void prefixSubArraySum(int arr[], int n)
{
    int prefixArray[n] = {0};
    prefixArray[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixArray[i] = prefixArray[i - 1] + arr[i];
    }
    int sum;
    int largestSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum = i > 0 ? prefixArray[j] - prefixArray[i - 1] : prefixArray[j];
            largestSum = max(largestSum, sum);
        }
    }
    cout << "Largest Sum = " << largestSum;
}

void KadaneSubArraySum(int arr[], int n)
{
    int sum = 0;
    int largestSum = 0;
    int tempIndex = 0;
    int firstIndex = 0;
    int finalIndex;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            tempIndex = i + 1;
        }
        if (sum > largestSum)
        {
            largestSum = sum;
            firstIndex = tempIndex;
            finalIndex = i + 1;
        }
        largestSum = max(largestSum, sum);
    }
    for (int i = firstIndex; i < finalIndex; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    cout << "Largest Sum = " << largestSum;
}

int main()
{
    // int arr[] = {-10, 15, 20, -25, 30, 35, 40, -45, 50, 55, -60, 65, 70, -50, 48, 36, 15};
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    KadaneSubArraySum(arr, n);
    return 0;
}