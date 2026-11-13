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

int n,u,a[105][105];
int path[105];
bool visited[105];
int cnt = 0;

void dfs(int step, int cur){
    if (step == n){
        if (a[cur][u]){
            for (int i = 0; i < n; i++){
                cout << path[i] << " ";
            }
            cout << u << endl;
            cnt++;
        }
        return ;
    }
    for (int v = 1; v <= n; v++){
        if (a[cur][v] && !visited[v]){
            visited[v] = true;
            path[step] = v;
            dfs(step + 1, v);
            visited[v] = false;
        }
    }
}

int main() {
    faster();
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> u;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    visited[u] = true;
    path[0] = u;
    dfs(1,u);
    if (cnt == 0){
        cout << 0 << endl;
    }else{
        cout << cnt << endl;
    }
    return 0;
}