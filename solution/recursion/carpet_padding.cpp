#include "../common.hpp"
using namespace std;

void carpet_padding(int x,int y,int a,int b,int len){
    if(len==1)return;
    
    if(x - a <= len/2 - 1 && y - b <= len/2 - 1){
        cout<<a + len/2<<" "<<b + len/2<<" "<<"1"<<endl;
        carpet_padding(x,y,a,b,len/2);
        carpet_padding(a + len/2 - 1,b + len/2,a,b + len/2,len/2);
        carpet_padding(a + len/2,b + len/2 - 1,a + len/2,b,len/2);
        carpet_padding(a + len/2,b + len/2,a + len/2,b + len/2,len/2);
    } else if(x - a <= len/2 - 1 && y - b > len/2 - 1){
        cout<<a + len/2<<" "<<b + len/2 - 1<<" "<<"2"<<endl;
        carpet_padding(a + len/2 - 1,b + len/2 - 1,a,b,len/2);
        carpet_padding(x,y,a,b + len/2,len/2);
        carpet_padding(a + len/2,b + len/2 - 1,a + len/2,b,len/2);
        carpet_padding(a + len/2,b + len/2,a + len/2,b + len/2,len/2);
    } else if(x - a > len/2 - 1 && y - b <= len/2 - 1){
        cout<<a + len/2 - 1<<" "<<b + len/2<<" "<<"3"<<endl;
        carpet_padding(a + len/2 - 1,b + len/2 - 1,a,b,len/2);
        carpet_padding(a + len/2 - 1,b + len/2,a,b + len/2,len/2);
        carpet_padding(x,y,a + len/2,b,len/2);
        carpet_padding(a + len/2,b + len/2,a + len/2,b + len/2,len/2);
    } else{
        cout<<a + len/2 - 1<<" "<<b + len/2 - 1<<" "<<"4"<<endl;
        carpet_padding(a + len/2 - 1,b + len/2 - 1,a,b,len/2);
        carpet_padding(a + len/2 - 1,b + len/2,a,b + len/2,len/2);
        carpet_padding(a + len/2,b + len/2 - 1,a + len/2,b,len/2);
        carpet_padding(x,y,a + len/2,b + len/2,len/2);
    }
}

void solution(){
    int n,x,y;
    cin>>n>>x>>y;
    carpet_padding(x,y,1,1,pow(2,n));
}