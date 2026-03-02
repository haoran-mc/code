<%@ page contentType="text/html; charset=gb2312" 
errorPage="pageTest2_error.jsp"%>
<html>
	<body>
		<%//此页面会向pageTest2_error抛出异常，让其来处理
			int num1=10;
			int num2=0;
			int num3=num1/num2;
		%>
	</body>
</html>
