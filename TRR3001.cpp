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

void dfs(int u){
    visited[u] = true;
    for (int i = 1; i <= n; i++){
        if (a[u][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}

int check(){
    memset(visited, false, sizeof(visited));
    int cnt = 0, u = -1;
    vector<int> deg(n + 1, 0);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1) deg[i]++;
        }
        if (deg[i] % 2 != 0) cnt++;
        if (deg[i] > 0 && u == -1) u = i;
    }

    if (u != -1) {
        dfs(u);
        for (int i = 1; i <= n; i++){
            if (deg[i] > 0 && !visited[i]) return 0; 
        }
    } 

    if (cnt == 0) return 1;
    if (cnt == 2) return 2;
    return 0;
}

void euler(int u){
    stack<int> st;
    vector<int> ec;
    st.push(u);
    while (!st.empty()){
        int x = st.top();
        bool adj = false;
        for (int i = 1; i <= n; i++){
            if (a[x][i] == 1){
                st.push(i);
                a[x][i] = a[i][x] = 0;
                adj = true;
                break;
            }
        }
        if (!adj){
            st.pop();
            ec.pb(x);
        }
    }
    for (int i = ec.size() - 1; i >= 0; i--){
        cout << ec[i] << " ";
    }
}

int main() {
    faster();
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    int t,u;
    cin >> t;
    if (t == 1){
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        cout << check() << endl;
    }else if (t == 2){
        cin >> n >> u;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        euler(u);
    }
    return 0;
}