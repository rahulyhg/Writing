
## 正则表达式  

正则表达式是一种用于字符串匹配的模式语言  

通过规定的语法组合字符和字符集来表示一类字符串  


### 匹配字符集

使用特殊的字符来表示一类特定的字符集合  

* 可以表示不是换行符的任何字符  

		.

* 可以表示任意数字  

		\d

* 可以表示任何英文字母、数字和下划线  

		\w

* 可以匹配任何空字符(Tab, 换行和空格)  

		\s

* `\D`,`\W`,`\S`分别是`\d`, `\w`, `\s`的补集  

* 转义字符`\b`通常用来匹配单词边界(比如标点符号，空格，字符的开头或结尾)  

		单词与单词之间的间隔
		单词的开头  
		单词的结尾  

#### 重复模式  

* 在元素后面跟一个星号(`*`)表示可以重复任意次数(`>=0`)  

* 在元素后面跟一个加号(`+`)表示匹配`>=1`的次数  

* 在元素后面跟一个问号(`?`)表示匹配`0`或`1`一次  

* 在元素后面跟一对花括号，并包含一个数字(`{num}`)或两个数字(`{num1,num2}`), 表示匹配num次  

		/\d{num}/		-- 	数字要出现num次
		/\d{num,}/		--  数字至少要出现num次 
		/\d{n1, n2}/	--  数字至少要出现n1次，至多出现n2次

#### 子表达式分组

使用小括号`(...)`对表达式进行分组匹配:  

* 可以使小括号内匹配进行多次  
* js的一些函数可以保留小括号的内容，进行一些其他的操作  

### 语法  

* 正则表达式的内容被`/../`包含着  

		/abc/ 	-- 		这就是一个匹配含有abc的字符串的正则表达式

* 一些特殊的字符在正则表达式中都有特殊的意义  
因此，要匹配这类字符就需要:**在特殊字符前使用反斜杠 (`\`)**   

		斜杠(/)表示正则表达式的开始和结束  
		因此要在正则表达式中表示，就需要使用反斜杠(`\/`)  
		
		表示反斜杠为`//`  

* `[...]` --  匹配括号中包含的字符的任意一个  

		/[abc]Mac/		--		可以匹配aMac, vMac, cMac

* `[^...]` -- 匹配除了括号中包含的字符之外的任意一个字符  

* 使用`^`来匹配字符串以某一字符开始，使用`$`来匹配字符串以某一字符结束  

		> /a/.test("blah");
		< true
		> /^a/.test("blah")
		< false
		> /h$/.test("blah")
		< true

#### 全局模式和不区分大小写模式  

* 使用`g`来表示全局匹配，即一个字符串有多少模式串就匹配多少模式串  

		> "dfh jds dt d".match(/d\w?/g)
		< ["df", "ds", "dt", "d"]

* 使用`i`来表示不区分大小写匹配  

		> "WoaIni df".match(/woai\w*/)
		< null
		> "WoaIni df".match(/woai\w*/)
		< "WoaIni"

#### 多选一

使用`(..|..)`表示在多个元素中选一个  

		> "sdshello world".match(/(hello|nihao|你好) world/)
		< ["hello world", "hello"]
		> "df你好 world".match(/(hello|nihao|你好) world/)
		< ["你好 world", "你好"]
		> "sdfjhnihao world".match(/(hello|nihao|你好) world/)
		< ["nihao world", "nihao"]


### JS中使用正则表达式的一些函数  


#### RegExpObjec.test(string)

用于检测一个字符串是否匹配某个模式  

如果匹配，返回true ; 否则，返回false  

**代码示例**  

		> /w\w+o/.test("sdfwo")
		< false
		> /w\w+o/.test("sdfwdso")
		> true

#### string.search(substring/RegExpObjec)

用于检索字符串中指定的子字符串或者与正则表达式相匹配的子字符串  

返回第一次匹配的起始位置  

它不执行全局匹配  

**代码示例:**  

		> "dfhello world hello world".search(/hello world/g)
		< 2

#### string.match(substring/RegExpObject)  

用于检索字符串中指定的子字符串或者与正则表达式相匹配的子字符串  

返回匹配的字符串的值

如果regexp中没有全局标志`g`,那么match()方法执行一次匹配  
如果没有找到，则返回`null`  
否则，将返回一个数组：  
> 第0个元素存放的是匹配文本  
> 其余数组元素存放正则表达式中子表达式匹配(使用`(...)`)的文本  
> 这个数组有两个属性:index和input  
> index属性: 匹配文本的首次出现位置  
> input属性: 要检索的字符串的引用  

如果regexp中有全局标志`g`，则match()方法执行全局搜索，找到字符串中所有匹配的子字母串  
如果没有找到，则返回`null`  
如果找到，也返回一个数组:  
> 数组元素全部为匹配的子串  

**示例代码1**  

		> var aa="fdsshr34sdhr543".match(/hr(\d+)(\w)/)
		< undefined
		> aa
		< ["hr34s", "34", "s"]
		> aa.index
		< 4
		> aa.input
		< fdsshr34sdhr543

**示例代码2**  

		> "woainiwohenniwo".match(/.?ni/g)
		< ["ini", "nni"]

#### string.replace(regexp/substr, replacement)

用于在string使用replacement替换substr或者regexp匹配的部分  

返回一个新的字符串，是被替换的字符串  


需要提到的是`$1`到`$9`分别代表模式里括号部分的替换  

replacement可以是函数func：  
> 每次找到匹配值，该函数就会被调用一次  
> 匹配的文本会被函数返回值替换掉  
> 传给函数的参数是一个数组:  
> 1. 第一个元素为匹配的文本  
> 2. 倒数第二个元素为匹配的位置  
> 3. 最后一个元素为源字符串  
> 4. 其余元素为正则表达式中括号中的模式匹配的文本  


**示例代码**  

		> var aa = function(){ for(var i=0; i<arguments.length; i++) document.write(	arguments[i]+"*"); document.write("<br />"); return "tihr"}
		< undefined
		> "wo23 df43 d24 ".replace(/(\w){1}(\d){1}/, aa)
		< "wtihr3 df43 d24 "

浏览器中显示：  

		o2*o*2*1*wo23 df43 d24 *

		> "wo23 df43 d24 ".replace(/(\w){1}(\d){1}/g, aa)
		< "wtihr3 dtihr3 tihr4 "

浏览器中显示:  

		o2*o*2*1*wo23 df43 d24 *
		f4*f*4*6*wo23 df43 d24 *
		d2*d*2*10*wo23 df43 d24 *