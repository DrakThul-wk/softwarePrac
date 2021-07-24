void QuickSort(int *data, int s, int t)
{
	int i, j, tmp;
	if (s < t) {
		i = s;
		j = t;
		tmp = data[i];
		while (i != j) { // 注意这个地方的退出条件
			while (i < j && data[j] > tmp) {
				j--;
			}
			data[i] = data[j];
			while (i < j && data[i] < tmp) {
				i++;
			}
			data[j] = data[i];
		}
		data[i] = tmp;
		QuickSort(data, s, i - 1);
		QuickSort(data, i + 1, t);
	}
}