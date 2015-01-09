
### 关于外置蓝牙  

当你的本本并没有蓝牙时，你可能需要外置蓝牙来提供蓝牙服务  

当使用外置蓝牙，往往在电脑开机后出现蓝牙管理器无法管理的工作  
这时你需要重启蓝牙服务  

#### 重启蓝牙服务

两种方案  

	热插拔  

或者  

	$ sudo /etc/init.d/bluetooth restart  

#### 重新连接蓝牙  

当你电脑重启，蓝牙服务运行正常，也显示你的设备与电脑建立蓝牙  
但是你的设备依旧无法使用，那么这样做:  

	点击蓝牙管理器，关闭已经建立的连接  
	重新开启的你的设备进入蓝牙搜索状态  
	等一会儿，会自动接入电脑的蓝牙服务  

### 蓝牙配置工具hciconfig

#### 查看本机的蓝牙适配器  

使用下面这个命令可以查看本机所有蓝牙设备的状态  

	$ hciconfig 
	hci0:	Type: BR/EDR  Bus: USB
	BD Address: 00:15:83:0C:BF:EB  ACL MTU: 339:8  SCO MTU: 128:2
	UP RUNNING PSCAN ISCAN 
	RX bytes:178388 acl:9473 sco:0 events:1173 errors:0
	TX bytes:6192 acl:317 sco:0 commands:305 errors:0

#### 激活你的蓝牙适配器  

假如你使用hciconfig看到蓝牙适配器为`DOWN`,那么你需要
	
	$ hciconfig hci0 up

#### 蓝牙设备的默认配置文件  

`/etc/bluetooth`下存储的是蓝牙设备的默认存储文件  

### 蓝牙连接的配置工具hcitool 

#### 显示local蓝牙设备  

	$ hcitool dev  
	Devices:
		hci0	00:15:83:0C:BF:EB

#### 显示remote蓝牙设备  

显示remote设备的地址，时钟偏移和设备类:  

	$ hcitool inq  

显示remote设备的设备名和地址:  

	$ hcitool scan  

根据地址打印蓝牙设备的名字:  

	$ hcitool name <bdaddr>  

根据地址打印蓝牙设备的详细信息:  

	$ sudo hcitool info <bdaddr>  

#### 显示活跃的蓝牙连接  

什么叫活跃的蓝牙连接呢？  
就是你的蓝牙设备已经与蓝牙适配器连接，并能很好的工作  
比如你可以使用蓝牙键盘操纵你的电脑了，你可以和你的手机进行文件传送了  

通过下面这个命令，可以查看活跃的蓝牙连接了  

	$ hcitool con

