#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
const int MAXN=2000;
int t,n,m;
long long k;
int C[2003][2003];//存 C(n,m) 模 k 后的余数


void solution(){
    cin>>t>>k;
    for(int i = 0;i <= MAXN;i++){
        for(int j = 0; j <= i;j++){
            if(j == 0 || i == j) C[i][j] = 1;
            else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % k;
        }
    }
    int res =0 ;

	while(t--){
		int ans=0;
		cin>>n>>m;
		for(int i=0;i<=n;i++){
			int mn=min(i,m);
			for(int j=0;j<=mn;j++){
				ans+=(C[i][j]%k==0);
			}
		}
		cout<<ans<<'\n';
	}
}

