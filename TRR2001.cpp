#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
#define pb push_back
#define fi first 
#define se second 
#define setpre(n) fixed << setprecision(n)
#define gcd __gcd
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define mod 1000000007

int t,n,u,v;
bool visited[1005];
int a[1005][1005];
int par[1005];

void dfs(int u){
    visited[u] = true;
    for (int i = 1; i <= n; i++){
        if (a[u][i] == 1 && !visited[i]){
            par[i] = u;
            dfs(i);
        }
    }
}

int main() {
    faster();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> t >> n >> u >> v;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){  
            cin >> a[i][j];
        }
    }
    if (t == 1){
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (a[u][i] == 1 && a[i][v] == 1){
                cnt++;
            } 
        }
        cout << cnt;
    }else if (t == 2){
        memset(visited, false, sizeof(visited));
        memset(par, 0, sizeof(par));
        dfs(u);
        if (!visited[v]){
            cout << 0 << endl;
        }else{
            vector<int> path;
            int cur = v;
            while (cur != u){
                path.pb(cur);
                cur = par[cur];
            }
            path.pb(u);
            for (int i = path.size() - 1; i >= 0; i--){
                cout << path[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}