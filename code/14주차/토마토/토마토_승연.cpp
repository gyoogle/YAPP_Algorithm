#include<iostream>
#include<queue>

using namespace std;

int box[1003][1003];
int m,n;
int MAX;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
queue<pair<int,int> > here;

int Max(int a, int b){
    return a > b ? a : b;
}


void bfs(int x,int y){
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx <n&&ny<m&&nx>=0&&nx>=0){
            if(box[nx][ny]==0){
                box[nx][ny]=box[x][y]+1;
                here.push({nx,ny});
            }
        }
    }
}
int main(){
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cin >> box[i][j];
            if(box[i][j]==1){
                here.push({i,j});
            }
        }
    }
    
    while(!here.empty()){
        bfs(here.front().first,here.front().second);
        here.pop();
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(box[i][j]==0){
               cout << -1;
                return 0;
            }
            MAX = Max(MAX,box[i][j]);
        }
    }
     cout << MAX - 1;
    return 0;
}