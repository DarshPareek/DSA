#include <bits/stdc++.h>
using namespace std;

void printVec(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout<<endl;
}

int main(){
    // 17 15
    // -13 0 6 15 16 2 15 -12 17 -16 0 -3 19 -3 2 -9 -6
    int N = 17, K = 15;
    int A[17] = {-13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6,};
    int maxLen = 0, currLen = 0, l = 0, r = 0, sum = A[r];
    while(l <= N-1){
        cout << l << " " << r << " " << sum << " " << currLen << endl;
        if(sum < K && r < N-1){
            r++;
            sum += A[r];
        }else if(sum > K){
            sum -= A[l];
            l++;
        }else if(sum == K){
            sum = 0;
            currLen = r-l+1;
            l++;
        }
        if(currLen > maxLen){
            maxLen = currLen;
        }
        if(r == N-1){
            sum -= A[l];
            l++;
        }
    }
    cout << maxLen << endl;
    return 0;
}
