memcpy_s是memory copy safe的缩写，意为安全内存复制，在写C语言程序的时候，我们常常会用到它。

用于内存拷贝。

推测函数的原型如下：

errno_t memcpy_s(
 
    void* dest,
 
    size_t destMaxLen,
 
    const void  *src,
 
    size_t count);
 
具体的每个参数的意义，推测如下：

dest  目的内存地址

destMaxLen  目的内存最大长度

src  源内存地址

count 要拷贝的长度

注意点：
count一般是strlen(src)，而且 destMaxLen的长度一定要大于等于count，否则会出现内存拷贝截断的问题。
