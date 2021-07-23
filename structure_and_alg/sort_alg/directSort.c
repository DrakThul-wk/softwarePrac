void DirectSort(int *data, int n)
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++) {
		tmp = data[i];
		j = i - 1;
		while (j >= 0 && tmp < data[j]) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = tmp;
	}
}