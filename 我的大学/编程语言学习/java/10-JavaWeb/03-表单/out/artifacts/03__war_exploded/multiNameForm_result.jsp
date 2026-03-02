<%@ page language="java" contentType="text/html; charset=gb2312"%>
<html>
	<body>
	<%
		String[] phone = request.getParameterValues("phone");
		out.println("ºÅÂëÎª:");
		for(int i=0;i<phone.length;i++){
			out.println(phone[i]);
		}
	%>
	</body>
</html>