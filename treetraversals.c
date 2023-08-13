#include<stdio.h>
#include<time.h>
int a[100][100],reach[100],count=0,pos[100],n;
void bfs(int n,int source){
    int s[1000],q[1000],f=0,r=-1;
    for(int i=0;i<n;i++) s[i]=0;
    q[++r]=source;
    s[source]=1;
    while(f<=r){
        int i=q[f++];
        for(int j=0;j<n;j++){
            if(a[i][j]==1 && s[j]==0){
                q[++r]=j;
                printf("The city visited is %d \t %d",i,j);
                s[j]=1;
            }
        }
    }
}
int checkreach(int u){
    for(int i=0;i<count+1;i++){
        if(reach[i]==u) return 1;
    }
    return 0;
}
int adjacent(int i){
    for(int j=pos[i]+1;j<n;j++){
       if(a[i][j]==1){
        pos[i]=j; return j;
       }
    }
    pos[i]=n+1;
    return 0;
}
void dfs(int v){
 reach[count++]=v;
 int u=adjacent(v);
 while(u){
    if(checkreach(u)==0) dfs(u);
    u=adjacent(v);
 }
}
int main(){

    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
        a[i][j]=rand()%2;
        printf("%d\t",a[i][j]);
       }
       printf("\n");
    }
    clock_t st,et;
    st=clock();
      dfs(0);
    et=clock();
    printf("The reach array is: ");
    for(int i=0;i<n;i++){
        printf("%d\t",reach[i]);
    }
     
    double clk=(double)(et-st)/CLOCKS_PER_SEC;
    printf("\nThe runtime is %f",clk);
}