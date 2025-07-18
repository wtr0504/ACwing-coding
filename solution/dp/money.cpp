#include <climits>
#include <iostream>

using namespace std;

int money[10005];
int n,w;
int a[1005];

void solution(){
    cin>>n>>w;
    for(int i = 0;i < n;i++) cin>>a[i];
    for(int i = 1;i <= w;i++) money[i] = 1145141919;

    for(int j = 0;j < n;j++){
        for(int i = a[j];i <= w;i++){
            money[i] = min(money[i],money[i - a[j]] + 1);
        }
    }
    cout<<money[w]<<endl;

}

