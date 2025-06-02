#include "../common.hpp"

void paint_stripes(){
    int n,m;
    cin>>n>>m;
    vector<int> w(n + 1,0);
    vector<int> b(n + 1,0);
    vector<int> r(n + 1,0);
    for(int i = 1;i <= n;i++){
        string s;
        cin>>s;
        int t1 = 0,t2 = 0,t3 = 0;
        for(auto & c : s){
            if(c == 'W') t1++;
            else if(c == 'B') t2++;
            else if(c == 'R') t3++;
        }
        w[i] = w[i - 1] + m - t1;
        b[i] = b[i - 1] + m - t2;
        r[i] = r[i - 1] + m - t3;
    }
    int res = INT_MAX;
    for(int i = 1;i < n - 1;i++){
        for(int j = i + 1;j < n;j++){
            res = min(res,w[i] + b[j] - b[i] + r[n] - r[j]);
        }
    }
    cout<<res<<endl;
}

void solution(){
    paint_stripes();
}