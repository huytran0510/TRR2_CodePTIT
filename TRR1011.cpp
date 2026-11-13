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
    int a[101][101] = {0};
    vector<int> deg(101, 0);
    for (int i = 1; i <= m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        deg[x]++;
        deg[y]++;
        a[x][y] =  a[y][x] = z; 
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j){
                a[i][j] = 0;
            }else if (i != j && a[i][j] == 0){
                a[i][j] = 10000;
            }
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << deg[i] << " ";
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