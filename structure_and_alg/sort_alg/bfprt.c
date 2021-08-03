void InsertSort(int *a, int s, int t)
{
    int i, j, tmp;
    for (i = s + 1; i <= t; i++) {
        tmp = a[i];
        j = i - 1;
        while (j >= s && a[j] > tmp) {
            a[j + 1] = a[j];
            j = j - 1;;
        }
        a[j + 1] = tmp;
    }
}

int partition(int *data, int s, int t, int pivotId)
{
    int a, b, c, tmp;
    a = c = s;
    b = t;
    int target = data[pivotId];
    while (c <= b) {
        if (data[c] < target) {
            tmp = data[c];
            data[c] = data[a];
            data[a] = tmp;
            a++;
            c++;
        } else if (data[c] > target) {
            tmp = data[c];
            data[c] = data[b];
            data[b] = tmp;
            b--;
        } else {
            c++;
        }
    }
    return a;
}

int bfprt(int *a, int l, int r, int id)
{
    if (r - l + 1 <= 5) {
        InsertSort(a, l, r);
        return a[l + id - 1];
    }
    int t = l - 1;
    for (int st = l, ed; (ed = st + 4) <= r; st += 5) {
        InsertSort(a, st, ed);
        t++;
        int tmp = a[t];
        a[t] = a[st + 2];
        a[st + 2] = tmp;
    }
    int pivotId = (l + t) / 2;
    bfprt(a, l, t, pivotId - l + 1);
    int m = partition(a, l, r, pivotId);
    int cur = m - l + 1;
    if (id == cur) {
        return a[m];
    } else if (cur < id) {
        return bfprt(a, m + 1, r, id - cur);
    } else {
        return bfprt(a, l, m - 1, id);
    }
}