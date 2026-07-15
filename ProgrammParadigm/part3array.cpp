#include "ppl1r_array.h"
#include <iostream>
using namespace std;

/* Largest element */
int largest(int n[], int idx, int ma, int s) {
    if (idx >= s) return ma;
    if (n[idx] > ma) ma = n[idx];
    return largest(n, idx + 1, ma, s);
}

/* Search element */
bool checker(int n[], int idx, int key, int s) {
    if (idx >= s) return false;
    if (n[idx] == key) return true;
    return checker(n, idx + 1, key, s);
}

/* Reverse print */
void reverse(int num[], int n, int idx) {
    if (idx >= n) return;
    reverse(num, n, idx + 1);
    cout << num[idx] << " ";
}

/* Sum of array */
int sum(int s, int num[], int n, int idx) {
    if (idx >= n) return s;
    return num[idx] + sum(s, num, n, idx + 1);
}
