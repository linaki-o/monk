# destructors
```cpp
Object::~Object(){}
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

# This
```cpp
class Complex {
    public:
        double real, imag;
        Complex(double real, double imag) {
            this->real = real;
            this->imag = imag;
        }
};
```
confusion:
```cpp
class A {
    int t;
    public:
        void Hello() {
            cout << "hello" << endl;
        }
};
int main() {
    A *p = NULL;
    p->Hello();
}
//=========complie to c
struct A {
    int t;
};
void Hello(A *this) {
    cout << "hello" << endl;
}
int main() {
    A *p = NULL;
    Hello(p);
}
```
# Static

```cpp
class CRectangle {
    private:
        int w, h;
        static int nTotalArea;
        static int nTotalNumber;
    public:
        CRectangle(int w_, int h_);
        ~CRectangle();
        CRectangle(CRectangle &r);
        static void PrintToal();
};
CRectangle::CRectangle(int w_, int h_) {
    w = w_;
    h = h_;
    nTotalNumber++;
    nTotalArea += w * h;
}
CRectangle::~CRectangle() {
    nTotalNumber--;
    nTotalArea -= w * h;
}
CRectangle::CRectangle(CRectangle &r) {
    w = r.w;
    h = r.h;
    nTotalNumber++;
    nTotalArea += w * h;
}
void CRectangle::PrintTotal() {
    cout << nTotalNumber << " " << nTotalArea << endl;
}

int CRectangle::nTotalArea = 0;
int CRectangle::nTotalNumber= 0;
```
static member datas belong to class, so "sizeof" doesn't count them on.

access:
```cpp
CRectangle::PrintTotal();
CRectangle r; r.PrintTotal();
CRectangle *p = &r; p->PrintTotal();
CRectangle &ref = r; int n = ref.nTotalNumber; 
```
# Enclosing Class

a class whose member data is other class object;
```cpp 
class CTyre {
    private:
        int radius;
        int width;
    public:
        CTyre(int r, int w):radius(r), width(w) { }
};
class CEngine {

};
class CCar { // enclosing class
    private:
        int price;
        CTyre tyre;
        CEngine engine;
    public:
        CCar(int p, int tr, int tw);
};
CCar::CCar(int p, int tr, int w):price(p), tyre(tr, w){ }
int main(void) {
    CCar car; // wrong, complier doesn't know how to init car.tyre.
    return 0;
}
```

constructor execution order:
1. member object's constructor(The order of member objects is the same as the order defined in the enclosing class)
2. enclosing class object's constructor

destructor execution order:
1. enclosing class object's 
2. member object's

# Const Plus 
## const object 
```cpp
const object obj;
```
## const member function
you can't modify member datas(except static member datas) and call other non-const member function(except static) within const member function
```cpp
class Sample {
    public:
        int value;
        void GetValue() const;
        void GetValue(); // Ok, this is overload 
        void func() { }
};
void Sample::GetValue() {}
void Sample::GetValue() const {
    value = 0; // wrong
    func(); // wrong
}
```

# Friends

## friend function
```cpp
class CCar;
class CDriver {
    public:
        void ModifyCar(CCar *pCar);
};
class CCar {
    private:
        int price;
    friend int MostExpensiveCar(CCar cars[], int total); // Not member function of this class, but the function can use any member of this class.
    friend void CDriver::ModifyCar(CCar *pCar);
};
void CDriver::ModifyCar(CCar *pCar) {
    pCar->price += 1000;
}
int MostExpensiveCar(CCar cars[], int total) {
    int tmpMax = -1;
    for (int i = 0; i < total; i++) {
        if (cars[i].price > tmpMax) {
            tmpMax = cars[i].price;
        }
    }
    return tmpMax;
}
```
## friend class
```cpp
class CCar {
    private:
        int price;
    friend class CDriver; //  
};
class CDriver {
    CCar myCar;
    public:    
        void ModifyCar() {
            myCar.price += 1000;
        }
};
```
friend class can't be passed and extended

# Operator Overload 
```cpp
class Complex {
    public:
    double real, imag;
    Complex(double r = 0.0, double i = 0.0):real(r), imag(i) {}
    Complex operator -(const Complex &c);
    Complex operator +(double r); // c + 5
    friend Complex operator +(double r, const Complex &c);
};
Complex operator +(const Complex &a, const Complex &b) {
    return Complex(a.real+b.real, a.imag+b.imag);
}
Complex Complex::operator -(const Complex &c) {
    return Complex(real - c.real, imag - c.imag);
}
Complex operator +(double r, const Complex &c) {
    return Complex(c.real + r, c.imag);
}
Complex Complex::operator +(double r) {
    return Complex(this.real + r, this.imag);
}
```
# Assignment operator overload

**=** can only be overloaded to member function
```cpp
class String {
    private:
        char *str;
    public:
        String():str(new char[1]) {str[0] = 0;}
        const char *c_str() {return str;}
        String & operator =(const char *s); //1
        String(String &s) {
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        ~String() {delete[] str;}
};
String &String::operator =(const char *s) {
    if (this == s) 
        return *this;    
    delete[] str;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    return *this;
}
int main() {
    String s;
    s = "Good Luck"; // Ok
    String s2 = "hello"; // Wrong, this is init not assignment
    return 0;
}
```
confusion:
```cpp
String S1, S2;
S1 = "this";
S2 = "that";
S1 = S2; // terrible operation if without overloading. 3 reasons.
s = s; // will be wrong without overloading
a = b = c;
(a = b) = c;

# Combination
```cpp
class CArray {
    int *ptr;
    int size;
    int length;
    public:
        CArray(int s = 0);
        CArray(CArray &a);
        ~CArray();
        int & operator [](int i);
        CArray & operator =(const CArray &a);
        void push_back(int i);
        int length();
};
CArray::CArray(int s):size(s) {
    if (!s) {
        ptr = NULL;
        length = 0;
    } else {
        ptr = new int[s];
        length = 0;
    }
}
CArray::CArray(CArray &a) {
    if (!a.size) {
        ptr = NULL;
        size = 0;
        lenght = 0;
        return ;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, a.size * sizeof(int));
    size = a.size;
    length = a.length;
}
CArray::~CArray() {
    if (ptr) {
        delete[] ptr;
    }
}
int &CArray::operator [](int i) {
    if (i >= 0 && i < length && ptr) {
        return ptr[i];
    } else {
        cout << "ERROR" << endl;
        return NULL;
    }
}
CArray &CArray::operator =(CArray &a) {
    if (ptr == a.ptr) 
        return *this;
    if (!a.size) {
        if (ptr)
            delete[] ptr;    
        ptr = NULL;
        size = 0;
        length = 0;
        return *this;
    }
    if (size < a.size) {
        if (ptr)
            delete[] ptr;
        ptr = new int[a.size];
        memcpy(ptr, a.ptr, a.size * sizeof(int));
        size = a.size;
        length = a.length;
        return *this;
    }
}
void CArray::push_back(int i) {
    if (i >= 0 && ptr) {
        if (length++ > size) {
            int nsize = size + size / 2;
            int *nptr = new int(nsize);
            memcpy(nptr, ptr, size);
            delete[] ptr;
            ptr = nptr;
            size = nsize;
        } else {
            ptr[length] = i;
        }
    } else {
        ptr = new int[1];
        ptr[size++] = i;
    }
}

int CArray::length() {
    return length;
}
```
# Input and Output operator overloading
```cpp
class Complex {
    double real, imag;
    public:
        Complex(double r = 0, double i = 0):real(r), imag(i){}
        friend ostream & operator <<(ostream &os, const Complex &c);
        friend istream & operator >>(istream &is, Complex &c);
};
ostream & operator <<(ostream &os, const Complex &c) {
    os << c.real << "+" << c.imag << "i";
    return os;
}
istream & operator >>(istream &is, Complex &c) {
    string s;
    is >> s;
    int pos = s.find("+", 0);
    string sTmp = s.substr(0, pos);
    c.real = atof(sTmp.c_str());
    sTmp = s.substr(pos+1, s.length()-pos-2);
    c.imag = atof(sTmp.c_str());
    return is;
}
```

# Type conversion operator overloading
```cpp
class Complex {
    double real, imag;
    public:
        Complex(double r = 0, double i = 0):real(r), imag(i) {}
        operator double() {
            return real;
        }
};
int main() {
    Complex c(1.2, 3.4);
    cout << (double)c << endl; // 1.2
    double n = 2 + c;
    cout << n; // 3.2
}
```
# Overloading of the self-increment operator self-subtraction operator
```cpp
class CDemo {
    int n;
    public:
        CDemo(int i = 0):n(i){}
        CDemo & operator ++();//prefix
        CDemo operator ++(int);// suffix, suffix need an extra parameter, but it doesn't do anything
        operator int() {
            return n;
        }
        friend CDemo & operator --(CDemo &);
        friend CDemo operator -- (CDemo &, int);
};
CDemo & CDemo::operator ++ () {
    ++n;
    return *this; // (++i) = 3; is ok
}
CDemo CDemo::operator ++ (int i) {
    CDemo tmp(*this);
    n++;
    return tmp; // (i++) = 3; is wrong
}
CDemo & operator -- (CDemo &d) {
    d.n--;
    return d;
}
CDemo operator -- (CDemo &d, int i) {
    CDemo tmp(d);
    d.n--;
    return tmp;
}
```

note:

1. No new operators are allowed to be defined
2. Operator overloading cannot change operator precedence
3. ".", ".*", "::", "?:", "sizeof" cannot be overloaded
4. "()", "[]", "->" and "=" must be overloaded as member function.

# Extend
```cpp
class CStudent {
    string sName;
    int nAge;
    public:
        bool isExcellent() {}
        void setName(const string &name) {
            sName = name;
        }
};
class CUndergraduateStudent:public CStudent {
    private:
        int nDepartment;
    public:
        bool isExcellent() {...} // override
}
```

# Inherited relationships and Compound relationship
```cpp
// ========bad
class CDog;
class CMaster {
    CDog dogs[10];
};
class CDog {
    CMaster m;
}; // Loop Definition
// ========bad
class CDog;
class CMaster {
    CDog *dogs[10];
};
class CDog {
    CMaster m;
};
// ========bad
class CMaster;
class CDog {
    CMaster *pm;
};
class CMaster {
    CDog dogs[10];
};
// ========good
class CMaster;
class CDog {
    CMaster *pm;
};
class CMaster {
    CDog *dogs[10];
};
``` 

# Access base class 
```cpp
class base {
    int j;
    public:
        int i;
        void func();    
};
class derived:public base {
    public:
        void access();
        void func();    
}
void derived::access() {
    j = 5; // subclass can't access the private data of base class
    func(); // subclass
    base::func(); // base class
}
```

# constructor of subclass
```cpp
class Bug { 
    int nLegs;
    int nColor;
    public:
        int nType;
        Bug(int legs, int color):nLegs(legs), nColor(color){}
        void printBug() {}
};
class Skill {
    public:
        Skill(int n) {}
}
class FlyBug:public Bug {
    int nWings;
    Skill sk1, sk2;
    public:
        FlyBug(int legs, int color, int wings);
};
FlyBug::FlyBug(int legs, int color, int wings):Bug(legs, color), sk1(5), sk2(color) {
    nWings = wings;
} // If the base class constructor is not explicitly called, the base class's parameterless constructor is used by default

/* 
constructor call order:
1. Bug
2. Skill
3. FlyBug
*/
```
# Public extend rules
```cpp
class base {};
class derived:public base {};
base b;
derived d;
// operations below is allowed
b = d;
base &br = d;
base *pb = &d;
```
# Virtual function and Polymorphic

Polymorphic representation:

1. 
    ```cpp
    class CBase {
        public:
            virtual void SomeVirtualFunction() {
                cout << "base class" << endl;
            }    
    };
    class CDerived:public CBase {
        public:
            virtual void SomeVirtualFunction() {
                cout << "subclass" << endl;
            }
    };
    int main() {
        CDerived ODerived;
        CBase *p = &ODerived;
        p->SomeVirtualFunction(); // print "base class" or "subclass" depends on which class the pointer points to. it has been decided during compiling.
    } 
    ```

2.
    ```cpp
    class CBase {
        public:
            virtual void SomeVirtualFunction() {
                cout << "base class" << endl;
            }    
    };
    class CDerived:public CBase {
        public:
            virtual void SomeVirtualFunction() {
                cout << "subclass" << endl;
            }
    };
    int main() {
        CDerived ODerived;
        CBase &r = ODerived;
        r.SomeVirtualFunction(); // Same as the example above 
    }
    ```
**Polymorphic can improve program expandability**

# Polymorphic Plus
```cpp
class Base {
    public:
        void fun1() {fun2();}
        virtual void fun2() {
            cout << "Base" << endl;
        }
};
class Derived:public Base {
    public:
        virtual void fun2() {
            cout << "Derived" << endl;
        }
};
int main() {
    Derived d;
    Base *pBase = &d;
    pBase->fun1(); // print "Derived"
    return 0;
}
```

**Calling virtual functions in constructors and destructors is not polymorphism**
```cpp
class myClass {
    public:
        virtual void hello() {
            cout << "hello from myclass" << endl;
        }
        virtual void bye() {
            cout << "bye from myclass" << endl;
        }
};
class son:public myClass {
    public:
        void hello() {
            cout << "hello from son" << endl;
        }    
        son() {hello();}
        ~son() {bye();}
};
class grandson:public son {
    public:
        virtual void hello() {
            cout << "hello from grandson" << endl;
        }
        virtual void bye() {
            cout << "bye from grandson" << endl;
        }
        grandson() {
            cout << "grandson" << endl;
        }
        ~grandson() {
            cout << "destructing grandson" << endl;
        }
};
int main() {
    grandson gson;
    son *pson;
    pson = &gson;
    pson->hello();
    return 0;
}

/*
print:
hello from son
grandson
hello from grandson
destructing grandson
bye from myclass
*/
```

# Virtual destructor

deleting  base class pointer will only call the base class destructor without virtual destructor
```cpp
class son {
    public:
        virtual ~son() {
            cout << "bye from son" << endl;
        }    
};
class grandson:public son {
    public:
        ~grandson() {
            cout << "bye from grandson" << endl;
        }    
};
int main() {
    son *pson;
    pson = new grandson();
    delete pson;
    return 0;
}

/*
output:
bye from grandson
bye from son
*/
```
when base class's member function is virtual, automatically, the subclass's member function is virtual too.

**note: you can't make constructor virtual**

# Pure virtual functions  
```cpp
virtual void func() = 0;
```
# Abstract class
A class that contains pure virtual functions is called an abstract class

```cpp
// given A is virtual class
A a; // wrong
A *pa; // ok
pa = new A; // wrong
```

you can call pure virtual functions in member functions of abstract class, except constructor and destructor

if a subclass extended from abstract class, it is also abstract unless all pure virtual functions is implemented.

# IO
<img src="img/io.png">

several objects:
- cin
    ```cpp
    freopen("text.txt", "r", stdin);
    ```
- cout
    ```cpp
    freopen("text.txt", "w", stdout);
    ```
- cerr
- clog
----
Determine if the input stream is finished:
```cpp
while(cin>>i) {
    // ...
}
```

istream:
- istream & getline(char *buf, int bufSize);
- istream & getline(char *buf, int bufSize, char delim);

    `two of these functions will add '\0' in the end`
- bool eof(); // determine whether the input stream is finished
- int peek(); // return the next character, but don't delete it from the input stream
- istream & putback(char c);
- istream & ignore(int nCount = 1, int delim = EOF); // delete nCount characters from input stream. finish when encounter EOF.


# Output format
```cpp
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
        int n = 141;
        cout << hex << n << " " << dec << n << " " << oct << n << endl;

        double x = 1234567.89, y = 12.34567;
        cout << setprecision(5) << x << " " << y << " " << endl;

        cout << fixed << setprecision(5) << x << " " << y << endl;

        cout << scientific << setprecision(5) << x << " " << y << endl;

        cout << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl;

        cout << noshowpos << setw(12) << left << 12.1 << endl;

        cout << setw(12) << right << 12.1 << endl;

        cout << setw(12) << internal << -12.1 << endl;

        cout << 12.1 << endl;
        return 0;
}
/* 
output:
8d 141 215
1.2346e+06 12.346 
1234567.89000 12.34567
1.23457e+06 1.23457e+01
***+12.10000
12.10000****
****12.10000
-***12.10000
12.10000
*/
```
 
Customization:
```cpp
ostream & tab(ostream &output) {
    return output << '\t';
}
cout << "aa" << tab << "bb" << endl;
/*
output:
aa  bb
*/

/* 
function prototype:
ostream & operator <<(ostream & (*p) (ostream &));
and *this as parameter in iostream
*/
```

# File
## creat a file
```cpp
#include <fstream>
ofstream outFile("clients.dat", ios::out|ios::binary);
ofstream outfile2;
outfile2.open("test.out", ios::out|ios::binary);
if (!outfile2) {
    cout << "File open error" << endl;
}
```
## file read and write pointers
write pointer:
```cpp
ofstream fout("a1.out", ios::app);
long location = fout.tellp(); // obtain the position of pointer
location = 10;
fout.seekp(location); // move the pointer for next 10 bytes 
fout.seekp(location, ios::beg); // move from the file head
fout.seekp(location, ios::cur); // move from the current place
fout.seekp(location, ios::end);
```

read pointer:
```cpp
ifstream fin("a1.in", ios::ate); // open a file whose point in the end
long location = fin.tellg(); // obtain the gosition of gointer
location = 10L;
fin.seekg(location); // move the gointer for next 10 bytes 
fin.seekg(location, ios::beg); // move from the file head
fin.seekg(location, ios::cur); // move from the current place
fin.seekg(location, ios::end);
```


# Binary files
## write and read
```cpp
istream & read(char *s, long n);
istream & write(const char *s, long n);
```
## the difference between a binary file and a text file
Line break symbols:
- unix, linux: '\n'
- windows: '\r\n'
- mac os: '\r'

In Unix/Linux, It makes no difference if you use ios::binary.

but in windows without ios::binary, when reading, all '\r\n' will be processed into a '\n', on the other side, when writing, a single '\n' will be processed into a '\r\n'.

# Template
## function
define:
```cpp
template <class T>
void Swap(T &x, T &y) {
    T tmp = x;
    x = y;
    y = tmp;
}
// ===============
T Inc(T n) {
    return 1 + n;
}
int main() {
    cout << Inc<double>(4) / 2; // print 2.5
    return 0;
}
```
overload:
```cpp
template<class T1, class T2>
void print(T1 arg1, T2 arg2) {
    // ...
}
template<class T>
void print(T1 arg1, T2 arg2) {
    // ...
}
template<class T1, class T2>
void print(T1 arg1, T1 arg2) {
    // ...
}
```
Function templates and function call order:
1. Common functions with matching parameters
2. Template functions with exactly matching parameters
3. Common functions that can match after automatic type conversion of real parameters

```cpp
#include <iostream>
using namespace std;
template <class T>
T Max(T a, T b) {
        cout << "TemplateMax" << endl;
        return 0;
}
template <class T1, class T2>
T1 Max(T1 a, T2 b) {
        cout << "TemplateMax2" << endl;
        return 0;
}
double Max(double a, double b) {
        cout << "MyMax" << endl;
        return 0;
}
int main() {
        int i = 4, j = 5;
        Max(1.2, 3.4);
        Max(i, j);
        Max(1.2, 3);
        return 0;
}

/*
output:
MyMax
TemplateMax
TemplateMax2
*/
```

No automatic type conversion when matching template functions
```cpp
myFunction(5, 8.4); // error
```

## class
```cpp
template<class T1, class T2>
class Pair {
    public:
        T1 key;
        T2 value;
        Pair (T1 k, T2 v):key(k), value(v) {}
        bool operator <(const Pair<T1, T2> &p) const;
};
template<class T1, class T2>
bool Pair<T1, T2>::operator <(const Pair<T1, T2> &p) {
    return key < p.key;
}
int main() {
    Pair<string, int> student("Tom", 19);
    cout << student.key << " " << student.value;
    return 0;
}
```
note:
```cpp
Pair<string, int> *p;
Pair<string, double> a;
p = &a; // wrong
```

function template be one of class template's member:
```cpp
#include <iostream>
using namespace std;
template <class T>
class A {
        public:
                template <class T2>
                void Func(T2 t) {
                        cout << t;
                }
};
int main() {
        A<int> a;
        a.Func('K');
        a.Func("hello");
        return 0;
}
```

Non-type parameters:
```cpp
#include <iostream>
using namespace std;
template <class T, int size>
class CArray {
        T array[size];
        public:
                void Print() {
                        for (int i = 0; i < size; ++i)
                                cout << array[i] << endl;
                }
};
CArray<double 40> a2;
CArray<int 50> a3;
```
## extend
1. 
    ```cpp
    template <class T1, class T2>
    class A {
        T1 v1;
        T2 v2;
    };

    template <class T1, class T2>
    class B:public A<T2, T1> {
        T1 v3;
        T2 v4;
    };
    ```
2. 
    ```cpp
    template <class T1, class T2>
    class A {
        T1 v1;
        T2 v2;
    };

    template <class T>
    class B:public A<int, double> {
        T v;
    };
    ```
3. 
    ```cpp
    class A {
        int v1;
    };
    template <class T>
    class B:public A {
        T v;
    };
    ```
4.
    ```cpp
    template <class T>
    class A {
        T v1;
        int n;
    }; 
    class B:public A<int> {
        double v;
    };
    ```

## friend
## static
```cpp
#include <iostream>
using namespace std;
template <class T>
class A {
        private:
                static int count;
        public:
                A() { count++;}
                ~A() { count--;}
                A(A &) { count++;}
                static void PrintCount() {
                        cout << count << endl;
                }
};
template<> int A<int>::count = 0;
template<> int A<double>::count = 0;
int main() {
        A<int> ia;
        A<double> da;
        ia.PrintCount();
        da.PrintCount();
        return 0;
}
```
# String
**typedef basic_string`<char>` string**
- .length()
- getline(cin, s)
- .assign()
- .at()
- .append()
- .size()
- .substr()
- .find()
- .rfind()
- .find_first_of()
- .find_last_of()
- .find_first_not_of()
- .erase()
- .replace()
- .insert()
- .c_str()
- .data()
- istringstream >> s
- ostringstream << "linaki"

# STL
- Containers: class template
- Iterators: pointer
- Algorithm: function template

- Sequential containers: vector, deque, list
- Associated containers: set, multiset, map, multimap
- Container adapter: stack, queue, priority_queue

**note: you had better overload "==", ">"... when a class is put into container**
## iterators
```cpp
#include <vector>
#include <iostream>
using namespace std;
int main() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        vector<int>::const_iterator i; // define const iterator
        for (i = v.begin(); i != v.end(); ++i)
                cout << *i << ",";
        cout << endl;
        vector<int>::reverse_iterator r;
        for (r = v.rbegin(); r != v.rend(); r++)
                cout << *r << ",";
        cout << endl;
        vector<int>::iterator j;
        for (j = v.begin(); j != v.end(); j++)
                *j = 100;
        for (i = v.begin(); i != v.end(); i++)
                cout << *i << ",";
        return 0;
}

```
Two-way iterators p q:
- ++p, p++
- --p, p--
- *p
- p = q
- p == q, p != q

list, set/multiset, map/multimap 

----
Random access iterator p q:
- p += i
- p -= i
- p + i
- p - i
- p[i]
- p < q, p >= q...

vector, deque

----
don't support iterator:

stack, queue, priority_queue


## vector
```cpp
vector<vector<int> > v(3);
```
## dequeue
## list
- .sort() 
    ```cpp    
    void sort();
    
    template< class Compare >
    void sort( Compare comp );
    /*
    comparison function which returns ???true if the first argument is less than the second.
    */
```cpp
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
class A {
        private:
                int n;
        public:
                A(int n_) {n = n_;}
                friend bool operator <(const A & a1, const A & a2);
                friend ostream & operator <<(ostream & o, const A & a);
};
bool operator <(const A & a1, const A & a2) {
        return a1.n < a2.n;
}
ostream & operator <<(ostream & o, const A & a) {
        o << a.n;
        return o;
}

template<class T>
void PrintList(const list<T> & lst) {
        typename list<T>::const_iterator i;
        for (i = lst.begin(); i != lst.end(); i++)
                cout << *i << ",";
}

```
## function object
If a class overloads the () operator, the class is a function object

**accumulate**:
```cpp
// First version
template<class InputIterator, class T>
T accumulate(InputIterator first, InputIterator last, T value)
{
    for (; first != last; ++first) {
        value = value + *first;
    }
    return value;
}
// Second version
template<class InputIterator, class T, class BinaryOperation>
T accumulate(InputIterator first, InputIterator last, T value, 
             BinaryOperation op)
{
    for (; first != last; ++first) {
        value = op(value, *first); // op can be function, function pointer or function object
    }
    return value;
}

accumulate(v.begin(), v.end(), 0, SumPowers<int>(4));
```

Function objects in <functional>

bigger or smaller in STL:
- **x < y == op(x, y) return true == y > x**
- **(x == y return true) == (x < y return false && y < x return false)**

## set and multiset
**pair:**
```cpp
template<
    class T1,
    class T2

> struct pair;
```
**multiset:**
```cpp
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>

> class multiset;


template< class T >
struct less {
    bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs < rhs;
    }
    ...
}
```
**set:**
```cpp
template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>

> class set;
// Set is an associative container that contains a sorted set of unique objects of type Key
```

## multimap and map
**multimap:**
**map:**
Map is an associative container that contains a sorted list of unique key-value pairs.

map's iterator is pointer of pair class
```cpp

T& operator[]( const Key& key );
	
T& operator[]( Key&& key );
```

## stack and queue and priority_queue
## algorithm
> Non-modifying sequence operations

**Time Complexity: O(n)**

Applicable for Sequential containers, Associated containers

- Minimum/maximum operations
- find()    
    ```cpp
    template< class InputIterator, class T >
    InputIterator find( InputIterator first,    InputIterator last, const T& value );

> Modifying sequence operations

Best not to use on associated containers
- copy
    ```cpp
    template<class InputIterator, class OutputIterator>
    OutputIterator copy(InputIterator first, InputIterator last, OutputIterator d_first){
    while (first != last) {
        *d_first++ = *first++;
    }
    return d_first;
    }
    ```


> value delete

**Time Complexity: O(n)**

Best not to use on associated containers
- remove()
    ```cpp
    // removes elements satisfying specific criteria    
    ```
- unique()
    ```cpp
    // removes consecutive duplicate elements in a range
    ```

> order change

**Time Complexity: O(n)**

Best not to use on associated containers
- reverse
    ```cpp
    // reverses the order elements in a range    
    ```
- next_permutation
    ```cpp
    // generates the next greater lexicographic permutation of a range of elements
    ```
- prev_permutation
    ```cpp
    // generates the next smaller lexicographic permutation of a range of elements
    ```    
- random_shuffle()
    ```cpp
    // randomly re-orders elements in a range
    ```    

> order sort

**Time Complexity: O(nlog(n))**

Best not to use on associated containers and list

Requires random access iterator support
- sort()


> Ordered interval

Best not to use on associated containers and list

Requires random access iterator support

The intervals to be manipulated need to be sorted from smallest to largest
- binary_search()
- lower_bound()
- upper_bound()
- equal_range()


> Numerical

> bitset




- find()
    ```cpp
    template< class InputIterator, class T >
    InputIterator find( InputIterator first, InputIterator last,const T& value );
    /* 
    [first, last)

    Judge by the == operator
    
    iterator to the first element satisfying the condition or last if no such element is found.

- binary_search()
    ```cpp
    #include <iostream>
    #include <algorithm>
    using namespace std;
    class A {
            int v;
            public:
                    A(int n):v(n) {}
                    bool operator <(const A &a2) const {
                            cout << v << "<" << a2.v << "?" << endl;
                            return false;
                    }
                    bool operator ==(const A &a2) const {
                            cout << v << "==" << a2.v << "?" << endl;
                            return v == a2.v;
                    }
    };
    int main() {
            A a[] = {A(1), A(2), A(3), A(4), A(5)};
            cout << binary_search(a, a+4, A(9));
            return 0;
    }
    ```

# C++11
## initialization
```cpp
int arr[3]{1, 2, 3};
vector<int> iv{1, 2, 3};
map<int, string> mp{{1, "a"}, {2, "b"}};
string str{"Hello World"};
int *p = new int[20]{1, 2, 3};
// ==========
class B {
        public:
                int m = 1234;
                int n;
};    
```

## auto
```cpp
map<string, int, greater<string> > mp;
for (auto i = mp.begin(); i != mp.end(); ++i) {
        cout << i->first << "," << i->second
;
}  
// =======
template<class T1, class T2>
auto add(T1 x, T2 y)-> decltype(x + y) {
        return x + y;
}       
```
## decltype
```cpp
int i;
double t;
struct A {
        double x;
}       
const A *a = new A();

decltype(a) x1; // x1 is A *
decltype(i) x2; // x2 is int
decltype(a) x3; // x3 is double
decltype((a->x)) x4 = t; // x4 is double &
```
## shared_ptr
## nullptr
## new for
```cpp
include <iostream>
#include <vector>
using namespace std;
class A {
        public:

                int n;
                A(int i):n(i) {}
};
int main() {
        int ary[] = {1, 2, 3, 4, 5};
        for (int &e : ary)
                e *= 10;
        for (int e : ary)
                cout << e << ",";
        cout << endl;
        vector<A> st(ary, ary+5);
        for (auto &it : st)
                it.n *= 10;
        for (A it : st)
                cout << it.n << ",";
        return 0;
}
```



