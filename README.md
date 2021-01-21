<p>這是程式設計課程的mini_project，模擬CPU計算時的程序，用C語言寫。<p>
<p>電腦的邏輯運算，主要由CPU來執行，首先須接收指令，並依照指令去記憶體或暫存器中尋找該data，獲取data後便開始執行。<p>
<p>暫存器儲存空間雖然有限，不過讀寫速度非常快，因此我模擬出表示法 : 將輸入的運算子先儲存於暫存器，讓CPU計算時可直接從暫存器中拿取，並馬上運算。<p>
<p>例如 : CPU在運算 1+2 時，會先將1存入r0(register 0)，再將2存入r1，最後CPU會拿取r0和r1，對它們add(加法)。<p>
<p>附上operation.c(主要邏輯code)及實作畫面。<p>
