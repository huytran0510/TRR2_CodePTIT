#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t,n;
    cin >> t >> n;
    int a[n + 1][n + 1], m = 0;
    vector<pair<int, int>> edge;
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if ((a[i][j] == 1) && (i < j)){
                deg[i]++;
                deg[j]++;
                m++;
                edge.push_back({i, j});
            }
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << deg[i] << " ";
        }
    }else if (t == 2){
        cout << n << " " << m << endl;
        for (auto x : edge){
            cout << x.first << " " << x.second << endl;
        }
    }
}