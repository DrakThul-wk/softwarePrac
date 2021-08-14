sprintf与sprintf_s的函数功能：
将数据格式化输出到字符串

int sprintf( char *buffer, const char *format [,argument] ... )
注意这里的buffer指针 指向的是格式化字符后写入的首地址。

意思就是：格式化数据，并写入字符串，这些方法已经不用，因为有更安全的方法可用。


int sprintf_s( char *buffer, size_t sizeOfBuffer, const char *format [, argument] ... );
从原型上看：sprintf 和 sprintf_s 的差别就是sprintf_s多了一个参数sizeofbuffer。

两个的具体差别：
一个差别是：sprintf_s 会检查格式化字符的合法性，而sprintf只会检查其是否是空指针；
另一个差别是：sprintf_s 设置了输出buffer的大小。

sprintf_s()是sprintf()的安全版本，通过指定缓冲区长度来避免sprintf()存在的溢出风险。

常见用法：

//把整数123 打印成一个字符串保存在s 中。
sprintf(s, "%d", 123); //产生"123"
//可以指定宽度，不足的左边补空格：
sprintf(s, "%8d%8d", 123, 4567); //产生：" 123 4567"
//当然也可以左对齐：
sprintf(s, "%-8d%8d", 123, 4567); //产生："123 4567"
//也可以按照16 进制打印：
sprintf(s, "%8x", 4567); //小写16 进制，宽度占8 个位置，右对齐
sprintf(s, "%-8X", 4568); //大写16 进制，宽度占8 个位置，左对齐
char filename[1024];//需要预先分配缓冲区
char path1[128] = "D:\\Program\\Tesseract-OCR\\tesseract.exe";
char path2[128] = "D:\\Program\\Tesseract-OCR\\";
char path3[128] = "D:\\Program\\Tesseract-OCR\\txt";
char path4[128] = "-l chi_sim";
sprintf_s(filename,"%s %s %s %s",path1,filepath,path3,path4);