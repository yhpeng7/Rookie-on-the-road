### Jni

1. JNI (Java Native Interface)
2. jclass 代表native方法所属类的class对象
3. Jni引用变量告知虚拟机何时回收一个Jni变量

### 常用命令

1. src目录下： javah [完整类名] --- 生成native方法头文件
2. `javap -s -p` [class文件路径] --- 查看类所有属性和方法的签名。 

### 其他资料

1. [NDK与Jni的区别](https://juejin.im/post/5989133ff265da3e2e56ff26)
2. [Jni系列之入门](https://juejin.im/post/5b5b16535188251afe7b99e5)
3. [Jni完全指南](https://www.zybuluo.com/cxm-2016/note/563686)
4. [Android框架层基础—JNI原理](https://blog.csdn.net/qq_38499859/article/details/88804471)
5. [__declspec(dllexport / dllimport)](https://www.cnblogs.com/xd502djj/archive/2010/09/21/1832493.html)