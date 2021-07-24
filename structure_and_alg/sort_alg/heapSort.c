void Sift(int *data, int low, int high)
{
	int i, j;
	i = low;
	j = 2 * i;
	int tmp = data[i];
	while (j <= high) {
		if (j < high && data[j] < data[j + 1]) {
			j++;
		}
		if (tmp < data[j]) {
			data[i] = data[j];
			i = j;
			j = 2 * i;
		} else {
			break;
		}
	}
	data[i] = tmp;
}

void HeapSort(int *data, int n)
{
	int i, j;
	// remember index start from 1
	for (i = n / 2; i >= 1; i--) {
		Sift(data, i, n); // 从子树开始构成堆
	}
	int tmp;
	for (i = n; i > 1; i--) {
		tmp = data[n];
		data[n] = data[1];
		data[1] = tmp;
		Sift(data, 1, i - 1); 
	}
}