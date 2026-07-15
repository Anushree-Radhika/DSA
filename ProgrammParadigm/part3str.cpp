#include "ppl1r_string.h"
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

/* Lexicographically smallest character */
char lexo(char s[], int n, int idx, char c) {
    if (idx >= n) return c;
    if (s[idx] < c) c = s[idx];
    return lexo(s, n, idx + 1, c);
}
