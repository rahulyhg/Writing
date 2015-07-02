
vagrant利用已有的虚拟机软件，使用给定的镜像，快速新建一个virtual machine  

这里的镜像是打包好的操作系统，在Vagrant中被称作box，体积小，制作快捷，因此，更方便转移  

vagrant默认使用的虚拟机软件是VirtualBox，但是并不局限于它，还可以使用其他providers：VMware,AWS,parallel...

## 安装vagrant

首先应安装一个虚拟机,VirtualBox是一个不错的选择(*免费，跨平台*)  

> [https://www.virtualbox.org/wiki/Linux_Downloads](https://www.virtualbox.org/wiki/Linux_Downloads "Linux_VirtualBox下载页")

下载并安装Vagrant  

> [https://www.vagrantup.com/downloads.html](https://www.vagrantup.com/downloads.html "vagrant下载页")

请选择合适版本来适应你的平台(MAC OS/WINDOWS/LINUXx86/LINUXx64)  

## 添加box

在使用vagrant运行虚拟机之前，我们需要添加box:  

	$ vagrant box add {title} {url}
`{title}`: 为添加box在命名，方便vagrant管理  
`{url}`: 要添加的box地址，可以是网络地址，也可以是本机地址  
使用你自己的信息替换{title}和{utl}即可  

添加的box可以被多个项目重复使用，每一个Vagrant项目使用box作为初始镜像去克隆，从来不会修改实际的镜像  
这意味着你添加了一个box,命名为`Ubuntu-Server`  
假如你有两个项目都使用了`Ubuntu-Server`,即使你对guest machine增删改，也不会对其他机器造成影响  

可以下载打包相应系统的box,也可以自己制作box  

[Vagrant_Colud]: https://vagrantcloud.com/ "Vagrant Cloud"  

> [https://vagrantcloud.com/][Vagrant_Colud]

上面这个地址里有HashiCorp提供的box,Vagrant内置了从上面地址搜索下载指定box  

因此,想使用上面地址的box，只需要提供在[Vagrant Cloud][Vagrant_Colud]上发现的名字即可  
例如:  

	$ vagrant box add hashicorp/precise32
这样，就添加了一个名为`hashicorp/precise32`的box了  

根据`vagrant box add`命令的使用来说，应该可以在从[Vagrant Cloud][Vagrant_Colud]下载box的同时可以重新命名，但是我试了好久都没成功，报错:  

	The box you're adding has a name different from the name you
	requested. For boxes with metadata, you cannot override the name.
	If you're adding a box using `vagrant box add`, don't specify
	the `--name` parameter. If the box is being added via a Vagrantfile,
	change the `config.vm.box` value to match the name below.

	Requested name: abc
	Actual name: chef/centos-6.5
然后，我就茫然了...(知道原因的，请告知我一下)  

不过不用担心，只要你指定完整的url地址，就可以解决了，这些都是小问题  

提供几个box的下载地址:  
>[http://cloud-images.ubuntu.com/vagrant/](http://cloud-images.ubuntu.com/vagrant/ "Ubuntu-box下载页")  

>[http://www.vagrantbox.es/](http://www.vagrantbox.es/ "vagrant-box下载页")

不建议你使用命令行下载添加box,因为速度真得很慢，国外，你懂得...  
还是手动下载吧  

## vagrant简易使用

	$ mkdir ~/Vagrant
	$ cd ~/Vagrant
	$ vagrant box list		# 列出已经添加的box
	$ vagrant init hashicorp/precise32	# 初始化项目目录，生成项目配置文件Vagrantfile
	$ vagrant up	# 启动你的machine

通过以上几步，你可以初步建立一个vagrant项目  
然后你可以通过`vagrant ssh`访问你的被vagrant管理的machine了：可以安装软件，可以搭建服务...  


## Vagrant的命令  

### 虚拟机初始化，启动，关闭  

> $ vagrant init	# 初始化项目  
> $ vagrant up		# 启动machine  
> $ vagrant ssh		# ssh登录你的machine  
> $ vagrant halt	# 关闭你的machine  
> $ vagrant suspend # 休眠你的machine  
> $ vagrant reload	# 重启你的machine  
> $ vagrant destroy # 删除你的machine,但是box还在  
> $ vagrant package # 把现有的machine制作成box

### 虚拟机状况查看

> $ vagrant status	# 查看你的machine状态  
> $ vagrant global-status # 查看你的所有machine状态  

### box管理  

> $ vagrant box add boxname		# 添加box
> $ vagrant box list			# 列出现有的box
> $ vagrant box remove boxname	# 删除box

### 命令帮助  

> $ vagrant list-commands # 查看所有的命令
> $ vagrant COMMAND -h	# 查看单个命令的详细用法  


关于更多命令的使用[《官方文档--Command-Line Interface》](http://docs.vagrantup.com/v2/cli/index.htmlH6)  

## Vagrant的详细配置  

Vagrant怎么管理virtual machine呢？  
它是通过一个名为`Vagrantfile`的文件管理的  

### 关于Vagrantfile

`Vagrantfile`是每一个vagrant的项目配置文件  

每次当我们执行`vagrant init`时，都会自动生成  

如果这个项目目录已经存在`Vagrantfile`了，而且已经导入相应box，那么请运行`vagrant up`启动虚拟机  

`Vagrantfile`是使用vagrant的关键，是一个vagrant项目最重要的部分  

因此`Vagrantfile`内容的修改和添加，是非常必要的  

当vagrant项目需要迁移或者给团队其他人员同样的开发环境，只要打包你的虚拟机，然后把`Vagrantfile`和你制作的box发给其他人即可  


现在假设我们已经添加了一个box，命名为`Ubuntu-Server`  

### 指定box

打开`Vagrantfile`,编辑它为:  

	Vagrant.configure("2") do |config|
	  config.vm.box = "Ubuntu-Server"
	end

这里的2是配置文件版本号,Vagrant兼容旧版本  

### UP and SSH

启动virtual machine：`vagrant up`  
你看不到任何东西，除了一些字符的输出，因为vagrant运行machine,没有UI  

使用ssh进行访问machine，在项目目录下，运行`vagrant ssh`  

### Synced Folder

默认，你的项目目录将作为Vagrant管理的客户机的共享目录，将被挂载guest machine的`/vagrant`目录下  

### Automated Provisioning(自动化配置)

在机器启动的时候，做一些自动化配置工作，是一件有意义的事情  

Vagrant的自动化工作是在Vagrantfile中使用一个`machine.vm.provision`方法来完成  

Vagrant可以使用多种为机器配置的工具：简单的shell脚本到更复杂的配置管理系统(chef/puppet...)  


这里举个关于shell脚本配置的例子 

install_apache2.sh:  

	#!/bin/bash

	apt-get update
	apt-get install -y apache2

	mkdir -p /vagrant/www

	if ! [ -L /var/www/html ]; then
		rm -rf /var/www/html
		ln -fs /vagrant/www /var/www/html
	fi

	exit 0
	
Vagrantfile:  

	Vagrant.configure("2") do |config|
	  config.vm.box = "Ubuntu-Server"
	  config.vm.provision "shell", path: "install_apache2.sh"
	  config.vm.provision "shell" do |s|
		s.inline = "date & Provisioning end"
	  end
	end

Vagrantfile中指定的path是相对于主机Vagrant项目的根目录的  

当你使用`vagrant up --provision`时，将会安装apache2,并修改根目录为web目录，最后打印出配置结束时间  

#### provisioning执行的时机  

* 第一次使用`vagrant up`，才会执行provision,所以要想每次都执行provision,必须指定`--provision`选项  

* 使用`vagrant provision`来执行provision  

* 使用`vagrant reload --provision`

当然，也可以不执行provision,只需指定`--no-provision`  

以上仅仅是默认的情况,可以通过在配置文件中指定`run: "always"`,使每次运行虚拟机可以执行provision，而不必指定`--provision`  

关于更详细的自动化配置，请参考[《官方文档--Vagrant-Provisioning》](http://docs.vagrantup.com/v2/provisioning/index.html "Vagrant Provisioning")  

### networks  

端口转换(Forwarded Port):把宿主计算机的端口映射到虚拟机的某一个端口，访问宿主计算机端口时，请求实际是被转发到虚拟机的指定端口

私有网络(Private_Network):

假如配置自动分配IP(dhcp),可能出现下面错误:  

	A host only network interface you're attempting to configure via DHCP
	already has a conflicting host only adapter with DHCP enabled. The
	DHCP on this adapter is incompatible with the DHCP settings. Two
	host only network interfaces are not allowed to overlap, and each
	host only network interface can have only one DHCP server. Please
	reconfigure your host only network or remove the virtual machine
	using the other host only network.
解决方案请参考:  
> [https://github.com/mitchellh/vagrant/issues/3083](https://github.com/mitchellh/vagrant/issues/3083 "Vagrant private network by dhcp")  
> [https://github.com/Chassis/Chassis/wiki/dhcp-private_network-failing-on-VirtualBox](https://github.com/Chassis/Chassis/wiki/dhcp-private_network-failing-on-VirtualBox )

假如自定义私有IP，则需要注意你要使用保留地址中的地址，而且如果你使用的wifi,你的ip地址不能与路由器冲突  
关于私有IP地址查看:  
> [维基百科-私有IPv4地址空间](http://en.wikipedia.org/wiki/Private_network#Private_IPv4_address_spaces "维基百科-私有IPv4地址空间")  

## vagrant push

* 首先需要把Vagrantfile所在的目录使用git初始化:`git init`  
* 并做一次简单的提交: `git commit -m "init"`  
* 命令行登录ATLAS: `vagrant login`
* 最后，`vagrant push`即可,出现类似下面这个字样:  

		Uploaded liluo/test v1

如果出先错误  

		error starting upload: upload: resource not found
那么，你可以在在[https://atlas.hashicorp.com/settings/tokens](https://atlas.hashicorp.com/settings/tokens "ATLAS tokens页面")生成一个新的token  
并使用其替换`~/.vagrant.d/data/vagrant_login_token`  
ATLAS的token只有在第一次生成的时候可以看得到，因此，需要备份一下  

如果还是不可以，可能还需要这样:  

	export ATLAS_TOKEN=`cat ~/.vagrant.d/data/vagrant_login_token`  

## vagrant share
## 制作box

	$ vagrant package --base my-virtual-machine
Where "my-virtual-machine" is replaced by the name of the virtual machine in VirtualBox to package as a base box.  

It will take a few minutes, but after it is complete, a file "package.box" should be in your working directory which is the new base box. At this point, you've successfully created a base box!  

If you're not using vagrant package --base above, you'll have to set the config.vm.base_mac setting in this Vagrantfile to the MAC address of the NAT device without colons.  

## 遇到的问题及解决办法  

### 下载和添加box遇到得问题  

1. 访问无法到达，需要FQ  

	An error occurred while downloading the remote file. The error
	message, if any, is reproduced below. Please fix this error and try
	again.

	Failed connect to dl.dropboxusercontent.com:443; Connection timed out

2. 资源不能找到，需要重新更换资源  

	An error occurred while downloading the remote file. The error
	message, if any, is reproduced below. Please fix this error and try
	again.

	The requested URL returned error: 509 Bandwidth Error

