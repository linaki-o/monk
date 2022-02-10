# Representing and Manipulating Information
## Information Storage
<img src="img/versions.png">

> Hexadecimal Notation

In C, numeric constants starting with 0x or 0X are interpreted as being in hexadecimal. The characters ‘A’ through ‘F’ may be written in either upper- or lowercase

<img src="img/hex.png">

**For convenience, you only need to remember "A", "C", "F"'s binary value, then you can deduce others by them**

---
tips:

<img src="img/tips.png">

> Data Sizes

**Every computer has a word size, indicating the nominal size of pointer data**

- That is, for a machine with a w-bit word size, the virtual addresses can range from 0 to 2^w − 1, giving the program access to at most 2^w bytes

directive:
```
linux> gcc -m32 prog.c
linux> gcc -m64 prog.c
```

data size:
<img src="img/size.png">


**ISO C99** introduced a class of data types where the data sizes are fixed regardless of compiler and machine settings. Among these are data types **int32_t** and **int64_t**, having exactly 4 and 8 bytes, respectively


The C language allows a variety of ways to order the keywords and to include or omit optional keywords

> Addressing and Byte Ordering

In virtually all machines, a multi-byte object is stored as a contiguous sequence of bytes, with the address of the object given by the smallest address of the bytes used

Some machines choose to store the object in memory ordered **from least significant byte to most**, while other machines store them **from most to least**
<img src="img/bOl.png">

`Most Intel-compatible machines operate exclusively in little-endian mode. On the other hand, most machines from IBM and Oracle (arising from their acquisition of Sun Microsystems in 2010) operate in big-endian mode`

**byte ordering would becomes an issue:**
- when binary data are communicated over a network between different machines.
    ```
    A common problem is for data produced by a little-endian machine to be sent to a big-endian machine, or vice versa, leading to the bytes within the words being in reverse order for the receiving program
    ```
- when looking at the byte sequences representing integer data
    ```
    4004d3: 01 05 43 0b 20 00   |   add %eax,0x200b4 (%rip)
    ```
- when programs are written that circumvent the normal type system.
    ```
    when programs are written that circumvent the normal type system.
    ```
> Representing Strings

`The base encoding, known as the “Universal Character Set” of Unicode, uses a 32-bit representation of characters`

`In particular, the UTF-8 representation encodes each character as a sequence of bytes, such that the standard ASCII characters use the same single-byte encodings as they have in ASCII, implying that all ASCII byte sequences have the same meaning in UTF-8 as they do in ASCII.`
> Introduction to Boolean Algebra

One useful application of bit vectors is to **represent finite sets** like
```
bit vector a = [01101001]encodes the set A = {0, 3, 5, 6}

With this way of encoding sets, Boolean operations | and & correspond to set union and intersection, respectively, and ~ corresponds to set complement
```
and the **bit-vector mask** is another useful way


`little practice:`
```c
/* bis and bic generate a result z consisting of the bits of x modified according to the bits of m

With bis, the modification involves setting z to 1 at each bit position where m is 1. With bic, the modification involves setting
z to 0 at each bit position where m is 1
*/
int bis(int x,int m) {
        return x | m;
}
int bic(int x,int m) {
        return x &~ m;
}
int bool_xor(int x, int y) {
        int result = bis(bic(x, y), bic(x,y));
        return result;
}
int main(void) {
        int a = bool_xor(3,3);
        int b = bool_xor(3,0);
        printf("a = %d, b = %d\n", a, b);
        return 0;
}
```
> Logical Operations in C

The logical operations treat any nonzero argument as representing true and argument 0 as representing false. They return either 1 or 0, indicating a result of either true or false,
> Shift Operations in C
- x << k(**filling the right end with k zeros**)
- two forms of right shift
    - Logical(**fills the left end with k zeros**)
    - Arithmetic(**fills the left end with k repetitions of the
most significant bit**)

    The C standards do not precisely define which type of right shift should be used with signed numbers.

    In practice, however, almost all compiler/machine combinations use **arithmetic** right shifts for **signed data**, and many programmers assume this to be the case. For **unsigned** data, on the other hand, right shifts must be **logical**.


**Shifting by k, for large values of k:**
```c
For a data type consisting of w bits, what should be the effect of shifting by some value k ≥ w?

On many machines, the shift instructions consider only the lower log2 w bits of the shift amount when shifting a w-bit value, and so the shift amount is computed as k mod w.

//This behavior is not guaranteed for C programs, however, and so shift amounts should be kept less than the word size
```

**1<<2 + 3<<4 ==  1 << (2+3) << 4** since addition (and subtraction) have higher precedence than shifts


## Integer Representations

> Integral Data Types
- Typical ranges for C integral data types for 32-bit programs.
    <img src="img/32b.png">
- Typical ranges for C integral data types for 64-bit programs.
    <img src="img/64b.png">
- Guaranteed ranges for C integral data types.
    <img src="img/c.png">
<font color="red">p99</font>