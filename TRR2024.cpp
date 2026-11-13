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
int a[101][101];
bool visited[101];
vector<int> ans;

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 1; i <= n; i++){
            if (a[x][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
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
    memset(visited, false, sizeof(visited));
    int lt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            lt++;
            bfs(i);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int cnt = 0;
        for (int j = 1; j <= n; j++){
            if (!visited[j]){
                cnt++;
                bfs(j);
            }
        }
        if (cnt > lt){
            res++;
            ans.pb(i);
        }
    }
    cout << res << endl;
    for (auto x : ans){
        cout << x << " ";
    }

    return 0;
}