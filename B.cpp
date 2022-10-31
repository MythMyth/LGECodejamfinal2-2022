#include <bits/stdc++.h>

using namespace std;

struct NodeDetail{
    long long maxIncluded;
    long long maxNotIncluded;
    NodeDetail() :maxIncluded(0), maxNotIncluded(0) {

    }
};

void Cal(int node, vector<vector<int>> &child, vector<NodeDetail> &details, vector<int> &nodes ) {
    details[node].maxIncluded = nodes[node];
    for(int i = 0; i < child[node].size(); i++) {
        Cal(child[node][i], child , details, nodes);

    }
    int childIncluded = 0;
    for(int i = 0; i < child[node].size(); i++) {
        int sub = child[node][i];
        if(details[sub].maxIncluded < details[sub].maxNotIncluded) {
            details[node].maxNotIncluded += details[sub].maxNotIncluded;
        } else {
            details[node].maxNotIncluded += details[sub].maxIncluded;
            childIncluded++;
        }
        details[node].maxIncluded += details[sub].maxNotIncluded;
    }
    if(childIncluded == 0 && child[node].size() > 0) {
    long long desc = LONG_LONG_MAX;
        for(int i = 0; i < child[node].size(); i++) {
            int sub = child[node][i];
            desc = min(desc, details[sub].maxNotIncluded - details[sub].maxIncluded);
        }
        details[node].maxNotIncluded -= desc;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t-- > 0) {
        int n; cin >> n;
        vector<int> nodes(n), parent(n);
        for(int i = 0; i < n; i++) {
            cin >> nodes[i];
        }
        int root = -1;
        vector<vector<int>> child(n);
        for(int i = 0; i < n; i++) {
            cin >> parent[i];
            parent[i]--;
            if(parent[i] == -1) root = i;
            else child[parent[i]].push_back(i);
        }

        vector<NodeDetail> details(n);
        Cal(root, child, details, nodes);

        cout << max(details[root].maxIncluded, details[root].maxNotIncluded ) << "\n";
    }
}
