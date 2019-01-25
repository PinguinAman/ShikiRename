#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>

class DirWatcher
{
private:
	HANDLE watchCancelEvent;
public:
	DirWatcher();
	int watch(LPTSTR);
	void cancel();
};
