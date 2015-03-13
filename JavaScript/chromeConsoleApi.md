

## 向chrome控制台输出文本  

chrome提供了访问控制台(console)的API  
由此，我们可以在枯燥的chrome控制台制造惊喜  

###  console下的输出API  

* console.log()  -- 输出正常的信息，黑色字体  

* console.warn() --  输出的文字前显示带感叹号的黄色三角警告符号,字的颜色是黑色的  

* console.erro() -- 输出的文字前显示带叉的红色圆形图标, 字体颜色是红色的    

这三个API的输出效果是可以改变，而且是通过你的样式  
由此，你可以输出3D效果的文字，输出七彩的颜色，甚至输出图片  
很酷!!!  


#### 输出格式

这几个API有特定的语法，就如C语言中的printf，有格式输出控制  


<table>
	<thead>
		<tr>
			<th>Formart Specifier</th>
			<th>Description</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>%s</td>
			<td>Formats the value as a string</td>
		</tr>
		<tr>
			<td>%d or %i</td>
			<td>Formats the value as a integer</td>
		</tr>
		<tr>
			<td>%f</td>
			<td>Formats the value as a floating point value</td>
		</tr>
		<tr>
			<td>%o</td>
			<td>Formats the value as an expandable DOM element(as in the Elements panel)</td>
		</tr>
		<tr>
			<td>%O</td>
			<td>Formats the value as a expandable JavaScript object</td>
		</tr>
		<tr>
			<td>%c</td>
			<td>Formats the output string according to CSS styles your provide</td>
		</tr>
	</tbody>
</table>

##### 代码示例  

1. 3D Text  

		console.log("%c3D Text"," text-shadow: 0 1px 0 #ccc,0 2px 0 #c9c9c9,0 3px 0 #bbb,0 4px 0 #b9b9b9,0 5px 0 #aaa,0 6px 1px rgba(0,0,0,.1),0 0 5px rgba(0,0,0,.1),0 1px 3px rgba(0,0,0,.3),0 3px 5px rgba(0,0,0,.2),0 5px 10px rgba(0,0,0,.25),0 10px 10px rgba(0,0,0,.2),0 20px 20px rgba(0,0,0,.15);font-size:5em")

2. Coloeful CSS  

		console.log("%cColorful CSS","background: rgba(252,234,187,1);background: -moz-linear-gradient(left, rgba(252,234,187,1) 0%, rgba(175,250,77,1) 12%, rgba(0,247,49,1) 28%, rgba(0,210,247,1) 39%,rgba(0,189,247,1) 51%, rgba(133,108,217,1) 64%, rgba(177,0,247,1) 78%, rgba(247,0,189,1) 87%, rgba(245,22,52,1) 100%);background: -webkit-gradient(left top, right top, color-stop(0%, rgba(252,234,187,1)), color-stop(12%, rgba(175,250,77,1)), color-stop(28%, rgba(0,247,49,1)), color-stop(39%, rgba(0,210,247,1)), color-stop(51%, rgba(0,189,247,1)), color-stop(64%, rgba(133,108,217,1)), color-stop(78%, rgba(177,0,247,1)), color-stop(87%, rgba(247,0,189,1)), color-stop(100%, rgba(245,22,52,1)));background: -webkit-linear-gradient(left, rgba(252,234,187,1) 0%, rgba(175,250,77,1) 12%, rgba(0,247,49,1) 28%, rgba(0,210,247,1) 39%, rgba(0,189,247,1) 51%, rgba(133,108,217,1) 64%, rgba(177,0,247,1) 78%, rgba(247,0,189,1) 87%, rgba(245,22,52,1) 100%);background: -o-linear-gradient(left, rgba(252,234,187,1) 0%, rgba(175,250,77,1) 12%, rgba(0,247,49,1) 28%, rgba(0,210,247,1) 39%, rgba(0,189,247,1) 51%, rgba(133,108,217,1) 64%, rgba(177,0,247,1) 78%, rgba(247,0,189,1) 87%, rgba(245,22,52,1) 100%);background: -ms-linear-gradient(left, rgba(252,234,187,1) 0%, rgba(175,250,77,1) 12%, rgba(0,247,49,1) 28%, rgba(0,210,247,1) 39%, rgba(0,189,247,1) 51%, rgba(133,108,217,1) 64%, rgba(177,0,247,1) 78%, rgba(247,0,189,1) 87%, rgba(245,22,52,1) 100%);background: linear-gradient(to right, rgba(252,234,187,1) 0%, rgba(175,250,77,1) 12%, rgba(0,247,49,1) 28%, rgba(0,210,247,1) 39%, rgba(0,189,247,1) 51%, rgba(133,108,217,1) 64%, rgba(177,0,247,1) 78%, rgba(247,0,189,1) 87%, rgba(245,22,52,1) 100%);filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#fceabb', endColorstr='#f51634', GradientType=1 );font-size:5em")

3. Rainbow Text  


		console.log('%cRainbow Text ', 'background-image:-webkit-gradient( linear, left top, right top, color-stop(0, #f22), color-stop(0.15, #f2f), color-stop(0.3, #22f), color-stop(0.45, #2ff), color-stop(0.6, #2f2),color-stop(0.75, #2f2), color-stop(0.9, #ff2), color-stop(1, #f22) );color:transparent;-webkit-background-clip: text;font-size:5em;');

4. cartoons  

		console.log("%c", "padding:80px 300px;line-height:200px;background:url('http://p0.so.qhimg.com/bdr/_240_/t0168e31adb7265cbe5.gif') no-repeat;");

---s

**参考链接**  

* [https://developer.chrome.com/devtools/docs/console-api](https://developer.chrome.com/devtools/docs/console-api "chrome console API")