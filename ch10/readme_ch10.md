### 第十章知识点

第一讲

- 只读算法：accumulate, equal。写算法：fill, fill_n, back_inserter, copy, replace, replace_copy。重新排列：sort, unique

- 定制操作：

  1、向算法传递函数

  2、Lambda 表达式（捕获列表，参数，返回类型，函数体），返回一个无类型，无名字的可调用对象。

  3、重载了()的类对象

  4、函数指针

- 当函数参数个数不满足算法的谓词时，bind重新修饰函数，返回一个满足算法参数个数的可调用对象。

10.2.cpp, new count-size.cc, lambda.cc, absInt.cc, bind.cc

注意：

```c++
// 算法内部实现是 func(first), 调用这个可调用的定制操作
for_each(item.begin(), item.end(), func)
// find_if内部实现 if(pred(*first)) return first;
find_if(item.beign(), item.end(), pred)
// 具体定制操作，可调用对象（函数，lambda）需要几个参数，内部做什么，需要参考源码
```



第二讲

- 插入迭代器
- 输入，输出流迭代器
- 反向迭代器

inserters.cc, iostream_iter.cc, use-istream-iter.cc, reverse-iter.cc