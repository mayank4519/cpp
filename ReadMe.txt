Constructors:
any new programmers are confused about whether constructors create the objects or not. They do not (the code the compiler creates does that).

Constructors actually serve two purpose. The primary purpose is to initialize objects that have already been created. The secondary purpose is to allow creation of an object. That is, an object of a class can only be created if a matching constructor can be found. This means that a class without any public constructors can’t be created!

Although the main purpose of a constructor is to initialize an object, whether the constructor actually does an initialization is up to the programmer. It’s perfectly valid to have a constructor that does no initialization at all (the constructor still serves the purpose of allowing the object to be created, as per the above).

Finally, constructors are only intended to be used for initialization when the object is created. You should not try to call a constructor to re-initialize an existing object. While it may compile, the results will not be what you intended (instead, the compiler will create a temporary object and then discard it).

Starting with C++11, constructors are now allowed to call other constructors. This process is called delegating constructors (or constructor chaining).

When the compiler compiles a normal member function, it implicitly adds a new parameter to the function named “this”. The this pointer is a hidden const pointer that holds the address of the object the member function was called on.

Pass by reference:

Pass by address:
 Passing an argument by address involves passing the address of the argument variable rather than the argument variable itself. Because the argument is an address, the function parameter must be a pointer. The function can then dereference the pointer to access or change the value being pointed to.
 
 Addresses are actually passed by value

When you pass a pointer to a function by address, the pointer’s value (the address it points to) is copied from the argument to the function’s parameter. In other words, it’s passed by value! If you change the function parameter’s value, you are only changing a copy. Consequently, the original pointer argument will not be changed.

Note that even though the address itself is passed by value, you can still dereference that address to change the argument’s value. This is a common point of confusion, so let’s clarify:

When passing an argument by address, the function parameter variable receives a copy of the address from the argument. At this point, the function parameter and the argument both point to the same value.
If the function parameter is then dereferenced to change the value being pointed to, that will impact the value the argument is pointing to, since both the function parameter and argument are pointing to the same value!
If the function parameter is assigned a different address, that will not impact the argument, since the function parameter is a copy, and changing the copy won’t impact the original. After changing the function parameter’s address, the function parameter and argument will point to different values, so dereferencing the parameter and changing the value will no longer affect the value pointed to by the argument.


Virtual function:
A virtual function is a special type of function that, when called, resolves to the most-derived version of the function that exists between the base and derived class. This capability is known as polymorphism. A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const) and return type as the base version of the function. Such functions are called overrides.

To help address the issue of functions that are meant to be overrides but aren’t, C++11 introduced the override specifier. Override can be applied to any override function by placing the specifier in the same place const would go. If the function does not override a base class function, the compiler will flag the function as an error.

Run time and compile time binding.
Virtual finction will allow run time binding to achieve runtime polymorphism.
Non virtual function bind at compile time.
Run time is achived only through pointer/reference of base class type.


There is no performance penalty for using the override specifier, and it helps avoid inadvertent errors. Consequently, we highly recommend using it for every virtual function override you write to ensure you’ve actually overridden the function you think you have.

Shallow copy and deep copy:


Late Binding

In some programs, it is not possible to know which function will be called until runtime (when the program is run). This is known as late binding (or dynamic binding). In C++, one way to get late binding is to use function pointers. To review function pointers briefly, a function pointer is a type of pointer that points to a function instead of a variable. The function that a function pointer points to can be called by using the function call operator (()) on the pointer.

For example, the following code calls the add() function:
#include <iostream>
 
int add(int x, int y)
{
    return x + y;
}
 
int main()
{
    // Create a function pointer and make it point to the add function
    int (*pFcn)(int, int) = add;
    std::cout << pFcn(5, 3) << std::endl; // add 5 + 3
 
    return 0;
}
Calling a function via a function pointer is also known as an indirect function call.


Pure virtual (abstract) functions and abstract base classes

So far, all of the virtual functions we have written have a body (a definition). However, C++ allows you to create a special kind of virtual function called a pure virtual function (or abstract function) that has no body at all! A pure virtual function simply acts as a placeholder that is meant to be redefined by derived classes.

To create a pure virtual function, rather than define a body for the function, we simply assign the function the value 0.


Type casting

In C++, there are 5 different types of casts: C-style casts, static casts, const casts, dynamic casts, and reinterpret casts.

Because C-style casts are not checked by the compiler at compile time, C-style casts can be inherently misused, because they will let you do things that may not make sense, such as getting rid of a const or changing a data type without changing the underlying representation (leading to garbage results).

Consequently, C-style casts should generally be avoided.

Rule: Avoid C-style cast

Smart pointer is a wrapper around a real pointer.It is used to automate the process of new and delete of a pointer.
Types:
1.Rule: std::auto_ptr is deprecated and should not be used. (Use std::unique_ptr or std::shared_ptr instead)
std::auto_ptr implements move semantics using copy constructor & copy assignment.Pass by value of ptr to function and then delete it.
While accessing the same ptr in caller will crash the program.
In auto ptr, when copy costructor is invoked r-value is deleted that means ownership changes.

2.unique_pointer -> which will get free when its out of scope.ptr copy is not possible means 2 unique_pointer pointing to same loaction
is not possible.
Copy constructor and copy assignment of unique ptr is deleted that means those operations are not allowed.

3.shared_pointer -> works on reference counting.As soon as that count reaches zero, memory is freed.


Dynamic casting is to find out object's class at runtime.


smart pointer
unique and shared pointer.

routing protocols -> spanning tree protocol,etc

containers ->vectors, list, map(in-depth)

run-time/compile time polymorphism
run-time: virtual functions
compile-time: function overloading

binary search tree,hasing, trie algorithms:

pointer and reference:

static variable in classes:
C++ forbids in-class initialization of non-const static member 
There cannot be multiple copy of static varibale in class for multiple objects.
Just like variables, objects also when declared as static have a scope till the lifetime of program.
Static member functions are allowed to access only the static data members or other static member functions, they can not access the non-static data members or member functions of the class.

diff between list and vector.

lambda function

design patterns->singleton class
The singleton design pattern restricts the instantaition of a class to one object.
Instance is created only once.
Other classes cannot instanciate, to do this constructor is made as private.
Instance should be globally accessible.

Factory method:
It creates object without exposing the creation logic to the client class.And client uses the same common interface to create new type of object.


dynamic casting->Dynamic casting is to find out object's class at runtime.dynamic_cast.base class should be polymorphic.
dynamic casting using shared pointer.

member intialisation list->initializer_list

virtual destructor: Base class should always have virtual destructor while using inheritance.
virtual constructor: To construct an object, a constructor needs the exact type of the object it is to create.Thats why constructor can't be virtual.
Constructor can only be inline.

Major new features in c++11:

auto keyword
default specifier->By default, C++ will provide a default constructor, copy constructor, copy assignment operator (operator=) and a destructor. If you provide alternate versions of any of these functions for your class, C++ will not provide a default version.
In c++11 you can do that using default specifier.
delegating constructors
delete specifier
override & final specifier
range based loops(for each loops)
nullptr
int *p = 1; // illegal, can't assign an int to an int* variable
int *q = 0; // legal, 0 has a special meaning as a null pointer
C++11 defines a new reserved identifier called nullptr 
enum class:
C++11 defines a new concept, the enum class, which makes enums both strongly typed and strongly scoped.



lambda expressions
move constructor & assignment
noexcept specifier

intializer list
uniform initialization

New in C++14
std::make_unique


Difference bw set and vector:
Set are ordered, vector are not.
Insertion time in set is log(number of elements),while in vector it is (number of elements).
t is faster to search an item against a set than a vector (O(log(n)) vs O(n)). To search an item against a vector, you need to iterate all items in the vector, but the set use red-black tree to optimize the search, only a few item will be looked to find a match.

Lists are sequence containers that allow non-contiguous memory allocation. As compared to vector, list has slow traversal.
This is doubly linked list.
singly linked list is implemented using forward_list.

char 				1 byte  -> -128 to 127 or 0 to 255
int 				4 bytes -> -2,147,483,648 to 2,147,483,647	
uint 				4 bytes -> 0 to 4,294,967,295
long int 			4 bytes -> -2,147,483,648 to 2,147,483,647
unsigned long int   4 bytes -> 0 to 4,294,967,295					
float 				4 bytes	-> 1.2E-38 to 3.4E+38					6 decimal place  precision
double  			8 bytes -> 2.3E-308 to 1.7E+308					15 decimal place  precision
long double 		10bytes -> 3.4E-4932 to 1.1E+4932				19 decimal place  precision

this pointer:
Say simple is an object,
simple.getID(2); --> what happen with call?
1.It becomes getId(&simple , 2)
2.Function declaration becomes getId(Simple const *this, int id)
3.Definition inside the call would be this->m_id = id;

Different IPC methods:
semaphores
message queues
shared memory
FIFO's(named pipes)

shared memory

int shm_open(const char *name, int oflag, mode_t mode); -->opens a POSIX shared memory object.It returns a file descriptor pointing to the 
shared memory object.

ftruncate(shm_fd, 4096); --> set the size of the object to 4096
 
ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0); --> Finally, the mmap() function establishes a memory-mapped file containing the 
shared-memory object. It also returns a pointer to the memory-mapped file that is used for accessing the shared-memory object.
 
MAP_SHARED --> specifies that changes to the shared memory object will be visible to all processes sharing the object.

shm_unlink(name);  --> shm_unlink() function removes the shared-memory segment after the consumer has accessed it.

Memory leak description: Memory is allocated but not released causing an application to consume memory reducing the available memory for 
other applications and eventually causing the system to page virtual memory to the hard drive slowing the application or crashing the 
application when than the computer memory resource limits are reached. The system may stop working as these limits are approached.

Memory Corruption:

Heap memory errors:
Attempting to free memory already freed.
Freeing memory that was not allocated.
Attempting to read/write memory already freed.
Attempting to read/write to memory which was never allocated.
Memory allocation error.
Reading/writing to memory out of the bounds of a dynamically allocated array
stack (local variables) memory errors:
Reading/writing to memory out of the bounds of a static array. (array index overflow - index too large/underflow - negative index)
Function pointer corruption: Invalid passing of function pointer and thus a bad call to a function.
