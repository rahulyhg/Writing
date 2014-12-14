## 微博分享
1. 在HTML标签中增加XML命名空间
2. 在HEAD头中引入WB.JS

		<script src="http://tjs.sjs.sinajs.cn/open/api/js/wb.js" type="text/javascript" charset="utf-8"></script>

3. 在需要部署微博发布器的位置粘贴WBML代码

		<wb:share-button addition="simple" type="button" language="zh_cn"></wb:share-button>
以上代码定制了一个按钮形状，简洁风格，关联帐号为空，预置文案为页面标题，预置图片为空，启用抓图服务，语言设置为简体中文的一个新浪微薄分享效果  

下面我具体讲讲第3条的WBML代码的参数设置 
## WBML代码参数解析
1. 分享的样式:按钮(`type="button"`)和图标(`type = "icon"`)
2. 分享的复杂版本:  

		addition="simple"	简洁版  
		addition="number"	数字版  
		addition="text"		文字版  
		addition="full"		完整版  
3. 预置文案：假如你需要预置分享的内容，那么这样做 

		default_text="Here is sina share"	
如果你只需要获取当前分享页的页面标题，那么就不要添加`default_text`这个属性  

4. 预置图片：假如你想预置几张用来分享的图片，那么这样做  

		pic="picture1||picture2||picture3" 	
之所以只写三个，那是因为最多课添加3张  
听说可使用wbml image属性定义来预置更多图片  

5. 抓图服务：抓取当前页面的图片用来分享  
假如不想抓取当前页面的图片，可以这样做  

		picture_search=false
默认是开启的，我们不用刻意去添加`picture_search`属性  

5. 语言设置：  

		language="zh_cn"		简体中文
		language="zh_tw"		繁体中文



