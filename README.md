<p>這是程式設計課程的mini_project，模擬CPU計算時的程序，用C語言寫。<p>
<p>暫存器儲存空間雖然有限，不過讀寫速度非常快，因此我模擬出表示法 : 將輸入的運算子先儲存於暫存器，讓CPU計算時可直接從暫存器中拿取，並馬上運算。<p>
<p>作法 : 因為數字運算皆為一個運算子搭配兩個數字或數字串，因此我利用binary tree，先把數字放在leaf node、運算子放在其他parent node，並將leaf node存入register，再提取register中的值，依照運算子執行指令。<p>
<p>例如 : CPU在運算 1+2 時，1被分配到左邊leaf node、2被分配到右邊leaf node、+被分配到root，完成後先將1存入r0(register 0)、將2存入r1，最後CPU會拿取r0和r1，執行add(加法指令)。<p>
<p>附上operation.c(主要邏輯code)及實作畫面。<p>
