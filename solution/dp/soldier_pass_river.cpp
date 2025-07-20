#include <iostream>

using namespace std;

long long  dp[25][25];
int valid[25][25];

int n,m;
int x,y;
int dir[8][2] = {{1,2},{1,-2},{2,-1},{2,1},{-1,2},{-1,-2},{-2,1},{-2,-1}};


void solution(){
    cin>>m>>n>>x>>y;
    dp[x][y] = -1;
    for(int i = 0;i < 8;i++){
        int n_x = x + dir[i][0];
        int n_y = y + dir[i][1];
        if(n_x >= 0 && n_x <= m && n_y >= 0&& n_y <= n){
            dp[n_x][n_y] = -1;
        }
    }

    dp[0][0] = 1;
    for(int i = 1;i <= m;i++){
        if(dp[i-1][0] != -1 && dp[i][0] != -1 && dp[i-1][0] != 0){
            dp[i][0] = 1;
        }
    }
    for(int i = 1;i <= n;i++){
        if(dp[0][i-1] != -1 && dp[0][i] != -1 && dp[0][i-1] != 0){
            dp[0][i] = 1;
        }
    }

    for(int i = 1;i <= m;i++){
        for(int j = 1; j <= n;j++){
            if(dp[i][j] == -1) continue;
            dp[i][j] = (dp[i-1][j] != -1 ? dp[i-1][j] : 0) + (dp[i][j-1] != -1 ? dp[i][j-1] : 0);
        }
    }

    cout<<dp[m][n]<<endl;
}



int main(){
    solution();
    return 0;
}