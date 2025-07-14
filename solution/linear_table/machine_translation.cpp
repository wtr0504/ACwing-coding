#include <algorithm>
#include <bits/stdc++.h>
#include "../common.hpp"



int n,m,x,ans,l,r,a[1005],b[1005];
void solution(){
    
        cin>>m>>n;
        l=0;r=0;//初始化两个指针
        for (int i=1;i<=n;i++)
         {
             scanf("%d",&x);//边读入边做
             if (a[x]==0) 
             {
                 ans++;
                r++;b[r]=x;a[x]=1;//因为每次遇到新单词都要做这些操作，不如搬到判断语句外做，这样程序更简洁
                if (r>m) {l++;a[b[l]]=0;}
             }
         }
        cout<<ans;
}
