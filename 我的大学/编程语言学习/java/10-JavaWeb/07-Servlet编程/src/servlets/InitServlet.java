package servlets;
import java.io.IOException;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class InitServlet extends HttpServlet {
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		ServletContext application = this.getServletContext();
		String encoding = application.getInitParameter("encoding");
		System.out.println("" + encoding);
		String driverClassName = this.getInitParameter("driverClassName");
		System.out.println("" + driverClassName);
	}
}
