### 安装 

	# sudo apt-get install mysql-server
安装mysql-server的同时，mysql-client也会被安装  
#### 默认账户
在安装mysql时，会提示输入密码  
这个密码是为默认账户root设置的  
root会在安装过程自动创建，但是此root非彼root  

Passwd for mysql root user: `woaini`  

### 输入查询  

* `select version();` -->查询mysql版本  
* `select current_date, curdate();` -->两者都是查询当前日期的  
* `select now();`-->查询当前时间(年月日时分秒) 
* `select sin(pi()/4), (4+1)*5;`-->计算数学表达式  

### 创建并使用数据库  
#### 数据库
* `show databases;` -->显示服务器山当前存在的所有数据库  
* `select database();` -->显示当前所在数据库  
* `use mysql`-->切换数据库到mysql(不用加分号，但需单行给出)  
* `create database menagerie;`-->创建了一个名为menageric的数据库  
* 可以在一开始从命令行登录服务器的时候，同时选择数据库  

		$ mysql -u root -p menageric 
#### 创建表
* `show tables;` -->展示当前数据库下所有表  
* 创建一个pet数据库，表项有:名字(name),主人(owner),种类(species),性别(sex),生日(birth),	死亡日期(death)   
	
		> create table pet (name varchar(20), owner varchar(20), species varchar(20), sex char(1), birth date, death date);

* 为了验证你的表是按你期望的方式创建，使用下面命令查看：  

		> describe pet;
或者  

		> show columns from pet;
这两者效果等同   
其实还有一种查看方法，只是这种方法的查看效果不是很好:  

		> show create table pet;
#### 删除一个表  
* `drop table pet;` -->删除名为pet的表  
* `drop table if exists pet;` -->假如表pet存在，删除pet  

#### 插入数据  
插入数据有两种方式：  
1. 单行插入  
使用列名指定插入相关列  
这样做的结果将是：任何未赋值的列都将被视作NULL(或者定义默认值的，就赋予默认值)  
如果列不能具有NULL值，并且没有默认值，那么不指定值将会引发一个错误  

		> insert into pet (name,owner,species,sex, death) values ('Puffball', 'Diane', 'hamster', 'f', '1993-03-30');
不指定列名，插入全部列  

		> insert into pet values ('Tim', 'Denny', 'dog', 'm', '1992-10-25', NULL);  
	
2. 多行插入  

		> insert into pet (name, owner) values ("a","A"), ('b','B'),('c', 'C'),('d','D');
	
3. 文本插入  
把想要插入的数据放在一个文本文件中，每行的数据安照表项依次写入，并以`tab`键相隔  
每行之间以换行符号()相隔  
Linux(`\n`), Windows('\r\n'), Mac-Os(`\r`)    
对于每个表项，如果允许缺失，那么可以使用`NULL`表示，不过在文本文件中，我们需要`\N`来表示`NULL`,在单条插入语句，直接使用`NULL`  

假如我有一个文件(/home/temp/pet.txt)：  


		Flutty	Harold cat f 1993-02-4 \N
		Claw Gwen dog \N 1992-11-24 \N
然后，我们就可以在mysql-client中使用一下命令插入此文件数据:  

		> load data local infile '/home/temp/pet.txt' into table pet;

如果出现错误  

		ERROR 1148 (42000): The used command is not allowed with this MySQL version  
那么需要做两件事(任选其一):  
 * 编译安装mysql时需要加上`--enable-local-infile`  
 * 可以在执行命令中`--local-infile`  

		$ mysql -uroot -p --local-infile  

##### replace语句 
`replace`是`insert`的一个变化  
只有当表中的主键或者唯一索引的值已经存在，那么`replace`将会更新存在的行  
否则，会同`insert`一样插入新行  

#### 从表中检索数据  
* `select * from pet;` -->搜索表pet所有的数据  
* `delete from pet;` 或者 `truncate table pet`-->删除整个表中的数据  
* `update pet set birth ='2014-09-30' where name = 'Bower'` -->修改名字为Bower的宠物出生日期为2014-09-30  
* 在where子句中可以使用逻辑运算符：and 和 or; and的优先级比or高  
* 选择指定列，用逗号隔开  

		> select name,irth from pet;
* 若是在一次查询中，某一列出现多次，为了保证输出的唯一，可以使用关键字`distinct`  

		> select distinct owner from pet;
* 可以对查询结果进行排序输出，使用`order by ... [asc/desc]`子句  

		> select name,birth from pet order by birth;	
默认时升序，可以*指定排序方式*:asc(升序)、降序(desc)  
每一个关键字，只能影响其前面的列名  
还需要注意一点，默认情况下排序并不区分大小写，若是想要*区分大小写*，还需从关键字`binary`  

		> select name,birth from pet order by binary owner;  

##### 使用limit  
限制结果条数  
输出3条结果  

	> select * from pet limit 3
指定结果开始位置(0开始)，并限定条数  
从搜索结果的第3个开始，输出5个结果  

	> select * from pet limit 2,5
对咯，`limit`不是标准SQL的语法，所以并不是所有的数据库都可以使用，但至少mysql可以使用  

##### 日期计算  
* 想要知道每个宠物有多大，可以计算当前日期的年和出生日期之间的差；如果当前月份天数比出生日期还早，那么减去一年  

		>select name,birth,curdate(),
		>(year(curdate())-year(birth))
		>-(right(curdate(), 5)<right(birth, 5))
		>as age  
		>from pet order by age;
`year(), month(), dayformonth()`可以从date格式的字符串获取年，月，月天  
`right(date, 5)`获取月，月天  

由于计算生日的表达式太长，我们使用`exprssion as alias`为其起了别名  
别名我们可以使用在`order by`子句，以及将来我们会用到的`having`子句  

* 如果你想知道哪个动物下个月生日,那么如下做：  
	
		> select name,birth from pet 
		> where month(birth) = month(date_add(curdate(), interval 1 month));
完成该任务的另一个方法是加1以得出当前月份的下一个月  
但是我们也不能直接+1,否则12月+1就有问题了  
因此使用`date_add(date, interval num [year/month/day])`,它会为date智能增加num年或月或日    
或者，我们使用`mod(num, base)`,它的意思是以base为基，对num取余  
因此，上述操作也可以这样：  

		> select name,birth from pet 
		> where month(birth) = mod(month(curdate(), 12))+1;  

#### NULL值的操作  
* `NULL`值意味着"没有值"或“未知值”,且它被看作与众不同的值  
* 判断某一字段为`NULL`：`is NULL`, `is not NULL`以及`ifnull()`函数  
* 在SQL中，`NULL`值与任何其它值的比较（即使是NULL）永远不会为“真”  
* 用`LOAD DATA INFILE`读取数据时，如果希望在列中具有`NULL`值，应在数据文件中使用`\N`。  
* `DISTINCT`、`GROUP BY`或`ORDER BY`时，所有`NULL`值将被视为等同的。 
* 使用`ORDER BY`时，首先将显示`NULL`值，如果指定了`DESC`按降序排列，`NULL`值将最后显示
* 对于聚合（累计）函数，如`COUNT()`、`MIN()`和`SUM()`，将忽略NULL值。但是`count(*)`是对整个结果统计行数，无法忽略含有`NULL`的项  

		> select count(*),count(birth) from pet;
* 对于某些列类型，MySQL将对`NULL`值进行特殊处理。  
 * 如果将`NULL`插入`TIMESTAMP`列，将插入当前日期和时间  
 * 如果将`NULL`插入具有`AUTO_INCREMENT`属性的整数列，将插入序列中的下一个编号  

#### 模式匹配  
MySQL提供标准的SQL模式匹配和一种基于类似Unix使用程序如vi、grep和sed的扩展正则表达式匹配的格式  

*需要注意的是*：无论那种匹配模式，都不能使用`=`和`!=`匹配，他们都有自己的关键字；而且，不区分大小写，需要区分大小写时，需要关键字`binary`  

##### SQL模式匹配  
* 使用`_`匹配任何单个字符  
* 使用`%`匹配任意数目字符(包括零字符)  
* 在MySQL中，SQL的模式默认是忽略大小写的  
* SQL模式需要模式与整个值匹配，才能匹配  
* 在where子句中使用SQL模式匹配需要使用`like`和`not like`  

For example：  
*找出以"b"开头的名字*  

	> select * from pet where name like `b%`;  
*要找出以"fy"结尾的名字*  

	> select * from pet where name like '%fy';  
*要想找出包含"w"的名字*  

	> select * from pet where name like '%w%';  
*要想找出正好包含5个任意字符的名字*  

	> select * from pet where name like '_____';

##### 类Unix实用程序的扩展正则表达式  
* `.`匹配任何单个字符  
* `*`匹配0个或多个在它前面的字符  
* `+`匹配1个或多个在它之前的字符  
* `?`匹配0个或1个在它之前的字符
* 还可使用`|`,对，就是获得意思，之前或之后符合正则表达式，那么匹配  
		*x --> 匹配任意'x'字符  
		[0-9]* --> 匹配任意数量的数字  
		.* --> 匹配任意数量的任何字符  
* 字符类`[...]`匹配在方括号内部的任何字符   
* 要想在正则表达式中使用特殊字符的文字实例，应在其前面加上2个反斜杠“\”字符  
MySQL解析程序负责解释其中一个，正则表达式库负责解释另一个,比如要匹配`+`,那么需要使用`^\\+$`  

		[abc] --> 匹配a, b,或c  
为了给命名字符一个范围，使用一个`-`  

		[a-z] -->匹配任何字符  
		[0-9] -->匹配任何数字
* 可以使用`{num}`指定字符重复num次  
		
		abcp{3} -->匹配abcppp的字符串  
如果希望某一字串重复num次，可以使用`(字串){num}`  

		(abcp){3} -->匹配abcpabcpabcp的字符串  
* 和SQL模式不同，只要REGEXP模式与被测试值的任何地方匹配，模式就匹配  
* 为了定位一个模式以便它必须匹配被测试值的开始或结尾：定位开始处，使用`^`；定位结尾处,使用`$`  
* 扩展正则表达式匹配，需要关键字`regexp`和`not regexp` 或者 `rlike` 和`not rlike`  
For example:  
*为了找出以"b"开头的名字*  

		> select * from pet where name regexp '^b';
*为了找出所有不以"l"开头的名字*  

		> select * from pet where name not rlike '^b'  
*为了找出以"fy"结尾的名字，且区分大小写*  

		> select * from pet where name rlike binary 'fy$';
*为了找出包含一个"w"的名字*  

		> select * from pet where name rlike 'w';
*为了找出恰好包含5个字符的名字*  

		> select * from pet where name rlike '^.....$';  
也可以这样做  

		> select * from pet where name rlike '^.{5}$';
*为了找出重复"ab"两次的名字*  

		> select * from pet where name rlike '(ab){2}';

#### 计数行  
注意`group by`的使用  

* 统计结果多少行  

		> select count(*) as NumberOfResults from pet;
* 搜索每个主人有多少个宠物  
	
		> select owner,count(*) as number from pet order by owner;
*注意*:使用`group by`对每个owner的所有记录进行分组，count此时对每一分组进行统计  

* 统计每种性别的动物数量  

		> select sex, count(*) from pet group by sex; 

##### 聚合函数  
avg()	平均值  
count()	所有值的个数,忽略NULL  
group_concat()	所有值的连接  
max(),min(),sum()	最大值，最小值，合计值  

#### 使用1个以上的表  
pet表追踪你有哪个宠物  
如果你想要记录其它相关信息，例如在他们一生中看兽医或何时后代出生，你需要另外的表。这张表应该像什么呢？需要：  
* 它需要包含宠物名字以便你知道每个事件属于哪个动物  
* 需要一个日期以便你知道事件是什么时候发生的  
* 需要一个描述事件的字段  
* 如果你想要对事件进行分类，则需要一个时间类型字段  
综合上述因素，我们创建一个event表:  

	> create table event (name varchar(20), date date, type varchar(15), remark varchar(255));  
我把event表的一些数据信息放在`/home/temp/event.txt`，因此按如下方式写入数据：  

	> load  data local infile '/home/temp/event.txt' into table event;
假如这些宠物中有些宠物生产了，我们需要这些宠物母亲的年龄，则  

	> select pet.name, 
	> (year(date)-year(birth))-(right(date, 5)-right(birth, 5)) as age,  
	> remark from pet, event  
	> where pet.name = event.name and event.type = 'litter';

*关于多表查询要注意的几件事情*  

* `from`子句列出两个表,因为查询需要从两个表提取信息  
* 当从多个表组合(联接)信息时，你需要指定一个表中的记录怎样能匹配其他表的记录  
在上例这很简单，因为它们都有一个name列。查询使用WHERE子句基于name值来匹配2个表中的记录。  
* 因为name列出现在两个表中，当引用列时，你一定要指定哪个表。把表名附在列名前即可以实现。  

你也可以自己可自己联接，考虑下面这种情况：  
为了在你的宠物之中繁殖配偶，你可以用pet联结自身来进行相似种类的雄雌配对  

	> SELECT p1.name, p1.sex, p2.name, p2.sex, p1.species
	> FROM pet AS p1, pet AS p2  
	> WHERE p1.species = p2.species AND p1.sex = 'f' AND p2.sex = 'm'; 
### 获取数据库和表的信息  
* `show databases;` -->列出由服务器哦管理的数据库  
* `select database();` -->列出当前选择数据库，如果没选择，结果为NULL 
* `show tables;` -->列出当前数据库中的表  
* `descrbe pet;` -->展示当前表pet的结构  
* `show index from tbl_name;` -->如果表tbl_name有索引，那么生成索引信息  
### 在批处理模式下使用mysql 
前面我们已经讲述了很多mysql命令，不过那些都是交互式使用mysql查询  
同样，我们也可以把很多命令写在一个文件里，然后让mysql读取执行，这就是批处理模式使用mysql  
假如脚本名为`query.sql`,那么你可这样使用它:  

	$ mysql -u root -p < query.sql  
如果在Windows下运行mysql.并且文件中有一些可以造成问题的特殊字符，可以这样操作:  

	C:\> mysql -u root -p -e "source query.sql"
如果你想在语句出现错误的时候。仍想继续执行脚本，则应使用`--force`命令行选项  

#### 为什么要使用一个脚本?  
* 如果你需要重复运行查询(比如说，每天或每周)，可以把它编成一个脚本，则每次执行时不必重新键  
* 可以通过拷贝并编辑脚本文件从类似的现有的查询生成一个新查询  
* 当你正在开发查询时，批模式也是很有用的，特别对多行命令或多语句命令序列。如果你犯了一个错误，你不必重新输入所有内容，只需要编辑脚本来改正错误，然后告诉mysql再次执行脚本。  
* 如果你有一个产生多个输出的查询，你可以通过一个分页器而不是盯着它翻屏到屏幕的顶端来运行输出：  

		$ mysql -u root -p <query.sql | more
* 你可以捕捉文件中的输出以便进行进一步的处理  

		$ mysql -u root -p <query.sql >mysql.out
* 你可以将脚本分发给另外的人，以便他们也能运行命令  
* 某些情况不允许交互地使用，例如, 当你从一个cron任务中运行查询时。在这种情况下，你必须使用批模式。  

当你以批模式运行mysql时，比起你交互地使用它时，其默认输出格式是不同的(更简明些),没有了表格表格限制  

如果你想要在批模式中得到交互输出格式，使用`mysql -t`    

为了回显以输出被执行的命令，使用`mysql -vvv`  

你还可以使用`source`或`\.`命令从mysql提示符运行脚本:  

	$ source query.sql;
	$ \. query.sql

### 查看错误和警告  
使用客户端进行插入、删除等操作时，会有警告出现，但是警告一般不提示，只是出现几条警告，那么想要查看警告怎么办？  

	> show warnings;
错误一般会显示出来，可能有这样一种需求，发生了一次错误，隔了很很久之后(期间并没发生错误)，突然想查看上一次发生的错误，那么这样做:  

	> show errors;

### 更新数据  

	update tablebame set column1=valueA,column2=valueB ... where ....
`tablename`用来指定更新那个表  
`column1=value1`用来指定更新表中的某一列和值  
`where ...`用来选择更新那一行，若是没有指定，那么全部更新  


### 一些函数  
`now` -->当前时间  
`sha1(str)` -->对字符串str进行sha1加密，形成40个字符的字符串  
#### 一些文本函数  
`concat(t1,t2, ...)`	创建形如t1t2的字符串  
`concat_ws(s, t1, t2, ...)`	创建形如t1st2的字符串,会忽略具有NULL的值  
`length(s)`	字符串s的长度  
`left(s,num)`	字符串s最靠左的num个字符  
`right(s,num)`	字符串s最靠右的num个字符  
`trim(s)`	从t的开头和末尾删除多余的空格  
`upper(str)` -->把str转化成大写  
`lower(str)`	把str转化成小写  
`replace(s, s1, s2)`	把字符串s的s1用s2替换  
`substring(s, pos, len)`	从字符串s的第pos个位置(pos>=1)截取len个长度  

#### 数学运算  
`abs(n)`	绝对值  
`ceiling(n)`	向上取整  
`floor(n)`	向下取整  
`mod(n1, n2)`	返回n1除以n2的余数  
`pow(n1, n2)`	返回n1的n2次幂  
`rand()`	返回会0-1.0之间的一个随机数  
`round(n, len)`	对n进行4舍5入，保留len位的小数  
`sqrt(n)`	计算n的平方根  
`format(num,n)`	格式化num,使其保留n为小数，并且整数部分每3位插入一个逗号  

##### 随机顺序输出结果  
`rand()`函数可以与查询一起用于随机顺序返回结果  

	> select * from pet order by rand();

#### 日期和时间的处理函数  
`curdate()`		返回当前日期  
`curtime()`		返回当前时间  
`now()`			返回当前日期和时间  
`unix_timestamp(dt)`	返回从新纪元到当前时刻(无参或者now())或者到指定日期的秒数  

假如`dt`是datetime个格式的时间  

`date(dt)`		返回dt中的日期
`hour(dt)`		返回dt的小时  
`minute(dt)`	返回dt的分钟数  
`second(dt)`	返回dt的秒数  
`dayname(dt)`	返回dt的属于一星期中的星期几   
`dayofmonth(dt)`	返回dt是一月的哪一天  
`monthname(dt)`		返回dt的月名  
`month(dt)`		返回dt的月份数字值  
`year(dt)`		返回dt的年份的数字值
`last_day(dt)`	返回当前月份的最后一天  

`adddate()`
`subdate()`
`addtime()`
`subtime()`

`utc_date()`
`utc_time()`
`utc_timestamp()`
##### 格式化日期和时间  
`date_format()`	  
`time_format(time)`  
如果一个值同时包含日期和时间，那么可用`date_format()`格式化  
而`time_format()`只能格式化时间值，并且仅当存储时间值时才可以使用它  

#### 外键  

	foreign key (item_value) references tablename (column)
如果你只是在使用上面内容，那只是标识了关系，而并没有说明约束被破坏如何操作  

你可以在上面的语句后面附加如下内容来决定触发什么动作：  

	on delete action
	on update action
`action`也5个行为可选(restrict, no action, set default, set null, cascade)  
其中restrict和no action是同义词，表示不指定任何动作  
set defalut则不起作用  
set null 意味着删除父记录将导致子表中相应的外键被设置为null;如果表的该列定义为not null,删除父记录将会引发错误  
而cascade应该是最有用的，意思是级联，当上出父记录时，同时删除子表中被外键关联的子记录  

和触发器很想，但触发器更灵活  
**Question**  
使用外键虽然避免误插入，但是也使得自动增长的那列受影响，插入可能失败，但是那列会自动增长?

### 联接

内联接和外联接  
外联接中引用表的顺序很重要  

#### 内连接  

	> select m.message_id, m.subject, f.name from messages as m inner join forums as f on m.forum_id = f.forum_id where f.name = 'MySQL';
这是个等值连接：跨两个表执行了相等性比较  

如果等值连接中的两个表列具有相同的名称，可以使用`using`进行简化:  

	> select m.message_id, m.subject, f.name from messages as m inner join forums as f using(forum_id) where f.name = 'MySQL';

还可以这样写，估计大家也没想到吧，原来不此不觉间竟然已经用了内连接:  

	> select m.message_id, m.subject, f.name from messages as m , forums as f where m.forum_id = f.forum_id and f.name = 'MySQL';

#### 外联接  

	> select f.name, m.subject from forums as f left join messages as m on f.forum_id = m.forum_id;  
这是个左外连接  
不用说，也有右外连接和全连接，右外联接是左外联接的反向连接，而mysql不支持全连接  
外联接和内联接的区别在于：外联接把所有的匹配或不匹配的项全列出来，而内联接只列出匹配列  

需要使用外联接来包括所有的用户，完全包含的表必须是左联接中列出来的第一个表  

#### Alter  
`t`表示表名，`c`表示列名，`i`表示索引名  

	alter table t add column c TYPE		//添加新列到表的末尾  
	alter table t change column c TYPE	//更改列的属性  
	alter table t drop column c		//从表中删除一列，包括其所有数据  
	alter table t add indextype i(c)		//在c上添加新的索引
	alter table t drop index i		//删除现有的索引  
	alter table t rename to new_t	//更改表的名字  

#### 优化  

	> optmize table tablename;
假如使用`alter`命令改变表或对表进行大量的删除后，在记录之间会留下虚拟的间断，而运行这个命令可以优化数据库  

	> analyze table tablename 
假如存储在表中的数据发生批量更改的时候，可以执行此命令更新表中的索引，从而改善查询状况  

#### 事务

	start transaction;

	some operation

	commit/rollback;
这是一个完整的事务  
可以在事务中创建保存点  

	savepoint savepoint_name;

回滚到保存点  

	rollback to savepoint savepoint_name;

	
Mysql对与每一个指令都是自动提交的，我们可以改变这种局面:  

	set autocommit=0;
然后每次直到你手动输入`commit`之后，才会永久生效  
否则，你都可以通过`rollback`回滚  

关于事务的恢复是有限制的，只能对insert,delete,update进行回滚  

#### 关于加密  
SHA1()函数只是返回了一个值的散列值，而并不是一个加密的值  

两个函数:`aes_encrypt()`和`aes_decrypt()` 
这两个函数需要两参数：加密或解密的数据和随机加密字串  
对与aes_encrypt返回的数据是16个字符长的二进制的，故需要定义二进制类型:varbinary 和 blob  

#### 存储过程  
SHOW PROCEDURE STATUS;
#### 触发器trigger

	create trigger trigger_name 
	[after/before] [insert/update/delete] on table_name
	for each row  
	begin
	your sql
	end
delimiter 符号	//定义sql分隔符

#### 用户变量  
可以先在用户变量中保存值然后在以后引用它；这样可以将值从一个语句传递到另一个语句。  

用户变量与连接有关。也就是说，一个客户端定义的变量不能被其它客户端看到或使用。当客户端退出时，该客户端连接的所有变量将自动释放。  

用户变量的形式为@var_name，其中变量名var_name可以由当前字符集的文字数字字符、‘.’、‘_’和‘$’组成  
用户变量名对大小写不敏感。  
设置用户变量的一个途径是执行SET语句：  

	SET @var_name = expr [, @var_name = expr] ...
对于SET，可以使用=或:=作为分配符。  

也可以用语句代替SET来为用户变量分配一个值。在这种情况下，分配符必须为:=而不能用=，因为在非SET语句中=被视为一个比较 操作符：  

	mysql> SET @t1=0, @t2=0, @t3=0;
	mysql> SELECT @t1:=(@t2:=1)+@t3:=4,@t1,@t2,@t3;  

