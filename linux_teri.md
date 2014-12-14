## 终端颜色设置

dircolors -p		//查看系统当前的文件名称显示颜色的值
~/.dircolors是当前用户目录下的文件名称显示颜色的配置文件
~/.bash_rc文件里有关于dircolors的加载,配置文件名可以在里面随意定义，ubuntu下默认为.dircolors

## C/c++代码格式化工具--indent

ubuntu下没有需要安装  
内核代码格式化格式：
indent -npro -kr -i8 -ts8 -sob -l80 -ss -ncs -cp1

## Rsyslog(集中日志服务器)
	用于收集服务器的体质信息用于及时发现错误，处理故障
	当我执行sudo tail /var/log/messages时候，没有任何输出，在一看发现 /var/log/messages没有内容，找了一下才发现，Ubuntu已经将默认的系统日志记录在了 /var/log/syslog 文件中，加入我们想要找回原来的 /var/log/messages。由于这些日志文件时候 rsyslog服务维护的，我们可以通过修改 syslog的配置文件使其将日志记录在 /var/log/messages.
/etc/rsyslog.d/*.conf 这些配置文件被 /etc/rsyslog.conf 通过 $IncludeConfig 指令包含进来。
我么可以通过修改 /etc/rsyslog.d/50-default.conf 配置文件实现
去掉注释或添加：
*.=info;*.=notice;*.=warn;\
auth,authpriv.none;\
cron,daemon.none;\
mail,news.none	 -/var/log/message

然后重启rsyslog服务
sudo service rsyslog restart

## dmesg打印了的信息来自于哪里即存放位置

javascript:(function(){var a=document.createElement('script');a.src='https://raw.github.com/Elity/erya/master/fuckerya.js';document.body.appendChild(a)})();

## grep 和 xargs
###　grep是什么
###  grep怎么用

###	xxargs
### xargs怎么用

### find
### find怎么用

time_t　从1970年到现在经过了多少秒

### Install Plugin
Launch vim and run :PluginInstall
To install from command line: vim +PluginInstall +qall


### ctags
安装catgs---->sudo apt-get install ctags
设置ctags文件路径---->在vim中运行set tags=path/tags(假如想一劳永逸，那么就加入.vimrc)
help usr_29
Ctrl + ]	跳转到当前光标下单词的标签
Ctrl + w + ]	新窗口显示TagName标签
Ctrl + w + ]	预览窗口
Ctrl + o	返回上一个标签
Ctrl + T	返回上一个标签
:tag TagName
:stag TagName
"tselect TagName	展示选择列表，然后输入选择
:pedit	file	在预览窗口编辑文件file
:pclose		关闭预览窗口
//在当前文件和任何包含文件中查找atoi,在预览窗口显示匹配  
//在没有使用标签文件的库函数时显得非常有用
:psearch atoi
### Markdown
#### commands
:Toc: create a quickfix vertical window navigable table of contents with the headers.  
  
Hit <Enter> on a line to jump to the corresponding line of the markdown file.  

:Toch: Same as :Toc but in an horizontal window.  

:Toct: Same as :Toc but in a new tab.  
:Tocv: Same as :Toc for symmetry with :Toch and Tocv.  
#### Mappings
The following work on normal and visual modes:

	]]: go to next header. <Plug>(Markdown_MoveToNextHeader)  
	[[: go to previous header. Contrast with ]c. <Plug>(Markdown_MoveToPreviousHeader)
	][: go to next sibling header if any. <Plug>(Markdown_MoveToNextSiblingHeader)
	[]: go to previous sibling header if any. <Plug>(Markdown_MoveToPreviousSiblingHeader)
	]c: go to Current header. <Plug>(Markdown_MoveToCurHeader)
	]u: go to parent header (Up). <Plug>(Markdown_MoveToParentHeader)

#### Options
* Disable Folding  
Add the following line to your .vimrc to disable folding.

	let g:vim_markdown_folding_disabled=1

* Set Initial Foldlevel  
Add the following line to your .vimrc to set the initial foldlevel. This option defaults to 0 (i.e. all folds are closed) and is ignored if folding is disabled.

	let g:vim_markdown_initial_foldlevel=1

* Disable Default Key Mappings  
Add the following line to your .vimrc to disable default key mappings. You can map them by yourself with <Plug> mappings.

	let g:vim_markdown_no_default_key_mappings=1

### Taglis标签浏览器
'\'+'t'+'l'		---->打开标签浏览器		相当于:Tlist
ctrl + w +w	    ---->标签页和代码页切换





