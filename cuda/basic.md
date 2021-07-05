1.执行相关
gpu函数（kernel）
声明前缀__global__（cpu调用，gpu执行） __device__（gpu调用 gpu执行）
调用方式<<<,,,>>> 参数1：block数   参数2：单block内线程数 数据类型为dim3
                               参数3：dynamic shared memory大小 参数4： stream编号 参数3、4默认为0

grid block thread
grid由block组成，block由thread组成，均为3维。
//抽象概念？有内存优化?实际测试矩阵乘法时相同block数和thread数的情况下不同维度设置对结果有影响。
连续thread对连续地址的访问可以在同一周期内完成。
同一个grid内的所有thread执行同一个kernel
SM
由SP组成，block会被分配到SM上，由SP负责执行具体kernel，SM将每个block的thread分组，成为wrap（一般大小为32，尽量确保每个block里线程数为32的倍数），每一个wrap执行相同的指令（如果存在分支，尽量保证同一个wrap内的线程在同一分支内，否则会串行执行不同分支）
//？t0-t31一定会分到一个wrap吗？


2.内存相关

shared memory ： SM内同一个block内所有线程共享（性能优化，用于减少对global memory的访问，适合对一组数据进行重复访问）
register、local memory： 每个线程独占，register直到thread结束才会被释放，所以要注意每个block内的线程数量
global memory、constant memory（只读，sm有自己的cache）、texture memory（只读）
速度：register > shared memory > constant memory > texture memory > global memory local memory
每个SM有自己的L1(数据)缓存（缓存global memory，尽量读取连续内存，如同一个wrap的线程同指令周期内读取连续的32*n字节），所有SM共享L2缓存，没有写入缓存，每个sm有自己的指令缓存？
//？存在缓存一致性协议？shared memory缓存写入减少对global memory的访问次数？
shared memory: static or dynamic
static: 在kernel函数内加入__shared__    dynamic:在调用kernel时传入大小，在kernel函数声明前加extern __shared__
将shared memory作为可编程的L1缓存使用，利用__syncthreads()保证所使用的数据正确(尽量不要在if分支内使用__syncthreads)
shared memory由不同数目的bank组成，compute capability 2.0之前为16，之后为32。
bank conflict： 不同thread对同一bank的不同地址访问是串行的（一个bank同一时间服务一个线程），
尽量保证同一wrap内的线程同一时间访问shared memory里连续的数据。是否存在bank conflict根据缓存数据类型和bank字长决定
锁页内存： 不会被操作系统换出（可能内存减少），portable：所有cuda设备都能访问。write-combining：加速写入，降低读取（不会使用L1/L2，hip没有此flag） mapped ：允许设备直接访问cpu内存，延迟较高，适合数据集大但访问数较低场景（需要同步）。
Unified Memory; 前缀__device__ __managed__ 隐式数据拷贝，需要同步，相比mpaped memory，速度更好，hip不支持

3.streams
streams是一串顺序队列，设备的data transfer和kernel执行可以并行执行，通过不同的data transfer和kernel的异步调用顺序来提高设备的负载（数据传输和指令执行，尽量保证gpu核心一直有计算指令执行）。内存指针为锁页内存（异步执行，防止被换出），host可以和某一stream同步

4.event
在streams里加入特殊标记记录触发时的状态，可用于计算kernel执行时间，不同流之间实现同步
