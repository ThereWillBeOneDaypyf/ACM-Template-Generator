# ACM-Template-Generator
A generator for acm/icpc template manaual with Latex.

# Latex
Latex的安装和配置就不说了，网上有很多资料。

# 文件/目录结构

* 所有文件和目录的格式都按照`**_**`以及`**_**.cpp`的形式

> `10_Section1`
> `20_Section2`
> > `10_Section1-Charpter1`
> > `20_Section1-Charpter2`

> `30_Section3`
> > `00_Section3-Charpter1`_(Hide)_

> `40_Section4`
> `50_Section5`

* 生成tex文件时，按照命令行中'ls'的顺序生成各个章节

* 开头为`00_`时，不生成子标题，具体可见repo内的格式和pdf

* 代码开头两个```//  ---```中包含的内容，会去除注释符号后显示在代码前的正文部分，可以写数学公式等

# 编译pdf

* 使用xelatex编译ctex文件

# 命令

* 将py文件放到根目录下

* `python Manaual.py`

# Update
刚写的代码很丑，还在不断改进中...
