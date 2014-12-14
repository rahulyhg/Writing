## 包含多个文件 
* PHP 中有4个用于外部文件的函数:`include()`,`include_once()`,`require()`,`require_once()`   
* `include*`系列函数执行失败时，会打印出一个警告  
* `require*`系列函数执行失败时，就会打印出一个错误  
* `*once`系列函数保证处理的文件只会被包含一次，而不管脚本可能试图包含多少次  
* 在`/etc/php5/apache2/php.ini`配置文件中,可以调整`include_path`设置，它指示是否允许PHP检索包含文件  
* 包含敏感信息(如数据库访问)的任何包含文件都应该存储在Web文档目录外部，氏得不能在Web浏览器内查看它  
* 

## 注意连接数据库时的两种编程风格  
* 面向对象  
	
		<?php
		$mysqli = new mysqli("localhost", "my_user", "my_password", "world");

		/* check connection */
		if (mysqli_connect_errno()) {
			printf("Connect failed: %s\n", mysqli_connect_error());
			exit();
		}

		$mysqli->query("CREATE TEMPORARY TABLE myCity LIKE City");

		$city = "'s Hertogenbosch";

		/* this query will fail, cause we didn't escape $city */
		if (!$mysqli->query("INSERT into myCity (Name) VALUES ('$city')")) {
		    printf("Error: %s\n", $mysqli->sqlstate);
		}

		$city = $mysqli->real_escape_string($city);

		/* this query with escaped $city will work */
		if ($mysqli->query("INSERT into myCity (Name) VALUES ('$city')")) {
		    printf("%d Row inserted.\n", $mysqli->affected_rows);
		}

		$mysqli->close();
		?>	
* 面向过程

		<?php
		$link = mysqli_connect("localhost", "my_user", "my_password", "world");

		/* check connection */
		if (mysqli_connect_errno()) {
		    printf("Connect failed: %s\n", mysqli_connect_error());
		    exit();
		}

		mysqli_query($link, "CREATE TEMPORARY TABLE myCity LIKE City");

		$city = "'s Hertogenbosch";

		/* this query will fail, cause we didn't escape $city */
		if (!mysqli_query($link, "INSERT into myCity (Name) VALUES ('$city')")) {
		    printf("Error: %s\n", mysqli_sqlstate($link));
}

		$city = mysqli_real_escape_string($link, $city);

		/* this query with escaped $city will work */
		if (mysqli_query($link, "INSERT into myCity (Name) VALUES ('$city')")) {
		    printf("%d Row inserted.\n", mysqli_affected_rows($link));
}

		mysqli_close($link);
		?>

## 文件上传  
### 检测Apache服务器的配置  
* php.ini中的`file_uploads`是否打开，需要设置为`on`  
* `upload_max_filesize`, 默认2M  
* `post_max_size`， 默认8M  
* 

### Php中的绝对路径  
当在Php中使用绝对路径的时候，`/`指的是系统路径，而不是Web服务器所指定的工作路径  

