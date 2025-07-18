#include <bits/stdc++.h>
using namespace std;

long long s=1,n,a[51];

void solution(){
    cin>>n;
    int c;
    int i;

    for(i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        s*=(a[i]-i+1);
        s%=(1000000000 + 7);
    }
    cout<<s<<endl;
}