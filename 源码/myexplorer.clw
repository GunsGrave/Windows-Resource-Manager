; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyexplorerView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "myexplorer.h"
LastPage=0

ClassCount=9
Class1=CMyexplorerApp
Class2=CMyexplorerDoc
Class3=CMyexplorerView
Class4=CMainFrame

ResourceCount=7
Resource1=ID_MENU2
Class5=CLeftView
Class6=CAboutDlg
Resource2=ID_MENU1
Resource3=IDR_MAINFRAME
Resource4=IDD_ABOUTBOX
Class7=CMyInputDlg
Class8=CMyInputDlg1
Resource5=IDD_DIALOG2
Resource6=IDD_DIALOG1
Class9=CSearchDlg
Resource7=IDD_DIALOG3

[CLS:CMyexplorerApp]
Type=0
HeaderFile=myexplorer.h
ImplementationFile=myexplorer.cpp
Filter=N
LastObject=CMyexplorerApp

[CLS:CMyexplorerDoc]
Type=0
HeaderFile=myexplorerDoc.h
ImplementationFile=myexplorerDoc.cpp
Filter=N
LastObject=CMyexplorerDoc

[CLS:CMyexplorerView]
Type=0
HeaderFile=myexplorerView.h
ImplementationFile=myexplorerView.cpp
Filter=C
LastObject=CMyexplorerView
BaseClass=CListView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame



[CLS:CLeftView]
Type=0
HeaderFile=LeftView.h
ImplementationFile=LeftView.cpp
Filter=T
LastObject=CLeftView
BaseClass=CTreeView
VirtualFilter=VWC

[CLS:CAboutDlg]
Type=0
HeaderFile=myexplorer.cpp
ImplementationFile=myexplorer.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_STATUS_BAR
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[MNU:ID_MENU1]
Type=1
Class=CMyexplorerView
CommandCount=0

[MNU:ID_MENU2]
Type=1
Class=CMyexplorerView
CommandCount=0

[DLG:IDD_DIALOG1]
Type=1
Class=CMyInputDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CMyInputDlg]
Type=0
HeaderFile=MyInputDlg.h
ImplementationFile=MyInputDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=CMyInputDlg1
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552

[CLS:CMyInputDlg1]
Type=0
HeaderFile=MyInputDlg1.h
ImplementationFile=MyInputDlg1.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMyInputDlg1

[DLG:IDD_DIALOG3]
Type=1
Class=CSearchDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CSearchDlg]
Type=0
HeaderFile=SearchDlg.h
ImplementationFile=SearchDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSearchDlg
VirtualFilter=dWC

