ASCII
a:97
A:65
0:48

大写变小写，小写变小写
x |= 32

大写变小写，小写变大写
x ^= 32

大写变大写，小写变大写
x &= -33

--------------------------------------------------
isalpha()判断一个字符是否是字母
int isalpha ( int c );

isalpha() 函数用来检测一个字符是否是字母。
在默认情况下，字母包括：
a b c d e f g h i j k l m n o p q r s t u v w x y z  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z


标准 ASCII 编码共包含了 128 个字符，不同的字符属于不同的分类，我们在 <ctype.h> 头文件中给出了详细的列表。
参数c
要检测的字符。它可以是一个有效的字符（被转换为 int 类型），也可以是 EOF（表示无效的字符）。
返回值
返回值为非零（真）表示c是字母，返回值为零（假）表示c不是字母。

---------------------------------------------------
isdigit()判断一个字符是否是十进制数字
int isdigit ( int c );

isdigit() 用来检测一个字符是否是十进制数字。

十进制数字包括：0 1 2 3 4 5 6 7 8 9

标准 ASCII 编码共包含了 128 个字符，不同的字符属于不同的分类，我们在 <ctype.h> 头文件中给出了详细的列表。
参数c
要检测的字符。它可以是一个有效的字符（被转换为 int 类型），也可以是 EOF（表示无效的字符）。
返回值
返回值为非零（真）表示c是十进制数字，返回值为零（假）表示c不是十进制数字。
char str[]="1776ad";
int year;
if (isdigit(str[0])) {
    year = atoi (str);
    printf ("The year that followed %d was %d.\n", year, year+1);
}
-----------------------------------------------------
isalnum()判断一个字符是否是字母或数字
int isalnum ( int c );

isalnum() 函数用来检测一个字符是否是字母或者十进制数字。

如果仅仅检测一个字符是否是字母，可以使用 isalpha() 函数；如果仅仅检测一个字符是否是十进制数字，可以使用 isdigit() 函数。

如果一个字符被 isalpha() 或者 isdigit() 检测后返回“真”，那么它被 isalnum() 检测后也一定会返回“真”。

标准 ASCII 编码共包含了 128 个字符，不同的字符属于不同的分类，我们在 <ctype.h> 头文件中给出了详细的列表。
参数c
要检测的字符。它可以是一个有效的字符（被转换为 int 类型），也可以是 EOF（表示无效的字符）。
返回值
返回值为非零（真）表示c是字母或者十进制数字，返回值为零（假）表示c既不是十进制数字，也不是字母。
int i = 0, n = 0;
char str[] = "*ab%c123_ABC-.";
while(str[i])
{
    if( isalnum(str[i]) ) n++;
    i++;
}
printf("There are %d characters in str is alphanumeric.\n", n);
运行结果：
There are 9 characters in str is alphanumeric.
-------------------------------------------------------
islower()判断一个字符是否是小写字母
int islower ( int c );

islower() 函数用来检测一个字符是否是小写字母。

在默认情况下，小写字母包括：
a b c d e f g h i j k l m n o p q r s t u v w x y z


标准 ASCII 编码共包含了 128 个字符，不同的字符属于不同的分类，我们在 <ctype.h> 头文件中给出了详细的列表。
参数c
要检测的字符。它可以是一个有效的字符（被转换为 int 类型），也可以是 EOF（表示无效的字符）。
返回值
返回值为非零（真）表示c是小写字母，返回值为零（假）表示c不是小写字母。
int i=0;
char str[]="c c++ java python.\n";
char c;
while (str[i])
{
    c=str[i];
    if (islower(c)) c=toupper(c);
    putchar (c);
    i++;
}