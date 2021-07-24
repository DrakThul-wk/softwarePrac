void Merge(int *data, int low, int mid, int high)
{
	int i, j, k;
	int n = (high - low + 1);
	int *dataTmp = (int *)malloc(sizeof(int) * n);
	i = low;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= high) {
		if (data[i] < data[j]) {
			dataTmp[k++] = data[i++];
		} else {
			dataTmp[k++] = data[j++];
		}
	}
	while (i <= mid) {
		dataTmp[k++] = data[i++];
	}
	while (j <= high) {
		dataTmp[k++] = data[j++];
	}
	memcpy(&data[low], dataTmp, sizeof(int) * n);
}

void MergeProc(int *data, int length, int n)
{
	int low, mid, high;
	low = 0;	
	while (low + 2 * length - 1 < n) {
		mid = low + length - 1;
		high = low + 2 * length - 1;
		Merge(data, low, mid, high);
		low = low + 2 * length;
	}
	if (low + length - 1 < n) {
		mid = low + length - 1;
		high = n - 1;
		Merge(data, low, mid, high);
	}
}


void MergeSort(int *data, int n) {
	for (int length = 1; length < n; length = length * 2) {
		MergeProc(data, length, n);
	}
}