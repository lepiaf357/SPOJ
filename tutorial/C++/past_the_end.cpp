#include <iostream>

// using namespace std;

int main()
{
     int a[10] = {1,2,3,4,5,6,7,8,9,10};
     int* p = &a[5]; // pointer to element at index 5
     std::cout << a[5] << " same as " << *p << '\n';
     int* q = p + 1; // pointer to element at index 6
     std::cout << a[6] << " same as " << *q << '\n';

     int a1[10] = {1,2,3,4,5,6,7,8,9,10};
     int* last = &a1[9]; // points to last element
     int* end = last + 1; // past-the-end pointer for array a

     int* bad = end + 1; // error (undefined behavior)

     std::cout << *end << '\n'; // error (undefined behavior)

     std::cout << &a1[9] << " same as " << *last << " same as " << (end-1) << '\n';

     return 0;

}
