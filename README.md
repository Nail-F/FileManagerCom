# FileManagerCom
There is a Windows app with the com-server and the com-client. File system implemented at the server side. The client uses it.

"The File Manager" Description: 
File manager is divided into two parts. 
1) Com-Server, which is described and implemented a file manager interface. To work with the file system used by the library boost 
2) File Manager application, which creates an object com server and the description of the file manager interface shall work with the file system. Achieved in the console application. 

Getting started: 
To get started, a file manager you must register with the com-interface library. 
To do this, run the following command in the console: 
regsvr32 IFileManagerCOM.dll
You can then run the file manager FileManagerConsole.exe 
After launching the application in the console window appears information on the commands that support the file manager. 
Supported commands: 
- copy files or folders, 
- rename (move) the folder and file 
- deleting folders (recursive) and files 
- to create the folder and file (a text file with the text: «Created file from FileManagerCOM») 
- display the list of folders and files in the specified directory 

Procedure: 
Command entry ends by pressing the Enter key. First entered the command name after the command arguments are entered, separated by a space. If you want to enter the name of the folder or file with a space in path, the entire argument must be enclosed in quotes. For example: mkfile "c: \ Program Files (x86) \ Test File.txt"
