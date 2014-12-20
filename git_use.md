## 比较缓存区文件和已修改但尚未缓存文件之间的差别

	git diff
'-'表示已缓存的文件  
'+'表示已经修改但尚未缓存的文件  
假如存在缓冲区文件，比较缓冲区和已经修改但尚未缓存  
假如不存在，比较快照和已经修改的文件  
否则，无结果

## 比较缓存区文件和上次的快照(即上次已提交文件)之间的差异  

	git diff --cached	或者	git diff --staged
'-'表示快照文件  
'+'表示已缓存的文件  

## 删除工作目录中文件和缓存中的文件

	git rm file
commit之后，file不在纳入以后的版本管理  

## 仅仅删除缓存中文件  

	git rm --cached file  

## 自动缓存并提交所有已修改和删除的文件

	git commit -a 
这里的所有指的是之前纳入版本管理的文件和git add的新文件  
删除的文件，之后不会在纳入版本管理  