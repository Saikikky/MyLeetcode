public class Singleton {

    /** 懒汉式 效率很低
     private static Singleton instance;
     private Singleton(){}

     public static synchronized Singleton getInstance() {
     if (instance == null) instance = new Singleton();
     return instance;
     }*/

    /** 饿汉式 没有加锁效率提高，但类加载就初始化浪费内存
     private static Singleton instance = new Singleton();
     private Singleton() {}
     public static Singleton getInstance() {
     return instance;
     }*/

    /** 双检锁
     private volatile static Singleton instance;
     private Singleton(){}
     public static Singleton getInstance() {
     if (instance == null) {
     synchronized (Singleton.class) {
     if (instance == null) {
     instance = new Singleton();
     }
     }
     }
     return instance;
     } */

    public static void main(String[] args) {
        int[] array = {1,2,3,4,5};
        array.length
    }
}
