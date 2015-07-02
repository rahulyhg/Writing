由终端乱码引发的对locale的探索

使用Linux的时候，我们常常会遇到一个问题: 终端下中文显示乱码  


为了解决这个问题，我们会baidu, google...,看文档，读博客...  
如果你对其原因不好奇的话，可能很快就解决了  
但是你如果像我一样充满探索之心的话，可能会花大量的时间去寻找原因  

先说说终端下中文乱码的解决办法  

## 终端下中文显示乱码

在`.bashrc`末尾添加:  

	export LC_ALL="en_US.UTF-8"

或者  

	export LC_ALL="zh_CN.UTF-8"  

或者  

修改文件`/etc/default/locale`内容为  

	LANG="en_US.UTF-8"
	LC_NUMERIC="zh_CN.UTF-8"
	LC_TIME="zh_CN.UTF-8"
	LC_MONETARY="zh_CN.UTF-8"
	LC_PAPER="zh_CN.UTF-8"
	LC_NAME="zh_CN.UTF-8"
	LC_ADDRESS="zh_CN.UTF-8"
	LC_TELEPHONE="zh_CN.UTF-8"
	LC_MEASUREMENT="zh_CN.UTF-8"
	LC_IDENTIFICATION="zh_CN.UTF-8"

重启一下使其生效  

可能会解决，是的，可能  

因为可能也会报出下列错误:

	locale: Cannot set LC_CTYPE to default locale: No such file or directory
	locale: Cannot set LC_MESSAGES to default locale: No such file or directory
	locale: Cannot set LC_ALL to default locale: No such file or directory

并不是我们的方法有问题，而是我们的指定的locale并没有编译  
(locale是什么，先不解释，你只要知道你指定的en_us.UTF-8并不存在)  

`locale`命令可以查看当前使用的locale:`LC_*`变量的值  

`locale -a`查看系统当前所有编译好的locale    

很明显，`LC_*`指定的locale并没有在`locale -a`的结果中  

只需要使用`locale-gen`编译locale即可:  

	# 将编译OS中所有的locale
	$ sudo locale-gen	
	# 可以编译指定的locale，对于身为中国人的我来说，这个就已经足够
	$ sudo locale-gen en_US.UTF-8 zh_CN.UTF-8

或者  

修改/var/lib/locales/supported.d/local的内容为:  

	zh_CN.UTF-8 UTF-8
	en_US.UTF-8 UTF-8

然后  
	
	# 编译生成`/var/lib/locales/supported.d/local`指定的两种locales
	$ sudo dpkg-reconfigure locales		
	
*注意*  

* `locale-gen`的man手册已经说了  
> Compiled  locale  files take about 50MB of disk space, and most users only need few locales

因此，我们只需要我们需要的locale即可  
当然，如果你不放心，或者你觉得自己硬盘大不在意这点小空间，那么你就全部编译生成  

*	`sudo dpkg-reconfigure locales`中的是`locales`，不是`locale`哈  
写错了，会提示`locales not installed`的错误  
然后又确实没有这个软件，你会陷入循环纠结中...  

* `lovale-gen`编译的是`/usr/share/i18n/locales`中的locales源文件

* `/usr/share/i18n`下东西与OS无关，不同体系结构不同系统可以通用  
若有丢失，可以从其他地方复制过来  

---

终端中文乱码已经解决了，我们下来分析一下为什么会有中文乱码  

先说说字符码和字符集吧  

## 字符码和字符集

字符码就是一个字符所对应的二进制数字序列  
就像`A`用1ooooo1(65)来表示  
用二进制数字来代表相应的字符的过程，称为字符编码  
因为计算机只能识别二进制数字，所以为了计算机可以表现出丰富的语言符号，我们必须对其进行字符编码  

Unicode是一种很流行的字符编码，它用统一的编号来索引目前已知的全部符号  
字符编码最终形成一个符号集，只规定了符号的二进制代码，却没有规定二进制代码应该如何存储  
因此，我们需要一种实现其存储的方式，这就是字符集  

字符集描述了字符在系统内的编码方式，规定了符号在系统中的存储，以便于应用程序的解码  
UTF-8就是字符集的一种，是目前互联网使用最广的一种Unicode的实现方式  

Linux系统的所有字符集都放在`/usr/share/i18n/charmaps`下，这些都是用Unicode编号索引的  

我尽可能用自己语言简化了概念,如果还是不清楚，请看这篇博文:  
[字符编码笔记：ASCII，Unicode和UTF-8](http://www.ruanyifeng.com/blog/2007/10/ascii_unicode_and_utf-8.html "来自阮一峰的网络日志")  

在解决方案中，我有提过Locale,那么现在就讲讲Locale吧   

## Locale是什么 

Locale中文翻译为地区，区域设置，本地化  
计算机中，通常理解为根据计算机用户所使用的语言，所在国家或者地区，以及当地的文化传统定义的一个软件运行时的语言环境  

我是中国人，却使用着美国的地址格式，美国时间，这明显不合适  
为此，我们使用了一种Locale的机制来使我们计算机可以更好的匹配用户的生活环境    

### Linux下Locale的具体表示

Locale描述了软件在运行时的语言环境，从语言(Language)，地域(Territory)，和字符集(Codeset)三个方面进行了描述  

像`en_us.UTF-8`就是Linux下Locale的一个实例  

`en_us.UTF-8`和`zh_CN.UTF-8`的含义是什么呢?  

**en_US.UTF-8**: 我说英文，身处美国，使用UTF-8字符集来表达字符  
**zh_CN.UTF-8**: 我说中文，身处中国，使用UTF-8字符集来表达字符  

这两种方式都可以在系统中表示中文，只有关于具体区域的文化定义不一样  
即使用它们都可以解决Linux下中文显示、输入的问题，但是这两种方式决定的时间显示格式、比较和排序习惯会不同  


### 用12个变量为软件运行获取环境

Linux系统定义了以下12个环境变量:  

	LC_CTYPE			--	字符分类和大小写转换
	LC_NUMERIC			--	非货币数字格式
	LC_TIME				--	时间显示格式
	LC_COLLATE			--	比较和排序习惯
	LC_MONETARY			--	货币格式
	LC_MESSAGES			--  信息，诊断信息和交互式响应的格式
	LC_PAPER			--	默认纸张尺寸大小
	LC_NAME				--	姓名书写格式
	LC_ADDRESS			--	地址书写格式
	LC_TELEPHONE		--	电话号码书写格式
	LC_MEASUREMENT		--	度量衡表达方式
	LC_IDENTIFICATION	--	对自身包含信息的概述

这些变量的意义也可以通过使用`man locale`了解  

这些变量是Linux下软件获取使用者文化习惯的重要途径  

### 设定具体Locale描述语言环境

为了定义语言环境，我们需要为上述的12个变量分别分配具体的Locale(像`en_us.UTF-8`)  

除了这12变量可以设定以外，还有:`LC_ALL`和`LANG`  

这总共14个变量的优先级关系:  

	LC_ALL > LC_* > LANG

可以这样理解：  

1. 当设定`LC_ALL="en_US.UTF-8"`,则其余12个`LC_*`的值和LANG值都被覆盖  

2. 当不设定`LC_ALL`，我们可以分别为这个12个`LC_*`赋值；如果有某个变量没有赋值，就会启用默认`LANG`  

---

好了，写到这里，相信大家已经分析出原因了吧：    
>由于应用程序解读文本使用的字符集不适合(比如要解读汉字，你却使用了ASCII码，这明显不能够)  

>或者所需的字符集缺失  

字符集与locale有关，所以我们的解决方法从Locale入手  


---

## 写在最后

我所做的这些分析是根据从网上获取的资料以及自己在vagrant中尝试所得  

如果有问题，请留言或者`mail me`  




## 终端下的自动补全

`complete` 命令的使用
