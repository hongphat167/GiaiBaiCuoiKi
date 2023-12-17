#include <iostream>
#include <algorithm>

using namespace std;

void SelectionSort(int a[], int n)
{
    int i, j, maxIndex;
    for(i = 0; i< n-1; i++)
    {
        maxIndex =i;
        for(j = i +1 ; j< n; j++)
        {
            if(a[j] > a[maxIndex])
            {
                maxIndex = j;
            }
        }
        swap(a[i], a[maxIndex]);
    }
}
void printArray(int a[], int n)
{
    for(int i = 0 ; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    SelectionSort(a,n);
    printArray(a,n);
    return 0;
}
