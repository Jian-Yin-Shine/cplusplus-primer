#### 第六章函数知识点



第一讲

- 函数生命周期，static.    6.1.cpp
- 参数传递：值传递（包括指针），引用传递， 形参用const修饰    6.2.1.cpp
- 数组作为参数，多维数组作为参数，形参是数组的指针（同普通对象的地址）6.2.2.cpp

第二讲

- main    6.2.3.cpp
- 实参数量不一定，initializer_list    6.2.4.cpp
- 返回类型，值传递，返回引用，返回指针，返回数组的指针 int (*fun(int i))[10]     6.2.5.cpp
- 函数重载，忽略顶层const，不忽略底层const    6.2.6.cpp

第三讲

- Const_cast    6.2.7.cpp
- 默认实参，内联函数，constexpr函数，重载函数的匹配  6.2.8.cpp
- 指向函数的指针，函数指针做形参bool (\*p)(int \*, int) ，返回函数的指针 auto f1(int i) -> int(*)(int *, int)  6.2.9.cpp