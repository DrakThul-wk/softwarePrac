int partition(int *data, int s, int t, int target)
{
    int a, b, c, tmp;
    a = c = s;
    b = t;
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