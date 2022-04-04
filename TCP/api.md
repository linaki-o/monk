- I/O
    ```c
    int open(const char *pathname, int flags, mode_t mode);
    open函数的返回值如果操作成功，它将返回一个文件描述符，如果操作失败，它将返回-1。
    flags: O_RDONLY, O_WRONLY, O_RDWR, O_APPEND, O_CREAT, O_EXCL, O_TRUNC, O_NOCTTY, O_NONBLOCK, O_DSYNC, O_RSYNC, O_SYNC
    mode: 第三个参数是在第二个参数中有O_CREAT时才作用，如果没有，则第三个参数可以忽略, 比如0644表示-rw-r–r– 
    ```

    ```c
    FILE *fopen(const char *filename, const char *mode)
    该函数返回一个 FILE 指针。否则返回 NULL，且设置全局变量 errno 来标识错误。
    
    size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)


    size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    如果成功，该函数返回一个 size_t 对象，表示元素的总数，该对象是一个整型数据类型。如果该数字与 nmemb 参数不同，则会显示一个错误。
    ```

    ```c
    int feof(FILE *stream)
    当设置了与流关联的文件结束标识符时，该函数返回一个非零值，否则返回零。
    ```


- 销毁僵尸进程
    ```c
    #include <sys/wait.h>
    pid_t wait(int* statloc); // 如果没有已终止的子进程，程序将阻塞
    ```
    ```c
    pid_t waitpid(pid_t pid, int* statloc,int  options);
    ```

- 注册信号
    ```c
    #include <signal.h>
    void (*signal(int signo, void (*func)(int)))(int);
    ```
    ```c
    int sigaction(int signo, const struct sigaction* act, struct sigaction* oldact);
    ```


- alarm 发出SIGALRM信号
    ```c
    #include <unistd.h>
    unsigned int alarm(unsigned int seconds);
    ```

- 管道
    ```c
    #include <unistd.h>
    int pipe(int filedes[2]);
    // filedes[0] 管道出口 filedes[1] 管道入口
    ```

- 复用服务器端设置检查范围及超时
    ```c
    #include<sys/time.h>
    #include<sys/types.h>
    #include<unistd.h>
    int select(int maxfd, fd_set* readfds,fd_set* writefds,fd_set* exceptfds,struct timeval* timeout);

    FD_CLR(inr fd,fd_set* set)；用来清除描述词组set中相关fd 的位
    FD_ISSET(int fd,fd_set *set)；用来测试描述词组set中相关fd 的位是否为真
    FD_SET（int fd,fd_set*set）；用来设置描述词组set中相关fd的位
    FD_ZERO（fd_set *set）； 用来清除描述词组set的全部位
    ```

- 标准I/O函数
    ```c
    #include <stdio.h>
    FILE *fdopen(int handle, char *type);  // 把流与一个文件句柄相接
    int fileno(FILE * stream); // 取得参数stream指定的文件流所使用的文件描述符
    ``