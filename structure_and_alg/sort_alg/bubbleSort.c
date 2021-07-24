void BubbleSort(int *data, int n)
{
	int i, j, exchange, tmp;
	for (i = 0; i < n - 1; i++) {
		exchange = 0;
		for (j = n - 1; j > i; j--) {
			if (data[j] > data[j - 1]) {
				exchange = 1;
				tmp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = tmp;
			}
		}
		if (exchange == 0) {
			break;
		}
	}
	return;
}