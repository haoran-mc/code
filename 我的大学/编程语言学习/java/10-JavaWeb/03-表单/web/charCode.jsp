<%@ page language="java" contentType="text/html; charset=gb2312"%>
<html>
	<body>		
	<form action="charCode.jsp" method="post">
		请您输入鲜花的模糊资料：<BR>
		<input name="flower" type="text">
		<input type="submit" value="查询">
	</form>
	<%
	    request.setCharacterEncoding("gb2312");
		String flower = request.getParameter("flower");
		if (flower!=null) {
		   //flower = new String(flower.getBytes("ISO-8859-1"),"gb2312");
			out.println("花朵名称为：" + flower);
		}
	%>
	</body>
</html>

