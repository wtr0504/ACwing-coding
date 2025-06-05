#include "../common.hpp"
#define ll long long
/**
 * COW -> COWWCO -> COWWCOOCOWWC
 * 先复制最后一个字符，再复制后面的串，化解子问题：
 * 求第三个串的8 ，就是求第二个串的 8 - L/2 - 1
 * 
 */

void Secret_Cow_Code_S(){
    string s;
    ll n;
    cin>>s>>n;
    ll len = s.size();
    ll L = len;
    while(n > len){
        L = len;
        while(n > L)
            L <<= 1;
        L /= 2;
        n -=  L + 1;
        if(n == 0) n = L;
    }

    cout<<s[n-1]<<endl;    
}

void solution(){
    Secret_Cow_Code_S();
}