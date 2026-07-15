// #include<stdio.h>
// #include<bits/stdc++.h>
// class Solution {
// public:
//     void nextGreaterElement() {

//         int n1 ,n2 ;
//         cin >> n1 >> n2;

//         vector<int> nums1(n1),nums2(n2),ans;

//         for(int i=0;i<n1;i++){
//             cin >> nums1[i];
//         }
//         for(int j=0;j<n2;j++){
//             cin >> nums2[j];
//         }
//         for(int i=0;i<n1;i++){
//             int j=0;int flag = 0;
//             while(j<n2){
//                 if(nums2[j] == nums1[i]){
//                     while(j<n2){
//                         if(nums2[j] > nums1[i]){
//                             ans.push_back(nums2[j]);
//                             flag = 1;
//                             break;
//                         }
//                         j++;
//                     }
//                     if(flag == 0){
//                         ans.push_back(-1);
//                     }
//                     break;
//                 }
//             } 
//         }
//         for(int k=0;k<n1;k++){
//             cout << ans[k] << " ";
//         }
//     }
// };
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextGreaterElement() {
        int n1, n2;
        cin >> n1 >> n2;

        vector<int> nums1(n1), nums2(n2), ans;

        for (int i = 0; i < n1; i++) {
            cin >> nums1[i];
        }
        for (int j = 0; j < n2; j++) {
            cin >> nums2[j];
        }

        for (int i = 0; i < n1; i++) {
            int j = 0, flag = 0;
            while (j < n2) {
                if (nums2[j] == nums1[i]) {
                    while (j < n2) {
                        if (nums2[j] > nums1[i]) {
                            ans.push_back(nums2[j]);
                            flag = 1;
                            break;
                        }
                        j++;
                    }
                    if (flag == 0) {
                        ans.push_back(-1);
                    }
                    break; // ✅ break only after processing a match
                }
                j++; // ✅ don't forget to move to next element
            }
        }

        for (int k = 0; k < n1; k++) {
            cout << ans[k] << " ";
        }
        cout << endl;
    }
};
