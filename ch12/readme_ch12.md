### 第十一章知识点

第一讲

- 动态内存与智能指针
- 动态数组

1. Shared_ptr可以用make_shared和new来初始化

2. Shared_ptr的拷贝，赋值。r = q;

3. 直接管理内存：new & delete, 也可以初始化const对象

4. Shared_ptr.get() 返回p中的指针。 

```C++
shared_ptr<int> p(new int(1024));
int *tp = p.get();
{
  shared_ptr<int> q(tp); // 则p,q指向同一个内存对象，但是p,q独立，计数器均为1
}
// 离开代码块后，q释放了对象
int tmp = *p; // 将变得未定义
```

5. unique_ptr指针，release()方法，不销毁对象，不释放内存，只是不再绑定该对象，返回那个对象的指针。

   ```C++
   p2.release() // 错误，p2不会释放内存，而且丢失了指针
   auto p = p2.release(); // 这才正确
   delete(p);
   ```

6. unique_ptr指针所指的对象，对象只能有一个指针，因此不能p=q; 使得q指向的对象有两个指针。但是，除了函数返回值值为unique_ptr之外。

   ```c++
   unique_ptr<int> clone(int p) {
     unique_ptr<int> ret(new int(p));
     //...
     return ret;
   }
   ```

7. Unique_ptr和shared_ptr都可以传递（自定义）删除器。形式不一样

   ```c++
   unique_ptr<objT, delT> p (new objT, fcn);
   shared_ptr<int> sp(new int[10], [](int *p){delete [] p});
   ```

8. Weak_ptr核查类，lock()检查对象是否被销毁

9. 动态数组

10. 智能指针& 动态数组：

- Unique_ptr版本能正常释放掉数组(release())，shared_ptr要传递删除器lambda表示式。
- Unique_ptr指向数组时，不能用.->。但是可以用[]
- Shared_ptr不能用[]，必须用get()拿到指针，访问数组。

Foo.h & StrBlob.h & useBlob.cc & knew.cc & UP.cc && weak.cc



第二讲

- allocator 类

```c++
allocator<int> alloc;
int *p = alloc.allocate(n);
int *q = p;
alloc.construct(p++, int(42));
while(q!=p)
  alloc.destroy(--p);
alloc.dellocate(p, n)

vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9};
auto p = alloc.allocate(vi.size()*2);
auto q = uninitialized_copy(vi.begin(), vi.end(), p);
uninitialized_fill_n(q, vi.size(), 42);
```

