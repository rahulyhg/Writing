### 安装ncurses库  

	sudo apt-get install libnurses5-dev  
可以从从[GNU的ftp站点](http://www.gnu.org/prep/ftp.html)下载,然后编译   
### 安装ncurse库的man手册  

	sudo apt-get install ncurses-doc
### 使用CDK(Curses Development Kit)库
默认安装的话,则这样使用  

	gcc -I /usr/local/include file -lcdk -lcurses
### 杂乱  
控制序列  转义字符"0x1B"  转义序列  


