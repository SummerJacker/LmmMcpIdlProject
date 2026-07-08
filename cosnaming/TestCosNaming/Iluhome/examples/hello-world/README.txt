#$Id: README.txt,v 1.4 2025/08/01 00:28:16 cvswxc Exp $
如何在Win32下运行当前程序
Step1:  首先需要用nmake 进行编译 ,命令是 
                	nmake -f  iluwin32.mak  
                	上面默认是在NODEBUG下运行, 如果需要进行Debug模式, 那么采用如下命令
      	nmake -f iluwin32.mak CFG="Win32 Debug"
Step2: 如果一切顺利, 生成的可执行程序在WinRel中. (Debug模式下是WinDebug)
	在WinRel中, 运行CMD命令,  server.exe 
	该程序会把当前服务程序(server.exe)的SBH序列码写入WinRel目录中一个叫SBHtempfile.tex的文件中. 
	打开该文件, 复制该SBH序列码. 
Step3: 同样, 打开一个新的CMD命令, 在WinRel中,运行 client.exe, 注意需要录入1个输入变量, 
	就是从SBHtempfile.txt中复制的SBH序列码, 一个是你自己任意输入的字符串. 
	client程序就会发送给服务端程序. 
	服务端程序会返回: Hello! (your message) 

需要改进的工作:

首先要求接收任务的同学, 首先学习相应的 java python lisp 语言哈. 

TODO 01 client需要不断地发送信息, 并得到返回的信息;  已经完成
TODO 02 需要改进JAVA; 保证在JAVA的Client can looply (exit will top) send server messages 
TODO 03 需要改进Python;  保证在Python的Client can looply (exit will top) send server messages 
TODO 04 需要改进lisp;  保证在lisp的Client can looply (exit will top) send server messages 
TODO 05 需要交叉进行跨语言的交换,共计4x4=16类之间的交叉client-server之间的调用试验. 
	that is :　client may be c java python lisp client; server may be c java python lisp server. 

TODO 06 有关客户端和服务端的失效安全改进：
　　　　	改进１：　关闭服务端后，　客户端能够抓取错误信息，　并在服务端恢复后，自动连接并继续运行（输入－返回）
	改进２：　关闭客户端，　再次启动，争取服务端能够抓取错误（很难）．



