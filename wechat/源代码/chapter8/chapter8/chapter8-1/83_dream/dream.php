<?php
/*
【版权声明】
    本软件产品的版权归方倍工作室所有，受《中华人民共和国计算机软件保护条例》等知识产权法律及国际条约与惯例的保护。您获得的只是本软件的使用权。

    您不得:
    * 在未得到授权的情况下删除、修改本软件及其他副本上一切关于版权的信息；
    * 销售、出租此软件产品的任何部分；
    * 从事其他侵害本软件版权的行为。

    如果您未遵守本条款的任一约定，方倍工作室有权立即终止本条款的执行，且您必须立即终止使用本软件并销毁本软件产品的任何副本。这项要求对各种拷贝形式有效。

    您同意承担使用本软件产品的风险，在适用法律允许的最大范围内，方倍工作室在任何情况下不就因使用或不能使用本软件产品所发生的特殊的、意外的、非直接或间接的损失承担赔偿责任。即使已事先被告知该损害发生的可能性。

    如使用本软件所添加的任何信息，发生版权纠纷，方倍工作室不承担任何责任。

    方倍工作室对本条款拥有最终解释权。

    CopyRight 2013  方倍工作室  All Rights Reserved

*/

function getDreamInfo($content)
{
    if ($content == ""){
        return "梦见什么？";
    }
    
    if(isset($_SERVER['HTTP_APPNAME'])){        //SAE
        $mysql_host = SAE_MYSQL_HOST_M;
        $mysql_host_s = SAE_MYSQL_HOST_S;
        $mysql_port = SAE_MYSQL_PORT;
        $mysql_user = SAE_MYSQL_USER;
        $mysql_password = SAE_MYSQL_PASS;
        $mysql_database = SAE_MYSQL_DB;
    }else{
        $mysql_host = "127.0.0.1";
        $mysql_host_s = "127.0.0.1";
        $mysql_port = "3306";
        $mysql_user = "root";
        $mysql_password = "root";
        $mysql_database = "weixin";
    }
	
	$mysql_table = "dream";
	$mysql_state = "SELECT * FROM `".$mysql_table."` WHERE `title` LIKE '%".$content."%'";
    $con = mysql_connect($mysql_host_s.':'.$mysql_port, $mysql_user, $mysql_password);
	if (!$con){
		die('Could not connect: ' . mysql_error());
	}
	
	mysql_query("SET NAMES 'UTF8'");
	mysql_select_db($mysql_database, $con);
	$result = mysql_query($mysql_state);
	$contentStr = "周公睡觉去了";
    while($row = mysql_fetch_array($result))
    {
		if (isset($row["content"]) && ($row["content"] != "")){
			$contentStr = $row["content"];
		}
        break;
	}
    mysql_close($con);
    return $contentStr;
}

?>