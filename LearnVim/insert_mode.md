# 输入模式
## 进入输入模式的方法
```
i    从光标之前的位置开始输入文本
I    从当前行第一个非空字符之前的位置之前开始输入文本
a    在光标之后的位置追加文本
A    在当前行的末尾追加文本
o    在光标位置下方新起一行并开始输入文本
O    在光标位置的上方新起一行并开始输入文本
s    删除当前光标位置的字符并开始输入文本
S    删除当前行并开始输入文本
gi   从当前缓冲区上次结束输入模式的地方开始输入文本
gI   在当前行的第一列的位置开始输入文本
```

## 退出输入模式的方法
```
<esc>     退出输入模式进入普通模式
Ctrl-[    退出输入模式进入普通模式
Ctrl-c    与 Ctrl-[ 和 <esc>功能相同, 但是不检查缩写
```
映射
```
inoremap jj <esc>
inoremap jk <esc>
```

## 重复输入模式
```
10i
```
## 在输入模式中删除大块文本
```
Ctrl-h    删除一个字符
Ctrl-w    删除一个单词
Ctrl-u    删除一整行
```
## 用寄存器进行输入
```
"ayiw
```
- "a 告诉Vim你下一个动作的目标地址是寄存器a
- yiw 复制一个内词（inner word），可以回顾Vim语法章节查看具体语法。

粘贴
```
Ctrl-r a
```

## 页面滚动
在输入模式下，如果你使用快捷键Ctrl-x进入Ctrl-x子模式
```
Ctrl-x Ctrl-y    向上滚动页面
Ctrl-x Ctrl-e    向下滚动页面
```

## 自动补全
```
Ctrl-x Ctrl-l	   补全一整行
Ctrl-x Ctrl-n	   从当前文件中补全文本
Ctrl-x Ctrl-i	   从引用（include）的文件中补全文本
Ctrl-x Ctrl-f	   补全一个文件名

Ctrl-n             使用下一个匹配的单词进行补全
Ctrl-p             使用上一个匹配的单词进行补全
```

## 执行普通模式下的命令
在输入模式下， 如果你按下Ctrl-o，你就会进入到insert-normal（输入-普通）子模式。
```
Ctrl-o zz       居中窗口
Ctrl-o H/M/L    跳转到窗口的顶部/中部/底部
Ctrl-o 'a       跳转到标志'a处

Ctrl-o 100ihello    输入 "hello" 100 次

Ctrl-o !! curl https://google.com    运行curl命令
Ctrl-o !! pwd                        运行pwd命令

Ctrl-o dtz    从当前位置开始删除文本，直到遇到字母"z"
Ctrl-o D      从当前位置开始删除文本，直到行末
```
