# coding=utf-8
import os
import re
import sys

Head = \
    r"""
\documentclass[a4paper]{article}
\usepackage{xeCJK} % For Chinese characters
\usepackage{amsmath, amsthm}
\usepackage{listings,xcolor}
\usepackage{geometry} % 设置页边距
\usepackage{fontspec}
\setsansfont{Monaco} % 设置英文字体
\setmonofont[Mapping={}]{Monaco} % 英文引号之类的正常显示，相当于设置英文字体
\geometry{left=2.5cm,right=2.5cm,top=2.5cm,bottom=2.5cm} % 页边距
% 代码格式设置
\lstset{
    language    = c++,
    breaklines  = true,
    captionpos  = b,
    tabsize     = 4,
    columns     = fullflexible,
    commentstyle = \color[RGB]{0,128,0},
    keywordstyle = \color[RGB]{0,0,255},
    basicstyle   = \large\ttfamily,
    stringstyle  = \color[RGB]{148,0,209}\ttfamily,
    rulesepcolor = \color{red!20!green!20!blue!20},
    showstringspaces = false,
}
"""


def Generate(filename):
    os.system('xelatex %s.tex' % filename)
    os.system('xelatex %s.tex' % filename)
    for suffix in ['aux', 'log', 'toc']:
        os.remove('%s.%s' % (filename, suffix))


def read(level, folder, pwd):
    if level == 1:
        f.write('\\clearpage\n')
    if folder:
        tmp = ['', 'section', 'subsection', 'subsubsection']
        f.write('\\%s{%s}\n' % (tmp[level], folder[1]))
    cur = os.popen('ls %s | grep .cpp -v | grep _' % pwd).read()
    if cur:
        folders = re.findall(r'(.*?)_(.*?)\n', cur)
        for folder in folders:
            read(level + 1, folder, pwd + '%s_%s/' % folder)
    else:
        cur = os.popen('ls %s | grep .cpp' % pwd).read()
        if cur:
            files = re.findall(r'(.*?)_(.*?)\n', cur)
            for file in files:
                if file[0] != '00':
                    tmp = ['', 'section', 'subsection', 'subsubsection']
                    f.write('\\%s{%s}\n' % (tmp[level + 1], file[1][:-4]))
                filename = '%s%s_%s' % (pwd, file[0], file[1])
                codes = open(filename, 'r')
                text = [line for line in codes]
                index = 0
                if text[index][:6] == '// ---':
                    index += 1
                    while index < len(text):
                        if text[index][:6] == '// ---':
                            index += 1
                            break
                        if index != 1:
                            f.write('\n')
                        f.write('%s' % text[index][3:-1])
                        index += 1
                if index < len(text):
                    f.write('\\begin{lstlisting}\n')
                    while index < len(text):
                        f.write('%s' % text[index])
                        index += 1
                    f.write('\\end{lstlisting}\n')
                # f.write('\\lstinputlisting{%s}\n' % filename)


if __name__ == '__main__':
    FileName = 'Manaual'
    Title = 'ACM/ICPC Template Manaual'
    Author = 'Mango Gao'

    f = open('%s.tex' % FileName, 'w')
    f.write('%s' % Head)
    f.write('\\title{%s}\n' % Title)
    f.write('\\author{%s}\n' % Author)
    f.write(
        '\\begin{document}\\large\n\\begin{titlepage}\n\\maketitle\n\\end{titlepage}\n\\clearpage\n\\tableofcontents\n')

    read(0, '', './')

    f.write('\\end{document}\n')
    f.close()
    Generate(FileName)
    os.system('open Manaual.pdf')
