
确定物理内存和交换内存所有可用空间是很重要的  

Linux为此提供了一个命令:`free`  
它可以给出操作系统中物理内存和交换内存的总使用量、可用量及内核使用的缓冲区情况  


1. 显示你的系统内存  

		$ free
					total       used       free     shared    buffers     cached
		Mem:       4023716    2885916    1137800      48636      29864     532024
		-/+ buffers/cache:    2324028    1699688
		Swap:      8363004      46268    8316736

2. 以b,Kb,Mb,Gb字节为单位显示内存  

		$ free -b
		$ free -k
		$ free -m
		$ free -g

3. 显示Total行  

		$ free -t
			         total       used       free     shared    buffers     cached
		Mem:       4023716    2901564    1122152      55400      30556     540784
		-/+ buffers/cache:    2330224    1693492
		Swap:      8363004      46268    8316736
		Total:    12386720    2947832    9438888

加上-t选项，将会在屏幕最后列出总计一行  

4. 关闭显示buffer adjusted行  

	$ free -o
					total       used       free     shared    buffers     cached
		Mem:       4023716    2905224    1118492      55400      30956     542164
		Swap:      8363004      46268    8316736

默认情况下，free命令会显示`buffer adjusted`一行，加上`-o`则可以关闭显示  

5. 定时刷新内存状态  

		$ free -s 5

每隔5s，自动重新执行free命令  

`-s`参数，用来设置时间间隔，默认是以秒为单位  

6. 显示低高内存统计信息  

		$ free -l

7. 使用1000来替换1024作为容量换算单位  

		$ free -h
					 total       used       free     shared    buffers     cached
		Mem:          3.8G       2.8G       1.0G        51M        31M       528M
		-/+ buffers/cache:       2.3G       1.6G
		Swap:         8.0G        45M       7.9G
		
		$ free --si -h
		             total       used       free     shared    buffers     cached
		Mem:          4.0G       2.9G       1.1G        52M        32M       541M
		-/+ buffers/cache:       2.4G       1.7G
		Swap:         8.4G        46M       8.3G

`--si`使用1000作为容量换算单位  


