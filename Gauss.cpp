/*
方程左边的矩阵和等式右边的值，求解之后x存放的就是结果
num表示自由变元个数
freeX从1开始，其余数组从0开始

返回-1表示无解，否则返回自由变元数量，0表示有唯一解，正整数表示无穷多解
*/
const double eps=1e-11;
const int maxn=220;
double a[maxn][maxn],x[maxn],freeX[maxn];

int Gauss(int equ,int var){//方程数和未知数个数,行数，列数，从0开始
    int i,j,row,col,max_r;int num=0;
    for(row=0,col=0;row<equ&&col<var;row++,col++){
        max_r=row;
        for(i=row+1;i<equ;i++){//选主元
            if(fabs(a[i][col])>fabs(a[max_r][col]))
                max_r=i;
        }
        if(fabs(a[max_r][col])==0) {
            freeX[++num]=col;//
            row--;
            continue;
        }
        if(row!=max_r) {
            for(j=col;j<var;j++){
                swap(a[row][j],a[max_r][j]);
            }
            swap(x[row],x[max_r]);    
        }
        
        x[row]/=a[row][col];
        for(j=col+1;j<var;j++) a[row][j]/=a[row][col];
        a[row][col]=1;
        for( i=0;i<equ;i++){
            if(i!=row){
                x[i]-=x[row]*a[i][col];
                for(j=col+1;j<var;j++)
                    a[i][j]-=a[row][j]*a[i][col];
                a[i][col]=0;
            }
        }
    }
   for(i=row;i<equ;i++)
        if(fabs(x[i])>0)return -1;//无解
    return var-row;//自由变元个数有var-row
}



/*
求解异或方程组

方程左边的矩阵和等式右边的值，求解之后x存放的就是结果
num表示自由变元个数
freeX从1开始，其余数组从0开始

返回-1表示无解，否则返回自由变元数量，0表示有唯一解，正整数表示无穷多解
*/
const int maxn=220;
int  a[maxn][maxn],x[maxn],freeX[maxn];
int Gauss(int equ,int var){//方程数和未知数个数,行数，列数，从0开始
    int i,j,row,col,max_r;int num=0;
    for(row=0,col=0;row<equ&&col<var;row++,col++){
        max_r=row;
        for(i=row+1;i<equ;i++){//选主元
            if(a[i][col]>a[max_r][col])
                max_r=i;
        }
        if(a[max_r][col]==0) {
            freeX[++num]=col;//
            row--;
            continue;
        }
        if(row!=max_r) {
            for(j=col;j<var;j++){
                swap(a[row][j],a[max_r][j]);
            }
            swap(x[row],x[max_r]);    
        }
        
        for( i=0;i<equ;i++){
            if(i!=row&&a[i][col]==1){
                x[i]^=x[row];
                for(j=col+1;j<var;j++)
                    a[i][j]^=a[row][j];
                a[i][col]=0;
            }
        }
    }
   for(i=row;i<equ;i++)
        if(a[i][col]!=0)return -1;//无解
    return var-row;//自由变元个数有var-row
}
