#include "../common.hpp"

void ping_pong(){
    vector<std::pair<int,int>> eleven;
    vector<pair<int,int>> twenty;
    int huahua_1 = 0,huahua_2 = 0;
    int rival_1 = 0,rival_2 = 0;
    char c;
    while(c = getchar()){
        if(c == 'E'){
            eleven.push_back({huahua_1,rival_1});
            twenty.push_back({huahua_2,rival_2});
            break;
        }
        if(c == 'W'){
            huahua_1++;
            huahua_2++;
        } 
        else if(c == 'L'){
            rival_1++;
            rival_2++;
        }else if (c == '\n' || c == ' ') {
            continue;  // 明确忽略换行或空格
        } else {
            continue;  // 忽略其他非法字符
        }
        if(abs(huahua_1 - rival_1) >= 2 && (huahua_1 >= 11 || rival_1 >= 11)){
            eleven.push_back({huahua_1,rival_1});
            huahua_1 = 0;
            rival_1 = 0;
        }
        if(abs(huahua_2 - rival_2) >= 2 && (huahua_2 >= 21 || rival_2 >= 21)){
            twenty.push_back({huahua_2,rival_2});
            huahua_2 = 0;
            rival_2 = 0;
        }
    }
    for(auto &[hua,rival] : eleven){
        cout<<hua<<":"<<rival<<endl;
    }
    cout<<endl;
    for(auto &[hua,rival] : twenty){
        cout<<hua<<":"<<rival<<endl;
    }
}

void solution(){
    ping_pong();
}