```shell
gcc -Og -S sum.c 
```
- -Og means using g optimization
- -S means stop at 1st step
- got sum.s after execute

```shell
gcc -Og -c sum.c 
```
- got sum.o after execute

```shell
gcc -Og -o sum.c 
```
- got sum after execute生成可执行文件

```shell
objdump -d a.out
```
- got disassembly code of a.out