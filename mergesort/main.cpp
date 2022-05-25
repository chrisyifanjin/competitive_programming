#include <iostream>

using namespace std;

const int N = 1000010;
int n[5] = { 16, 2, 77, 40, 12071 };


int q[N], tmp[N];


void merge_sort(int q[], int l, int r) {

    // base case
    if (l >= r) return;

    // middle pointer
    int mid = (l + r)>>1;

    // recursion on both left and right side
    merge_sort(q, l, mid), merge_sort(q, mid+1, r);

    // two pointer method to merge left and right
    int k = 0, i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }

    while (i <= mid) tmp[k++] = q[i++];

    while (j <= r) tmp[k++] = q[j++];

    // move numbers in temp to original number array
    for (i = l, j = 0; i <= r; i++, j ++) q[i] = tmp[j];
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < 5; i++) scanf("%d", &q[i]);

    merge_sort(q, 0, 5 - 1);

    for (int i = 0; i < 5; i++) printf("%d", q[i]);
}
