

- linux的 sh -c 是什么意思和功能

在Linux中，sh -c 是一个命令行选项，用于执行指定的命令字符串。它允许在shell中执行单个命令或命令序列，并且可以与其他命令和选项结合使用。

sh -c 的语法如下：

```
sh -c 'command_string'
```

其中，command_string 是要执行的命令或命令序列。这个字符串可以包含任何合法的Shell命令，包括管道、重定向和其他Shell特性。

以下是一个使用 sh -c 的示例：

```
sh -c 'echo "Hello, world!"'
```

- chsh -s $(which zsh) 是什么意思

用于更改当前用户的默认Shell（登录Shell）为 Zsh（Z shell）的命令。下面是具体解释：

chsh 是用于更改用户默认Shell的命令。它接受一个用户名作为参数，如果没有指定用户名，则默认为当前用户。

-s 选项用于指定要更改为的Shell。在给定的示例中，-s $(which zsh) 指定将Shell更改为 zsh（Z shell）。$(which zsh) 是一个命令替换，用于获取 zsh Shell 的可执行路径。


- which 与 whereis 这两个命令有什么区别

* 【1】which 命令用于查找给定命令在系统的可执行文件路径中的位置。它会在环境变量 PATH 指定的路径列表中搜索命令，并返回找到的第一个匹配项
* 【2】whereis 命令用于查找给定命令的二进制、源代码和帮助文档等相关文件的位置。它会在系统默认的一组目录中搜索相关文件。