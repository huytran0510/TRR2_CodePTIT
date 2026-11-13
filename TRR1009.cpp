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
    int t,n;
    cin >> t >> n;
    vector<int> deg(105, 0);
    int a[105][105] = {0};
    int m = 0;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        deg[i] = k;
        while (k--){
            int x;
            cin >> x;
            if (i < x){
                m++;
                a[i][m] = 1;
                a[x][m] = 1;
            }
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << deg[i] << " ";
        }
    }else if (t == 2){
        cout << n << " " << m << endl;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}