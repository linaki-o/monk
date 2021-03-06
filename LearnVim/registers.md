# 寄存器

## 寄存器的10种类型
1. 匿名寄存器（""）.
1. 编号寄存器("0-9).
1. 小删除寄存器 ("-).
1. 命名寄存器 ("a-z).
1. 只读寄存器 (":, "., and "%).
1. Buffer交替文件寄存器 ("#).
1. 表达式寄存器 ("=).
1. 选取和拖放寄存器("* and "+).
1. 黑洞寄存器 ("_).
1. 搜索模式寄存器 ("/).

## 寄存器命令

存值到寄存器中的操作：
```
y    复制
c    删除文本并进入输入模式
d    删除文本
```

想要从寄存器中取出（粘贴）文本，你可以用以下的命令：
```
p    在光标位置之后粘贴文本
P    在光标位置之前粘贴文本
```

## 在普通模式下使用寄存器：
```
"ap
```
## 在输入模式中使用寄存器
```
Ctrl-r x
```
## 匿名寄存器("")
匿名寄存器默认存储着你最近一次复制，修改或删除的文本。

""p 其实就是 p

## 编号寄存器("0-9)

### 复制寄存器 ("0)
如果你使用yy来复制一整行文本，事实上Vim会将文本存放两个寄存器中：
1. 匿名寄存器 (p).
1. 复制寄存器 ("0p).

### 编号寄存器 ("1-9)
当你修改或者删除至少一整行的文本时，这部分文本会按时间顺序被存储在1-9号编号寄存器中。（编号越小时间距离越近）

编号寄存器的编号在使用点命令时会自动增加。比如，如果你的1号编号寄存器（"1）中的内容为"line one"， 2号寄存器（"2）为"line two", 三号寄存器（"3）"line three",你可以使用以下的技巧来连续地粘贴他们：

- 使用"1p来粘贴1号寄存器中的内容。
- 使用. (点命令)来粘贴2号寄存器（"2）中的内容。
- 使用. (点命令)来粘贴3号寄存器（"3）中的内容。


## 小删除寄存器("-)
不足一行的修改或者删除都不会被存储在0-9号编号寄存器中，而是会被存储在小删除寄存器 ("-)中。

## 命名寄存器 ("a-z)
命名寄存器是Vim中用法最丰富的寄存器。a-z命名寄存器可以存储复制的，修改的和被删除的文本。不像之前介绍的3种寄存器一样，它们会自动将文本存储到寄存器中，你需要显式地告诉Vim你要使用命名寄存器，你拥有完整的控制权。

为了复制一个单词到寄存器"a"中，你可以使用命令"ayiw。

1. "a告诉Vim下一个动作（删除/修改/复制）会被存储在寄存器"a"中
1. yiw复制这个单词


有时你可能会想要往已有内容的命名寄存器中继续添加内容，这种情况下，你可以追加文本而不是全部重来。**你可以使用大写版本的命名寄存器来进行文本的追加**。比如，假设你的"a"寄存器中已经存有文本"Hello"，如果你想继续添加"world"到寄存器"a"中，你可以先找到文本"world"然后使用"Ayiw来进行复制,即可完成追加。

## 只读寄存器(":, "., "%)
```
.    存储上一个输入的文本
:    存储上一次执行的命令
%    存储当前文件的文件名
```

## Buffer交替文件寄存器 ("#)
在Vim中，#通常代表交替文件。交替文件指的是你上一个打开的文件，想要插入交替文件的名字的话，可以使用命令"#p。

## 表达式寄存器 ("=)
Vim有一个表达式寄存器，"=,用于计算表达式的结果。

你可以使用以下命令计算数学表达式1+1的值：

```
"=1+1<Enter>p
```

你可以使用@来从任何寄存器中获取表达式并用表达式寄存器计算其值。如果你希望从寄存器"a"中获取文本：

```
"=@a
```

## 选取和拖放寄存器 ("*, "+)
你难道不觉得有些时候你需要从某些外部的程序中复制一些文本并粘贴到Vim中吗，或者反过来操作？有了Vim的选取和拖放寄存器你就能办到。Vim有两个选取寄存器：quotestar ("*) 和 quoteplus ("+)。你可以用它们来访问从外部程序中复制的文本。

如果你在运行一个外部程序（比如Chrome浏览器），然后你使用Ctrl-c(或者Cmd-c,取决于你的操作系统)复制了一部分文本，通常你是没有办法在Vim里使用p来粘贴这部分文本的。但是，Vim的两个寄存器"+和"*都是和你系统的粘贴板相连接的，所以你可以使用"+p和"*p来粘贴这些文本。反过来，如果你使用"+yiw或者"*yiw在Vim中复制了一些文本，你可以使用Ctrl-v（或者Cmd-v）。值得注意的是这个方法只在你的Vim开启了+clipboard选项时才有用，可以在命令行中运行vim --version查看这一选项。如果你看见-clipboard的话，则需要安装一下支持Vim粘贴板的配置。

你也许会想如果"*和"+能办到的事完全相同，那为什么Vim需要两个不同的寄存器呢？一些机器使用的是X11窗口系统，这一系统有3个类型的选项：首选，次选和粘贴板。如果你的机器使用的是X11的话,Vim使用的是quotestar ("*)寄存器作为X11的首选选项，并使用 quoteplus ("+)作为粘贴板选项。这只在你的Vim配置里开启了xterm_clipboard 选项时才有效（vim --version中的+xterm_clipboard）。如果你的的Vim配置中没有 xterm_clipboard也不是什么大问题。这只是意味着quotestar 和quoteplus两个寄存器是可以互相替代的。

我发觉使用"*p或者"+p的话比较麻烦，为了使Vim仅使用p就能粘贴从外部程序复制的文本，你可以在你的vimrc配置文件中加入下面一行：
```
set clipboard=unnamed
```
现在当我从外部程序中复制文本时，我可以使用匿名寄存器p来进行粘贴。我也可以在Vim中复制文本后在外部程序中使用Ctrl-v来粘贴。如果你的Vim开启了 +xterm_clipboard设置，你或许会想同时也使用unnamed和unnamedplus的粘贴板选项。

## 黑洞寄存器 ("_)
你每次删除或修改文本的时候，这部分文本都会自动保存在Vim的寄存器中。有些时候你并不希望把什么东西都往寄存器里存，这该怎么办到呢？

## 搜索模式寄存器 ("/)
为了粘贴你的上一个搜索询问（/ 或 ?），你可以使用搜索模式寄存器("/)。使用命令 "/p就能粘贴上一个搜索的条目。

## 查看所有的寄存器

你可以使用:register命令来查看你的所有寄存器。如果你只想查看"a","1"和"-"寄存器的内容的话则可以使用命令:register a 1 -。

有一个Vim的插件叫做 vim-peekaboo ,可以让你查看到寄存器的内容，在普通模式下输入"或@ 即可，或者在输入模式中输入Ctrl-r。我发现这个插件相当的有用，因为大多数时候我是记不住我的寄存器中的内容的。值得一试！

## 执行寄存器
命名寄存器不只可以用来存放文本，你还可以借助@来执行宏命令。我会在下一章节中介绍宏命令。

## 清除寄存器
然而，你可以通过记录一个空的宏命令来快速地清除任何命名寄存器。比如，如果你运行qaq，Vim就会在寄存器"a"中记录一个空的宏命令。

还有一种方法就是运行命令:call setreg('a','hello register a'),其中'a'代表的就是寄存器"a"。而"hello register a"就是你想存储的内容。

还有一种清除寄存器的方法就是使用表达式:let @a = ''来将寄存器"a 的值设为空的字符串。


## 获取寄存器中的内容
你可以使用:put命令来粘贴任何寄存器的内容。比如，如果你运行命令:put a,Vim就会打印出寄存器"a"的内容，这和"ap非常像，唯一的区别在于在普通模式下命令p在当前光标位置之后打印寄存器的内容，而:put新起一行来打印寄存器的内容。

因为:put是一个命令行命令，您可以传一个地址给它。:10put a将会在当前光标下数10行，然后插入新行，内容为寄存器a中的内容。

一个很酷的技巧是将黑洞寄存器("_)传给:put命令。因为黑洞寄存器不保存任何值，:put _命令将插入一个新的空白行。您可将这个与全局命令联合起来，插入多个空行。比如，要在所有以文本"end"结尾的行下插入空行，使用:g/end/put _。在后面您将了解关于全局命令的知识。
