#include <bits/stdc++.h>
#include <unordered_map>
#include "../common.hpp"

unordered_map<string,string> m;


void solution(){
    string s,name,father;
    while(true){
        cin>>s;
        if(s[0] == '#'){
            name = s.substr(1,6);
            if(m.find(name) == m.end()){
                m.insert({name,""});
            } 
            father = name;
        } else if(s[0] == '+'){
            name = s.substr(1,6);
            m[name] = father;
        } else if(s[0] == '?'){
            name = s.substr(1,6);
            while(m.find(name) != m.end()){
                name = m[name];
            }
            cout<<s.substr(1,6)<<" "<<name<<endl;
        } else{
            break;
        }
    }
}