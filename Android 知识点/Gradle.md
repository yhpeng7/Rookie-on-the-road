### Groovy

#### Groovy简单语法

```groovy
//groovy 可以省略语句最末尾的分号
println("hello groovy")

//groovy 可以省略括号
println "hello groovy"

//groovy中如何定义变量
//def是弱类型的，groovy会自动根据情况来给变量赋予对应的类型
def i = 13.13
println i

//定义一个集合类型
def list = ['a','b']
//往list中添加元素
list << 'c'
//取出list中的第三个元素
println list.get(2)

//定义一个map
def map = ['key1' : 'value1','key2' : 'value2']
//向map中添加键值对
map.key3 = 'value3'
//打印出key3的值
println map.get("key3")
```

#### Groovy中的闭包

```groovy
//闭包其实就是一段代码块，在gradle中，我们主要把闭包当成参数来用
//定义一个闭包
def b1 = {
    println "hello b1"
}
//定义一个方法，方法里需要闭包类型参数
def method1(Closure closure) {
    closure()
}
//调用方法method1
method1(b1)

//定义一个闭包，带参数
def b2 = {
    v ->
        println "hello ${v}"
}

def method2(Closure closure) {
    closure("鹏举翅摩天")
}

method2(b2)
```

