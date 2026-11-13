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
int start;

void dfs(int u){
    visited[u] = true;
    for (int i = 1; i <= n; i++){
        if ((a[u][i] || a[i][u]) && !visited[i]){
            dfs(i);
        }
    }
}

int check(){
    int in[105] = {0}, out[105] = {0};
    int s_cnt = 0, e_cnt = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j]){
                out[i]++;
                in[j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (out[i] - in[i] == 1){
            s_cnt++;
        }else if (in[i] - out[i] == 1){
            e_cnt++;
        }else if (in[i] != out[i]){
            return 0;
        }
    }
    if (s_cnt > 1 || e_cnt > 1) return 0;
        memset(visited, false, sizeof(visited));
        start = 1;
        for (int i = 1; i <= n; i++){
            if (in[i] > 0 || out[i] > 0){
                start = i;
                break;
            }
        }
        dfs(start);
         for (int i = 1; i <= n; i++){
            if ((in[i] > 0 || out[i] > 0) && !visited[i]) return 0;
        }
        if (s_cnt == 0 && e_cnt == 0) return 1;
        if (s_cnt == 1 && e_cnt == 1) return 2;
        return 0;
}

void euler(int u){
    stack<int> st;
    vector<int> EC;
    st.push(u);
    while(!st.empty()){
        int x = st.top();
        bool adj = false;
        for (int i = 1; i <= n; i++){
            if (a[x][i] == 1){
                st.push(i);
                a[x][i] = 0;
                adj = true;
                break;
            }
        }
        if (!adj){
            st.pop();
            EC.pb(x);
        }
    }
    for (int i = EC.size() - 1; i >= 0; i--){
        cout << EC[i] << " ";  
    }
}

int main() {
    faster();
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    int t,m;
    cin >> t;
    if (t == 1){
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        cout << check() << " ";
    }else if (t == 2){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        euler(m);
    }
    return 0;
}