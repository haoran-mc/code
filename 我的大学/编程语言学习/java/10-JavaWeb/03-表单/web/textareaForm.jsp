<%@ page language="java" contentType="text/html; charset=gb2312"%>
<html>
	<body>
	请您输入自己的信息进行注册
	<form action="textareaForm_result.jsp" method="post">
		请您输入账号：<input name="account" type="text"><BR>
		请您输入密码：<input name="password" type="password"><BR>
		请您输入个人信息：<BR>
		<textarea name="info" rows="5" cols="30"></textarea>
		<input type="submit" value="注册">
	</form>
	</body>
</html>

