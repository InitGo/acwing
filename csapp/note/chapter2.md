# CHAPTER 2 Represent ans Mainpulating Information

## 2.1 Informa Storage

computers use blocks of 8 bits
every byte of memory is identified by a unique number, know as its address

### 2.1.1 Hexadecimal Notation
- remember
A 1010 / C 1100 / F 1111

- binary 2 hex
  - `x = 2^n` : `2^1`就是1后面有1个0， `2^n`就是1后面有n个0
  - `n = i + 4*j` ：把n个0分成4个一组
    - `i = 0 --> 1` : 正好分完，hex就是1后面j个0
    - `i = 1 --> 2` : 多1个0， hex就是10后面j个0
    - `i = 2 --> 4` : 多2个0， hex就是100后面j个0
    - `i = 3 --> 8` : 多3个0， hex就是1000后面j个0
  - ex : `x = 2048 = 2^11`, `n = 11 = 3 + 4*2`,`x = 0x800`
- decimal 2 hex : 短除法

### 2.1.2 Data Sizes
- the word size determine the max size of the virtual address space
  - 32bit - 4GB
  - 64bit - 16EB
- distinction : 32 / 64 bit programs
  - right : the way it is compiled
    - `gcc -m32 prog.c`
    - `gcc -m64 prog.c`
  - error : the type of machine to run 
  
### 2.1.3 Addressing and Byte Ordering
- little-endian mode：数字的低位在小地址处 
- big-endian mode
- show_bytes function

### 2.1.4 Representing Strings
### 2.1.5 Representing Code

### 2.1.6 Boolean Algebra
| boolean | logical |
|---|---| 
|  ~  |  $\neg$  | 
|  &  |  $\bigwedge$  |
|  \|  |  $\bigvee$  |
|  ^  |  $\bigoplus$  |
