#include "../common.hpp"

struct Compare
{
    bool operator() (const string& rhs,const string& lhs)const {
        if(rhs.size() > lhs.size()){
            return true;
        }else if(rhs.size() < lhs.size()){
            return false;
        } else{
            int i = 0;
            while(i < rhs.size()){
                if(rhs[i] > lhs[i]){
                    return true;
                } else if(rhs[i] < lhs[i]){
                    return false;
                }
                i++;
            }
            return false;
        }
    }
    /* data */
};


void universe_president(){
    int n;
    cin>>n;
    string m = "",cur;
    int res = 0;
    for(int i = 1;i <= n;i++){
        cin>>cur;
        if(cur.size() > m.size() || (cur.size() >= m.size() && cur > m)){
            res = i;
            m = cur;
        }
    }
    cout<<res<<endl;
    cout<<m<<endl;
}

void solution(){
    universe_president();
}