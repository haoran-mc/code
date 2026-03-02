package com.example.dao;

import com.example.entity.BookCategory;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.math.BigInteger;

@Repository
public interface BookCategoryDao extends JpaRepository<BookCategory, BigInteger> {
}
