(1)strlen计算时，一定要确保字符数组是以空字符结束的，如果没有则可能沿着数组在内存中的位置不断向前寻找，
知道遇到空字符才停下来。
(2)当字符串为nullptr时，strlen行为未定义。

char str[] = "hello,world";
int len = strlen(str); // 11， 正常长度

char str[] = {'h','e','l','l','o',',','w','o','r','l','d'};
int len = strlen(str); // 23 or random value

char str[] = "hello,world";
int len = strnlen_s(str, 5); // 5， 只在要求范围内找

char str[] = {'h','e','l','l','\0'};
int len = strnlen_s(str, 5); // 4， 在要求范围内找到了\0

char str[] = {'h','e','l','l'};
int len = strnlen_s(str, 5); // 5， 在要求范围内没找到\0，所以输出5

char *str = NULL;
int len = strnlen_s(str, 5); // 0， 空指针，直接0