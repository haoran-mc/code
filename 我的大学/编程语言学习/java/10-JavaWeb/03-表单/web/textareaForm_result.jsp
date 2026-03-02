<%@ page language="java" contentType="text/html; charset=gb2312"%>
<html>
	<body>
	<%
		String info = request.getParameter("info");
		out.println("个人信息为:" + info);
	%>
	</body>
</html>

