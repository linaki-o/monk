# 缓冲区(Buffers)，窗口(Windows)和选项卡(Tabs)

```
set hidden
```
若没有配置该选项，当您想切换buffer且当前buffer没有保存时，Vim将提示您保存文件（如果您想快速切换，您不会想要这个提示）。

## Buffer
```
vim file1.js file2.js
```
查看创建的buffers:
- :buffers
- :ls
- :files

要遍历所有buffers，有以下几种方法：

- :bnext 切换至下一个buffer（:bprevious切换至前一个buffer）。
- :buffer + 文件名。（按下<Tab>键Vim会自动补全文件名）。
- :buffer + n, n是buffer的编号。比如，输入:buffer 2将使您切换到buffer #2。
- 按下Ctrl-O将跳转至跳转列表中旧的位置，对应的，按下Ctrl-I将跳转至跳转列表中新的位置。这并不是属于buffer的特有方法，但它可以用来在不同的buffers中跳转。我将在第5章详细讲述关于跳转的知识。
- 按下Ctrl-^跳转至先前编辑过的buffer。

删除buffer：
- :bdelete + n
- :bdelete + 文件名

退出所有buffers：
- :qall
- :qall!
- :wqall

## Window
分割一个窗口：
```
:split file2.js  水平分割线
:vsplit file3.js  垂直分割线
:new filename       创建一个新窗口并打开名为filename的文件。
Ctrl-W V    打开一个新的垂直分割的窗口
Ctrl-W S    打开一个新的水平分割的窗口
Ctrl-W C    关闭一个窗口
Ctrl-W O    除了当前窗口，关闭所有其他的窗口

```
移动光标：
```
Ctrl-W H    移动光标到左边的窗口
Ctrl-W J    移动光标到下面的窗口
Ctrl-W K    移动光标到上面的窗口
Ctrl-W L    移动光标到右边的窗口
```

## Tab

```
:tabnew file2.js
```

tab导航：
```
:tabnew file.txt    在tab中打开一个文件
:tabclose           关闭当前tab
:tabnext            切换至下一个tab
:tabprevious        切换至前一个tab
:tablast            切换至最后一个tab
:tabfirst           切换至第一个tab
ngt                  下n个
ngT                  上n个
```

若想让Vim启动时就包含多个tabs，您可以在终端中运行如下命令：
```
vim -p file1.js file2.js file3.js
```