int ans[100][100];
#define Max 1000000
int n;
int main(void){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ans[i][k]==Max||ans[k][j]==Max) continue;
                if(ans[i][j]==Max||ans[i][k]+ans[k][j]<ans[i][j])
                    ans[i][j]=ans[i][k]+ans[k][j];
            }
        }
    }
}
