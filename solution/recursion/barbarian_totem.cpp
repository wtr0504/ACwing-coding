#include "../common.hpp"

/**
    /\
   /__\
*/
string ans[2000];
//2^10=1024，开2000足够
void add(int end){
	for (int i=end;i<(end<<1);i++){
		ans[i]=ans[i-end]+ans[i-end];
	}
	for (int i=0;i<end;i++){
		ans[i].insert(0,end,' ');
		ans[i].insert(ans[i].length(),end,' ');
	}
}


void barbarian_totem(){
	int n;
    cin>>n;
	ans[0]=" /\\ ";
	ans[1]="/__\\";//这里要写两个反斜杠，一个反斜杠是转义字符
	for (int i=1;i<n;i++) add(1<<i);//不断复制原图形
	for (int i=0;i<(1<<n);i++) cout<<ans[i]<<endl;
}

void solution(){
    barbarian_totem();
}
