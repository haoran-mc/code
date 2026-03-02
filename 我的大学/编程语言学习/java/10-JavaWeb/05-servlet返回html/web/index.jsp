<%--
  Created by IntelliJ IDEA.
  User: haoran
  Date: 2021/11/23
  Time: 上午9:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>$Title$</title>
    <style>
        form {
            display: table;
        }

        p {
            display: table-row;
        }

        label {
            display: table-cell;
        }

        input {
            display: table-cell;
        }
    </style>
</head>
<body>
<form action="/05_servlethtml_war_exploded/data">
    <!-- <div style="display: table-column;"></div> -->
    <!-- <div style="display: table-column; width:100%;"></div> -->
    <p>
        <label for="name">姓名：</label>
        <input id="name" name="name" type="text">
    </p>
    <p>
        <label for="email">Email：</label>
        <input id="email" name="email" type="text">
    </p>
    <p>
        <label for="address">通信地址：</label>
        <input id="address" name="address" type="text">
    </p>
    <p>
        <label for="resume">个人简历：</label>
<%--        <input id="resume" name="resume" type="file">--%>
        <textarea name="resume" id="resume" cols="20" rows="5"></textarea>
    </p>
    <p>
        <input type="submit">
    </p>
</form>
</body>
</html>