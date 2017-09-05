# coding=utf-8
import os
import sys
import json

TexHead = r"""
\documentclass[a4]{article}
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
        op = raw_input('是否使用已保存的设置？[Y/n]')
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
    TITLE = raw_input('请输入标题: ')
    AUTHOR = raw_input('请输入作者: ')
    FILE = raw_input('请输入文件名: ')
    Data = dict()
    for key in ['TITLE', 'AUTHOR', 'FILE']:
        Data[key] = globals()[key]
    json.dump(Data, open('setting.dat', 'w'))


def Clear():
    for suffix in ['aux', 'log', 'toc']:
        filename = '%s.%s' % (FILE, suffix)
        if os.path.exists(filename):
            os.remove(filename)


def Generate():
    Clear()
    os.system('xelatex %s.tex' % FILE)
    os.system('xelatex %s.tex' % FILE)
    Clear()
    os.system('open %s.pdf' % FILE)


def ReadCpp(file):
    f = open(file, 'r')
    Tex = 0
    TargetFile.write('\\begin{lstlisting}\n')
    for line in f:
        if line[:-1] == '// ---':
            Tex = not Tex
            ToWrite = '\\%s{lstlisting}\n' % ('begin', 'end')[Tex]
            TargetFile.write(ToWrite)
            continue
        TargetFile.write(line[(0, 3)[Tex]:])
    TargetFile.write('\\end{lstlisting}\n')
    f.close()


def ReadTex(file):
    f = open(file, 'r')
    for line in f:
        TargetFile.write(line)
    f.close()


def Search(level, pwd, folder=''):
    ls = os.popen('ls %s| grep [0-9]_' % pwd).read().split('\n')[:-1]
    if folder:
        TargetFile.write(SECTION[level] % folder[3:])
    for item in ls:
        item.replace(' ', '\\ ')
        if '.cpp' in item:
            if not item[:2] == '00':
                TargetFile.write(SECTION[level + 1] % item[3:-4])
            ReadCpp(pwd + item)
        elif '.tex' in item:
            if not item[:2] == '00':
                TargetFile.write(SECTION[level + 1] % item[3:-4])
            ReadTex(pwd + item)
        else:
            cd = os.popen('cd %s%s/' % (pwd, item)).read()
            if 'Not a directory' in cd or 'No such file or directory' in cd:
                print '[Unknown File] %s/%s' % (pwd, item)
            else:
                Search(level + 1, pwd + item + '/', item)


if __name__ == '__main__':
    # 全局设置
    TITLE, AUTHOR, FILE = '', '', ''
    SECTION = ['', '\\clearpage\\section{%s}\n',
               '\\subsection{%s}\n', '\\subsubsection{%s}\n']

    InitSetting()

    TargetFile = open('%s.tex' % FILE, 'w')


    # Output Head File
    TargetFile.write(TexHead)
    TargetFile.write('\\title{%s}\n' % TITLE)
    TargetFile.write('\\author{%s}\n' % AUTHOR)
    TargetFile.write('\\begin{document}\\large\n')
    TargetFile.write('\\begin{titlepage}\n\\maketitle\\setcounter{page}{0}\\thispagestyle{empty}\\clearpage\n\\clearpage\n\\tableofcontents\\clearpage\n\end{titlepage}\n')
    TargetFile.write('\\setcounter{section}{-1}\n')

    # Search Files
    Search(0, './')

    # End Output
    TargetFile.write('\n\\end{document}\n')
    TargetFile.close()

    # Gen
    Generate()
