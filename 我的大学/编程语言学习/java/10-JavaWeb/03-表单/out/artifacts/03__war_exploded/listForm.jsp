<%@ page language="java" contentType="text/html; charset=gb2312"%>
<html>
	<body>  
	请您输入自己的信息进行注册  
	<form action="listForm_result.jsp" method="post">
		请您选择您的爱好：<BR>
		<select name="fav" multiple>
			<option value="sing">唱歌</option>
			<option value="dance">跳舞</option>
			<option value="ball">打球</option>
			<option value="game">打游戏</option>
		</select>
		<input type="submit" value="注册">
	</form>
	</body>
</html>

