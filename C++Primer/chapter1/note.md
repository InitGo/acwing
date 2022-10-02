### 1.2
- 黑体字

### linux查询c++编译器 ： 
```gcc -v```

### 编译cpp文件
```shell
gcc -o 1.1 1.1.cpp
ls
echo $? #查看返回值 
#return 0;  返回0
#return -1; 返回255
```

### iostream
- 标准输入输出对象： `cin cout cerr clog`
- 向流写入数据：流是不是就是小黑窗?【IO显示设备】
  - 左侧对象 + << + 右侧对象 构成express
    - `<<`运算符
    - 左侧是ostream对象
    - 右侧是要打印的值
    - 运算结果是左侧运算对象
 
  - `endl`操纵符 manipulator
      - 结束当前行，并将与设备关联的buffer中的内容刷到设备中。缓冲刷新操作可以保证到目前为止程序产生的所有输出都真正写入ostream中。而不是仅停留在内存中等待写入流
      - 调试打印时，应当保证“一直”刷新流，避免程序崩溃时还有输出内容留在buffer中，导致错误判断
- 从流读取数据
  - 左侧对象 + >> + 右侧对象 构成express
    - `>>`运算符
    - 左侧是istream对象
    - 右侧是要将读入数据保存在哪里
    - 运算结果是左侧运算对象
- 使用标准库中的名字
  - `std::`指出`cout`和`endl`都是定义在名为`std`的namespace中

### 注释
// 单行注释
/* */ 这个里面不能嵌套

### 控制流
- while
- for
- 读取数量不确定的输入数据
  - while (std::cin >> x)
  - while的condition为std::cin
    - 当使用istream对象作为条件时,效果是检测流的状态.如果流是有效的,检测成功;如果遇到end-of-file/无效输入(ex.读入的值不是一个整数),则流变成无效的,条件为假
    - 如何从键盘输入end-of-file: windows ctrl+z // unix ctrl+d
- if
  
### 类简介

### 文件重定向
```shell
gcc -o add add.cpp
add <infile >outfile
```