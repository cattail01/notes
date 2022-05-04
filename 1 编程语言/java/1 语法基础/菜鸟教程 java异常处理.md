### [菜鸟教程 java异常处理](https://www.runoob.com/java/java-exceptions.html)

[toc]

#### 异常和错误

* 异常是程序中一些不可避免的错误

#### Exception：异常类的层次

* error和exception的层次

#### Java 内置异常类、异常处理方法、

* 内置异常类和异常方法表格

#### 捕获异常：try catch finally

```java
try{
    
}catch(Exception e){
    
}...{
    
}finally{
    
}
```



#### 抛出异常：throw/throws

#### 声明自定义异常

在 Java 中你可以自定义异常。编写自己的异常类时需要记住下面的几点。

- 所有异常都必须是 Throwable 的子类。
- 如果希望写一个检查性异常类，则需要继承 Exception 类。
- 如果你想写一个运行时异常类，那么需要继承 RuntimeException 类。

