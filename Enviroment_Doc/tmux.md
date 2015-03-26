
终端复用器  

## tmux的安装  

	$ sudo apt-get install tmux


## tmux的配置  

## tmux的简单快捷使用  

创建一个tmux session  

	$ tmux

在会话窗口左下角，可以看到当前会话的运行的程序  
一般默认进入bash,所以左下角在启动tmux session时，显示bash  

列出当前所有的session  

	$ tmux list-sessions

新建一个命名的session  

	$ tmux new-session -s test

想干点其他事儿，但保留当前工作的session环境，那么就脱离当前的session环境  

	请使用快捷键:ctrl+b+d  


重新attach指定的session test   

	$ tmux attach-session -t test

杀掉一个指定的session test  

	$ tmux kill-session -t test

杀死所有的sessions,因为所有的session跑在一个server上，所以只要关掉tmux这个服务器即可  

	$ tmux kill-server

在tmux session中创建窗口  

	请使用快捷键: Ctrl+b + c

tmux session中的窗口以0开始的编号  
因此可以使用一下快捷键切换到num窗口  

	Ctrl+b + num  --- num是一个数字
当前工作窗口被星号(*)标记  


查看tmux快捷键，当在一个session中时，我们可以使用一下快捷键查看tmux的帮助快捷键界面  

	Ctrl+b + ?  

在一个多个窗格上下左右移动  

	Ctrl+b + Arrow[Up/Down/Left/Right]

在tmux中打开(command-prompt)命令提示窗口，此时可以输入对应快捷键的命令(快捷键帮助界面每个快捷键后面的字符串)，来实现与快捷键相应的操作  
打开command-prompt的快捷键:  

	Ctrl+b + :  

重新设置快捷键：取消旧的快捷键，绑定新的快捷键  
比如重新绑定新的send-prefix为`Ctrl+a`  

	unbind C-b
	set -g prefix C-a

然后启动command-prompt,输入  

	 source-file ~/.tmux.conf
通过上面这个操作启用新的配置  

我们通过快捷键新创建的窗口以数字为编号，我们可以为每个窗口命名以便于更好地区分工作  

	Ctrl+b + , 
	这样就进入修改窗口名的模式，输入想设置的窗口名即可  

	Ctrl-b + n 切换到下一个窗口
	Ctrl-b + p 切换到上一个窗口
	Ctrl-a + w 显示当前会话的所有窗口，使用上下键选择
	Ctrl-a + & 退出当前窗口
	
	Ctrl-a + " 分割出一个垂直的窗口
	Ctrl-a + % 分割出一个水平的窗口
	Ctrl-a + Arrow 移动窗格
	Ctrl-a + ! 关闭所有的小窗格
	Ctrl-a + t 钟表
	Ctrl-a + q 每一个窗格都会出现一个数字，按指定的数字切换到指定的窗格  

### 自动生成布局  

新建一个文件~/.tmux/mylayout  

	selectp -t 0 #选中第0个窗格
	splitw -h -p 50 #将其分成左右两个
	selectp -t 1 #选中第一个，也就是右边那个
	splitw -v -p 50 #将右边那个分成上下两个
	selectp -t 0 #选中第一个

然后在.tmux.conf后面添加一句  

	bind D sourc-file ~/.tmux/mylayout

这样，每次当我们启动tmux后，可以使用`Ctrl-b D`来生成布局

### 增强鼠标  

在.tmux.conf中添加  

	set-option -g mouse-select-pane on  #鼠标可以选中窗格
	set-window-option -g mode-mouse on  #鼠标滚轮可以使用

### 更改tmux的操作模式  

tmux下默认不支持鼠标滚轮的   
虽然我们可以开启设置，但是并不推荐此种方式  
我们有更好的方式解决此类问题，这就是tmux的copy模式  

tmux有很多模式，正常模式(什么都不做)可以进行正常的工作 
tmux的copy模式,类似于vim的命令模式,在此模式将不能进行输入  

	使用Ctrl+b + [ -->进入Copy模式

tmux在copy模式下快捷键有两种选择：支持vim和Emacs的操作方式  
因此可以根据自己的喜欢选择vim和Emacs的操作方式  

	编辑.tmux.conf,添加 setw -g mode-keys vi 
	然后，保存，重新加载配置文件,这样将会启用vim操作方式  

退出Copy模式,**回车即可**  

在Copy模式下，假如我们启用了vim操作方式，那么就可以使用vim中的一些快捷键  
顾名思义，Copy模式下我们也可以复制  

	移动光标到复制开始位置  
	按下Space键即可复制  
	移动光标选择要复制的内容
	按下Enter键完成复制

到你想要粘贴内容的位置，按下`Ctrl+b+]`,可以发现刚才复制的内容，已经完美粘贴  

tmux复制的步骤看似有点麻烦，但是如果你的所有工作任务在统一个Session中，那么无论是vim打开的文件，还是其他终端输出的文本，都可以完美的复制  

#### 进入copy模式  

	Ctrl+b + [
## tmux的任务会话机制

一个server可以有多个sessions  
一个session可以有多个窗口，类似多个标签页  
一个窗口可以有多个窗格，即分屏  


## 类似于tmux的软件
GNU Screen


动态跟踪文件的增长  

	$ tail -f file


## tmux服务器下的作用  

如果通过ssh远程登录到服务器进行工作，我们刚好安装一个东西，这个东西有恰好很大，那么不得不等待或者重新开启一个终端ssh登录，然后进行其他操作  

显然，这样做极度不方便

是的，我们可以利用tmux的窗口和窗格机制  

因此，我们可以这样解决：

	ssh登录远程服务器  
	首先使用tmux建立一个session  
	接着安装我们的东西或其他进行长任务，占用了屏幕  
	然后，我们可以开启一个窗格或者开启一个窗口去完成我们其他操作

如果仅仅是这样，tmux也不会被如此的推崇了  

在我们进行远程工作时，往往面临一个问题网络断开，这时，我们的任务往往会停止  

就算不会停止，也不能回到之前工作现场，这会极大的影响我们的工作效率  

tmux的出现解决这个问题  

是的，我知道你知道我要说什么：tmux的session机制 

当我们有一个命名为code的session工作时，这个时候，网络断开  

“Oh,MyGod",过去我们或许会这样尖叫  

现在我们可以重新ssh登录到服务器，然后type:  

	$ tmux attach-session -t code

你会惊奇的发现，我们的任务还在，我们的工作现场完美无缺的保留与呈现  

## 结对编程(Pair Programming)

关于结对编程的概念，可以查看维基百科http://zh.wikipedia.org/wiki/%E7%BB%93%E5%AF%B9%E7%BC%96%E7%A8%8B  

怎么使用tmux进行结对编程呢？  

首先有一台公共的服务器  

然后有两个伙伴Peter和Tom,他们都有这台服务器的同一个登录权利，即同一个帐号  

Peter使用`ssh buddy@211.123.2.12`登录服务器，使用`tmux new-session -s combine`  

Tom也用同样的方法登录服务器，使用`tmux a -t combine`进入combine这个session  

这个时候，任何一方所做的改变，另外一方都可以看见  

因为tmux是基于文本的，所有即使网速慢点，影响也不会很大  

## tmux和vim的powerline插件  

默认情况下，启动vim，如果您使用了powerline插件，那么会发现颜色显示不正常  

此时，只要你在每次打开tmux时启用256色即可,即`tmux -2`  

但是这样每次都需要使用`-2`参数很是麻烦，所以我们可以使用`alias tmux='tmux -2'`对其进行匿名  


