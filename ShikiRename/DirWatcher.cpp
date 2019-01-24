//src: https://docs.microsoft.com/en-us/windows/desktop/fileio/obtaining-directory-change-notifications
#include <DirWatcher.h>
#include <QDebug>

DirWatcher::DirWatcher(){
	//aborts current directory watch
	watchCancelEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
}

void DirWatcher::cancel() {
	SetEvent(watchCancelEvent);    // signal stop event
}

int DirWatcher::watchDirectory(LPTSTR lpDir) {
	TCHAR lpDrive[4];
	TCHAR lpFile[_MAX_FNAME];
	TCHAR lpExt[_MAX_EXT];
	_tsplitpath_s(lpDir, lpDrive, 4, NULL, 0, lpFile, _MAX_FNAME, lpExt, _MAX_EXT);
	lpDrive[2] = (TCHAR)'\\';
	lpDrive[3] = (TCHAR)'\0';

	DWORD watchStatus;
	HANDLE watchHandles[2];
	// Watch the directory for file creation and deletion. 
	watchHandles[0] = FindFirstChangeNotification(
		lpDir,                         // directory to watch 
		FALSE,                         // do not watch subtree 
		FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME | FILE_NOTIFY_CHANGE_LAST_WRITE); // watch file name changes 
	watchHandles[1] = watchCancelEvent;

	if (watchHandles[0] == INVALID_HANDLE_VALUE)
	{
		qDebug() << "DirWatcher - ERROR: FindFirstChangeNotification function failed: Handle is invalid";
		ExitProcess(GetLastError());
	}
	if ((watchHandles[0] == NULL))
	{
		qDebug() << "DirWatcher - ERROR: FindFirstChangeNotification function failed: Handle is NULL";
		ExitProcess(GetLastError());
	}

	// Change notification is set. Now wait on notification handle and refresh accordingly. 
	while (true)
	{
		// Wait for notification.
		qDebug() << "DirWatcher - Waiting for notification...";

		watchStatus = WaitForMultipleObjects(2, watchHandles, FALSE, INFINITE);

		switch (watchStatus)
		{
		case WAIT_OBJECT_0:

			// A file was created, renamed, or deleted in the directory.
			if (FindNextChangeNotification(watchHandles[0]) == FALSE)
			{
				qDebug() << "DirWatcher - ERROR: FindNextChangeNotification failed";
				ExitProcess(GetLastError());
			}
			return 0;

		case (WAIT_OBJECT_0 + 1):
			qDebug() << "DirWatcher - Aborted by function call";
			ResetEvent(watchCancelEvent);
			return 0;
		default:
			qDebug() << "DirWatcher - ERROR: Unhandled dwWaitStatus.";
			ExitProcess(GetLastError());
			return 1;
		}
	}
}
