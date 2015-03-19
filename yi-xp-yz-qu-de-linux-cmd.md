
## sl  



## fortune  

一个简单的文字游戏  
每输入一次命令，就会输出一句话:笑话，名言等  
要唐诗宋词，还次安装`fortune-zh`  

	$ sudo apt-get install fortune fortune-zh  

`-c` -- 显示名言的来源  
`-f` -- 输出要搜索的内容的文件  


## cowsay/cowsay -- 奶牛说/奶牛想

用ASCII字符打印一个小牛（或者其他动物），说话或想象，内容可以自定  

说话的内容可在后面指定，也可以从标准输入中获取  

cowsay的几种显示模式:  
* `-b` -- Borg mode    
* `-d` -- dead mode  
* `-g` -- greedy mode 
* `-p` -- paranoia mode  
* `-s` -- stoned mode
* `-t` -- tired  
* `-w` -- wonderful mode(default)  
* `-y` -- youthful mode

cowsay还可以显示其他图案，查看图案名:  

	$ cowsay -l

然后使用`cowsay -f 图案名 一段文字`,就可以打印出羊说等:  

	$ cowsay -d daemon "I am a daemon"

cowsay可以指定换行的列数:`-W mum`  
默认以40列进行换行，相当于`-W 40`  

`-T "Tongue"` -- 配置舌头的字符(1-2)  
`-e "eye"` -- 配置眼睛的字符(1-2)  
但是dead and stored mode不起作用  

## cmatrix -- 黑客帝国矩阵效果  

可以设置字符落下的速度(0-9),默认是4  

	$ cmatrix -u 7

可以矩阵的颜色,默认是green:  

	$ cmatrix -C yellow

在运行状态，也可以实时改变矩阵的状态  
具体看man手册的KEYSTROKES`  

## figlet、toilet和banner命令  

	$ sudo apt-get install figlet toilet sysvbanner -y  

这些命令可以把ASCII文本显示成艺术字的形式    

figlet的字体目录在`/usr/share/figlet/`下，字体文件以`.tlf`,`.flf`为后缀  
使用`-f font-name`即可更换字体  

toilet使用figlet的字体目录  
toilet有个`--gay`的选项可以使输出的字符带有颜色  

banner没那么多选项，只是打印要输出的前10个字符效果为大而已  

## oneko -- 喵星人  

运行一直猫，随着你的鼠标动  
知道ctrl+c  

可以替换其他动物，具体看man手册  

## apt-get moo -- "Have you mooed today?"  

## xeyes -- 一双盯着你鼠标的眼睛  

## xev -- 打印及时的X事件 

## linuxlogo -- 打印系统logo和系统信息  

## yes -- 无穷的y  

## cal 9  1752 -- 很奇葩的一个月  

## shred -- 文档粉碎  

## factor -- 分解因数  
	
	$ factor 75

## free the fish -- 桌面游过一条鱼  

alt+f2，输入free the fish  

## who is i/who is sb
