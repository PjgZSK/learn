# Android Quick Start
## 1. Concept
- app : application  
- apk : android package  
- component : the essential building blocks of an android app, there four type of component  
    - services : a general-purpose entry point for keeping an app running in the background  
        for all king of reasons  
    - activities : the entry point for interacting with the user  
    - broadcast receivers : let the system deliver events to the app outside of regular user  
        flow so the app can respond to system-wide broadcast announcements  
    - content providers : manages a shared set of app data that you can store in the file system  
- intent : an asynchronous message activates three of four component types : activities, services  
    and broadcast receivers  
- magnifest : app defines all components in this file  
## 2. About android
1. The android operating system is a multi-user linux system in which each app is  
different user  
2. By default, every app runs in its own linux process, each process has its own virtual machine  
3. When the system start a component, it start the process for that app  
4. Any app can start another app's component  
5. android don't have s single entry point, there is no main() function  
## 3. Processes and threads in android application
- main thread : dispatch events to the approciate user interface widgets, including draw events  
