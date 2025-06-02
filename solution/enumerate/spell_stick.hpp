#include "../common.hpp"
#define C(m,n) (n == 1 ? m : m * (m-1) / 2)
#define MOD(n) (n % (1000000000 + 7))

vector<int> length(50001,0);


void spell_stick(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int maxa = INT_MIN,mina = INT_MAX;
    for(int i = 0;i < n;i++){
        cin>>nums[i];
        maxa = max(maxa,nums[i]);
        mina = min(mina,nums[i]);
        length[nums[i]]++;
    }
    int res = 0;

    for(int i = mina + 1;i <= maxa;i++){
        if(length[i] >= 2){
            int times = MOD(C(length[i] , 2));
            for(int j = mina;j <= i / 2;j++){
                if(j == i - j && length[j] >= 2){
                    res = MOD(res + times * C(length[j],2));
                }else if(j != i - j && length[j] >= 1 && length[i - j] >= 1){
                    res = MOD(res + times * C(length[j],1) * C(length[i - j],1));
                }
                res = MOD(res);
            }
        }
    }
    cout<<res<<endl;
}

void solution(){
    spell_stick();
}