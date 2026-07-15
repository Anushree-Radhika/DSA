#include "ppl1r.h"
#include <iostream>
using namespace std;

/* String comparison */
void recur(int n1, int n2, char s1[], char s2[], int id1, int id2) {
    if (id1 >= n1 && id2 >= n2) {
        cout << 0 << endl;
        return;
    }
    if (id1 >= n1) {
        cout << -1 << endl;
        return;
    }
    if (id2 >= n2) {
        cout << 1 << endl;
        return;
    }
    if (s1[id1] > s2[id2]) {
        cout << 1 << endl;
        return;
    }
    if (s1[id1] < s2[id2]) {
        cout << -1 << endl;
        return;
    }
    recur(n1, n2, s1, s2, id1 + 1, id2 + 1);
}

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

/* Palindrome */
bool palindrome(int n, char s[], int low, int high) {
    if (low >= high) return true;
    if (s[low] != s[high]) return false;
    return palindrome(n, s, low + 1, high - 1);
}

/* Replace character */
void character(int n, char s[], char c1, char c2, int idx) {
    if (idx >= n) return;
    if (s[idx] == c1) s[idx] = c2;
    character(n, s, c1, c2, idx + 1);
}

/* Sum of array */
int sum(int s, int num[], int n, int idx) {
    if (idx >= n) return s;
    return num[idx] + sum(s, num, n, idx + 1);
}

/* Lexicographically smallest character */
char lexo(char s[], int n, int idx, char c) {
    if (idx >= n) return c;
    if (s[idx] < c) c = s[idx];
    return lexo(s, n, idx + 1, c);
}
