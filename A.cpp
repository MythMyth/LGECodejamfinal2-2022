#include <bits/stdc++.h>

using namespace std;

const int UP = 1;
const int DOWN = -1;
const int NONE = 0;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t-- > 0) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if(n == 1) {
            cout << "0\n";
            continue;
        }
        int i = 1;
        long long ret = 0;
        while(i < n) {
            int currDir = NONE;
            while(currDir == NONE && i < n) {
                if(arr[i] > arr[i-1]) {
                    currDir = UP;
                } else if(arr[i] < arr[i-1]) {
                    currDir = DOWN;
                }
                i++;
            }
            long long currLen = 2;
            while(currDir != NONE && i < n) {
                if(currDir == UP) {
                    if(arr[i] < arr[i-1]) {
                        currDir = DOWN;
                        currLen++;
                    } else {
                        break;
                    }
                } else {
                    if( arr[i] > arr[i-1]) {
                        currDir = UP;
                        currLen++;
                    } else {
                        break;
                    }
                }
                i++;
            }
            if(currDir != NONE) {
                currLen--;
                ret += ((currLen) * (currLen+1)) / 2;
            }

        }
        cout << ret << "\n";
    }
}