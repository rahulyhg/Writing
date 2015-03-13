## DOM--文档对象模型  

DOM把HTML文档描述成了一个层次化的节点树  

提供了一套简单的API方便开发者去添加，移除，修改节点  

### DOM元素  

HTML文档在DOM看来，就是一个层次分明的节点树  
而每一个HTML标签就是其中的节点,也被称为DOM元素  
对了，文本块也属于DOM元素  

一个简单的HTML文档模板:  

		<!DOCTYPE html>
		<html>
		<head>
			<meta charset="utf-8">
			<meta http-equiv="X-UA-Compatible" content="IE=edge">
			<title></title>
			<link rel="stylesheet" href="">
		</head>
		<body>
			<p>I am text area element</p>
		</body>
		</html>

html就是head的*父元素*，而head就是html的*子元素*，以此类推  
由此可知，在整个HTML文档中唯一*没有父元素*的标签就是html  
而*没有子元素*就是文本块元素  

### document的一些对象  

* `document.head`和`document.body`可以分别得到HTML文档的`<head>...</head>`，`<body>...</body>`

* `document.documentElement`就是`html`  

* `document.documentURI`是当前页面的完整链接  

* `document.domain`是当前页面的域  

#### 节点链接  

* 父节点  

		node.parentNode

* 子节点数组  

		node.childNodes

* 第一个子节点  

		node.firstChild

* 最后一个子节点  

		node.lastChild

* 前一个兄弟节点  

		node.previousSibling

* 后一个兄弟节点  

		node.nextSibling


#### 节点类型  

DOM有12节点类型，经常用的只有两种:普通节点和文本节点  

普通节点就是HTML元素，用1表示  
文本节点就是文本块，像p标签包含的段落文本，用3表示  
document对象节点类型为9  

可以使用`nodeName`属性查看普通节点(非文本节点)的节点名  
使用`nodeValue`查看文本节点的文本内容  

		> document.body.nodeName
		< "BODY"

### 节点的操作 

#### innerHTML属性  

每个节点对象都有这个属性，代表了节点里的HTML文本  

通过这个属性可以查看节点包含的HTML文本或修改其HTML文本  

		document.body.innerHTML = "<p>嘿嘿，我怕是新的body内容</p>"

#### 查找节点  

`document.getElementById()`使用节点的id属性查找节点  

因为在HTML中id是唯一，故可作为查询条件  

如果找不到，则返回null; 否额，返回节点对象  

DOM还有个`document.getElementsByName()`  方法，使用标签的name属性，查找标签  
因为name可以有相同的，所以返回的是一个数组  

`document.getElementsByTagName()` 同理，使用标签名  

#### 创建节点  

`document.createElement()`用于创建HTML节点  
`document.createTextNode()`用于创建文本块节点  

		var pa = document.createElement("p");
		var text = document.createTextNode("我是一个段落");
		pa.appendChild(text);		//为p节点创建了文本  
		document.body.appendChild(pa); 		//把p节点添加到body节点下

###### 节点创建辅助函数

		function dom(name, attr_array, /*,child...*/) {

			var node = document.createElement(name);
			//设置属性
			if (attr_array) {
				for(var i=0; i<attr_array.length; i++)
					node.setAttribute(attr_array[i])
			}
			//假如child是字符串，则作为标签的文本内容 
			//假如child不是字符串，当做子节点来添加
			for (var i=2; i < arguments.length; i++) {

				var child = arguments[i];
				if (typeof child == "string")
					child = document.createTextNode(child);
				node.appendChild(child);
			}
		}
#### 访问和设置属性  

大多数属性可以直接作为DOM节点的属性来操作  

但也可以使用`setAttribute()`和`getAttribute()`来设置和获取属性  
这是比较通用的方法  

#### 移动节点  

* 把node添加在newnode之前  

		node.parentNode.insertBefore(newnode, node)

* 把node添加在newnode之前  

		node.parentNode.replaceChild(newnode, node)`  

* 把node从其父节点删除  

		node.parentNode.removeNode(node)


#### className属性  

使用此属性为节点设置css类，来改变样式  

#### 样式属性  

每个DOM节点都有一个style属性，用于操作该节点的样式  

		node.style.borderWidth="10px"
在样式表中，单词使用连字符分割的(border-width),但在js中，用大写字母来区分不同单词  

##### 隐藏节点  

节点消失  

	node.style.display = "none"		

节点出现  

	node.style.display = ""

##### 控制节点大小  

	node.style.width = "400px"
	node.style.height = "200px"


##### 一个让节点旋转的例子  

		node.style.position = "absolute";
		var angle = 0;
		setInterval(function(){
			angle += 0.1;
			node.style.left = (100 + 100 + Math.cos(angle)) + "px";
			node.style.top = (100 + 100 + Math.sin(angle)) + "px";

			}, 100);

node以每秒10次的频率改变坐标  


