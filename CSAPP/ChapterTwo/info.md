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
