1. 添加依赖：

   ```groovy
   
   dependencies {
   	...
       implementation 'com.android.support:multidex:1.0.3'
   }
   ```

2. 在App的Gradle下开启multiDexEnabled属性：

   ```groovy
   android {
   	...
       defaultConfig {
       	...
           multiDexEnabled true
       }
   }
   ```

3. 将项目原Application更改为MultiDexApplication，有三种方案可选：

   1. 在AndroidManifest.xml文件的application标签下添加属性：

      ```xml
          <application
              android:name="android.support.multidex.MultiDexApplication"
              ...
          </application>
      ```

   2. 让应用的Application继承MultiDexApplication，比如：

      ```java
      public class App extends MultiDexApplication{
      	...
      }
      ```

   3. 如果不想让应用的Application继承MultiDexApplication，还可以选择重写Application的attachBaseContext方法，这个方法比Application的onCreate方法要先执行，如：

      ```java
      public class App extends MultiDexApplication {
          @Override
          protected void attachBaseContext(Context base) {
              super.attachBaseContext(base);
              MultiDex.install(this);
          }
      }
      ```

      

      