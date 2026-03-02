package cn.edu.ncu;

import cn.edu.ncu.dao.BookDao;

public class BookService {
    private String bookID;
    private BookDao bookDao;

    public void setBookDao(BookDao bookDao) {
        this.bookDao = bookDao;
    }

    public void deleteBookByID(String ID) {
        bookDao.deleteBookByID(ID);
    }

    public BookService() {
    }

    public BookService(String bookID) {
        this.bookID = bookID;
    }

    public void addBook() {
        System.out.println(this.bookID);
        // System.out.println("Add book info");
    }
}
