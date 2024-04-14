# FZU ASC 2024超算优化纳新
欢迎大家申请加入福州大学超算实验室的大家庭。这是超算实验室优化方向的纳新考核指南。（如果你是AI方向，请去寻找另一份文档！）
本次任务，我们将着重考核你的以下方面的能力：
1. 阅读源代码的能力
2. 阅读手册的能力
3. 基本的英语能力
4. 代码能力
5. 自学能力

我们将会用以下的几个任务检验你是否具备这个能力。在初步筛查过后，我们会邀请符合条件的同学与我们线下（或者线上）进行一轮面对面的交流，以便让我们更了解大家。

为了更好的检验大家的能力，在本次考核中，我们在文档中不会过于明确地指出你的任务，你需要仔细地阅读源代码来找到你的任务。此外，我们也不会具体的告诉你你需要怎么做，我们仅仅只会提示你，具体的工作需要你进一步的自学以及查阅相关的资料。最后，我们不会将代码所需要的库文件告诉你，你需要独立的阅读编译的报错信息来查找并安装相应的库。

## 提交方式
请将所有任务打包并压缩，命名为”<学号>+<姓名>“，发送至邮箱1353406961@qq.com。

## 截止时间
6月2日。

## 准备工作
本次任务的代码均已上传至github，链接如下：
```
https://github.com/DavidBao03/ASC_EX.git (Task1, Task3, Task4, Task5)
https://github.com/MITEGithub/Task-CV2.git （Task6）
```
具体怎么用这个链接把代码下载下来呢？这也是你自学的一部分！

下面是详细的任务介绍：
## Task1 学习汇编基础

将以下由C编译成的汇编程序补全（填写至task1目录的文件下）

![截屏2024-04-14 15.15.00](/Users/david_bao/mdIMG/截屏2024-04-14 15.15.00.png)


### 要求
1. 理解汇编中的一些基本概念, 如指令 寄存器 等 能够顺畅地阅读汇编程序
2. 理解C语言过程在汇编中执行的过程, 理解过程调用的本质和约定 
3. 给出一个C程序, 能动手翻译成汇编
4. 能够用gcc将C语言编译成汇编程序

### 期望输出
无

### 参考资料
视频课程: Machine Level Programing 部分 (lecture 5 ~ 9)
https://www.bilibili.com/video/BV1iW411d7hd?p=5

## Task2 BombLab
lab 链接 : http://csapp.cs.cmu.edu/3e/labs.html

做完lab后，请自行创建名为Task2的文件夹，并自行撰写一份pdf实验报告，要求有每个任务的答案和解决思路，放在该文件夹下。

### 要求
1. 学习使用 gdb 调试程序, 熟悉 gdb 常用的指令
2. 通过完成 bomb lab 巩固对汇编基础的理解

### 期望输出
无

## Task3 UserThread
实现一个用户级进程。

## 重要！
在编译该任务时，请加上-Og的编译选项。（附加题：思考为什么会这样；加上之后会有什么样的后果）

### 要求
1. 理解进程/线程的区别与本质
2. 了解CPU是如何在多个控制流之间进行切换的 ( context switch )

### 参考资料
1. CSAPP: Exception Control Flow ( 异常控制流部分 )
https://www.bilibili.com/video/BV1iW411d7hd?p=14&vd_source=a1c8e81f4cdf9b8bdf7f7b55a139faf3
2. 操作系统--哈工大李治军: 用户级线程1 ( P18 , 4分22秒左右开始 )
https://www.bilibili.com/video/BV1iW411Y73K?p=18&vd_source=a1c8e81f4cdf9b8bdf7f7b55a139faf3

### 期望输出
```
this is function A 
this is function C 
this is function B 
this is function D 
this is function C 
this is function D 
this is function C 
this is function D
......
```

## Task4 并发控制
使用条件变量或信号量实现一个简单的生产-消费模型

### 要求
1. 学会使用 pthread 或 std::thread 并行化程序
2. 了解为什么需要并发控制（从汇编层面解释）
3. 学习并发控制的手段：互斥锁，条件变量，信号量

### 参考资料
1. pthread :
https://man7.org/linux/man-pages/man7/pthreads.7.html（文档）
https://www.bilibili.com/video/BV1iW411d7hd?p=23（课程，39分半开始）
2. std::thread：https://en.cppreference.com/w/cpp/thread/thread（文档） 
3. 并发控制：
https://www.bilibili.com/video/BV1ja411h7jt/?spm_id_from=333.337 （锁）
https://www.bilibili.com/video/BV17T4y1S7RS/?spm_id_from=333.788 （条件变量与信号量）

### 期望输出
参考程序输出。

## Task5 Matmul
优化通用矩阵乘。

### 要求
1. SIMD
2. 共享内存模型 （pthread / std::thread / openmp）
3. 消息传递模型 （mpi）
4. 了解这些手段提供的同步机制

### 参考资料
1. SIMD：
http://ftp.cvut.cz/kernel/people/geoff/cell/ps3-linux-docs/CellProgrammingTutorial/BasicsOfSIMDProgramming.html (SIMD 介绍)
https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html （指令手册）
2. openmp：https://www.openmp.org/wp-content/uploads/OpenMPRefCard-5-2-web.pdf
3. mpi ： https://www.math-cs.gordon.edu/courses/cps343/presentations/Intro_to_MPI.pdf

### 期望输出
参考程序输出。

## Task6 CV-Optim

现在你已经学会如何对一个通用的矩阵进行乘法运算了，下面通过一个具体的图片处理的并行优化来测试以下你的学习情况吧

tips: 这次的图片是在Windows操作系统下的Bitmap图片处理

### 要求

​	1.能正确输出一个处理后的图片

​	2.在测试代码中需要提供代码优化前和优化之后的加速比，你可以尝试不同的并行方案，体会不同方案之前的区别

​	3.从这个小项目中提高自身的阅读项目，维护项目的能力

​	4.优化后的代码保存，如果自己实现的源码会酌情加分

### 参考资料

​	这一部分内容是前面所学知识的具体运用，将不会给出参考资料

​	tips: 能成功进行优化的前提是你能理解windows是如何处理bmp的，虽然跟具体的优化没有什么关系，

​	但是一个好的程序员必须要有一个好的自学能力，发挥你们的rfsc,stfw能力去学习吧

## Task7 ArchLinux Install

**注意：这一部分内容是附加题**

使用一个Linux相比于Windows对程序员来说能加强你在计算机操作系统和架构上的理解，如果你已经在使用Linux了，这很好;

如何你还没有使用或者听说过Linux系统，那学长推荐可以使用双系统在你的计算机上，当然如果你觉得双系统容易将自己的计算机搞炸

虚拟机也是不错的选择。这边学长推荐的是Arch系的Archlinux, 当然你有自己更好的选择Ubuntu和Cent Os也是非常棒的选择

>  这边配上rchlinux的ISO的下载  https://archlinux.org/download/
