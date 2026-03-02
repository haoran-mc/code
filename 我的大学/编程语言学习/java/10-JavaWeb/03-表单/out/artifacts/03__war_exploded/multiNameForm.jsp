<%@ page language="java" contentType="text/html; charset=gb2312"%>
<html>
	<body>  
	请您输入自己的信息进行注册  
	<form action="multiNameForm_result.jsp" method="post">
		请您输入您的电话号码(最多4个)：<BR>
		<%for(int i=1;i<=4;i++){ %>
		    号码<%=i %>：<input name="phone" type="text"><BR>
		<%} %>
		<input type="submit" value="注册">
	</form>
	</body>
</html>

