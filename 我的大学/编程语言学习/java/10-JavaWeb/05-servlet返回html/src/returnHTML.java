import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/data")
public class returnHTML extends HttpServlet {
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String name = req.getParameter("name");
        String email = req.getParameter("email");
        String address = req.getParameter("address");
        String resume = req.getParameter("resume");

        resp.setContentType("text/html; charset=gb2312");
        PrintWriter out = resp.getWriter();
        out.println("姓名：" + name + "<br>");
        out.println("邮箱：" + email + "<br>");
        out.println("地址：" + address + "<br>");
        out.println("个人简历：" + resume + "<br>");
    }
}
