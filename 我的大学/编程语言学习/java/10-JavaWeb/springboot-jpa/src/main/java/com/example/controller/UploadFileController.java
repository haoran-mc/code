package com.example.controller;


import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

@RestController
@RequestMapping("/file")
public class UploadFileController {

    @PostMapping("/images")
    public String singleFileUpload(@RequestParam("file") MultipartFile file) {
        System.out.println("--");
        if (file.isEmpty()) {
            return "请选择上传文件";
        }
        try {
            byte[] bytes = file.getBytes();
            Path path = Paths.get("upload/images/"+file.getOriginalFilename());
            Files.write(path, bytes);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "上传成功";
    }
}
