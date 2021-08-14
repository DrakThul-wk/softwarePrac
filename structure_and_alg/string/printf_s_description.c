printf_s与printf的异同

printf只是检查format字符串是否为空，如果为空会触发assert(false)
而printf_s还会检查format字符串是否有效，即格式是否合法，如果不合法，则触发assert(false)

#include <cstdio>
#include <string>

int main()
{
    char* format = nullptr;
    printf(format, "hello", 10); // 不合法，空指针
------------------------------------------
    char* format = "%s %d %k";
    printf_s(format, "hello", 10, 1); // 不合法，没有%k这个格式 
    return 0;
} 

在format字符串格式正确的情况下，
如果参数个数大于需要的个数，多余的参数忽略不处理。
如果是小于，没填参数的位置随机（或者为乱码）。
#include <cstdio>
#include <string>

int main()
{
    char* format1 = "%s %d\n";
    printf(format1, "hello", 10, 1); // 输出hello 10
    printf_s(format1, "hello", 10, 1); // hello 10

    char* format2 = "%s %d %d %d %s\n";
    printf(format2, "hello", 10, 1); // hello 10 1 123456789 ?6
    printf_s(format2, "hello", 10, 1); // hello 10 1 123456789 ?6

    return 0;
} 
