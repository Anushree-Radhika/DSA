#include <iostream>
#include <climits>
#include "ppl1r_array.h"
#include "ppl1r_string.h"
using namespace std;

int main() {
    int choice;
    cout << "Enter option (1–8): ";
    cin >> choice;

    switch (choice) {

        case 1: {
            int n1, n2;
            cin >> n1 >> n2;
            char s1[101], s2[101];
            for (int i = 0; i < n1; i++) cin >> s1[i];
            for (int i = 0; i < n2; i++) cin >> s2[i];
            recur(n1, n2, s1, s2, 0, 0);
            break;
        }

        case 2: {
            int n;
            cin >> n;
            int a[100];
            for (int i = 0; i < n; i++) cin >> a[i];
            cout << largest(a, 0, INT_MIN, n) << endl;
            break;
        }

        case 3: {
            int n, key;
            cin >> n >> key;
            int a[100];
            for (int i = 0; i < n; i++) cin >> a[i];
            cout << checker(a, 0, key, n) << endl;
            break;
        }

        case 4: {
            int n;
            cin >> n;
            int a[100];
            for (int i = 0; i < n; i++) cin >> a[i];
            reverse(a, n, 0);
            cout << endl;
            break;
        }

        case 5: {
            int n;
            cin >> n;
            char s[101];
            for (int i = 0; i < n; i++) cin >> s[i];
            cout << palindrome(n, s, 0, n - 1) << endl;
            break;
        }

        case 6: {
            int n;
            cin >> n;
            char s[101];
            for (int i = 0; i < n; i++) cin >> s[i];
            char c1, c2;
            cin >> c1 >> c2;
            character(n, s, c1, c2, 0);
            cout << s << endl;
            break;
        }

        case 7: {
            int n;
            cin >> n;
            int a[100];
            for (int i = 0; i < n; i++) cin >> a[i];
            cout << sum(0, a, n, 0) << endl;
            break;
        }

        case 8: {
            int n;
            cin >> n;
            char s[101];
            for (int i = 0; i < n; i++) cin >> s[i];
            cout << lexo(s, n, 0, s[0]) << endl;
            break;
        }
    }
    return 0;
}
