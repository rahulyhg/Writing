## python的简易参考教程  
http://sebug.net/paper/python/index.html    

## python的变量和类型  
### python的变量 
python的变量不需要声明为某种具体的类型，它是根据具体赋值来确定类型的  
因此存在这样一种情况：变量`a`开始是`int`的型的，在后面的某个时刻因为某个赋值，变成`list`类型  

这种特性使我们的代码中变量名变得很少  
但如果滥用，可能会造成我们的代码难以读懂，甚至当错误发生时，难以调试  

#### 使用函数type来打印标识符的类型  
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
### python的数据类型
Python有多种内置数据类型  
python的4种基本数值类型:`int`,`long`,`float`, `complex`  

还有很多聚合类型，常见的有:字符串(str)，列表(list)，元组(tuple),字典,这三种类型也被称为容器类型:   
> str是字符的列表，使用单引号或双引号分割 ,它是一种不变对象，创建后的值不能改变   
> list是可变的对象，即可以在列表中移除或添加条目,使用符号`[]`来创建  
> tuple和list的用法基本相似，只是它是不变的对象，故创建后不能改变，使用符号`()`来创建  
> dict是可变的对象，使用符号`{}`和键值对`...:...`来创建  

[内置数据类型](http://woodpecker.org.cn/diveintopython3/native-datatypes.html)
#### str的操作  
[Python字符串的操作](http://wangwei007.blog.51cto.com/68019/903426)

#### 三种容器类型的使用  
**print_type.py**  

	#coding=utf-8
	'''
	This is a example, which is used to show `type()`'s usage and all typea in python
	'''

	a = 2 #创建一个int型的变量  
	print "a = 2 : "+str(type(a))

	a = 324234234234324234234  #创建一个long型的变量  
	print "a = 324234234234324234234 : "+str(type(a))

	a = 3.14 #创建一个float型的变量  
	print "a = 3.14 : "+str(type(a))

	a = complex(2, -3) #创建一个compex型的变量  
	print "a = complex(2, -3) : "+str(type(a))

	a = False
	print "a =False : "+str(type(a))

	def hello():
		print "show function type"

	print "hello() : " +str(type(hello))

	class Dog:
		def bake():
        print "bake"

	print "class Dog : "+str(type(Dog)) 

	a = Dog()
	print "a = Dog() : "+str(type(a))
	print "a.bake() : "+str(type(a.bake))
### python中的类  
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


