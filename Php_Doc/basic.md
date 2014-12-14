## 大小写
1. 函数名不区分大小写  
2. 变量名区分大小写  
3. 常量名最好大写(推荐)  

## 变量
### 变量类型
#### 四种标量(单值) 
* 布尔型  `TRUE` or `FALSE`  
* 整型  
* 浮点型  
* 字符串  用引号(`'str'`or'"str"')括起来的字符:字母、数字、空格、标点符号.

#### 两种非标量(多值)  
* 数组  
* 对象  

#### 其他两种  
* 资源 与数据库交互时将看到  
* NULL 一种不具有任何值的特殊类型  

### 变量注意  
* 命名，以`$`开头，紧跟数字或下划线，其余可用数字、字母、下划线填充  
* 单引号内不能使用变量,双引号可以  
* 字符串中双引号和单引号互相可以包含，但是包含自身时，需要使用斜杠`\\`  
## 常量  
* 使用`define()`函数定义常量，格式形如:`define ('name', value)`   
* 使用常量不需要美元符号,直接使用即可，但是不能直接在引号内引用  
* value只能是一个标量值  

## 字符串的一些操作  
* 使用连字符`.`来连接多个字符串使其构成一个大的字符串  

		$name="LiLuo";
		$intro="My name is ".$name;
PHP支持组合连接赋值运算符:`.=`  
* strlen()得到字符串的长度  
* strtolower()和strtoupper():小写和大写  
* ucfirst()和ucwords():首单词首字母大写和每个单词首字母大写  
* stripslashes():删除字符串中出现的任何反斜杠  
## 数字的一些操作  
* round()  
* number_format()  转化成更常见的形式  
* is_numeric()  测试提交的值是否为数字  

## 数组的一些操作  
数组分为索引数组和关联数组  
* 当属组使用字符串作为它的键时，把数组名和键包括在花括号中   

		echo "It is {$states['IL']}";
* 创建数组  

		$arr1[]="apple";$arr1[]="pear";$arr1[]="dear";
这样就创建了一个索引从0开始，从2结束的索引数组  

		$arr2=array('I'=>'luo','he'=>'su');
这就创建了一个关联数组  

		$arr3=array(1=>'Me','hh','tt');
这样也创建了一个索引数组  

* 使用`range()`创建连续数字,连续字母的数组  

		$arr4=range(1,10);  
		$arr5-range('a','z');

* 确定数组元素个数，使用`count()`  

		$num = count($arr1);
* `is_array()`函数可以确认一个变量是数组类型  
### 超全局数组  
`$_GET`,`$_POST`,`_REQUEST`,`_SERVER`,`_ENV`,`_SESSION`,`$_COOKIE`  

## 数组与字符串  
* `explode(separator, $str)` 把字符串使用分隔符separator分割成一个个子字符串放进数组  
* `implode(glue, $arr)` 把数组中的元素通过glue连接成一个字符串  
### 预定义变量  
#### `$_SERVER`
此变量存储了大量与服务器相关的信息  
$_SERVER['SCRIPT_FILENAME']--存储当前脚本的完整路径和名称  
$_SERVER['HTTP_USER_AGENT']--访问脚本的用户的Web浏览器和操作系统  
$_SERVER['SERVER_SOFAWARE']--运行PHP的服务器上的Web应用程序  

#### `$_REQUEST`超全局变量
存储了通过Get或者POST方法发送到PHP页面的所有数据，以及在cookie中可访问的数据  
使用此变量，可以获取指定name所对应HTML标签的值,例如在一个form标签中有  

	<input type="text" name="name" size="20" maxlength="40" />
那么，当提交表单后，在form的action属性指定的php页面中可以通过`$_REQUEST['name']`可以获得其值  


## 换行符  
* php的换行符号`\n`,可以把解释的HTML换行，即php最后生成的html代码是换行的，在页面展示，换行符前后两段文本只是一个空格  

## 单引号和双引号  
* 在PHP中，扩在单引号内的值将照字面意义进行处理(变量不处理)，而括在双引号内的值将被解释  
## PHP函数查询  
* 浏览器中访问`www.php.net/function_name`,例如查找ucwords(),则  

		www.php.net/ucwords
* 查看中文手册，`http://www.php.net/manual/zh/function.function_name.php`,例如  
	
		www.php.net/manual/zh/function.isset.php  

## 调试PHP脚本  
* 确保通过URL来运行PHP脚本  
* 查看运行的PHP版本  
* 确保display_errors启用。若禁用，则出现错误，出现空白页,或者在脚本中使用`ini_set('display_errors', 1)`  
* 调整显示的错误`error_reporting()`  
* 可以使用`set_error_handler()`来指定某错误发生时的错误处理函数  
* 使用`@`抑制错误  

		@include('config.inc.php');
* 检查HTML源代码  
* 出去休息一会儿   

## PHP条件真假  
* 假如某一变量或常量值为0,"",FALSE,NULL,则条件语句中为假  
* isset()函数可以判断某一变量是否设置(包括0,false,空字符串)并且不是`NULL`  
