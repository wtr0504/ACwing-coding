#include <bits/stdc++.h>
#include "../common.hpp"

#define ull unsigned long long
int n,ans;           //城市数 金币总数/答案
string a,b;          //城市名 州名 
map<string,int> box; //神奇的 map 

ull hashe(string x){
    const ull P = 131;
    const ull MOD = 1e9 + 7;
    ull h = 0;
    for(int i = 0;i < x.size();i++){
        h = (h * P + x[i]) % MOD;
    }
    return h;
}

void solution(){
	cin>>n;    //城市数量 
	while(n--) //重复 n 次 
	{
		cin>>a>>b;       //城市名 和 州名 
		a=a.substr(0,2); //取城市名称的前两位 
		if(a!=b)         //特判 不能自己跟自己对应 
		ans+=box[a+b];   //取得金币/答案贡献
		box[b+a]++;      //存入金币，造福 城州名恰好相反的城市 
	}
	cout<<ans<<endl;
}

