##find命令  
Linux下find命令在目录结构中搜索文件，并执行指定的操作  
若不指定目录，则当前目录为搜索目录  
### 命令格式  

	$ find path -options [-print -exec -ok ...]

#### 命令参数
*path:*用来指定查找路径，不指定，则默认当前目录  
*-print:*将匹配的文件输出到标准输出  
*-exec*将匹配的文件作为此参数后面紧跟的shell命令，相应命令的形式:`command {} \;`,注意`{}`和`\\`之间的空格,而且`\\`之后还有`;`  
*-ok:*和`-exec`的作用相同，只不过以一种更为安全的模式来执行该参数所给出的shell命令在执行每一个命令之前，都会给出提示，让用户来确定是否执行  

#### 命令选项(options)  
* -name 文件名查找  -iname 忽略文件名大小写  
* -path 匹配文件路径或文件  
* -regex 和path类似，完整路径的匹配，但是是基于正则表达式的  
* -perm 文件权限查找  
* -prune 可以使find命令不在当前指定的目录中查找，如果同时使用-depth选项，那么-prune将被find命令忽略  
* -user 文件属主来查找
* -group 文件属组查找  
* -mtime n -n +n 文件更改时间查找，-n表示文件更改时间距现在n天以内，+n表示文件更改时间距现在n天之前, n表示恰好n天  (modify time, 修改文件内容, `ls -l file`)  
* -atime 和mtime用法差不多 (access time, 查看文件内容 `ls -lu file`)  
* -ctime 和ctime用法差不多  (change time, 修改文件内容，文件更名，修改文件属性, `ls -lc file`)  
* -nogroup 查找无效属组的文件，即该文件所属的组在`/etc/group`中不存在  
* -nouser 查找无效属主的文件，即该文件属主在`/etc/passwd`中不存在  
* -newer file1 ! file2 查找更改时间比文件file1新但比文件file2旧的文件  
* -type 查找某一类型的文件  

		b - 块设备	d - 目录	c - 字符设备
		p - 管道	l - 符号连接	f - 普通文件

* -size n[cwbkMG] 查找文件长度为n[char,word,block,kB,MB,GB]的文件  
* -depth 查找文件时，首先查找当前目录中的文件，然后再在其子目录中查找  
* -fstype 查找某一类型文件系统的文件，这些文件系统类型可以在`/etc/fstab`是找到，该配置文件中包含了本系统中有关文件系统的信息  
* -mount 在查找文件时，不跨越文件系统挂载点  
* -follow 如果find命令遇到符号连接文件，就跟踪至所指向的文件  
* -cpio 对匹配的文件使用cpio，将这些文件备份到磁带设备文件中  

还需要注意一下几个参数：  

	-amin  n	查找系统中最后n分钟访问的文件  
	-atime n	查找系统中最后n天访问的文件  
	-cmin  n	查找系统中最后n分钟状态改变的文件
	-ctime n	查找系统中最后n天状态改变的文件
	-mmin  n	查找系统中最后n分钟文件内容改变的文件
	-mtime n	查找系统中最后n天文件内容改变的文件

在参数中被指定的数字参数:  

	+n     for greater than n
	-n     for less than n
    n      for exactly n

### 实战演练  
1. 查找用户主目录下的所有.txt文件  

		$ find ~ -name "*.txt" -print 
忽略大小写，则  

		$ find ~ -iname "*.txt" -print
2. 匹配多个条件中的一个，使用OR条件操作符，find中的表示是-o,比如我们查找用户主目录下的txt或pdf文件，则  

		$ find ~ \(-name ".txt" -o -name ".pdf"\) -print

3. -path参数使用通配符匹配文件路径或文件,而-name总是用给定的文件名进行匹配，例如匹配/目录下所有匹配usr的路径和文件  

		$ find / -path "*usr*"
4. -regex使用正则表达式匹配，和path一样，匹配完整路径名  
例如找到当前目录下(及子目录)所有.py或.sh文件  

		$ find . -regex ".*\(\.py\|\.sh\)"
可以使用-iregex用于忽略正则表达式大小写  

5. find可以使用`!`否定参数的含义，例如匹配所有不以.txt为后缀的的文件  

		$ find . ! -name "*.txt" -print

6. 基于目录深度的搜索,使用`-maxdepth`和`-mindepth`,如果不指定，则会从当前指定搜索目录递归搜索，如果指定`-maxdepth n`，则递归搜索到第3层(指定目录为第1层);如果指定`-mindepth m`,则从第m层开始搜索  
例如从根目录开始搜索到第2层，找到所有权限为777的文件  

		$ find / -maxdepth 2 -perm 777
这里有必要说一点，find的效率还和参数位置有关，比如上面这条命令，如果`-maxdepth 2`在`-perm 777`之后，那么find将会先找寻所有777的文件，然后在这些文件中进行目录的对比；如果按照之前的顺序的话，那么它只会下，找到根目录到2层目录之间的文件，然后判断权限是否为777.显而易见，这样的效率更高  
所以说find的参数位置也很重要  

7. 找出所有的目录文件  

		$ find / -type d
这是使用type参数，指定了要找的文件类型(f,l,d,c,b,s,p)  

8. 选择最近修改时间比指定文件更新的文件，使用`-newer file`  

		$ find / -newer ~/.vimrc
9. 找出文件大小小于2k的文件  

		$ find ~ -size -2k
7. 删除匹配的文件

		$ find ~/temp -name "s*" -delete  
删除在temp目录下的所有以s开头的文件  

8. 使用`-exec`执行命令，例如上面那条删除语句可以这样用:  

		$ find ~/temp  -name s*" -exec rm {} \;
效果和上面一样  
`{}`代替find的检索结果,末尾的`\\`一定要加上，不然会报错"find: missing argument to `-exec`",因为有了`\\`,所有末尾一定要`;`,这个大家应该都知道;  
`-exec cmd {} \;`对于检索的结果的每一个文件都执行一次cmd  
`-exec cmd {} +`对于检索结果汇集成一个参数集合,一次性提交给命令执行   
`-ok`用法以及作用和`-exec`一样，只是在每次执行操作的时候会询问  

9. 把普通文件中用户属主为root的文件属主改为普通用户  

		$ sudo find . type f -user root -exec chown liluo {} \;
需要超级用户权限身份执行find命令  

10. 将指定目录中的.c文件拼接写入一个文件  

		$ find . -name "*.c" -exec cat {} \; > combine.txt
可以看到我们没有使用`>>`,也就是追加，因为find命令的全部输出只是一个单数据流，而只有当多个数据流被追加到单个文件中的时候才有必要使用`>>`  

`-exec`命令无法结合多个命令，但是我们可以把多个命令写到一个脚本，让后在-exec中调用此脚本  

11. 让find跳过特定的目录  
例如:去除.git目录下得文件搜索  

		$ find . \( -name ".git" -prune \) -o \( -type -f -print\)
