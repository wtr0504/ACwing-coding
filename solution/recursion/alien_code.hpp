#include "../common.hpp"



string ailen_code(string &s){
    stack<pair<int,string>> stk;
    string res;
    int times = 0;
    for(int i = 0;i < s.size();){
        if(s[i] == '['){
            i++;
            while(isdigit(s[i])){
                times = times * 10 + s[i++] - '0';
            }
            stk.push({times,res});
            times = 0;
            res = "";
        } else if(s[i] == ']'){
            string tmp;
            int last_times = stk.top().first;
            string last_res = stk.top().second;
            stk.pop();
            for(int j = 0;j < last_times;j++){
                tmp += res;
            }
            res += last_res + tmp;
        } else{
            res += s[i];
        }
    }
}


void solution(){
    string s;
    getline(cin,s);
    cout<<ailen_code(s)<<endl;

}