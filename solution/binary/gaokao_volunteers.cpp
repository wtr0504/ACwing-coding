#include "../common.hpp"
#include <algorithm>



int score[100005],line[100005];
void gaokao_volunteers(){
    int m,n;
    cin>>m>>n;
    for(int i = 0;i < m;i++) cin>>line[i];
    for(int j = 0;j < n;j++) cin>>score[j];

    sort(line,line + m);
    long res = 0;
    for(int i = 0;i < n;i++){
        int l = 0,r = m - 1;
        while(l < r){
            int mid = (l + r) /2;
            if(line[mid] >= score[i]){
                r = mid;
            } else{
                l = mid + 1;
            }
        }
        if(line[0] >= score[i]){
            res += line[0] - score[i];
        } else
        res += min(abs(line[l] - score[i]),abs(line[l - 1] - score[i]));
    }
    cout<<res<<endl;
}

void solution(){
    gaokao_volunteers();
}