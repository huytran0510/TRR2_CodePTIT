#include <bits/stdc++.h>

using namespace std;

int n,u;
int a[101][101];
vector<bool> vis(101, false);
vector<vector<int>> g(101);
vector<pair<int, int>> ck;

void dfs(int u){
    vis[u] = true;
    for (int v : g[u]){
        if (!vis[v]){
            ck.push_back({min(u,v), max(u,v)});
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int v : g[x]){
            if (!vis[v]){
                vis[v] = true;
                ck.push_back({min(x,v), max(x,v)});
                q.push(v);
            }
        }
    }
}


int main(){
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    int t;
    cin >> t >> n >> u;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] == 1){
                g[i].push_back(j);
            }
        }
    }
    if (t == 1){
        dfs(u);
    }else if (t == 2){
        bfs(u);
    }
    if (ck.size() == n - 1){
        cout << ck.size() << endl;
        for (auto x : ck){
            cout << x.first << " " << x.second << endl;
        }
    }else{
        cout << 0 << endl;
    }
}