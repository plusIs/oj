#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
int n,m;  
int a[105];  
int b[105];  
int cnt;  
int flag;  
int main()  
{  
    int T;  
    scanf("%d",&T);  
    while(T--)  
    {  
        flag=0;  
        cnt=0;  
        scanf("%d%d",&n,&m);  
        if(m==0)  
        {  
            if(n==1)  
                printf("0 0\n");  
            else  
                printf("-1 -1\n");  
            continue;  
        }  
        memset(a,0,sizeof(a));  
        memset(b,0,sizeof(b));  
        int t=n-1;  
        while(m&&t>=0)//t>=0不能少，因为有可能各位上都是9，和也小于m   
        {  
            if(m>=9)  
            {  
                a[t]=9;  
                b[t]=a[t];  
                m-=9;  
            }     
            else  
            {  
                a[t]=m;  
                b[t]=a[t];  
                m=0;  
            }  
            t--;  
        }  
        if(m>0)  
        {  
            printf("-1 -1\n");  
            continue;  
        }  
        if(a[0]==0)//因为最高位要尽量小，但是有可能为0，又因为题上说不能有前导0   
        {//所以应该为1，然后把第二个高位非零位上的数减1！   
            a[0]=1;  
            a[t+1]--;  
        }//但是因为最大数不受这个因素影响，所以不用管它！   
        for(int i=0;i<n;i++)  
        {  
            printf("%d",a[i]);  
        }  
        printf(" ");  
        sort(b,b+n);  
        for(int i=n-1;i>=0;i--)  
        {  
            printf("%d",b[i]);  
        }  
        printf("\n");  
    }  
    return 0;  
}  