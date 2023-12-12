const int N=1e7;
bool notp[N];
int prime[N],pnum;
void PrimeSieve(){
    //求[0,N) 的素数
    memset(notp,0,sizeof notp);
    notp[0]=notp[1]=1;
    pnum=0;
    for(int i=2;i<N;i++){
        if(!notp[i]) prime[++pnum]=i;
        for(int j=1;j<=pnum&&prime[j]*i<N;j++){
            notp[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}