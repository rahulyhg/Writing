
## virtualbox与jekyll  

解决虚拟机中运行jekyll,外部机器不能访问问题？

`jekyll serve`默认监听的是`127.0.0.1:4000`,而这个地址是环回地址 
不能接受到外网的请求，因此，只要改变监听地址即可  
使用以下命令:  

	$jekyll serve -H 0.0.0.0 -P 4000

`-H`指定服务器的监听ip  
`-P`指定使用的端口  

对了，如果在virtualbox中使用NAT模式，那么需要做下port forward  


