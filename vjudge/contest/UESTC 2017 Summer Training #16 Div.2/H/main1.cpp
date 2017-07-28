#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
struct node
{
    char str[60][60];
    int num;
};
node M[3][4];
node temp;
char in[20];
char ch;
int H[5];
int x,y,len;
int d;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(M,0,sizeof M);
    for(int i=0;i<5;i++)
        H[i]=1;
    scanf("%d",&n);getchar();
    for(int i=0;i<n;i++)
    {
        gets(temp.str[0]);
        temp.num=1;
        for(int i=0;strlen(temp.str[i])>10;i++)
        {
            int j;
            if(temp.str[i][10]==' ')
                j=10;
            else
            {
                for(j=9;j>0;j--)
                    if(temp.str[i][j]==' ')
                    break;
            }
            temp.str[i][j++]=0;
            strcpy(temp.str[i+1],temp.str[i]+j);
            temp.num++;
        }
        scanf("%s",in);
        if(in[0]=='S')
            x=2;
        else if(in[0]=='T'&&in[1]=='u')
            x=0;
        else if(in[0]=='T'&&in[1]=='h')
            x=1;
        scanf("%d",&y);getchar();
        y--;
        M[x][y]=temp;
        H[y]=max(H[y],temp.num);
    }
    for(int i=0;i<4;i++)
    {
        printf("+----------+----------+----------+\n");
        for(int j=0;j<H[i];j++)
        {
            for(int k=0;k<3;k++)
            {
                putchar('|');
                if(j<M[k][i].num)
                {
                    printf("%s",M[k][i].str[j]);
                    len=strlen(M[k][i].str[j]);
                    for(int m=10-len;m;m--)
                        putchar(' ');
                }
                else
                    printf("          ");
            }
            puts("|");
        }
    }
    printf("+----------+----------+----------+");
    return 0;
}