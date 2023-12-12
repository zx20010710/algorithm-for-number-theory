typedef long long ll;
const ll N =1e6+10;//
int mu[N],notp[N],prime[N],pnum;
void MobiusSieve()
{
    //[0,N]的Mobius 表
    // mu[1]=1,有平方数银子为0，否则为(-1)^k,k为不相同的素因子个数
    //notp表示是不是素数,0表示是素数
    memset(notp,0,sizeof(notp));
    notp[0]=notp[1]=1,mu[1] = 1,pnum=0;
    for (int i = 2; i <= N; i++)
    {
        if (!notp[i])  prime[++pnum] = i,mu[i]=-1;//i是素数，mu[i]=-1;
        for (int j = 1; j <= pnum && prime[j] * i <= N; j++)
        {
            notp[prime[j] * i] = 1;
            if (i % prime[j] == 0) {mu[i*prime[j]]=0;break;}
            mu[i*prime[j]]=-mu[i];//从i上添了一个不同的素因子,所以*（-1）
        }
    }
}