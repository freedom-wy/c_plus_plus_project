### windows sdk 开发
#### 字符编码
```txt
根据unicode和多字节调整TCHAR
TCHAR* tszWinBuffer; // 定义变量
通过_tcslen来查看字符串长度
通过printf输出字符串时,%S表示unicode，%s表示ascii

console程序
argc参数个数, argv参数
反编译时入口函数_mainCRTStartup为ASCII版入口函数,_wmainCRTStartup为unicode版入口函数

windows程序
反编译时入口函数 WinMain _WinMainCRTStartup为ascii版入口函数, wWinMain _wWinMainCRTStartup为unicode版入口函数

在visual studio中，显示为紫色则为宏
```