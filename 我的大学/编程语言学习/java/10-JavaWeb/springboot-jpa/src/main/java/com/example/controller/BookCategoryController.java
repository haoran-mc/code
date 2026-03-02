package com.example.controller;

import com.example.entity.BookCategory;
import com.example.service.BookCategoryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping(value = "category")
public class BookCategoryController {
    @Autowired
    private BookCategoryService service;

    @RequestMapping(value = "", method = RequestMethod.GET)
    public List<BookCategory> findAll() {
        return service.findAll();
    }

    @PostMapping("")
    public void saveBookCategory(BookCategory bookCategory){
        service.saveBookCategory(bookCategory);
    }
}
