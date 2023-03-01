linking : 把编译器编译好的.o文件merge成一个可执行文件a.out

### 概述
why linkers?
- modularity ：方便build标准库
- effeciency ：更改一个小module m，只重新编译m，再执行linking

what do linkers do?
- step1: symbol resolution :对**global** variables/functions进行符号解析,linkers只能看到symbols，不能看到variables/functions
- step2: relocation ：merge modules

three kind of object files (modules)
- .o
- a.out
- .so

executable and linkable formate (ELF)


### step1: symbol resolution
Linker Symbols：都是对于程序中的全局变量而言的，程序中的local变量存在stack里，Linker看不见
- external symbols：对于具体的module m而言，定义在m之外的变量/函数，使用时用extern标注
- global symbols：对于具体的variables/functions，没有static修饰，expose to other modules
- local symbols：对于具体的variables/functions，有static修饰，只在本module内可见、
这些symbols都存在ELF的.data里

Linker处理重复的symbols定义-三个规则
- 将symbols分为strong和weak
  - strong：procedures and initialized globals
  - weak：uninitialized globals
- rule 1：多个strong symbols are not allowed
- rule 2：给定一个strong和多个weak，有strong选strong
- rule 3: 无strong任选

使用global变量的一些建议：
1. 尽量避免定义全局变量
2. 如果要定义全局变量，尽量设置成static，这样它的作用域就只在本module内，可以避免重名
3. 如果定义了全局变量，尽量初始化它，strong以后就能发现是否有多个重名的全局变量
4. 如果引用了外部变量，则通过extern告诉编译器

### step2:relocation