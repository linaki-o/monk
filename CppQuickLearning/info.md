-pedantic-errors 
-Wall -Weffc++ -Wextra -Wsign-conversion

-Werror




# Reference "&"
```cpp
int & r = n;
```
Now, r is considered an alias for n.

**When the initialization of a reference variable is completed, the variable cannot refer to another variable**

Simple example:
```cpp
void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
}
int n1, n2;
swap(n1, n2);
```
## Constant references
```cpp
const int &r = n;
```
You cannot modify the content of a constant reference
```cpp
int i;
cont int j;
int &n = i;
const int &r = n; // Ok
int &k = r; // Wrong
int &l = j; // Wrong
```

# Const

```cpp
int n, m;
const int *p = &n;
*p = 5; // Wrong
n = 4; // Ok
p = &m; // Ok
```
-----
```cpp
const int *p1;
int *p2;
p1 = p2; // Ok
p2 = p1; // Wrong
p2 = (int *)p1; // Ok
```

# "new" and "delete"
## new 
```cpp
p = new T;
/*
T: data type
p: point of T
*/
```
```cpp
p = new T[N];
```

## delete
```cpp
delete p;
/*
p must point to dynamically allocated memory and you can delete the same memory twice
*/
```
```cpp
delete []p;
```



# Function
## inline function
when you call a function, you need to do some preparations like pushing local variables into stack, jumping to the function code address... And when function finish, you need to pop the data out of the stack, ret...

This is a bit of a waste of time when you have a small amount of function code.

So inline function is just insert function code into the caller. As a result, you save a lot of time. But this may make your code bloated.
```cpp
inline int function(int p){
    // do something
    return p;
}
```
## function overloading

functions have the same name, but the different parameters

```cpp
int Max(double f1, double f2){}
int Max(int n1, int n2) {}
int Max(int n1, int n2, int n3) {}
```

## default parameters

```cpp
void func(int x1, int x2 = 2, int x3 = 3) {}
//==========
func(10); // Ok
func(10, 8); // Ok
func(10, ,8); // Wrong
```

default parameters can improve your program's expandability

# Class and Object
```cpp
class CRectangle {
    public:
        int w, h;
        int Area() {
            return w * h;
        }
        int Perimeter() {
            return 2 * (w + h);
        }
        void Init(int w_, int h_) {
            w = w_;
            h = h_;
        }
};
```
the size of a object is the sum of its member variables. Where is the member functions? The functions is belonged to class, and is sharing by all object.

-----
you can write the defination of memeber functions elsewhere
```cpp
class CRectangle {
    public:
        int w, h;
        int Area();
        int Perimeter();
        void Init(int w_, int h_);
};
int CRectangle::Area() {
    return w * h;    
}
int CRectangle::Perimeter() {
    return 2 * (w + h);
}
void CRectangle::Init(int w_, int h_) {
    w = w_;
    h = h_;
}
```
## access scope

"private" is the default scope of class members

In member functions, you can access any member datas and memeber functions of this object, and the member of other objects in the same class

# Constructor

> Standard
- don't have return value
- same name as class
- only initialize the member datas, not allocate memory to object
- there is a default constructor do nothing, as if you don't define one. 

```cpp
class CSample {
    int x;
    public:
        CSample() {
            cout << "C1" << endl;
        }
        CSample(int n) {
            x = n;
            cout << "C2" << endl;
        }
        CSample(int i, int j) {
            cout << "C3" << endl;
        }
};
int main() {
    CSample array1[2]; // print: "C1 C1"
    CSample array2[2] = {4, 5}; // print: "C2 C2"
    CSample array3[2] = {3}; // print: "C2 C1"
    CSample array4[2] = {CSample(1, 2), CSample(1, 2)};
    CSample *array5[2] = {new CSample(1, 2), new CSample(1, 2)};
}
```

# Copy constructor
1. look like **X::X(X &)** or **X::X(const X &)**
2. class always has one copy constructor
3. Features: copy a object to another which have the same class of the former
4. The three situations where it works
    - assign
        ```cpp
        Object o2(o1);
        Object o2 = o1;
        ```
    - calling function
        ```cpp
        class A {
            public 
                A(){};
                A(A &a) {
                    cout << "Copy constructor called" << endl; 
                }
        };
        void func(A a1) {}
        int main() {
            A a2;
            func(a2); // calling copy constructor
            return 0;
        }
        ```
    - function return
        ```cpp
        class A {
            public:
                int v;
                A(int n) {v = n;}
                A(const A &a) {
                    v = a.v;
                    cout << "Copy constructor called" << endl; 
                }
        };
        A func() {
            A b(4);
            return b;
        }
        int main() {
            cout << func().v << endl; // calling copy constructor
            return 0;
        }
        ```
5. problem
    ```cpp
    void func(Object obj) { // there create a parameter by copy constructor. this may cost a lot of time. instead, you can use "Object &obj"
        cout << "func calling" << endl;
    }

# Type conversion constructor
automatic type conversion
```cpp
class Complex {
    public:
        double real, imag;
        Complex(int i){ // type conversion constructor
            cout << "IntConstructor called" << endl;
            real = i;
            imag = 0;
        }
        Complex(double r, double i) {
            real = r;
            imag = i;
        }
};
int main() {
    Complex c1(7, 8);
    c1 = 9; // 9 is converted to Complex object by type conversion, and then assign to c1
    return 0;
}
```

# destructors
```cpp
~Object::Object(){}
// don't have parameters and return values
```
destuctors don't release memory, they just do something before the memory be released.

confusion:
```cpp
class A {
    public:
        int x;
        A(int x_):x(x_) {
            cout << x << "constructor called" << endl;
        }
        A(const A &a) {
            x = 2 + a.x;
            cout << "copy called" << endl;
        }
        ~A() {
            cout << x << "destructor called" << endl;
        }
};
A f() { 
    A b(10);
    return b;
}
int main() {
    A a(1);
    a = f();
    return 0;
}
```