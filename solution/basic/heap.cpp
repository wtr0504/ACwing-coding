#include <iostream>

using namespace std;
int heap[1005];
int n;
int cnt;


void heapify(int start){
    int parent = start;
    int child = start * 2;

    while(child <= cnt){
        if(child + 1 <= cnt && heap[child + 1] < heap[child]) child++;
        if(heap[child] < heap[parent]){
            swap(heap[child],heap[parent]);
            parent = child;
            child  = parent * 2;
        } else {
            break;
        }
    }
}

void insert(int val){
    heap[++cnt] = val;
    if(cnt == 1){
        return;
    }
    for(int i = (cnt / 2); i > 0;i /=2 ){
        heapify(i);
    }
}


void rm(){
    heap[1] = heap[cnt--];
    heapify(1);
}


void solution(){
    cin>>n;
    int o;
    for(int i = 0;i < n;i++){
        cin>>o;
        int val;
        if(o == 1){
            cin>>val;
            insert(val);
        } else if(o == 2){
            cout<<heap[1]<<endl;
        } else {
            rm();
        }
    }
}

