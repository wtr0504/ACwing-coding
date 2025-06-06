#include "../common.hpp"

vector<char> V(210);

vector<string> ss = {"ooo*o**--","o--*o**oo","o*o*o*--o","--o*o*o*o"};

void move_chess_piece(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        V[i] = 'o';
    }
    for(int i = n+3;i <= 2 * n + 2;i++){
        V[i] = '*';
    }
    V[n + 1] = '-';
    V[n + 2] = '-';
    int blank = n + 1;
    int black_end = 2 * n + 1;
    for(int i = 1;i <= n - 3;i++){
        swap(V[blank],V[black_end]);
        swap(V[blank + 1],V[black_end + 1]);
        for(int j = 1;j <= 2 * n + 2;j++){
            cout<<V[j];
        }
        cout<<endl;
        swap(V[blank - 1],V[black_end]);
        swap(V[blank],V[black_end + 1]);
        for(int j = 1;j <= 2 * n + 2;j++){
            cout<<V[j];
        }
        cout<<endl;
        blank--;
        black_end -= 2;
    }
    int p = ss[0].size() + 1;
    for(int i = 0;i < 4;i++){
        string post(V.begin() + (size_t)p,V.begin() + (size_t)(2 * n + 3));
        cout<<ss[i] + post<<endl;
    }
}

void solution(){
    move_chess_piece();
}