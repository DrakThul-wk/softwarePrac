void SelectSort(int *data, int n)
{
	int i, j, k, tmp;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (data[j] < data[i]) {
				k = j;
			}
		}
		if (k != i) {
			tmp = data[i];
			data[i] = data[k];
			data[k] = tmp;
		}
	}
	return;
}