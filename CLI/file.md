
Linux系统并不要求文件名来反映文件的内容，就像世界之大，叫liluo的人多。但不总指我一样  

虽然系统没有要求，但是我们尽可能**用不同的文件名后缀反映文件的类型，不用的文件名来反映文件的内容**，这方便我们日常对文件的使用和检索:  

1. 某些应用需要使用指定类型的文件，而往往通过文件后缀来指定相应类型文件  
2. 某些应用的配置文件被放在指定路径读取，我们尽可能避免取一样名字  

3. 我们使用计算机时，看到文件名，脑海中自然而然呈现文件的类型和这个文件包含什么，这是非常有益的  


当然，有的情况下，我们的确并不能从文件名获知其类型  

但是，不用担心，Linux为我们提供一个`file`的工具  

这个工具会显示指定文件的类型的详细信息  

	$ file /bin/ls
	/bin/ls: ELF 64-bit LSB  executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=64d095bc6589dd4bfbf1c6d62ae985385965461b, stripped


