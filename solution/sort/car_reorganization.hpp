#include "../common.hpp"



int bubble(vector<int>& cars){
    int res = 0;
    int n = cars.size();
    for(int i = 0;i < n - 1;i++){
        bool fin = true;
        for(int j = 0;j < n - i - 1;j++){
            if(cars[j] > cars[j+1]){
                swap(cars[j],cars[j+1]);
                res++;
                fin = false;
            }
        }
        if(fin) return res;
    }
}


void car_reorganization(){
    int n;
    cin>>n;
    vector<int> cars(n);
    for(int i = 0;i < n;i++){
        cin>>cars[i];
    }
    cout<<bubble(cars)<<endl;
}

void solution(){
car_reorganization();
}