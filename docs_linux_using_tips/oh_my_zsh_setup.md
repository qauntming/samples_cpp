# 在 Linux 系统上安装 Oh My Zsh 的步骤：

<font size="+1">1. 安装 Zsh </font>

如果您的系统中没有安装 Zsh，请使用以下命令安装：

$ sudo apt-get update
$ sudo apt-get install zsh


<font size="+1">2. 安装 Git</font>

Oh My Zsh 使用 Git 来管理其存储库，因此您需要先安装 Git：

$ sudo apt-get install git


<font size="+1">3. 安装 Oh My Zsh</font>

使用以下命令安装 Oh My Zsh：

$ sh -c "$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"

该命令将从 Oh My Zsh 存储库下载安装脚本，并在您的系统上安装 Oh My Zsh。在安装过程中，您可能需要按下回车键来确认安装选项。

<font size="+1">4. 切换默认 shell</font>

默认情况下，您的系统可能仍在使用 Bash shell。要切换到 Zsh shell，请使用以下命令：

$ chsh -s $(which zsh)


<font size="+1">5. 配置 Oh My Zsh</font>

安装完成后，您可以通过编辑 ~/.zshrc 文件来配置 Oh My Zsh。该文件存储了 Zsh shell 的配置信息，包括主题、插件等。

您可以使用以下命令编辑该文件：

$ nano ~/.zshrc
在该文件中，您可以修改主题、添加插件、设置别名等。完成修改后，按下 Ctrl+X 键，然后按下 Y 键保存并退出文件。

<font size="+1"> 6. 使用 Oh My Zsh </font> 
现在 Oh My Zsh 已经安装成功，
但需要注销当前账户重新登入后才能被使用
尝试打开一个终端窗口，您应该会看到新的 Oh My Zsh shell。

除了自带的插件和主题之外，您还可以在 Oh My Zsh 的官方网站上找到更多的插件和主题，以满足您的需求。

希望这些步骤能够帮助您成功安装和配置 Oh My Zsh！

<font size="+1"> 7. 卸载oh-my-zsh命令：uninstall_oh_my_zsh  </font> 

<font size="+1">  8. 插件安装 </font> 
```
8.1 自动补全插件
1) 官网：Incremental completion on zsh
wget -O incr-0.2.zsh https://mimosa-pudica.net/src/incr-0.2.zsh

2) 复制incr*.zsh文件到plugins
cp incr-0.2.zsh .oh-my-zsh/plugins/

3) 在.zshrc 文件末尾添加下面这行
source ~/.oh-my-zsh/plugins/incr*.zsh

4) 重新打开终端，以使配置生效

```