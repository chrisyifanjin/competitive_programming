#include <iostream>
using namespace std;

// quick sort


const int N = 1e6 + 10;
int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return; // edge case

    int x = q[(l+r)/2], i = l - 1, j = r + 1; // left and right pointer from start and begin
    while (i < j){
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);  // swap

    }

    quick_sort(q, l, j);
    quick_sort(q, j+1, r); //recursive call
}



int main() {
    // 1. find the pivot point:
    // q[l] or q[(l+r)/2] or q[r] or random number

    // 2. adjust interval:
    // number less than pivot put to the left
    // number greater than pivot put to the right
    // if equal, indifferent between left and right

    // 3. recursion: on left and right side

    // two pointer way: i, j  = 0 , len(arr) - 1
    // i move if not > x
    // j move if not < x
    // swap(arr[i], arr[j])
    // then procedure two completed

    // [3,1,2,3,5]  x= 3


    scanf("%d", &n);
    for (int i = 0; i< n; i++) scanf("%d", &q[i]);

    quick_sort(q, 0, n-1);

    for (int i = 0; i < n; i ++) printf("%d", q[i]);

}
