# 起步
## 参数
```
vim +%s/pancake/bagel/g +%s/bagel/egg/g +%s/egg/donut/g hello.txt
```

您同样可以使用c标志来代替+语法，在终端中：
```
    vim -c %s/pancake/bagel/g hello.txt
    vim -c %s/pancake/bagel/g -c %s/bagel/egg/g -c %s/egg/donut/g hello.txt
```

## 打开多个窗口

**您可以使用o和O选项使Vim打开后分别显示为水平或垂直分割的窗口。**
若想将Vim打开为2个水平分割的窗口，在终端中运行：
```
vim -o2
```

## 挂起
**如果您编辑时想将Vim挂起，您可以按下Ctrl-z。同样，您也可以使用:stop或:suspend命令达到相同的效果。若想从挂起状态返回，在终端中运行fg命令。**