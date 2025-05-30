#include "../common.hpp"

int m[301][101][301];
int cnt[301][100];

void scholarship(){
    int n;
    memset(m, -1, sizeof(m));
    cin>>n;
    for(int i = 0;i < n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int sum = a+b+c;
        m[sum][a][cnt[sum][a]++] = i;
    }
    int c = 0;
    for(int i = 300;i >= 0;i--){
        for(int j = 100;j > 0;j--){
            for(int k = cnt[i][j];k >= 0;k--){
                if(m[i][j][k] != -1){
                    if(c == 5) return;
                    c++;
                    cout<<m[i][j][k] + 1<<" "<<i<<endl;
                }
                
            }
        }
    }
}
void solution(){
    scholarship();
}