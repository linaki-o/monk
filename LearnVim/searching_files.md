# 打开和搜索文件

## 打开和编辑文件

```
:edit file.txt
:edit *.yml<Tab>
:edit **/*.md<Tab>
```
:edit可以用于运行netrw（Vim的内置文件浏览器）。使用方法是，给:edit一个目录参数而不是文件名就行了：
```
:edit .
:edit test/unit/
```

## 使用find命令搜索文件

### Find 和 Path
:find命令根据path选项配置的路径查找文件，而:edit不会

查看path：
```
:set path?
```

添加路径：
```
:set path+=app/controllers/
:set path+=$PWD/**  $PWD 表示的是当前工作目录
```

### 使用Grep命令在文件中搜索

- 内置grep （:vim。没错，就是:vim，它是:vimgrep的简写）。
- 外部grep (:grep)。

> 内置grep

```
:vim /pattern/ file
```
- /pattern/ 是您要搜索的内容的正则表达式。
- file 是文件参数。您可以传入多个参数。Vim将在文件中搜索所有匹配正则表达式的内容。类似于:find，您可以传入*和**通配符。

Vim的vim搜索命令使用quickfix进行处理。要查看所有搜索结果，运行:copen会打开一个quickfix窗口。
```
:copen        打开quickfix窗口
:cclose       关闭quickfix窗口
:cnext        跳到下一个错误
:cprevious    跳到前一个错误
:colder       跳到旧的错误列表
:cnewer       跳到新的错误列表
```

您可能注意到运行内置grep(:vim)命令时，如果匹配结果数量较多时系统速度会变慢。这是因为Vim将每一个搜索结果读入内存。Vim加载每一个匹配的文件就像它们被编辑一样。如果Vim查到大量文件，它将消耗很多内存。

> 外置grep

让我们谈谈外置grep。默认情况下，它使用终端命令grep。要想在app/controllers/目录中搜索字符串"lunch"，您可以这样做：

```
:grep -R "lunch" app/controllers/
```

Vim使用grepprg变量来决定运行:grep时，应该使用哪个外部程序。所以您并不是非得使用终端的grep命令。

### 用Netrw浏览文件
您需要在您的.vimrc中做以下设置：
```
set nocp
filetype plugin on
```

```
vim .
vim src/client/
vim app/controllers/

:Explore     从当前文件启动netrw。
:Sexplore    Sex_Plore?不是开玩笑:)，在顶部水平分割的窗口打开netrw。
:Vexplore    在左侧垂直分割的窗口打开netrw。
```

```
%    创建新文件
d    创建新目录
R    重命名文件/目录
D    删除文件/目录
```