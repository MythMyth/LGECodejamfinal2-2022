#include <bits/stdc++.h>

using namespace std;

long long Cal(vector<long long> &sufixSum, int firstRange, int secondRange, int thirdRange) {
    int n = sufixSum.size();
    vector<long long> maxVal(n, LONG_LONG_MIN);
    vector<long long> minVal(n, LONG_LONG_MAX);
    for(int i = firstRange; i < n; i++) {
        long long sum = sufixSum[i] - sufixSum[i - firstRange];
        maxVal[i] = max(sum, maxVal[i-1]);
        minVal[i] = min(sum, minVal[i-1]);
    }

    vector<long long> maxVal2(n, LONG_LONG_MIN);
    vector<long long> minVal2(n, LONG_LONG_MAX);
    for(int i = secondRange + firstRange; i < n; i++) {
        long long sum = sufixSum[i] - sufixSum[i - secondRange];
        maxVal2[i] = max(maxVal2[i-1], max(maxVal[i - secondRange] * sum, minVal[i - secondRange] * sum));
        minVal2[i] = min(minVal2[i-1], min(maxVal[i - secondRange] * sum, minVal[i - secondRange] * sum));
    }
    long long ret = LONG_LONG_MIN;
    for(int i = secondRange + firstRange + thirdRange; i < n; i++) {
        long long sum = sufixSum[i] - sufixSum[i - thirdRange];
        ret = max(ret, max(maxVal2[i - thirdRange] * sum, minVal2[i - thirdRange] * sum));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t-- > 0) {
        int a, b, c, n;
        cin >> n >> a >> b >> c;
        vector<long long> v(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            v[i] += v[i-1];
        }
        long long ret = LONG_LONG_MIN;
        ret = max(ret, Cal(v, a, b, c));
        ret = max(ret, Cal(v, a, c, b));
        ret = max(ret, Cal(v, b, a, c));
        ret = max(ret, Cal(v, b, c, a));
        ret = max(ret, Cal(v, c, a, b));
        ret = max(ret, Cal(v, c, b , a));
        cout << ret << "\n";
    }
}
