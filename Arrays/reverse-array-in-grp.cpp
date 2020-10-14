//Problem statement:
//  Given an array arr[] of positive integers of size N. Reverse every sub-array of K group elements.
#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end, int k)
{
for(int i = 0; i < k/2; i++)
{
int temp = arr[start];
arr[start] = arr[end];
arr[end] = temp;
end--;
start++;
}
}

int main() {
//code
int n, k;
cin >> n >> k;
int a[n];
for(int i = 0; i < n; i++)
{
cin >> a[i];
}
int start = 0;
int end = k-1;
for(int i = 0; i < n/k; i++)
{
reverse(a, start, end, k);
start += k;
end += k;
}
if(n%k != 0)
{
reverse(a, n-(n%k), n-1, (n%k));
}
for(int i = 0; i < n; i++)
{
cout << a[i] << " ";
}
cout << endl;
return 0;
}