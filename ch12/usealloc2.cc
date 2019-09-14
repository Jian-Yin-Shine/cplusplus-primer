#include <memory>
using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_fill_n;

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() 
{
    int temp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vi(temp, temp+sizeof(temp)/sizeof(*temp));
    
    allocator<int> alloc;
    int *p = alloc.allocate(vi.size() *2);

    int *q = uninitialized_copy(vi.begin(), vi.end(), p);
    uninitialized_fill_n(q, vi.size(), 42);

    for (size_t i = 0; i != vi.size() * 2; ++i)
        cout << *(p + i) << " ";
    cout << endl;
    
    alloc.deallocate(p, vi.size()*2);

    return 0;    
}
