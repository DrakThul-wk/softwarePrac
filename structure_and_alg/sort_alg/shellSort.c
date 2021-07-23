void ShellSort(int *data, int n)
{
	int d, i, j, tmp;
	d = n / 2;
	while (d > 0) {
		for (i = d; i < n; i++) {
			tmp = data[i];
			j = i - d;
			while (j >= 0 && tmp < data[j]) {
				data[j + d] = data[j];
				j = j - d;
			}
			data[j + d] = tmp;
		}
		d = d / 2;
	}
}