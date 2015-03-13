<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>字符串逆置-js</title>
        
    </head>
    <body>
        <script  type="text/javascript" >
             /*
            字符串反转
            */
            function reverse(str) {
                if (str.length == 0)
                    return str;
                else
                    return reverse(str.substring(1, str.length)) + str.substring(0, 1);
            }
            document.write(reverse("李宗妖子"));
            
        </script>
        
    </body>
</html>