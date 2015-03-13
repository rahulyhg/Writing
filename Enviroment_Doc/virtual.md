### 主机和虚拟机  
#### 主机(Host 宿主机)  
可以看得见摸得着的物理计算机  
因为虚拟机位于其上构建，故也称为宿主机  

#### 虚拟机(Guest 客户机)  
通过VBox虚拟出来的一台模拟计算机，不是真实存在，但又可以可以像一台真正计算机来使用  
它"寄生"于Host内，故也称其为客户机  

#### Host和Guest的猫腻  
Guest的硬件系统是由软件模拟出来的，在创建的过程中，选择完要安装的OS之后，一路默认，可以创建一个标准型号设备;当然，也可以根据你的choice进行定制相应硬件参数(内存，硬盘等)  

虚拟机的性能弱于主机，其内存设置必须小于主机内存，其硬盘大小也受主机硬盘空闲分区大小影响  

虚拟机崩溃后不影响主机，应此可用虚拟机来测试软件、研究病毒、模拟网络功能等  
用VBox软件新建一台虚拟机后，仅仅是"买了"台没有软件系统的裸机，那么如果你想正常使用的话，还需要给这台裸机装上相应OS  
OS的安装就和一台真正的计算机差不多，甚至更简单   

##### 简单的嵌套模型  
Host-->VBox软件-->Guest  
一般情况下，Host和Guest都指的是一台具有完整软件系统的计算机,而不仅仅是裸机  

### Guest Additions and Extension Pack  
<body>
	<tr>
		<th>VBox Guest Additions</th>
		<th>VBox Extension Pack</th>
	</tr>
	<tr>
		<td>Guest增强包(功能扩展包)</td>
		<td>扩展增强包</td>
	</tr>
	<tr>
		<td>Guest内，为虚拟机安装</td>
		<td>Host主机内，为VBox软件安装</td>
	</tr>
	<tr>
		<td>Guest Additions中的Additions是复数<br>指的是读哦个软件包的集合</td>
		<td>Extension Pack中的Pack是单数，表示每一个扩展包都是针对一个特定功能的扩展<br>
		如果写成Extension Packs,则是指好几个，一堆的Extension Pack <br>
		可以通过VBox管理器去查看当前已经安装了哪些功能增强包	
		</td>
	</tr>
	<tr>
		<td>启动Guest,点击菜单栏的Devices->Insert Guest Additions CD <br>
		或者按Host+D键
		</td>
		<td>
			下载相应扩展包，切换到VBox,点击菜单栏的File->PreFerences,然后在弹出的新窗口选择Extensions,添加扩展包
		</td>
	</tr>
</body>

GuestAdditions主要作用是为了增加：共享文件夹，剪贴板共享,无缝窗口，3D虚拟化显示。  

### VirtualBox的Guest Additions  
获取Guest Additons当前版本  

	$ VBoxControl getversion
Windows下这个命令的位置:C:\Program Files\Sun\xVM VirtualBox Guest Additions  
VirtualBox命令怎在跨平台的时候是相同的  

### VBox支持的虚拟磁盘映像  
VBox支持六种磁盘映像格式：VDI、VMDK、VHD、HDD、QED、QCOW  
其中，QED(QEMU enhanced disk)、QEMU(QEMU Copy-On-Write)并不常见  
#### VDI(VirtualBox Disk Image)
这是VBox自己的虚拟磁盘映像格式  

#### VMFK(Virtual Machine Disk)
一种比较流行的虚拟机磁盘映像，VMvare Workstation这款虚拟机软件就用的是这个格式  

#### VHD(Virtual Hard Disk)
微软自己开发的虚拟机Virtual	 PC的VHD格式  
在Windows7中我们可以通过磁盘管理器按照向导轻松创建VHD  

##### VHD文件类型  
VHD虚拟磁盘有四种类型，我们可以根据自己的实际需要去选择相应格式  
Windows7中只有固定VHD和动态VHD两种类型  

* 固定VHD：对已经分配的大小不会更改  
* 动态VHD：大小与写入的数据大小相同，并随着数据增加而增大(直至上限)  
* 差异VHD：与动态VHD类似，但只包含父VHD修改后的磁盘块  
* 链接硬盘VHD：文件本身指向一个磁盘或者一个分区	  

这么详细介绍VHD,当然是因为它有很多优点:  
1. 维护简单  
VHD磁盘操作时就跟物理磁盘一样，维护起来较为简单，我们可以对它进行分区、格式化、压缩、删除等等操作，这些操作并不影响物理分区。这种操作更有利于初学者反复试验分区、格式等功能。  

2. 像U盘一样加载自如  
当你对VHD分区写入一些重要数据后，并不想他人修改其中的内容时，我们可以随时将此VHD进行脱机或分离操作，在需要的时侯再将它附加进来修改。同样可以向U盘一样从“安全删除硬件并弹出媒体”中弹出某个VHD。  

3. 轻松备份  
备份时我们仅仅需要将创建的VHD文件进行备份，它所包含的分区中所内容便被统一备份，当然我们也可以用备份工具将VHD文件所在的整个物理分区进行备份，这样不用说VHD分区中的内容也被纳入其中了。（其实Windows7和Windows2008的Backup工具备份产生的主文件也是VHD格式）  

4. 迁移方便  
当我们有一个VHD文件需要在多台计算机上使用时，我们只要先将此VHD分离开来，将其复制到目的计算机上，再进行附加上去即可。同时我们可以通过服务器进行分发，使用脚本将其附加到目的机。当然在物理机与虚拟机之间迁移也是没问题的。  

5. 与虚拟机互相通用  
Windows7和Windows2008R2的VHD文件与VPC、Hyper-V的虚拟硬盘是互通的，我们可以将虚拟机中的VHD文件附加到Windows7和Windows2008R2中。反过来Windows7和Windows2008R2中的VHD在分离后也可以挂载到VPC和Hyper-V中。  

6. 可直接用于系统部署  
我们可以使用Imagex工具将已经捕获的映像释放到此放，或通过WDS服务器部署系统到VHD。  

7. 双重的安全保护  
由于VHD创建时产生的是一个存储文件，在这里我们便可以对此文件和VHD的分区进行不同的权限限制，这样即可以对分区读写权限进行设置保证部分人员有往VHD分区中存储数据的权限，也可以对此VHD文件设置读写权限保证此文件在分离后不被他人给删除。  
##### 原生VHD启动(Native VHD Boot)
指物理计算机安装和启动的操作系统包含在VHD中。  
Windows7企业版和旗舰版及Windows8专业版以及WindowsServer2008的R2支持这种方式。  
适合用于体验多系统而又无需单独分区或者安装虚拟机。  

VHD启动需要依赖一下几点：  
* 磁盘上至少有2个分区：一个是作为启动的，另一个是用来存放文件的(不要加密)  
* 包含VHD文件的分区必须拥有足够大的可用空间。  
**待续**  

#### HDD(Parallels Hard Disk)
MAC上比较有名的虚拟机Parallels所支持的格式  

#### 格式转换  
VirtualBox提供了VBoxManager用来转换格式  
Windows和Linux命令相同  

* VMDK into VDI  

		$ VBoxManager clonehd from.vmdk into.vdi --format VDI

* VDI into VMDK  

		$ VBoxManager clonehd from.vdik into.vmdk --format VMDK  

* VDI into VHD  

		$ VBoxManager clonehd from.vdi into.vhd --format VHD 
运行完命令，原文件并不会删除  

#### 虚拟磁盘分配类型  
* 动态分配(Dynamically allocated)：使用时才占空间，占用空间较少，但运行比较慢  
* 固定大小(Fixed Size)：一次性分配，分配时占用时间较长，单运行较快  

### VBox网络连接  
一张表展示VBox集中网络连接的效果  
<table>
	<tr>
		<th></th>
		<th>NAT</th>
		<th>Bridged Adapter</th>
		<th>Internal</th>
		<th>Host-only Adapter</th>
	</tr>
	<tr>
		<th>虚拟机->主机</th>
		<td>ok</td>
		<td>ok</td>
		<td>no</td>
		<td>默认不能设置</td>
	</tr>
	<tr>
		<th>主机->虚拟机</th>
		<td>no</td>
		<td>ok</td>
		<td>no</td>
		<td>默认不能设置</td>
	</tr>
	<tr>
		<th>虚拟机->其他主机</th>
		<td>ok</td>
		<td>ok</td>
		<td>no</td>
		<td>默认不能设置</td>
	</tr>
	<tr>
		<th>其他主机->虚拟机</th>
		<td>no</td>
		<td>ok</td>
		<td>no</td>
		<td>默认不能设置</td>
	</tr>
	<tr>
		<th>虚拟机之间</th>
		<td>no</td>
		<td>ok</td>
		<td>同网络名下可以</td>
		<td>ok</td>
	</tr>
</table>

NAT方式的图形示意：  
![NAT网络连接](http://hiphotos.baidu.com/exp/pic/item/d57e9994a4c27d1e956b65de19d5ad6eddc4381f.jpg)  
这种方式下，虚拟机的网卡连接到宿主的 VMnet8 上。此时系统的 VMWare NAT Service 服务就充当了路由器的作用，负责将虚拟机发到 VMnet8的包进行地址转换之后发到实际的网络上，再将实际网络上返回的包进行地址转换后通过 VMnet8 发送给虚拟机。  
VMWare DHCP Service 负责为虚拟机提供 DHCP 服务。

Bridged方式的图形示意：  
![Bridged网络连接](http://hiphotos.baidu.com/exp/pic/item/e865a699a9014c08fd8876bf087b02087bf4f43e.jpg)  
这种方式下，虚拟机就像一台真正的计算机一样，直接连接到实际的网络上，与宿主机没有任何联系  
它是通过主机网卡，架设了一条桥，直接连入到网络中了  
因此，它使得虚拟机能被分配到一个网络中独立的IP，所有网络功能完全和在网络中的真实机器一样。
网桥模式下的虚拟机，你把它认为是真实计算机就行了。

其他方式用的不多，就暂且不管  

关于VBox网络连接，可以参考[http://jingyan.baidu.com/article/9f7e7ec04f73c66f28155484.html](http://jingyan.baidu.com/article/9f7e7ec04f73c66f28155484.html)  

### 虚拟机与主机的通讯  
这里的通讯指的是：文件交换,信息交换    
介绍3种方式:共享文件夹，使用U盘，双向共享粘帖板、拖放    

#### 共享文件夹（推荐）  
共享，就是在主机中创建或选择一个文件夹让虚拟机和主机共同使用  
在此之前，若是共享不能使用，请首先安装*Guest Additions*  

右键点击Vbox的右下角从左至右的第5个形如文件夹的图标或者[Decices]->[Share Folders Settings ...]->[Share Folders]  

接着单击右边的加号，在弹出的面板中：  
* [Folder Path] :设置主机要共享的文件夹的实际位置  
* [Folder Name] :设置共享文件夹的名字，用以在Guest中进行访问  
* [Read-Only] : 设置访问权限,一般情况下不选择  
* [Make-mount] : 自动挂载，选择    
* [Make Permannet] : 设置永久共享，选择; 若只是临时共享，那么就不选择  

Okay,Windows(Guest)下通过网上邻居访问，或者使用映射网络驱动器的办法：  

	[右键计算机]->[映射网络驱动器]  
	在[驱动器]选项设置驱动器盘符，在[文件夹]设置要要硬射的共享文件夹  
	单击[完成],好了，可以打开[计算机]像访问其他分区一样访问了  

Linux(Guest)下，假如共享文件夹名为*share_folder*,那么在Guest里将自动挂载共享文件夹为*/media/sf_share_folder*，此时，你没有访问权限，因此需要获取root权限或者使用假如*vboxsf* 组，使用：  

	$ sudo adduser username vboxsf  
好了你可以访问了  

官方文档中这样解释Linux下的手动挂载：  
若是没有自动挂载，请手动挂载  

	$ sudo mkdir /mnt/shared
	$ sudo mount -t vboxsf share_folder /mnt/shared  
*share_folder*就是在虚拟机中设置的共享文件夹名  
*/mnt/shared*就是我们要把共享文件夹挂载在Guest上的路径  
若是自动挂载，请在*/etc/rc.local*的exit之前添加:`sudo mount -t vboxsf share_folder /mnt/shared `  

但是我们没有成功  
参考链接：[http://www.crifan.com/summary_virtualbox_how_to_drap_and_drop_file_between_host_and_guest_vm/comment-page-1/](http://www.crifan.com/summary_virtualbox_how_to_drap_and_drop_file_between_host_and_guest_vm/comment-page-1/)  

[官方文档](http://dlc.sun.com.edgesuite.net/virtualbox/4.3.14/UserManual.pdf)  

#### 使用U盘进行共享  
首先，请确保安装*VBox Extension Pack*（Linux/Windows）  

然后，Linux用户请将用户添加到*vboxusers*组，才能访问USB设备:  

	$ sudo adduser username vboxusers  

最后，重启服务(Linux/windows)    

#### 双向共享粘帖板、拖放 
首先，请确保安装*VBox Extension Pack*（Linux/Windows）  

然后在Guest中开启Shared Clipboard 和 Drag'n'Drop为*Bidirectional(双向)*

最后，必要的话，请重启服务  

### snapshot(快照)
Snapshots：系统快照，保存虚拟系统在某一时刻的全部运行状态，以后可以将虚拟系统恢复到创建此快照时的状态。在VirtualBox中文版中，snapshots被翻译成“备份”  

使用虚拟机最方便的一点是可以随时备份系统状态（创建快照），然后就可以放心地折腾了，即使把虚拟系统搞坏了也可以随时恢复到备份时的状态，甚至是正在运行中的状态，比“一键还原”还方便

其实，这个功能应该被称之为Branched spanshots(分支快照)，过去所谓的snapshot，只能恢复到最近一个的snapshot，如果要恢复到更久以前的snapshot，得先删除最近的snapshot才行；而Branched spanshots，可以将虚拟系统直接恢复到任意时间的snapshot，并且保留最近的snapshot，当修改了过去snapshot的状态后，可以在原有的snapshot时间线上创建一个分支，并且可以随时在不同分支上继续运行系统。

在VBox的软件界面，可以选中要操作的Guest,然后单击菜单栏右边的Snapshots  
接着，你就可以查看当前Fuest所有的Snapshot,并对他进行操作了  

对了，回复Snapshot需要在Guest关闭之后才可以  



## Ubuntu下安装VirtualBox

	$ sudo apt-get install virtualbox
	$ sudo apt-get install dpkg-dev debhelper virtualbox-guest-additions-iso vde2


---  
		2015-03-13 17:17:08  

## virtualbox命令行工具的使用  

* 列举当前虚拟机  

		$ VBoxManage list vms

* 使用VRDP方式启动虚拟机  

		$ VBoxManage startvm ubuntu -type vrdp

* 使用Headless启动无前端界面方式  

		$ VBoxHeadless -startvm ubuntu

* 查看虚拟机的运行状态  

		$ VBoxManage list runningvms



lszsz --windows下使用远程登录工具链接linux，可以使用其快速的传送文件 

rz 
sz 
