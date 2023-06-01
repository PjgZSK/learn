# Start unity project failed with UPM(Unity Package Manager) exit code 3221225785
## 1. Environment
- Operate system  
```
systeminfo

OS 名称:          Microsoft Windows 7 旗舰版
OS 版本:          6.1.7601 Service Pack 1 Build 7601
```
- Unity version  
```
2021.3.8f1
```
- Unity Hub version  
```
win_3.1.2_with_editor_patchpro
```
## 2. Key error info
```
âŒ UPM health check (FAIL)
Start the UPM process and call its health endpoint
>> Server exited unexpectedly. Exit code: 3221225785
```
## 3. Fix it
- Fixed by updating to [KB3080149](https://www.catalog.update.microsoft.com/Search.aspx?q=KB3080149)
## 4. References
- [update-not-applicable-to-computer](https://www.minitool.com/backup-tips/update-not-applicable-to-computer.html)  
- [Unity Forums](https://forum.unity.com/threads/does-unitypackagemanager-needs-spying-update-for-windows7-starting-from-2021-2-17.1264310/)  

