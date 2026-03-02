<%@ page language="java" contentType="text/html; charset=gb2312"%>
<html>
	<body>
	欢迎登录学生管理系统
	<script type="text/javascript">
		function validate(){
			if(loginForm.account.value==""){
				alert("账号不能为空!");
				return;
			}
			if(loginForm.password.value==""){
				alert("密码不能为空!");
				return;
			}
			loginForm.submit();
		}
	</script>
	<form name="loginForm" action="target.jsp " method="post">
		请您输入账号：<input name="account" type="text"><BR>
		请您输入密码：<input name="password" type="password"><BR>
		<input type="button" value="登录" onClick="validate()">	
	</form>
	</body>
</html>
