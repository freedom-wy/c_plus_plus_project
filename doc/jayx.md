### windows SDK
#### 字符编码
```txt
include <Windows.h>
在windows中使用TCHAR代表字符型,会根据项目属性unicode或多字节自动调整
使用tcslen()函数看字符长度
```
#### main方法
```txt
hinstance 实例句柄，指向我们的exe
hprevinstance 废弃
lpcmdline 命令行参数
ncmdshow 程序显示模式，最大化显示，最小化

在调试器中看到的main方法
ASCII main _mainCRTStartup
UNICODE main _mainCRTStartup或_wmainCRTStartup

windows程序
UNICODE wWinMain _wWinMainCRTStartup
ASCII WinMain _WinMainCRTStartup

MessageBox(句柄一般为NULL, "内容", "标题", 按钮类型)
```