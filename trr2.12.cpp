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
int a[105][105];
bool visited[105];
vector<int> c;
vector<vector<int>> ans;

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    c.pb(u);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 1; i <= n; i++){
            if (a[x][i] && !visited[i]){
                visited[i] = true;
                c.pb(i);
                q.push(i);
            }
        }
    }
}

int main() {
    faster();
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            c.clear();
            bfs(i);
            sort(c.begin(), c.end());
            ans.pb(c);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans){
        for (int i = 0; i < x.size(); i++){
            cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}