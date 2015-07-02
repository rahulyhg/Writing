
## 库的种类

Linux 下的库有两种：静态库 和 共享库(动态库)  

两者的不同点在与代码被载入的时刻不同  

静态库的代码在编译过程中已经被载入可执行程序，因此体积较大  
共享库的代码是在可执行程序运行时才载入内存的，在编译过程中仅简单的引用，因此代码体积较小  

## 库的意义  

库是别人写好的现有的，成熟的，可以复用的代码，你可以使用但要遵守协议  

现实中每个程序都要依赖很多基础的底层库，不可能每个人的代码都从零开始，因此库的存在意义很大  

共享库的好处: 不同的应用程序如果调用相同的库，那么内存里只需要有一份该共享库的实例  

## 库文件的命名  

在 Linux 下， 库文件一般放在 `/usr/lib` 和 `/lib` 下  

静态库的名字一般为 `libxxx.a`  
动态库的名字一般为 `libxxx.so.major.minor` 

*说明*:  

1. `xxx` 是该 lib 的名称  

2. `major` 是主版本号，`minor` 是副版本号  

## 如何知道一个可执行程序依赖哪些库  

`ldd` 命令可以查看一个可执行程序 或 共享库 依赖的共享库  

比如查看一个最简单 `hello,world` 程序:  

	$ ldd hello
	linux-vdso.so.1 =>  (0x00007fffd959b000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fd797406000)
	/lib64/ld-linux-x86-64.so.2 (0x00007fd7977d5000)

## 可执行程序在执行的时候如何定位共享库文件  

当系统加载可执行代码时候， 能够知道其所以来的库的名字，但还需要知道其绝对路径  

此时就需要系统动态载入其(dynamic linker/loader)  
对于 `elf` 格式的可执行程序，是由 `ld-linux-xxxx.so*`完成的  
它根据一个环境变量值指定的路径去依次寻找库文件，将其放入内存  

## 新安装的库如何让系统找到  

如果是安装在 `lib` 或 `/usr/lib` 下， 那么 `ld` 默认能够找到, 无需其他操作  

如果安装在其他目录，需要将其添加到 `/etc/ld.so.cache` 文件中:  

1. 在 `/etc/ld.so.conf` 文件中加入库文件所在目录的路径  

2. 运行 `ldconfig` 去重建 `/etc/ld.so.cache` 文件  

## 库文件在 Linux 下的生成  

静态库的后缀 `.a` ,它的产生分两步:  

1. 由源文件编译生成一堆	`.o` , 每个 `.o` 里都包含这个编译单元的符号表  

2. `ar` 命令将很多 `.o` 转化称 `.a` ,成为静态库  

动态库的后缀是 `.so` , 它有`gcc` 加特定参数编译生成  
具体方法见后文  


## 用 gcc 生成静态和动态链接库  

我们通常把一些共用函数制作称函数库，以供其它程序使用  

函数库分为静态库和动态库两种  

静态库在程序编译时会被链接到目标代码中， 程序运行时将何不再需要该静态库  
动态库在程序编译时并不会链接到目标代码中， 而是在程序运行时被载入，因此程序运行时还需要动态库存在  


### 环境  

我们有三个文件  

`hello.h`:  

	#ifndef __HELLO_H
	#define __HELLO_H

	void hello(const char *name);

	#endif

`hello.c`:  

	#include <stdio.h>

	void hello(const char *name) {
		printf("hello, %s\n", name);
	}

`main.c`:  

	#include "hello.h"

	int main(int argc, char **argv) {
	
		hello("Everyone");

		return 0;
	}

### 生成可执行文件  

我们需要把 `main.c` 这个主程序编译成一个可执行程序，有三种思路:  

1. 通过编译多个源文件为目标代码文件，最终将目标代码文件合成一个可执行文件  

2. 通过创建静态链接库  `libhello.a`, 使生成可执行文件时能把`hello`函数从 `libhello.a` 中取出写入可执行文件中  

3. 通过创建动态链接库  `libhello.so`, 使的生成的可执行文件在执行到`hello("Everyone")` 时能动态从 `libhello.so` 中取出相应代码  

#### 编译称多个源文件  

	$ gcc -c hello.c	// 生成 hello.o
	$ gcc -c main.c		// 生成 main.o
	$ gcc -o hello1 hello.o main.o	//生成可执行文件 hello1

#### 使用静态链接库  

	$ ar rcs libhello.a hello.o	// 生成libhello.a
	$ gcc -o hello2 main.c -static -L. -lhello //生成可执行文件 hello2  

*说明:*  

1. `ar` 命令来生成静态库  
	
		`r` 插入一个目标文件到库文件(*.a)
		`c` 创建一个库文件
		`s` 建立符号表
		`d` 从库文件中删除一个目标文件
		`u` 更新库文件中已有的目标文件  

2. 使用静态库:  

		添加静态编译参数  `-static`
		指定静态库所在路径 `-L.` -- 静态库未知为当前目录
		指定加载的静态库 `-lhello` -- 加载静态库libhello.a

#### 使用动态库  

		$ gcc hello.c -fPIC -c
		$ gcc -shared -o libhello.so hello.o //生成的libhello.so
		$ gcc -o hello3 main.c -L. -lhello	//生成可执行文件 hello3
	
这样运行时，可能会报错  
所以:  

		$ sudo mv libhello.so /usr/lib


或者添加环境变量:  

		export  LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

`.` 表示库文件所在目录，即当前目录  

