#include<bits/stdc++.h>

using namespace std;

typedef tuple<int,int,int> iii;
vector<pair<int,int>> g[1005];
vector<bool> visited(1005, false);
vector<iii> caykhung;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    int n, u;
    cin >> n >> u;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int w; cin >> w;
            if(w > 0 && w != 10000){
                g[i].push_back({j, w});
            }
        }
    }
    int weight = 0;
    visited[u] = true;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    for(auto x : g[u]){
        int v = x.first;
        int w = x.second;
        pq.push({w, u, v});
    }
    while(!pq.empty() && caykhung.size() < n - 1) {
        auto[w, x, y]= pq.top(); pq.pop();
        if(visited[y]) continue;

        visited[y] = true;
        weight += w;
        caykhung.push_back({min(x, y), max(x, y), w});

        for(auto z : g[y]){
            int next_y = z.first;
            int next_w = z.second;
            if(!visited[next_y]){
                pq.push({next_w, y, next_y});
            }
        }
    }
    if(caykhung.size() < n - 1){
        cout << "0" << endl;
    }else{
        cout << weight << endl;
        for(auto[x, y, z] : caykhung){
            cout << x << " " << y << " " << z << endl;
        }
    }
    return 0;
}