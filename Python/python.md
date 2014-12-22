
## python的简易参考教程  
http://sebug.net/paper/python/index.html    

## 值得思考的一些东西  
> 有两种方式构建软件设计：
>	一种是把软件做地很简单以至于明显找不到缺陷；
>	另一种是把它做得很复杂以至于找不到明显的缺陷  
>
>---C.A.R. Hoare
> 
> 获得人生中的成功需要的专注与坚持不懈多过天才与机会 
>
>---C.W. Wendte

## 正式使用python前
### 编译安装python 
你可从  
>	http://www.python.org/download/  

下载python源码，然后按照网站上的帮助编译安装  

### 检查python的版本  
假如你是一个Linux用户，那么很可能你的系统已经继承了python  
打开一个终端，试试这个命令:  

	$ python -V 
	Python 2.7.6  

事实上，python2和python3还是有些差异：大多数原来是语句的关键字，变成了内建函数  

### 两种使用python运行程序的方式  

* 使用交互式的带提示符的解释器  
* 使用源文件  

### 挑选你喜欢的编辑器  

工欲善其事，必先利其器。选择一个用起来比较爽的编辑器，那么编写程序也变的有意思多  

什么叫比较爽的编辑器?  
* 代码高亮(这是最基本的)
* 可以格式化源码(方便查看在网上获取的源码)  
* 代码提示，补全(这简直是福音)
* 方便相关源文件之间跳转(像C语言中的.h和.c之间的迅速切换)
* 可以查看APi(这个不是非常必要，但是有的话，当然最好)  

Linux下使用Vim和Emacs  
Windows下使用IDLE  

这儿还有一些其他Python编辑器:`http://www.python.org/cgi-bin/moinmoin/PythonEditors`  
这儿还有一些使用Python的IDE:`http://www.python.org/cgi-bin/moinmoin/IntegratedDevelopmentEnvironments`  

## 开始python之旅

### 一个简单，完整的python程序  
**Hello.py**

	#!/usr/bin/python 
	#coding=utf-8
	'''
	This is a simple python program example
	'''
	#定义了一个hello()函数,需要一个字符串作为参数
	def hello(s):
		a = "hello,"
		a +=s
		print a
	
	hello("python") #调用hello()函数  

	# 或者你可以直接打印  
	print "hello,python"

	#或者使用;来把多行语句写在一行  
	a = "hello,python";print a

#### 运行  

	$ python hello.py
或者  

	$ chmod a+x hello.py
	$ ./hello.py

#### 关于hello.py的一些解释  

##### 关于注释

Python的两种注释:  
1. 以#号开始是python的单行注释  
2. 以2组三个单引号(''')包裹的是python的块注释  
	
第一行注释指明了解释此python程序的解释器位置  
> 如果有了第一行，那么当hello.py具有可执行权限(`chmod a+x hello.py`)时，直接指明位置即可运行此程序；
> 当然你也可以直接使用`python hello.py`指明解释器来运行此程序，那么此时就不需要写这行注释  

##### 关于编码类型

第二行注释指明了python所使用的编码类型  
> 如果没有第二行，那么你就不可以在你的源码中使用中文，即使在注释中使用中文，也不可以  
> 因为python默认是以ASCII作为编码方式，如果在源码中包含了中文了，即使你以utf-8格式保存源码也不可以正确执行  
> 因此最明智的做法,在使用中文前生命编码方式:`#coding=utf-8`  

##### 关于缩进和块 

可以看到，python使用`:`说明可以开始一个块，使用缩进来划分块  
这意味着同一层次的语句必须有相同的缩进  
缩进就是行首的空白,不是仅仅指`tab`  
不要混合使用`tab`和空格来缩进，因为这在跨越不同的平台的时候，无法正常工作  
三种建议的风格:单个tab或者两个空格或者四个空格  
选择一种风格，然后一贯使用它，这是好的做法  

##### 关于语句  

python的希望一行就是一个语句，以换行符作为语句结束标志   
同样，它也可以使用`;`来分割语句，使多个语句可以位于一行  
但是尽可能单独称呼吧，这样代码变得清晰明了  

### 获取帮助  

python包罗万象，基本所有你可以想象的功能都有  
万象也就意味着杂  
但是python提供了一个好的帮助方式  

	$ python
	Python 2.7.6 (default, Mar 22 2014, 22:59:56) 
	[GCC 4.8.2] on linux2
	Type "help", "copyright", "credits" or "license" for more information.
	>>> help(print)

是的，通过在命令行键入`python`进入python交互模式  
然后，在交互模式中使用help函数查看API文档 

如果仅仅使用help()，那么将可以进入help模式  
help模式下，你直接输入函数名或者类名就可以查看帮助了  

如果还觉得不足，那么google吧  

## 基本概念  

### 字面意义上的常量  
2、1.23、9.25e-3和'This is a string'都是字面意义上的常量  

根据其字面意义，即可知道其类型和具体的值  

不能改变，因此是一个常量  

### 数
Python中有4中类型的数:`int、long、float、complex`

声明一个复数(-5-4j):`int n = complex(-5, -4)`

### 字符串(str)  

字符串是字符的序列，但是python中并没有char类型，而是str.  
不过，这无丝毫使用的影响  

在python中定义一个字符串  

* 使用单引号(')  
> 使用单引号指示字符串，例如'Quote me on thi'.
> 所有的空白，即空格和制表符都照原样保留 

* 使用双引号(")  
> 双引号的字符串与单引号中的字符串使用完全一一致(这一点Php使用者注意)  
> 例如:"What's your name?"  

* 使用三引号('''或""")  
> 利用三引号，你可以指示一个多行的字符串  
> 在三引号字符串中你还可以使用单引号和双引号  
> 例如:  
>	'''This is a multi-line string. This is the first line.
>	This is the second line.
>	"What's your name?"," I asked.
>	He said "Tom."
>	'''

* 转义符  
> 如果你想要在字符串中最终显示具有特殊意义的字符，那么必须使用(\)来转意  
> 比如要在字符串中保留`\n`,而不是换行：`"This is \n, not newline"`  
>  
>值得注意的一件事是，在一个字符串中，行末的单独一个反斜杠表示字符串在下一行继续，而不是开始一个新的行。  

* 自然字符串  
> 你如果想要显示特殊意义的字符，而不想使用转义符`\`  
> 那么你需要使用自然字符串，只需要在正常字符串前添加r或者R  
> 例如: `r"Newlines are indicated by \n"`  

* Unicode字符串  
> python允许处理Unicode文本，只需要在正常字符串前添加u即可  
> 例如: `u"This is a Unidcode string"`
>
> 记住，在你处理文本文件的时候使用Unicode字符串，特别是当你知道这个文件含有用非英语的语言写的文本  

字符串是不可变的，即字符串不能被修改  

所有两个相邻的字符串都将被合并成一个字符串,例如:  

		"what's"' your name'  == "what's your name"
或者，你可以使用`+`号来合并两个字符串:  

		"what's "+"your name"

#### 字符串的操作 
字符串的操作，无论是哪门语言，都是很重要的   

请参考:

		http://wangwei007.blog.51cto.com/68019/903426 
		http://sebug.net/paper/python/ch09s07.html


或者使用python的help模式  

在或者google吧  

### 变量 
python的变量不需要声明或定义数据类型，使用变量时只需要给它赋一个值,它是根据具体赋值来确定处理什么类型的

因此存在这样一种情况：变量`a`开始是`int`的型的，在后面的某个时刻因为某个赋值，变成`list`类型  

#### 标识符的命名  

标识符是用来表示某样东西(函数，变量)的名字  

python中规则如下:  

* 第一个字符必须是字母或者下划线('_')  

* 其他部分可以由字母、下划线或数字组成  

* 标识符大小写敏感  

#### 定义变量  
我们使用标识符为变量命名:  
	
	#!/usr/bin/python 
	#coding=utf-8  
	
	a = 3	#定义了int型变量  
	print a

	a = 3.4 #定义了一个float型变量  
	print a 

	a = "string" #定义了一个字符串
	print a

#### 关于全局变量和局部变量  

全局变量使用`global`语句  

具体参考：[python中的局部变量和全局变量](http://sebug.net/paper/python/ch07s03.html)  

### 数据类型

变量可以处理不同类型的值,称为数据类型  

基本的类型是数和字符串  

python支持面向对象，所有还存在类  

### 类  
python 使用关键字`class`定义一个类  

类中每一个定义的方法都有一个至少有一个参数`self`,它指代实例变量  
当我们有一个类`Dog`,它这样定义:  

	class Dog:
		def __init__(self, name):
			if name != "":
				self.name = name
			else:
				self.name = "Dog"

		def bake(self,s):
			print self.name+" is baking in " + s
	dog = Dog()
	dog.bake("bake")
可以看得到我们实际使用并没有在括号中传入`self`,因为这个是由语言自己管理的  

在这里，我们还可以看到`__init__`方法，这是Dog的构造方法，当实例化此类，将会自动调用  

#### python中的继承  
python允许继承,下面是一个继承的例子  


	#coding=utf-8
	print "Object-Oriented Programming"
	class Animal:
		def __init__(self, atype):
			if atype != "":
				self.atype=atype
	        else:
		        self.atype="Animal"
	class Dog(Animal):
		def __init__(self, name):
			Animal.__init__(self, "dog")
	        if name != "":
		        self.name=name
	        else:
		        self.name=""
	    def desc(self):
		    if(self.name != ""):
			    print "The "+self.atype+"'s name is "+self.name
	        else:
		        print "The "+self.atype+" has no name"
    
	dog = Dog("")
	dog.desc()

#### 使用函数type来打印类型  
幸好，python提供了函数`type`来确定变量的类型，不然还真可能糟糕透顶  

比如:  
	>>> a=2
	>>> type(a)
	<type 'int'>
	>>> a="this is a str"
	<type 'str'>

python中不仅变量有类型，python中所有的对象都有类型  
如果声明一个函数，那么它的类型`function` 
如果声明一个类,那么它的类型`classobj`  

当我们不知道某个标识符的类型时，我们都可以使用`type(indetifier)`来明确类型  

---

## 运算符和表达式  

### python中几个特别的运算符  

* `*`	-- 乘  
> 关于乘法需要说的是：字符串与数字相乘，会扩展字符串,例如  
>		
>		>>> a = "str"*5
>		strstrstrstrstr

* `**`	--	幂  
> 返回x的y次幂  
> 例如: `3**4` == `3*3*3*3`

* `//`	--	取整除  
> 返回商的整数部分  
> 例如: `4//3.0` == `1.0`

* `not` -- 布尔‘非’  
> 没有C语言和php中的`!`

* `and` -- 布尔‘与’  
> 没有C语言和php中的`&&`

* `or`  -- 布尔‘或’  
> 没有C语言和php中的`||`

### 运算符的优先级  

运算符的优先级决定了表达式的计算顺序  

可以参考:[Python运算符优先级](http://sebug.net/paper/python/ch05s03.html)  

---

## 控制流  
if , for , while  

* if使用参考：[python中的if语句](http://sebug.net/paper/python/ch06s02.html)  

* for使用参考：[python中的for语句](http://sebug.net/paper/python/ch06s04.html)

* while使用参考：[python中的while语句](http://sebug.net/paper/python/ch06s03.html)  

*需要注意的是*：  
> while语句和for语句后可以使用else，如果包含else，它总是在for循环结束后执行一次，除非遇到break语句   
 
---

## 函数

### 定义函数  

	def functionName([参数列表]):
		函数体 

### 默认参数  

只有在形参表末尾的那些参数可以有默认参数值  
即你不能在声明函数形参的时候，先声明有默认值的形参而后声明没有默认值的形参  

可参考：[python函数中的默认参数](http://sebug.net/paper/python/ch07s04.html)  

### 关键参数  

调用函数指定参数名赋值，可以忽略传参的顺序  

具体参考：[python函数中的关键参数](http://sebug.net/paper/python/ch07s05.html)  

### return None

python的每个函数都有返回值，即使没有返回值的函数，每个函数都在结尾暗含`retun None`  

`None`是python中表示没有任何东西的特殊类型(NoneType)  

如果一个变量的值为`None`，那么表示它没有值  

`pass`在python中表示一个空的语句块  

因此，定义一个返回值为`None`,无任何语句的函数:  

	>>> def func():
	...		pass
	...
	>>>print func()
	None
	>>> type(func())
	<Type 'NoneType'>


### 一些内建的函数  

* len(str) -- 返回字符串和其他序列(list,dict,tuple)的长度  
* range(start, end [, step]) -- 返回一个列表  

		>>> range(1, 5)
		[1, 2, 3, 4]
		>>> range(1, 5, 3)
		[1, 4]

* 
---

## 文档  

python中得自动生成文档功能很吸引人：文档字符串  

文档字符串是Python中的一个很奇妙的特性，简称**docstring**  


那么docstring到底是什么?  
在函数是第一行的字符串就是这个函数的文档字符串  
当然不仅仅函数中可以使用，同样模块和类也可以  

docstring的惯例是一个多行字符串('''或""")  
它的首行以大写字母开始，句号(.)结尾  
第二行是空行  
从第三行开始是详细的描述  

你定义一个函数，使用了docstring,那么你可以打印函数的`__doc__`属性来读取docstring  

你使用help()功能打印函数的帮助，其实就是打印函数内部的文档字符串 

pydoc命令也是抓取docstring  

---

## 模块  

一个.py的python程序被其他python程序使用`import`导入使用，那么这个.py的python程序就是一个模块  

所以任意一个python程序都是一个模块  

### 从sys模块导入开始  

	#!/usr/bin/python 
	#coding=utf-8
	#FileName: using_sys.py 

	import sys
	print "打印命令行参数:"
	for i in sys.argv:
		print i
	
	print 'The python path is', sys.path 

通过以下命令使用:  

	$ chmod a+x using_sys.py 
	$ ./using_sys.py I love you
	I
	love
	you
	The python path is ['/home/mwumli/Coding/Python', '/usr/lib/python2.7', '/usr/lib/python2.7/plat-x86_64-linux-gnu', '/usr/lib/python2.7/lib-tk', '/usr/lib/python2.7/lib-old', '/usr/lib/python2.7/lib-dynload', '/usr/local/lib/python2.7/dist-packages', '/usr/lib/python2.7/dist-packages', '/usr/lib/python2.7/dist-packages/PILcompat', '/usr/lib/python2.7/dist-packages/gtk-2.0', '/usr/lib/pymodules/python2.7', '/usr/lib/python2.7/dist-packages/ubuntu-sso-client', '/usr/lib/python2.7/dist-packages/wx-2.8-gtk2-unicode'] 

#### 解释  

第一行`import sys`,我们导入了sys模块，这是一个包含python解释器和它环境有关函数的模块   

导入了模块，我们就可以使用模块里面的东西(函数，变量等)  

`sys.argv`是包含命令行参数的列表
我们可以看到在命令行中输入的参数都被我们打印出来了，和C语言中一样  

`sys.path`是包含python输入模块路径的列表  
以后我们想使用一个新的模块，只要把新的模块放入这些路径的任意一个路径即可  
`sys.path`的第一个元素是一个空字符串，这代表当前目录，即当前目录下python程序也可以被当作一个模块被导入使用 

### .pyc字节码文件  

.pyc文件是python的字节码文件，是.py的python源程序文件经过编译生成  

单纯加载一个.py的模块，需要先编译此文件，生成二进制字节码文件，然后在加载  
所以说，加载.pyc的模块明显速度快  

而且.pyc的文件是二进制文件，防止泄漏源码(假如用于商业)，也有反编译的软件  

### 导入模块的语句  

* `import module_name`  
> 这种导入方式，我们使用模块中的变量和函数，需要`module_name.var`或者`module_name.function`

* `from module_name import var/function/class`  
> 这种导入方式只是导入模块中的某一变量var，然后，我们可以直接使用var,不用`module_name.`来引用  

可以使用`from module_name import *`来导入所有变量、函数等  
但是这样可能引起命名冲突，也不妨便查看变量所属模块，对于源码阅读和修改造成不变  
推荐使用方式`import module_name`  

### 模块的主块  

当一个源程序被作为模块加载时，首先运行其内部可执行代码，然后才能被能被导入使用，而这段代码通常被称作**主块**  

所以，如果一个源程序作为模块被加载时，应该使其主块代码不会被执行，这样才能**提高加载速度**  

每个Python模块都有它的__name__，如果它是'__main__'，这说明这个模块被用户单独运行，我们可以进行相应的恰当操作  

#### 一个典型的模块文件定义  

下面是一个典型的模块文件定义:  

	#!/usr/bin/python 
	#coding=utf-8
	#FileName: module_demo.py

	printf 'This code can  be imported as a module'

	if __name__ == '__main__':
		print 'This program is being run by itself'
 
运行此程序:  

	$ python module_name.py
	This code can be imported as a module
	This program is being run by itself

把此文件当作模块导入:  

	$ python
	>>> import module_name
	This code can be imported as a module
	>>>

### dir()函数和del语句  

使用dir()函数可以打印指定模块的标识符(函数、类和变量)  
如果没有指定，默认打印当前模块的标识符  

**需要注意的是:**在指定模块使用`import`导入的模块的标识符也会被当作指定模块的标识符 

`del`语句可以删除标识符，之后就无法再使用此标识符，除非重新定义  

### python中的一些模块  

* sys模块   
* os模块  
* time模块   
* zipfile模块  
* tarfile模块  

## python的数据结构  

数据结构可以处理和存储一组数据的结构  

python有三种内建的数据结构: 列表(list)，元组(tuple),字典(dict)  

### list

list是可变的对象，即可以在列表中移除或添加条目  

使用符号`[]`来创建  

### tuple

tuple是不变的对象，故创建后不能改变  

用法基本和list一样，只是不能修改，删除  

使用符号`()`来创建  

#### tuple和print的组合使用

	>>> print "%s  is %d years" % ("mwumli", 21)  
	mwumli is 21 years

### dict

dict是可变的对象  

使用符号`{}`和键值对`...:...`来创建  

### 序列  

list、tuple和str都是序列  

序列的两个主要特点是索引操作符(`[]`)和切片操作符(`[num1:num2]`)  

`[]`可以让我们从序列中抓取一个特定项目  
`[num1:num2]`可以让我们获取序列的一部分，也简称切片  

#### python中的索引  

索引是整数，即可以是正数、0、负数  

	>>> a = "abcde"
	>>> print a[0],a[1],a[2],a[3],a[4]
	a b  c d e
	>>> print a[-5],a[-4],a[-3],a[-2],a[-1]
	a b  c d e

对于list,tuple同理  

#### python中的切片操作  

切片操作符是序列名后跟一个方括号，方括号中有一对可选的数字(索引)，并用冒号分割  

记住数是可选的，而冒号是必须的  

	>>> a = "abcde"
	>>> a[1:3]
	bc
	>>> a[1:]
	bcde
	>>> a[:4]
	abcd
	>>> a[:]
	abcde
	
对于list,tuple同理  

---

## 面向对象  

把数据和功能结合起来，用称为对象的东西包裹起来组织程序的方法。  
这种方法称为面向对象的编程理念  

*类和对象*是面向对象编程的两个主要方面  
类创建一个新类型，而对象是这个类的实例  
这类似你有个int型的变量，这存储整数的变量就是int类的对象  

**python中所有标识符数值都组成对象，即便是基本类型int(属于int类),这点是和C++,JAVA不一样的**  
我们可以看到有时候使用int(str)把包含数值的str转化成int型数值  
其他类型也可以这样使用  


---
## python的动态代码  
把代码当作数据处理，把数据当作代码执行，这是动态语言的魅力  

把数据当作代码执行，怎么实现呢?  
python提供了几个函数和语句:  

### python的读取和写出  
python使用raw_input(prompt)读取一个字符串  
python使用print打印value
### eval()函数
计算表达式的值并返回或者计算`compile()`函数生成的code object

	#coding=utf-8
	def square(x);
		return x*x
	l = ['square', '(3)', '+', 'square', '(2)']
	code = "".join(l)
	print l+" = "str(eval(code))

### exec语句  
可以执行python代码(多行)，也可以执行`compile()`编译得到的code object

	#coding=utf-8
	code = "print 'hh'\n\rprint 'tt'"
	exec code
	byte_object = compile(code,'', "exec")
	exec byte_code
	
### execfile()函数
执行指定的python文件  

### compile()函数
把语句编译成code object,根据编译选项的不同，生成不同的code object  

	$coding=utf-8
	code = "2+4*3"
	c = compile(code, '', 'eval') #编译成表达式code object
	print eval(c)

	code = "print 'hh'\r\nprint 'tt'"
	c = compile(code), '', 'exec' #编译成exec型的code object
	exec code

	#还有个single,编译成单行code object

### input(prompt)函数
input(prompt) == eval(input(prompt))

	#coding=utf-8
	#A simple caculator 
	
	while True:
		print input("> ")


## 一些牛叉的对列表操纵的函数  
map(), filter(), reduce(),lambda()
### map()函数
使用原型:`map(function, l1 [, l2])`   

参数可以是多个 

对列表l1中每一个元素使用function处理，最终返回一个元素为返回值的列表  
假如有m个列表，那么必然有这么两个限制条件(否则，报错):  
	* function有m个参数 
	* 每个列表的item个数相同  
最后当执行map()，它会将每个列表的元素组合成一个列表作为参数依次处理，最后返回一个和提供参数的列表元素个数相同的列表   


### filter()函数--返回值为真的过滤器
使用原型:`map(None or function, list or tuple or string)`  

参数只有一个  

filter()相当于一个过滤器，会把list,tuple,string中的每一个元素当作参数传进function,最后把返回为真的元素组成一个新的list,tuple,string返回  


### reduce()函数  
使用原型：`reduce(function, list [, initial])`  

使用reduce对列表从左到右依次进行累计应用，假如initial存在，那么initial将作为第一次应用的第一个参数  

阶乘代码实例:  

	#coding=utf-8
	def multiply(x,y):
		print str(x)+"*"+str(y)
		return x*y
		    
	x = [1, 2, 3, 4, 5]
	print x 
	print ""
	print reduce(multiply, x)
	print ""
	print reduce(multiply, x, 2)


### lambda语句  
python可使用lambda语句创建一个只有一行语句，而且语句为表达式的函数对象    
lambda定义的函数可以有多个参数  

lambda的使用原型:`aa = lambda x,y[,args]: x和y组成的表达式`  

实例:  

	#!/usr/bin/python2.7 
	#coding=utf-8 
	def make_repeater(n):
		return lambda s: s*n

	twice = make_repeater(2)

	print twice('word')
	print twice(5)

## 异常捕获  
异常捕获就是通过某个关键字包含运行的代码，如果代码在运行时发生错误，则会执行异常处理代码  

python提供了`try`,`except`,`finally`,`raise`关键字  

捕获异常实例:	

	>>>  try:
	...		print 'I love Python'
	...	except:
	...		print 'There is no exception'
	...	else:
	...		print 'When no exception,print me '
	I love Python 
	When no exception , print me
	>>> try:
	...		print 1/0
	...	except:
	...		print 'There is a exception'
	...	else:
	...		print 'This sentence will not print'
	...	finally:
	...		print 'However this sentence will be printed'
	There is a exception
	However this sentence will be printed

`try:`模块中的代码为异常检测代码  
`except:`模块中的代码为异常处理代码，
`except`后面可跟具体的异常对象，当有多个异常对象时，使用括号`(异常1,异常2...)`括起来  
`except`后面无任何对象时，指捕获所有异常  
`finally:`模块的代码是无论异常发不发生，都将执行的 
`raise`可以主动发出异常信号  

### python定义的异常对象  
* ArithmeticError	--- 溢出、除零和浮点错误  
* AssertionError	--- 声明失败时抛出的异常  
* AttributeError	--- 对象不支持所用的属性  
* MemoryError		--- 内存不足  
* NameError			--- 在命名空间未找到局部或全部变量  
* SystemError		--- 解释器内部错误  
* IOError			--- 试图打开不存在的文件  
* IndexError		--- 使用序列中不存在的索引  
* KeyError			--- 使用字典中不存在的键  

print语句中的输出元素之间使用逗号间隔，会自动在输出时使用空格分割  
例如:  

		>>> print "I","love","you"
		I love you
