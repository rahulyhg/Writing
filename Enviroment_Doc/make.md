
## Makefile 中的小知识

1. `$()` 在 Makefile 常出现，用来表示执行一个 Makefile 的函数 

2. `$(var-name)` 表示使用变量 var-name 的值  

3. `$?` 表示一个规则中的所有依赖文件  

4. `$@` 表示一个规则中的所有目标，在命令中使用$@会依次取出目标,并执行命令  

5. 在命令前加`-`, 错误会被忽略  

5. 在命令前加`@`,命令会打印到屏幕上  

6. `make -n` 或 `make --just-print`,那么只是显示命令，但不会执行命令  这个功能有利于我们调试我们的 Makefile, 看看我们书写的命令是执行起来的样子或是什么顺序  


7. `make -s` 或 `make --slient`则是全面禁止命令的显示  

## Makefile 中的关键字  

### wildcard -- 函数

用途: 展开通配符  
	
	# 列出所有的.c文件,注意查看使用 wildcard 与没有使用的差别  
	test = *.c
	extendTest = $(wildcard *c)

	show:
		echo $(test)
		echo $(extendTest)


### patsubst -- 函数


	# 列出所有的.c文件,注意查看使用 wildcard 与没有使用的差别  
	test = *.c
	extendTest = $(patsubst %.c,%.o,$(wildcard *.c))

	show:
		echo $(test)
		echo $(extendTest)

### subst -- 函数 

用途: 替换指定字符串  

`$(subst hello,,hellowohellorld)`的结果是 `world`  
用空字符串替换可字符串中的 `hello`

### filter -- 函数

用途: 提取指定模式的字符串  

`$(filter %.o,hello.c hello.o li.o li.bal)`的结果是`hello.o`  


### vpath

用途: 指定文件(依赖和目标文件)搜索路径


	为符合 <pattern> 的文件指定搜索目录 <direcories>
	vpath <pattern> <direcories>

	清除符合模式<pattern>的文件的搜索目录
	vpath <pattern>

	清除所有已被设置好了的文件的搜索目录
	vpath

`vpath` 使用中的 `<pattern>` 需要包含 `%` 字符来进行匹配零或若干字符  
此时，`%` 的作用和通配符`*`一样，知识在这种情况下不能使用`*`来表达同样的意思  


demo:  

	# 当在当前目录没有找到指定的.h文件
	# 会在../header去找 
	# 如果没找到，会在../include寻找
	vpath %.h ../headers:../include


`vpath` 语句可以被连续的使用  
当连续使用时，相同的 `<pattern>`被重复指定，那么按照指定的先后顺序来执行搜索  



## 文件搜索  

make 提供了两种文件搜索的方法:  

1. `vpath` 关键字，见上  
2. `VPATH` 变量  

		VPATH = src:../headers
	当在当前目录找不到依赖文件和目标文件，会在 `VPATH` 变量指定的路径寻找，即 `src` 目录 -> `../headers` 目录  

无论哪种方式，当前目录永远是最高优先搜死的地方  


## 伪目标

伪目标不是一个文件，只是一个标签  

一般情况下不与文件名重名  

为了避免重名，因此有了一个特殊标记 `.PHONY` 来指明一个目标是伪目标，向 `make` 说明，不管是否有这个文件，这个目标就是伪目标  

例如:  

	.PHONY : clean
	clean:
		rm  .*.swp

## 静态模式规则  

## 自动生成依赖性


## 书写命令  

如果你要让上一条命令的结果应用在下一条命令时，你应该使用分号分隔这两条命令  
比如你的第一条命令是cd命令，你希望第二条命令得在cd之后的基础上运行，那么你就不能把这两条命令写在两行上，而应该把这两条命令写在一行上，用分号分隔  


## 自动化变量  

`$@` -- 规则的目标文件名  
如果是一个文档文件(.a), 它代表这个文档的文件名  

`$%` -- 当规则的目标文件名是一个静态库文件时，代表静态库的一个成员名  

例如:  

	foo.a(bar.o) : prerequisuits
		command

此时的 `$@` 就是 `foo.a`, `$%` 就是 `bar.o`  

`$<` -- 规则的第一个依赖文件名  
`$?` -- 所有比目标文件新的依赖文件列表  
如果目标文件是静态库文件名，代表的是比库成员更新的.o文件  

`$^` -- 规则的所有文件列表(去除重复出现的)  
`$+` -- 规则的所有文件列表(没有去除重复的)  


## 参考文献  

[跟我一起写Makefile--陈皓](http://htwm.readthedocs.org/zh_CN/latest/index.html)
