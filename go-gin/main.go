package main

import (
	"fmt"
	"log"
	"net/http"
	"time"

	"github.com/gin-gonic/gin"
)

func StatCostMW() gin.HandlerFunc {
	return func(c *gin.Context) {
		start := time.Now()
		c.Set("startTime", start.String())
		c.Next()
		cost := time.Since(start).String()
		log.Println(cost)
	}
}

func main() {
	r := gin.Default()

	echo := r.Group("/echo")
	{
		echo.GET("/*path", func(c *gin.Context) {
			p := c.Param("path")
			c.String(http.StatusOK, "[GET] Path: %s\n", p)
		})
		echo.POST("/*path", func(c *gin.Context) {
			p := c.Param("path")
			raw, _ := c.GetRawData()
			c.String(http.StatusOK, "[POST] Path: %s, Data: %s\n", p, string(raw))
		})
		echo.PUT("/*path", func(c *gin.Context) {
			p := c.Param("path")
			raw, _ := c.GetRawData()
			c.String(http.StatusOK, "[PUT] Path: %s, Data: %s\n", p, string(raw))
		})
		echo.DELETE("/*path", func(c *gin.Context) {
			p := c.Param("path")
			raw, _ := c.GetRawData()
			c.String(http.StatusOK, "[DELETE] Path: %s, Data: %s\n", p, string(raw))
		})
	}

	param := r.Group("/param")
	{
		// 1. 路径参数
		param.GET("/params/:foobar", func(c *gin.Context) {
			foobar := c.Param("foobar")
			c.String(http.StatusOK, "param(foobar): %s\n", foobar)
		})
		// 2. querymap, http://127.0.0.1:8080/querymap?foobar=xxxx
		param.GET("/querymap", func(c *gin.Context) {
			foobar := c.Query("foobar")
			c.String(http.StatusOK, "querymap(foobar): %s\n", foobar)
		})
		// 3. 请求体
		param.POST("/body", func(c *gin.Context) {
			type User struct {
				Name string `json:"name"`
				Pass string `json:"pass"`
			}
			var u User
			err := c.ShouldBindJSON(&u)
			if err != nil {
				c.JSON(http.StatusBadRequest, err.Error())
				return
			}
			c.JSON(http.StatusOK, u)
		})
		// 4. form 表单
		param.POST("/form", func(c *gin.Context) {
			foobar := c.PostForm("foobar")
			c.String(http.StatusOK, foobar)
		})
	}

	// 重定向
	redirect := r.Group("/redirect")
	{
		redirect.GET("/hello1", func(c *gin.Context) {
			c.Redirect(http.StatusFound, "/redirect/hello2")
		})
		redirect.GET("/hello2", func(c *gin.Context) {
			c.String(http.StatusOK, "OK")
		})
	}

	// 文件上传
	file := r.Group("/file")
	{
		file.POST("/upload", func(c *gin.Context) {
			file, err := c.FormFile("f1")
			if err != nil {
				c.JSON(http.StatusInternalServerError, gin.H{
					"message": err.Error(),
				})
				return
			}
			dst := fmt.Sprintf("C:/tmp/%s", file.Filename)
			c.SaveUploadedFile(file, dst)
			c.JSON(http.StatusOK, gin.H{
				"message": fmt.Sprintf("'%s' uploaded!", file.Filename),
			})
		})
		file.POST("/multi", func(c *gin.Context) {
			form, _ := c.MultipartForm()
			files := form.File["file"]

			for index, file := range files {
				log.Println(file.Filename)
				dst := fmt.Sprintf("C:/tmp/%s_%d", file.Filename, index)
				c.SaveUploadedFile(file, dst)
			}
			c.JSON(http.StatusOK, fmt.Sprintf("%d files uploaded!", len(files)))
		})
	}

	// 中间件
	mw := r.Group("/mw")
	{
		mw.GET("/stat/cost", StatCostMW(), func(c *gin.Context) {
			ts := c.MustGet("startTime").(string)
			c.String(http.StatusOK, ts)
		})
	}

	r.Run(":8080")
}
