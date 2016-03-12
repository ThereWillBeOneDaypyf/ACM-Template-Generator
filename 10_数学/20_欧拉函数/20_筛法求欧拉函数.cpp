const int MAXN = 10001;
int phi[MAXN] = {0, 1};
void CalEuler() {
	for (int i = 2; i < MAXN; i++)
		if (!phi[i]) for (int j = i; j < MAXN; j += i) {
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
}
