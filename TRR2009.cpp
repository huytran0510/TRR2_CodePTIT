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
bool visited[1001];
int a[1001][1001];
vector<int> lt;
vector<vector<int>> ans;

void dfs(int u){
    visited[u] = true;
    lt.pb(u);
    for (int i = 1; i <= n; i++){
        if (a[u][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}

int main() {
    faster();
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            lt.clear();
            dfs(i);
            sort(lt.begin(), lt.end());
            ans.pb(lt);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans){
        for (int i : x){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}