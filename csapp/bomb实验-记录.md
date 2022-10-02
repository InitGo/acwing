objdump -d bomb > obj.txt //反汇编bomb 存入obj.txt文件中

gdb bomb 用gdb调试bomb
disase phase_1 //反汇编phase_1函数
disas sum //Disassemble function sum
disas 0x80483b7 //Disassemble function around 0x80483b7
disas 0x80483b7 0x80483c7 //Disassemble code within specified address range

print (char *) 0x402400 //检查该地址处的字符串

break sum   //Set breakpoint at the entry to function sum


### gdb设置断点的方式：
gdb bomb 进入调试模式
breake sum / break *0x45506 在sum函数/0x45506地址处设置断点
run //运行程序

print /x $eax 打印出eax的16进制值




break sum //Set breakpoint at the entry to function sum
break *0x80483c3 //Set breakpoint at address 0x80483c3
delete 1 //Delete breakpoint 1
disable 1 //Disable the breakpoint 1
(gdb numbers each breakpoint you create)
enable 1 //Enable breakpoint 1
delete //Delete all breakpoints
clear sum //Clear any breakpoints at the entry to function sum