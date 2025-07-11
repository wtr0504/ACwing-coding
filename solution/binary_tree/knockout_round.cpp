#include <bits/stdc++.h>
#include <iostream>
#include "../common.hpp"
/**
    
*/
int tmp,n,tmp2,p,ans;
struct cou{
	int en;//每个国家的能量值
	int ta;//每个国家的编号
}a[200];

bool cmp(cou x,cou y)
{
	return x.en>y.en;//对结构体sort排序
}


void solution(){
	cin>>tmp;
	n=pow(2,tmp);
	for(int i=1;i<=n;i++){
		cin>>a[i].en;
		a[i].ta=i;
	}
	sort(a+1,a+n/2+1,cmp);//前一部分国家排序
	sort(a+n/2+1,a+n+1,cmp);//后一部分国家排序
	if(a[1].en>a[n/2+1].en){
		cout<<a[n/2+1].ta;//输出较小能量值的国家的编号
	}
	else{
		cout<<a[1].ta;
	}
}