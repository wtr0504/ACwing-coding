#include <iostream>
#include <vector>

using namespace std;


int graph[25][25];
int a[25];
int n;
vector<int> path;

void dfs(int x){
    path.push_back(x);

    for(int i = x + 1;i <= n;i++){
        if(graph[x][i]){
            dfs(i);
        }
    }


}


void solution(){
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= n - 1;i++){
        for(int j = i + 1;j <= n;j++){
            int c;
            cin>>c;
            if(c == 1){
                graph[i][j] = 1;
            }
        }
    }

    for(int i = 0;i <= n;i++){

    }
}

