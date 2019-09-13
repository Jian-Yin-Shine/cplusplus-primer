#include <memory>
using std::weak_ptr; using std::shared_ptr;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	shared_ptr<int> p(new int(42));

	weak_ptr<int> wp(p);  // wp weakly shares with p; use count in p is unchanged

	p.reset(); // assuming p.unique() was true, the int is deleted

	if (shared_ptr<int> np = wp.lock()) { // true if np is not null
		// inside the if, np shares its object with p
	    cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
    return 0;
}
