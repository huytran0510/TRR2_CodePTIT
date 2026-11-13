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

int main() {
    faster();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t,n,m;
    cin >> t >> n >> m;
    vector<int> deg_ra (n + 1, 0), deg_vao(n + 1, 0);
    int a[n + 1][n + 1] = {0};
    for (int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        deg_ra[u]++;
        deg_vao[v]++;
        a[u][v] = 1;
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << deg_vao[i] << " " << deg_ra[i] << endl;
        }
    }else if (t == 2){
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}