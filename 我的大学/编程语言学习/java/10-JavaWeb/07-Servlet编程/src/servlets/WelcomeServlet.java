package servlets;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class WelcomeServlet extends HttpServlet{
	public WelcomeServlet(){
		System.out.println("Welcome");
	}
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		System.out.println("欢迎！");

//		response.setContentType("text/html; charset=gb2312");
//		PrintWriter out = response.getWriter();
//		out.println("欢迎来到这里！");
	}	
}

