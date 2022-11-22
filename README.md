## 介紹
指令經過 compiler 後，會編譯出 assembly code，通常會使用register暫存數值，並用tree的概念分配operator和operant，用C語言寫，其中含括很多.c檔
## 動機、內容
register儲存空間雖然有限，不過讀寫速度非常快，因此我模擬出表示法，將輸入的內容先儲存於暫存器，讓CPU計算時可直接從暫存器中拿取，並馬上運算
## 實作 
因為數字運算皆為一個運算子搭配兩個數字或數字串，因此我利用binary tree，先把數字放在leaf node、運算子放在它們的parent node，並將leaf node存入register，再提取register中的值，依照運算子執行指令

![image](https://user-images.githubusercontent.com/56677419/202917063-c1972316-0e61-45d9-b580-46b3798d1cbb.png)

## 舉例 
CPU在運算 A=1+2 時，A被分配到r0(register 0)，1被分配到左邊leaf node、2被分配到右邊leaf node、+被分配到root，完成後先將1存入r1、將2存入r2，CPU會拿取r1和r2，執行add(加法指令)，r1=r1+r2，並把r1 move to r0，最後A即=r0
## 附件
operation.c(主要邏輯code)及實作畫面
