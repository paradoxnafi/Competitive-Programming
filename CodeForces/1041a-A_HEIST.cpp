#include <iostream>
using namespace std;

void merge(int *a, int *l, int nL, int *r, int nR) {
    int i=0,j=0,k=0;
    while(i < nL && j < nR) {
        if(l[i] < r[j])
            a[k++] = l[i++];
        else
            a[k++] = r[j++];
    }
    while(i < nL) {
        a[k++] = l[i++];
    }
    while(j < nR){
        a[k++] = r[j++];
    }
}

void mergesort(int *a, int len)
{
    if(len<2) {
        return;
    }
    int mid = len/2;
    int *left = (int *)malloc(mid*sizeof(int));
    int *right = (int *)malloc(sizeof(int)*(len-mid));
    for(int i=0;i<mid;i++) {
        left[i] = a[i];
    }
    for(int i=mid;i<len;i++) {
        right[i-mid] = a[i];
    }
    mergesort(left, mid);
    mergesort(right, len-mid);
    merge(a, left, mid, right, len-mid);
}

int main()
{
    int n, counter = 0;
    cin >> n;
    int data[n];

    for(int i = 0; i < n; i++) {
        cin >> data[i];
    }
    mergesort(data, n);

    for(int i = 0; i < n-1; i++) {
        if( (data[i+1] - data[i]) > 1) {
            counter += (data[i+1] - data[i]-1);
        }
    }

    cout << counter;

    return 0;
}