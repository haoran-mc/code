<%@ page contentType="text/html; charset=gb2312" isErrorPage="true"%>
<html>
	<body>
		<% //此页面会会处理pageTest2.jsp抛出的异常
		    //友好地显示错误信息
			out.println("网页出现数学运算异常!");
		%>
	</body>
</html>
