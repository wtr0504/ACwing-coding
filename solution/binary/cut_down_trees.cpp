#include "../common.hpp"
#define ll long long

int heighs[400005];

void solution(){
    int n,m;
    cin>>n>>m;
    ll h;
    ll m_h = 0;
    for(int i = 0;i < n;i++){
        cin>>h;
        heighs[h]++;
        m_h = max(h,m_h);
    }
    ll mid;
    ll low = 0;
    ll cut = 0;
    while(low <= m_h){
        cut = 0;
        mid = (low + m_h) / 2;
        for(int i = mid + 1;i <= 400005;i++){
            if(heighs[i] != 0){
                cut += (i - mid) * heighs[i];
            }
        }
        if(cut < m){
            m_h = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout<<low - 1<<endl;
}