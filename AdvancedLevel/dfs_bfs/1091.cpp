#include<iostream>
#include<queue>
using namespace std;
struct node{
    int x,y,z;
}Node;
int m,n,sclice,T;
int pixel[1290][130][61];
bool inq[1290][130][61]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
bool judge(int x,int y,int z)
{
    if(x<0 || x>=n || y<0 || y>=m || z>=sclice || z<0) return false;
    if(pixel[x][y][z]==0 || inq[x][y][z]==true) return false;
    return true;
}
int BFS(int x,int y,int z)
{
    int tot=0;
    queue<node> Q;
    Node.x=x,Node.y=y,Node.z=z;
    Q.push(Node);
    inq[x][y][z]=true;
    while(!Q.empty()){
        node top=Q.front();
        Q.pop();
        tot++;
        for(int i=0;i<6;i++){
            int nextX=top.x+X[i];
            int nextY=top.y+Y[i];
            int nextZ=top.z+Z[i];
            if(judge(nextX,nextY,nextZ)){
                Node.x=nextX,Node.y=nextY,Node.z=nextZ;
                Q.push(Node);
                inq[nextX][nextY][nextZ]=true;
            }
        }
    }
    if(tot>=T) return tot;
    return 0;
}
int main()
{
    cin >> n >> m >> sclice >> T;
    int sum=0;
    for(int z=0;z<sclice;z++){
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                cin >> pixel[x][y][z];
            }
        }
    }
    int ans=0;
    for(int z=0;z<sclice;z++){
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                if(pixel[x][y][z]==1 && inq[x][y][z]==false){
                    ans+=BFS(x,y,z);
                }
            }
        }
    }
    cout << ans;
    return 0;
}