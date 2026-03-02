package service;

import dao.BookDao;
import dao.impl.BookDaoImpl;
import vo.Book;

import java.util.List;

public class BookService {
    private BookDao bookDao = new BookDaoImpl();

    public List<Book> getBookByCategoryID(int id) {
        return bookDao.getBookByCategory(id);
    }
}
