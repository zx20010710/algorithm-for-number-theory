const int maxn=5e4+5;
long long phi[maxn];
void phi_table()
{
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!phi[i]){//如果是素数
            for(int j=i;j<maxn;j+=i){
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}