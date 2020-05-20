//
//        This sample project illustrates how to capture crashes (unhandled exceptions) in native Windows applications using BugSplat.
//
//        The shared sample database 'Fred' is used in this example.
//        You may view crashes for the Fred account by logging in at https://www.bugsplat.com:
//        Account (Email Address): Fred 
//                       Password: Flintstone
//
//        In order to assure that crashes sent to the BugSplat website yield exception stack traces with file/line # information, 
//        just rebuild this project.  A Visual Studio post build event is configured to send the resulting .exe and .pdb files
//        to BugSplat via the SendPdbs utility.  If you wish to use your own account and database, you will need to modify the post build
//        event accordingly.  If you do not care about file/line # info or for any reason you do not want  to send these files, 
//        simply disable the post build event.
//
//        More information is available online at https://www.bugsplat.com


#pragma optimize( "", off) // prevent optimizer from interfering with our crash-producing code

#include "stdafx.h"
#include "BugSplat.h"
#include "Editor.h"
#include "Doohickey.h"
#include "Gizmo.h"
#include "Widget.h"

MiniDmpSender *mpSender;

int wmain(int argc, wchar_t **argv)
{
	if (IsDebuggerPresent())
	{
		wprintf(L"Run this application without the debugger attached to enable BugSplat exception handling.\n");
		//DebugBreak();
		//exit(0);
	}

	// BugSplat initialization.  Post crash reports to the "Fred" database for application "myConsoleCrasher" version "1.0"
	mpSender = new MiniDmpSender(L"Fred", L"mySubkeyCrasher", L"1.0", NULL, MDSF_USEGUARDMEMORY | MDSF_LOGFILE | MDSF_PREVENTHIJACKING);

	// The following calls add support for collecting crashes for abort(), vectored exceptions, out of memory,
	// pure virtual function calls, and for invalid parameters for OS functions.
	// These calls should be used for each module that links with a separate copy of the CRT.
	SetGlobalCRTExceptionBehavior();
	SetPerThreadCRTExceptionBehavior();  // This call needed in each thread of your app

	// A guard buffer of 20mb is needed to catch OutOfMemory crashes
	mpSender->setGuardByteBufferSize(20*1024*1024);

	// Set optional default values for user, email, and user description of the crash.
	mpSender->setDefaultUserName(_T("Fred"));
	mpSender->setDefaultUserEmail(_T("fred@bedrock.com"));
	mpSender->setDefaultUserDescription(_T("This is the default user crash description."));

	// Force a crash, in a variety of ways
	for (int i = 1; i < argc; i++) {

		// Crash saving the contents of a Doohickey!
		if (!_wcsicmp(argv[i], L"/Doohickey")) {
			Doohickey *doohickey = new Doohickey();
			Editor editor(doohickey);
			editor.Edit();
			editor.Save();
		}

		// Crash saving the contents of a Gizmo!
		if (!_wcsicmp(argv[i], L"/Gizmo")) {
			Gizmo* gizmo = new Gizmo();
			Editor editor(gizmo);
			editor.Edit();
			editor.Save();
		}

		// Crash saving the contents of a Widget!
		if (!_wcsicmp(argv[i], L"/Widget")) {
			Widget* widget = new Widget();
			Editor editor(widget);
			editor.Edit();
			editor.Save();
		}
	}

	return 0;
}
