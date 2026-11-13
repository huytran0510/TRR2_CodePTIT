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

int n;
int a[1001][1001];
bool visited[1001];
vector<int> ans;


void dfs(int u){
    visited[u] = true;
    for (int i = 1; i <= n; i++){
        if (a[u][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}

int main() {
    faster();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int tplt = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            tplt++;
            dfs(i);
        }
    }
    vector<pair<int, int>> edge;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1 && i < j){
                a[i][j] = 0;
                a[j][i] = 0;
                memset(visited, false, sizeof(visited));
                int cnt = 0;
                for (int k = 1; k <= n; k++){
                    if (!visited[k]){
                        cnt++;
                        dfs(k);
                    }
                }
                if (cnt > tplt){
                    edge.pb({i,j});
                }
                a[i][j] = 1;
                a[j][i] = 1;
            }
        }
    }
    cout << edge.size() << endl;
    for (auto x : edge){
        cout << x.fi << " " << x.se << endl;
    }
    return 0;
}