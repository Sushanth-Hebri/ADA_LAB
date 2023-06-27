#include<stdio.h>
int vis[10];
int q[10][10];
void bfs(int v){
int f=0,r=0,u;
vis[v]=1;
q[r]=v;
while(f<=r){
    u=q[f];
    printf("%d",u);
    for(int i=1;i<=n;++){
        if(q[u][i]==1 && vis[i]==0){
            r=r+1;
            q[r]=i;
            vis[i]=1;
        }
    }
    f=f+1;
}
}
void main(){
    int n;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&q[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            bfs(i);
        }
    }
    getch();
}
