两个文件a.log和range.log  
a.log的数据是这样的:  
192.168.0.1,3,4,6
122.168.0.1,3,4,6
152.168.0.1,3,4,6
162.168.0.1,3,5,6
162.168.0.1,3,4,6
...
大概一百万条  
range.log的数据是这样的  
192.0.0.1-192.168.23.74
192.168.22.1-192.168.23.74
192.0.0.1-255.168.23.74
...
大概100条  
请找处a.log中的每行数据中的第一字段ip在range.log中每行的ip范围出现的次数  
例如192.168.0.1在192.168.0.-192.168.23.74中，那么+1  
统计次数，并一一列举出来  

