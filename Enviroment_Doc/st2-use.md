
## 模糊匹配

在命令行面板(Ctrl+Shift+p)中输入的命令，不必全部输完  

只需要输入部分，就会列出所有含你输入字符的命令  

你选择即可

## 添加配置  

往`Preferences->Settings-User`


## 插件篇

### Alignment

选中需要对齐的部分  

按下`Ctrl+Alt+A`		

然后就对齐了（按照最突出的部分）  


### Markdown Preview and LiveReload

Markdown Preview -- 一个Markdown效果预览插件  
LiveReload -- 配合Markdown Preview的预览功能，生成实时预览效果

#### 

	Ctrl+B 	-- 		生成HTML文档

#### 预览效果

* 采用命令行面板 , 输入`Markdown Preview: Preview in Browser`,回车即可  

* 在`Preferences->Key Bindings-Default/User`中添加  

		
		{ "keys": ["alt+m"], "command": "markdown_preview", "args": {"target": "browser", "parser":"github"} }

然后，就可以使用`alt+m`进行预览咯  

`parser`指定了解析Markdown语法工具，提供了两种:`markdown`和`github`  
个人比较喜欢`github`方式  

##### 实时预览  

使用命令行面板，安装`LiveReload`插件  

每次当对你的Markdown更改  

保存一下修改的内容  

可以看到浏览器上的内容已经实时更新咯

### Clipboard History

剪贴板历史  

使用快捷键`Ctrl+Alt+V`  

### JSFormat  

格式化js代码: `ctrl+alt+f`  

### HTMLBeautify  

格式化HTML代码: `ctrl+alt+shift+f`

### KeymapManager

管理所有已经安装插件的快捷键功能  

`ctrl+alt+k`调出面板   

选择合适的功能，回车即可  

### jQuery  

jQuery代码智能提示

### HTML5

快速编写HTML末班

### Color​Picker

跨平台颜色取色器

使用`ctrl+shift+c`可以打开一个取色器  

选择你需要的颜色确定即会生成颜色代码  

### Emmet  

一款使用特定语法快速编写HTML, XML, HAML and CSS/SASS/LESS/Stylus的利器  

缺点就是无法使用ST2本身的代码片段  

#### 使用方式

两种使用方式：tab或者交互式对话框  

* 根据Emmet规定的语法编写代码，使用tab键扩展  

* 使用`ctrl+alt+enter`打开交互式对话框，在对话矿中编写Emmet代码，文件光标处会自动扩展

具体语法使用请看这里: [Emmet使用手册](http://www.w3cplus.com/tools/emmet-cheat-sheet.html)

### Placeholders  

通过键入一些HTML的字符，按下tab键，可以插入一些相关的HTML代码  

在写一些测试代码时，很有用  

### BracketHighlighter

当你光标移动到某位置，自动显示其包含域
## 主题  

* Cobalt  
* Solarized Dark  

## 原生快捷键  

### 打开/前往
* 跳转到某一行  

		ctrl+g  或者	搜索面板输入:

* 跳转到某一字段  

		ctrl+; 	或者 	搜获面板输入#


*  显示python命令行  

		ctrl+`		//自动安装Package Control插件用到过  

* 打开/新建  

		ctrl+o 
		ctrl+n

### 界面  

* 全屏  

		F11
* 无干扰全屏  

		shift+F11
* 开关侧边栏

		Ctrl+k, ctrl+b
* 显示底部面板  

		ctrl+i

### 编辑  

* 拼写检查  

		F6
* 行排序  

		F9

#### 选择  
	
* 选择整行（继续按键则继续向下选择）  

	ctrl+L

* 选中光标位置所在单词(继续按键则继续选择下个相同单词进行同时编辑)  

	ctrl+d

* 选择所有相同的单词  

	alt+F3

* 光标移动到所在位置括号的开始或结束位置  

	ctrl+m

* 选中光标所在括号内的所有内容  

	ctrl+shift+m

#### 多处编辑  

* ctrl+左键 -- 依次点击选取需要编辑的多处位置  
* ctrl+alt+Arrow up/down -- 多竖行同时编辑 

#### 代码折叠  

* 代码折叠  

		ctrl+shift[
* 代码展开  

		ctrl+shift+]

#### 删除  

* 光标处删除到行尾  

		ctrl+k+k
* 光标处删除到航首  

		ctrl+shift+backspace

#### 上下行互换  

* 与上行互换   

		ctrl+shift+Arrow-Up  

* 与下行互换  

		ctrl+shift+Arrow-Down

#### 缩进  
	
* 减少当前行缩进  

		ctrl+[	或者 	shift+tab

* 增加当前行缩进
	
		ctrl+]	或者	tab


#### 大小写  

* 变成大写  

		ctrl+k+u

* 变成小写  

		ctrl+k+L

#### 闭合当前标签  

		alt + .

