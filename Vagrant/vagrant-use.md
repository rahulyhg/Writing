

### 命令  

1. 创建一个项目目录  


		$ mkdir vagrant

2. 查看当前系统内可用的 box   


		$ vagrant box list
		hashicorp/connect-vm    (virtualbox, 0.1.0)
		hashicorp/precise32     (virtualbox, 1.0.0)
		ubuntu_server_14-04_x64 (virtualbox, 0)
		ubuntu_server_14-04_x86 (virtualbox, 0)
	
	上面这些 box 就相当于系统镜像，可以被你用来初始化你的项目，即可以以其中一个创建你的虚拟机  

3. 指定一个box, 初始化你的项目  

		vagrant $ vagrant init ubuntu_server_14-04_x64

	当初始化成功，目录会有一个名为 `Vagrantfile` 的文件   
	此文件就是你项目配置文件，当启动虚拟机的时候会加载  

4. 启动你的项目，即启动虚拟机  

		vagrant $ vagrant up
		
5. 通过 ssh 访问你的项目机器  

		vagrant $ vagrant ssh
	
6. 关闭虚拟机  

		vagrant $ vagrant halt

7. 虚拟机休眠  

		vagrant $ vagrant suspend

8. 重启虚拟机  

		vagrant $ vagrant reload

9. 删除虚拟机，但是之前的 box 还存在  

		vagrant $ vagrant destroy

