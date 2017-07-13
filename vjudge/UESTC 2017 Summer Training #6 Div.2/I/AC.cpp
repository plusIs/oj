#include<stdio.h>
#include<string.h>
using namespace std;
#define mod 1000000007
#define ll long long int
ll dp[2005][4];
void init()
{
    memset(dp,0,sizeof(dp));
    dp[1][1]=26;
    for(int i=2;i<=2003;i++)
    {
        dp[i][1]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod*25;
        dp[i][2]=dp[i-1][1]%mod;
        dp[i][3]=dp[i-1][2]%mod;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    init();
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%I64d\n",(dp[n][1]+dp[n][2]+dp[n][3])%mod);
    }
}
