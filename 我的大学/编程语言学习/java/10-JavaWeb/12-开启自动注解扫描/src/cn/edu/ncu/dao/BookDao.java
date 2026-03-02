package cn.edu.ncu.dao;

import org.springframework.stereotype.Repository;

@Repository
public class BookDao {
    public void addBook() {
        System.out.println("add book info!");
    }
}
