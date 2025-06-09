#include "../common.hpp"
#include <cstdio>


vector<int> v(255,-1);
void del_number(){
    char c;
    int i = 1;
    while((c = getchar())){
        if(c == '\n') break;
        v[i++] = c - '0';
    }
    int n = i - 2;
    int k;
    cin>>k;
    for(int m = 0;m < k;m++){
        for(int j = 1;j <= n;j++){
            if(v[j] == -1) continue;

            int next = j + 1;
            while(next <= n && v[next] == -1) next++;

            if(next > n || v[j] > v[next]){
                v[j] = -1;
                break;
            }
        }
    }
    bool leading_zero = true;
    int count = 0;
    for (int j = 1; j <= n; ++j) {
        if (v[j] == -1) continue;
        if (leading_zero && v[j] == 0) continue;
        leading_zero = false;
        cout << v[j];
        count++;
        if (count == n - k) break;
    }

    if (count == 0) cout << "0";
    cout << endl;

}

void solution(){
    del_number();
}