#include<stdio.h>
void dfs(int);
int a[10][10],n,exp[10],vis[10],j=0;
void main(){
    int m,u,v;
    printf("Enter the number of vertices:");
    scanf("%d",&n);


   printf("Enter number of edges edges\n");
   scanf("%d",&m);

    printf("Enter all edges\n");
   for(int i=1;i<=m;i++){

    scanf("%d%d",&u,&v);
    a[u][v]=1;
   }
   for(int i=1;i<=n;i++){
    if(vis[i]==0){
        dfs(i);
    }
   }
   printf("Topological order\n");
   for(int i=n-1;i>=0;i--){
    printf("%d\t",exp[i]);
   }
}
void dfs(int v){
    for(int i=1;i<=n;i++){
        if(a[v][i]==1 && vis[i]==0){
            dfs(i);
        }
    }
    exp[j++]=v;
}
