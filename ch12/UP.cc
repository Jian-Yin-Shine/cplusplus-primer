#include <memory>
using std::shared_ptr;
using std::unique_ptr;

void deleter(int *p) { delete [] p; }

int main()
{
    unique_ptr<int[]> up(new int[10]);
    for (int i = 0; i != 10; ++i) 
        up[i] = i;
    up.release();

    shared_ptr<int> sp(new int[10], deleter);
    for (int i = 0; i != 10; ++i)
        *(sp.get() + i) = i;
    sp.reset();

    return 0;    
}
