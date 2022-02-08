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