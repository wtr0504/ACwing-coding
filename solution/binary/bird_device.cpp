#include "../common.hpp"
#include <iomanip>

int n,p;
int a[100005],b[100005];

bool f(double x){
    double q = x * p;
    double sum = 0;
    for(int i = 0;i < n;i++){
        if(b[i] >= x * a[i]){
            continue;
        } else{
            sum += (a[i] * x - b[i]);
        }
    }
    return sum <= q;
}


void solution(){
    cin>>n>>p;
    int sum = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    if(sum <= p){
        cout<<(double)-1.0<<endl;
        return;
    }
    double l = 0,r = 1e10;
    while(r - l > 1e-6){
        double mid = (l + r) / 2;
        if(f(mid)){
            l = mid;
        } else{
            r = mid;
        }
    }
    cout<<fixed<<setprecision(10)<<l<<endl;
    return;
}