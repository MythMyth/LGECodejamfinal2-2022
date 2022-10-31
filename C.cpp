#include <bits/stdc++.h>

using namespace std;

struct LvlDetail {
    int count;
    int startFrom;
    LvlDetail() : count(0), startFrom(0) {}
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t-- > 0) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> xlvl(n, 0), ylvl(m, 0);
        vector<pair<int, int>> e;

        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            e.push_back({x, y});
            xlvl[x]++;
            ylvl[y]++;
        }
        map<int, LvlDetail> xcounter, ycounter;
        for(int i = 0; i < n; i++) {
            xcounter[xlvl[i]].count++;
        }
        for(int i = 0; i < m; i++) {
            ycounter[ylvl[i]].count++;
        }
        long long startFrom = 1;
        long long retH = 0, retHi = 0;
        for(auto it: xcounter) {
            long long endAt = startFrom + it.second.count - 1;
            retH += ((startFrom + endAt) * it.second.count / 2 * it.first);
            xcounter[it.first].startFrom = startFrom;
            startFrom += it.second.count;
        }
        startFrom = 1;
        for(auto it: ycounter) {
            long long endAt = startFrom + it.second.count - 1;
            retH += ((startFrom + endAt) * it.second.count / 2 * it.first);
            ycounter[it.first].startFrom = startFrom;
            startFrom += it.second.count;
        }
        long long minDesc = LONG_LONG_MAX;
        for(int i = 0; i < k; i++) {
            int thisXlvl = xlvl[e[i].first], thisYlvl= ylvl[e[i].second];
            minDesc = min(minDesc, (long long)(xcounter[thisXlvl].startFrom + ycounter[thisYlvl].startFrom));
        }
        retHi = retH - minDesc;
        cout << retH << " " << retHi << "\n";

    }
}
