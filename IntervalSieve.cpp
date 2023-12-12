typedef long long ll;
const int N=1e6+5;//N>=sqrt(R);
ll L, R;
bool notp[N];
int prime[N], pnum;
void sieve()
{
    //[0,sqrt(R)]的素数表
    memset(notp, 0, sizeof(notp));//0为素数；
    notp[0] = notp[1] = 1;
    pnum = 0;
    for (int i = 2; i <= sqrt(R); i++)
    {
        if (!notp[i])  prime[++pnum] = i;
        for (int j = 1; j <= pnum && prime[j] * i <= sqrt(R); j++)
        {
            notp[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
const int max_k=1e6+5; //max_v>=R-L+2
bool v[max_k];//从L开始的数是否为素数，素数0；
void interval_sieve()//区间筛[L,R]  放进[1,R-L+1]我喜欢闭区间
{
    memset(v,0,sizeof(v));
    for (int i = 1; i <= pnum; i++)
    {
        for (ll j = L / prime[i]; j <= R / prime[i]; j++)
            if (j > 1) v[prime[i] * j - L + 1] = 1;
    }
}