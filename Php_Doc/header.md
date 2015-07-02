php的header函数可以有很多用途，常用的是设置传输头信息和页面跳转。现在我们就来介绍header函数跳转方面的一些注意使用和使用过程中的用法。

header("Location:login.php")应该注意的几个问题 
header("Location:")作为php的转向语句。其实在使用中，他有几点需要注意的地方。

1、要求header前没有任何输出

但是很多时候在header前我们已经输出了好多东 西了，此时如果再次header的话，显然是出错的，在这里我们启用了一个ob的概念，ob的意思是在服务器端先存储有关输出，等待适当的时机再输出，而 不是像现在这样运行一句，输出一句,发现header语句就只能报错了。

具体的语句有： ob_start(); ob_end_clean();ob_flush();.........


2、在header("Location:")后要及时exit

否则他是会继续执行的，虽然在浏览器端你看不到相应的数据出现，但是如果你进行抓包分析的话，你就会看到下面的语句也是在执行的。而且被输送到了浏览器客户端，只不过是没有被浏览器执行为html而已（浏览器执行了header进行了转向操作）。


所以,标准的使用方法是：

ob_start();

........

if ( something ){

ob_end_clean();

header("Location: yourlocation")；

exit;

else{

..........

ob_flush(); //可省略

 

要想在header前有输出的话，可以修改php.ini文件

output_handler =mb_output_handler

或 output_handler =on

 

Output Control 函数可以让你自由控制脚本中数据的输出。它非常地有用，特别是对于：当你想在数据已经输出后，再输出文件头的情况。输出控制函数不对使用 header() 或 setcookie(), 发送的文件头信息产生影响,只对那些类似于 echo() 和 PHP 代码的数据块有作用。
