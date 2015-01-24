## 什么是shell  

shell是一个程序，它接受从键盘输入的命令，然后把命令传递给操作系统去执行  
几乎所有Linux发行版本都提供一个名为bash的shell(Bourne Again Shell)程序,是UNIX上shell程序sh的增强版  

### 终端仿真器  

当使用图形界面时，我们需要另一个和shell交互的叫做终端仿真器的程序  

在桌面菜单中，有一个`Teriminal`的终端仿真器程序，KDE中用的是konsole,GDK则使用gnome-terminal  

这些终端仿真器基本完成一件事:让我们能访问shell  


### 一些简单的命令  

显示系统当前时间和日期:  

	$ date
	Thu Jan 22 16:39:26 CST 2015

显示当前月份的日历:  

	$ cal
	    January 2015      
	Su Mo Tu We Th Fr Sa  
	             1  2  3  
	4  5  6  7  8  9 10  
	11 12 13 14 15 16 17  
	18 19 20 21 22 23 24  
	25 26 27 28 29 30 31  
		
查看磁盘空间:  

	$ df -h
	Filesystem      Size  Used Avail Use% Mounted on
	/dev/sda1       103G  5.3G   92G   6% /
	none            4.0K     0  4.0K   0% /sys/fs/cgroup
	udev            2.0G  4.0K  2.0G   1% /dev
	tmpfs           393M  1.2M  392M   1% /run
	none            5.0M     0  5.0M   0% /run/lock
	none            2.0G   47M  1.9G   3% /run/shm
	none            100M   56K  100M   1% /run/user

显示空闲内存:  

	$ free
	             total       used       free     shared    buffers     cached
	Mem:          3.8G       2.5G       1.4G        62M       149M       982M
	-/+ buffers/cache:       1.4G       2.5G
	Swap:         8.0G         0B       8.0G

结束一个终端会话:  

	$ exit

### 幕后控制台  

即使终端仿真器没有运行，在后台仍然有几个终端会话运行着,它们叫做虚拟终端 或者是虚拟控制台。  

在大多数 Linux 发行版中，这些终端会话都可以通过按下 Ctrl-Alt-F1 到 Ctrl-Alt-F6 访问。  

当一个会话被访问的时候， 它会显示登录提示框，我们需要输入用户名和密码。  
要从一个虚拟控制台转换到另一个， 按下 Alt 和 F1-F6(中的一个)。返回图形桌面，按下 Alt-F7。  


