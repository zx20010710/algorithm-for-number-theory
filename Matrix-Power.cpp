const int max_n=4;
const int max_m=4;
struct Matrix
{
	ll m, n;//mxn 矩阵
	long long  M[max_m][max_n];
	Matrix(int m, int n) :m(m), n(n) {}
	void init() { memset(M, 0, sizeof(M)); }
	Matrix operator*(const Matrix B) const {
		Matrix result(m, B.n);//存放答案
		result.init();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (M[i][j])//快速幂优化
					for (int k = 0; k <B.n; k++)
						result.M[i][k] =(result.M[i][k]+1ll* M[i][j] * B.M[j][k])%Mod;
		return result;
	}
};
Matrix Matrixfast(Matrix a, ll n)
{
	Matrix res(a.m, a.m);
	res.init();
	for (int i = 0; i < a.m; i++)
		res.M[i][i] = 1;
	while (n)
	{
		if (n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}