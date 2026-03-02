<%@ page language="java" contentType="text/html; charset=gb2312"%>
<html>
	<body> 
	请您输入自己的信息进行注册 
	<form action="selectForm_result.jsp" method="post">
		请您输入账号：<input name="account" type="text"><BR>
		请您输入密码：<input name="password" type="password"><BR>
		请您选择家乡：
		<select name="home">
			<option value="beijing">北京</option>
			<option value="shanghai">上海</option>
			<option value="guangdong">广东</option>
		</select>	
		<input type="submit" value="注册">
	</form>
	</body>
</html>

