#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main(){
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    int n,s,t;
    cin >> n >> s >> t;
    vector<tuple<int, int, int>> edge;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int w;
            cin >> w;
            if (i != j && w != 10000){
                edge.push_back({i,j,w});
            }
        }
    }
    vector<int> d(n + 1, INF);
    vector<int> par(n + 1, 0);
    d[s] = 0;
    for (int i = 1; i < n; i++){
        bool ok = false;
        for (auto x : edge){
            int u = get<0>(x);
            int v = get<1>(x);
            int w = get<2>(x);

            if (d[u] != INF && d[u] + w < d[v]){
                d[v] = d[u] + w;
                par[v] = u;
                ok = true;
            }
        }
        if (!ok) break;
    }
    bool check = false;
    for (auto x : edge){
        int u = get<0>(x);
        int v = get<1>(x);
        int w = get<2>(x);
        if (d[u] != INF && d[u] + w < d[v]){
            check = true;
            break;
        }
    }
    if (check){
        cout << -1 << endl;
    }else if (d[t] == INF){
        cout << 0 << endl;
    }else{
        cout << d[t] << endl;
        vector<int> path;
        int cur = t;
        while (cur != s){
            path.push_back(cur);
            cur = par[cur];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (auto x : path){
            cout << x << " ";
    }
}
}