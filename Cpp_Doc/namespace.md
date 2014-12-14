## 名字空间  
名字空间，这是C++用来避免相同名字定义的一种策略，就像相同名字的文件放在不同目录下一样  

名字空间除了系统定义的名字空间之外，还可以自己定义  

定义名字空间的关键字"namespace",使用名字空间需要符号"::"指定  

For Example:

	namespace na {
	
		void print(int n) {
			cout << "na::print"<<n<<endl;
		}
	}
我定义了一个名为"na"的名字空间,然后，我可以这样是用它：  

	na::print(3);  
假如我们在别的范围内引用此名字空间的东西，则需要这样：  

	using namespace na;
或者
	
	using  na::print;
	
