### 提高磁盘I/O速度的其它方法

* **提前读**：顺序访问方式能够**预知下一个是用的盘块号**，可提前读入缓冲区，减少启动磁盘次数，提高磁盘I/O速度。
* **延迟写**：**缓冲区的数据不立即写回磁盘**，而是将它**挂在空闲缓冲区队列尾部**，直到**移到缓冲区首部再写回**。
* **优化物理块的分布**：使用**位示图法或簇分配**，使文件**存放在同一条磁道上或相邻的磁道**。
* **虚拟盘**：**用内存空间仿真磁盘**，即虚拟盘RAM，由用户控制，就像使用磁盘一样。

