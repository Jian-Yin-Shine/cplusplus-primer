#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::allocator;

#include <cstddef>
using std::size_t;

#include <fstream>
using std::ifstream;

int main()
{
    const size_t n = 100;
    allocator<string> alloc;
    string *p = alloc.allocate(n);
    
    string *q = p;

    alloc.construct(q++, string());
    cout << *(q-1) << endl;
    
    alloc.construct(q++, 10, 'c');
    cout << *(q-1) << endl;
    
    alloc.construct(q++, string("hi"));
    cout << *(q-1) << endl;
    
    cout << *p << endl;

    while(q!=p) {
        cout << "destroy " << *q << endl;
        alloc.destroy(--q);
    }
    
    cout << *p << endl;
    alloc.deallocate(p, n);
    
    p = alloc.allocate(n);
    string s;
    q = p;
    ifstream in("data/storyDataFile");
    while(in >> s && q != p + n) 
        alloc.construct(q++, s);
    size_t size = q -p;

    cout << "read " << size << " strings" << endl;
    
    for (q = p + size -1; q != p; --q)
        alloc.destroy(q);
    alloc.deallocate(p, n);

    in.close();
    in.open("data/storyDataFile");
    p = new string[n];
    q = p;
    while(in >> s && q != p + n)
        *q ++  = s;
    size = q - p;
    cout << "read " << size << " strings" << endl;
    in.close();

    delete [] p;

    return 0;    
}
