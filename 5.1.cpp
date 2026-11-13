#include <bits/stdc++.h>

using namespace std;

const int INF = 10000;

int n,s,t;
int a[101][101];
int d[101], pre[101];
bool vis[101];

void dijkstra(int s, int t){  
    d[s] = 0;
    vis[s] = 1;
    for (int i = 1; i <= n; i++){
        d[i] = a[s][i];
        pre[i] = s;
    }
    for (int i = 1; i <= n; i++){
        int u = 0;
        int min_d = INF;
        for (int v = 1; v <= n; v++){
            if (!vis[v] && d[v] < min_d){
                min_d = d[v];
                u = v;
            }
        }
        if (u == 0 || u == t) break;
        vis[u] = -1;
        for (int v = 1; v <= n; v++){
            if (!vis[v] && a[u][v] != INF && a[u][v] != 0){
                if (d[v] > d[u] + a[u][v]){
                    d[v] = d[u] + a[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}

int main(){
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    dijkstra(s,t);
    if (d[t] == INF) cout << 0;
    else{
        cout << d[t] << endl;
        vector<int> path;
        int cur = t;
        while(cur != s){
            path.push_back(cur);
            cur = pre[cur];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (auto x : path){
            cout << x << " ";
        }
    }

}