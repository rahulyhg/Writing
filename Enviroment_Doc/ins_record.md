
1. 更新软件源  

	$ sudo apt-get update 
如遇到无法更新软件源的情况，则需要更改软件源的地址或者番羽土啬  
你可以自行搜索适合自己的软件源，也可以通过Ubuntu的`Software & Updates`进行选择修改  

选择源的时候一般遵循两个原则:选择离自己最近的和当前最受欢迎的  

不同的网络状况链接源的速度不同，在选择源的时候建议手动验证源的链接速度，选择最快的源可以节省大批下载时间(`使用ping来测试速度`)  

使用Ubuntu的`Software & Updates`:`System Settings`->`Software & Updates`->`Ubuntu Software`,从`Download from`中选择适合的服务器  

**通过命令行更新源**  

* 首先备份源列表  

		$ sudo cp /etc/apt/sources.list /etc/apt/sources.list_backup

* 使用vim编辑`/etc/apt/sources.list`
* 从[ubuntu-source][]选择合适的源，替换掉文件中所有的内容，保存编辑好的文件  
[ubuntu-source]: http://wiki.ubuntu.org.cn/%E6%BA%90%E5%88%97%E8%A1%A8#.E6.BA.90.E5.88.97.E8.A1.A8 "Ubuntu 源列表"
> 注意要选择合适的版本:  
> 如果是14.10,则不用替换  
> Trusty(14.04)版本：将源列表中的utopic替换成trusty即可  
> Precise(12.04)版本：将源列表中的utopic替换成precise即可  
> Lucid(10.04)版本：将源列表中的utopic替换为lucid即可  
> 停止维护的版本:13.10,13.04,12.10,11.10,11.04,10.10,9.10,9.04,8.10,7.10,7.04,6.10,6.06,5.10,5.10,5.04,4.10

* 最后，刷新列表  

		$ sudo apt-get update

2. 安装适合自己的输入法(个人喜欢双拼--小鹤双拼)  

	$ sudo apt-get remove --purge ibus  
	$ sudo apt-get install ubuntu-desktop 
	# sudo apt-get install fcitx fcitx-pinyin  

重启之后:  

打开输入法管理器，添加输入法-- `Pinyin` 或者 `Shuangpin`  

如果是双拼，点击管理器最下面一栏从右到左第二个图标(斧头样子)  
然后，在弹出的框体中选择默认的双拼输入法，我用的是小鹤，所以选择`XiaoHe`  
对于其他配置，按要求配置即可  

在输入法管理器中选择`Global Config`标签页，设置输入法的切换热键以及其他一些全局设置  

3. 然后从下面的github地址中clone下`Linux`项目  

	 git clone https://github.com/MwumLi/Linux.git  

`Linux`中一个我写的关于`Ubuntu 14.04 Desktop`的配置脚本，主要完成了一下配置:  

	1. 安装了基本的编译环境  
	2. 安装vim并进行一些配置:
		建立`~/.vimrc`的配置文件
		建立`~/.vim`目录,此目录为vim的用户插件目录 
		下载Vundle.vim到`~/.vim/bundle`
		建立`~/.vim/doc ~/.vim/plugin ~/.vim/syntax ~/.vim/autoload ~/.vim/ftplugin`等目录
		建立vim中文文档帮助,使用`,h`可切换中英文
		重启之后，运行vim,输入`PluginInstall`安装配置文件中的插件
	3. 安装git(假如未安装git)
	4. 安装ctags
	5. 安装tree命令 
	5. 配置终端的配色(你可以修改脚本中的bg_color和fg_color来指定你喜欢的颜色)
	6. 安装jekyll开发环境

4. 安装chrome安装(http://www.google.cn/intl/zh-CN/chrome/browser/desktop/index.html)  

	$ sudo dpkg -i google-chrome-stable_current_amd64.deb  

出现Error，使用下面命令修复安装:  

	$ sudo apt-get install -f

好了，这样就可以使用了  


由于某种很奇特的原因，我们不能使用谷歌的服务，因此需要FQ  
FQ之后，你就可以自由地访问这个世界任何地方的东西了  

推荐FQ方式:  

	1. 使用GoAgent代理软件,http://zh.wikipedia.org/wiki/GoAgent  
	2. 使用谷歌红杏插件,下面是我的邀请链接：  

		http://honx.in/i/VCoMrYIaAyd3DXkF
	3. 购买一个VPN，推荐云梯,下面是我邀请链接:  

	...

还有很多FQ的方式，期待你的发现，如果好的话，麻烦share给我哦  

如果chrome出现乱码，则....

5. 安装wps  

下载的wps安装包`wps-office_8.1.0.3724~b1p2_i386.deb`,并安装  

	$ sudo dpkg -i wps-office_8.1.0.3724~b1p2_i386.deb

如果出现因为某些以来安装错误，那么使用一下命令安装依赖:  

	$ sudo apt-get install -f

这时候已经安装成功，你发现即使你双击运行，不能正常运行  
这是由于WPS只提供32bit版本的,可能你的系统是64bit  
所以要想安装wps并运行，需要安装32库,安装完整的的ia32-lib:  

	$ sudo -i
	# cd /etc/apt/sources.list.d
	# echo "deb http://old-releases.ubuntu.com/ubuntu/ raring main restricted universe multiverse" >ia32-libs-raring.list
	# apt-get update
	# apt-get install ia32-libs
	# rm ia32-libs-raring.list
	# apt-get update

用这种方式，你可以安装`ia32-libs`.  
然而，我们使用了13.04的源，因此，可能会有一些未知的问题  
在安装`ia32-libs`后，我推荐删除`/etc/apt/sources.list.d/ia32-libs-raring.list`，并使用`sudo apt-get update`  

现在你可以正常运行了哦，当运行成功，可能会出现一个系统检查窗口：`系统缺失字体:Wingdings、Wingdings2、Wingdings 3...`等  
这是因为你的系统缺失symbol-fonts字体  
这个字体并不好找，还好我已经找到了，share一下，下载之后安装即可:  

	$ sudo apt-get install symbol-fonts_1.2_all.deb

Okay，搞定

6. tmux的安装

7. vagrant统一开发环境

8. 播放器 -- VLC  

	$ sudo apt-get install vlc

9. 截图软件 Shutter  

	$ sudo apt-get install shutter

## 在Ubuntu 64-bit下编译、运行32位程序

要在64-bit架构的Ubuntu系统中运行32-bit程序,你应该这样做:  
添加`i386`架构体系，然后更新软件源，最后安装`libc6:i386`、`libncurses5:i386`、`libstdc++6:i386`这些库包  

	$ sudo dpkg --add-architecture i386
	$ sudo apt-get .update
	$ sudo apt-get install libc6:i386 libncurses5:i386 libstdc++6:i386
	$ ./test	

如果需要编译生成32bit程序，需要在编译时添加`-m32`


`sudo apt-get install program:i386`安装program的32bit库,program具体程序具体对待  

## chrome中文乱码

sans-serif
字体缺失问题  

1. 修改`/etc/fonts/conf.d/49-sansserif.conf`里倒数第四行的`sans-serif`为`ubuntu`,其他已有的字体也可以  

2. 使用一下命令安装字体  

		$ sudo apt-get install ttf-wqy-microhei ttf-wqy-zenhei xfonts-wqy

`ttf-wqy-microhei`: 文泉驿-微米黑  
`ttf-wqy-zenhei`: 文泉驿-正黑  
`xfonts-wqy`: 文泉驿-点阵宋体  

搜索字体: `dpkg -l | grep font`  
删除ibus后可能删除控制面板的一些选项  
因此我们需要重建控制面板:  

	sudo apt-get instll unity-control-center

或者  

	sudo apt-get install ubuntu-desktop
	


字体文件存放路径:  

	/usr/share/fonts/		系统字体。需要root权限  
	~/.fonts	用户字体，随便怎蒙城，推荐

字体配置文件路径:  

	/etc/fonts/conf.d/fonts.conf

关于字体一些命令:  

	fc-cache fc-match
