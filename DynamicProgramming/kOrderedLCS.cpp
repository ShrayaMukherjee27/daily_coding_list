#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long dp[2005][2005][8];
int m,n;
long long korderedLCS(int *a, int *b, int i, int j, int k){
    if(i==m || j==n) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    long long res = 0;
    if(a[i]==b[j]){
        res = 1 + korderedLCS(a,b,i+1,j+1,k);
    }
    else{
        if(k>0){
            res = 1 + korderedLCS(a,b,i+1,j+1,k-1);
        }
        res = max(res, korderedLCS(a,b,i+1,j,k));
        res = max(res, korderedLCS(a,b,i,j+1,k));
    }
    return dp[i][j][k]=res;
}

int main(){
    int k = 2;
    int a[] = {1, 3, 4, 1, 7, 9, 6};
    int b[] = {3, 4, 1, 6, 8};
    m = sizeof(a)/sizeof(a[0]);
    n = sizeof(b)/sizeof(b[0]);
    memset(dp, -1, sizeof(dp));
    cout<<korderedLCS(a,b,0,0,k);
}
