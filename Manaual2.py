# coding=utf-8
import os
import sys
import json

TexHead = r"""
\documentclass[a4paper]{article}
\usepackage{xeCJK}
\usepackage{amsmath, amsthm}
\usepackage{listings,xcolor}
\usepackage{geometry}
\usepackage{fontspec}
\setsansfont{Monaco}
\setmonofont[Mapping={}]{Monaco}
\geometry{left=2.5cm,right=2.5cm,top=2.5cm,bottom=2.5cm}
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


def InitSetting():
    try:
        SettingFile = file('setting.dat')
        SettingData = json.load(SettingFile)
        print u'读取到保存的设置: '
        for key in SettingData:
            print '[%s] %s' % (key, SettingData[key])
        op = raw_input(u'是否使用已保存的设置？[Y/n]')
        if not op in ['n', 'N', 'no', 'No', 'NO']:
            global TITLE, AUTHOR, FILE
            for key in ['TITLE', 'AUTHOR', 'FILE']:
                globals()[key] = SettingData[key]
        else:
            NewSetting()
    except:
        print u'读取设置失败'
        NewSetting()


def NewSetting():
    global TITLE, AUTHOR, FILE
    TITLE = raw_input(u'请输入标题: ')
    AUTHOR = raw_input(u'请输入作者: ')
    FILE = raw_input(u'请输入文件名: ')
    Data = dict()
    for key in ['TITLE', 'AUTHOR', 'FILE']:
        Data[key] = globals()[key]
    json.dump(Data, open('setting.dat', 'w'))


def Generate():
    os.system('xelatex %s.tex' % FILE)
    for suffix in ['aux', 'log', 'toc']:
        os.remove('%s.%s' % (FILE, suffix))
        os.system('open %s.pdf' % FILE)


def dfs(pwd):
    ls = os.popen('ls | grep [0-9]_').read().split('\n')[:-1]
    for item in ls:
        if '.cpp' in item:
            pass
        elif '.md' in item:
            pass
        else:
            pass


if __name__ == '__main__':
    # 全局设置
    TITLE, AUTHOR, FILE = '', '', ''

    InitSetting()

    TargetFile = open('%s.tex' % FILE, 'w')

    # Output Head File
    TargetFile.write(TexHead)
    TargetFile.write('\\title{%s}\n' % TITLE)
    TargetFile.write('\\author{%s}\n' % AUTHOR)
    TargetFile.write('\\begin{document}\\large\n')
    TargetFile.write('\\maketitle\\clearpage\n\\tableofcontents\\clearpage\n')

    # Search Files
    dfs('./')

    # End Output
    TargetFile.write('\\end{document}\n')
    TargetFile.close()

    # Gen
    # Generate()
