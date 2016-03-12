typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
const ll mod = 1000000007;
class Matrix {
private:
	int r, c;
	ll **m;
public:
	Matrix(int R, int C): r(R), c(C) {
		m = new ll*[r];
		REP(i, r) m[i] = new ll[c];
		REP(i, r) REP(j, c) m[i][j] = 0;
	}
	Matrix(const Matrix& B) {
		r = B.r; c = B.c; m = new ll*[r];
		REP(i, r) m[i] = new ll[c];
		REP(i, r) REP(j, c) m[i][j] = B.m[i][j];
	}
	~Matrix() {REP(i, r) delete[] m[i]; delete[] m;}
	void e() {REP(i, r) REP(j, c) m[i][j] = !(i ^ j);}
	ll* operator [] (int p) {return m[p];}
	ll* operator [] (int p) const {return m[p];}
	Matrix& operator = (const Matrix& B) {
		r = B.r; c = B.c; this->~Matrix(); m = new ll*[r];
		REP(i, r) m[i] = new ll[c];
		REP(i, r) REP(j, c) m[i][j] = B[i][j];
		return *this;
	}
	Matrix operator * (const Matrix& B) const {
		Matrix rt(r, B.c);
		REP(i, r) REP(k, c) if (m[i][k] != 0) REP(j, B.c)
			rt[i][j] = (rt[i][j] + m[i][k] * B[k][j] % mod) % mod;
		return rt;
	}
	Matrix operator ^ (ll n) {
		Matrix rt(r, c); rt.e();
		Matrix ba(*this);
		while (n) {
			if (n & 1) rt = rt * ba;
			ba = ba * ba;
			n >>= 1;
		}
		return rt;
	}
	void out() {
		REP(i, r) REP(j, c)
		cout << m[i][j] << (j == c - 1 ? '\n' : ' ');
		cout << endl;
	}
};
