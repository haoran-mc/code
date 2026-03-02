package com.example.service;

import com.example.dao.BookCategoryDao;
import com.example.entity.BookCategory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BookCategoryService {
    @Autowired
    private BookCategoryDao bookCategoryDao;

    public List<BookCategory> findAll() {
        return bookCategoryDao.findAll();
    }

    public void saveBookCategory(BookCategory bookCategory) {
        bookCategoryDao.save(bookCategory);
    }
}
