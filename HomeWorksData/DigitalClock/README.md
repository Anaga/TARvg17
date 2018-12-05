# TARvg17

### Homework - Digital Clock

# You need to write a GUI application, that show current time in one big LCD widget. 

This is realy simple application, only one lcdNumber in centralWidget, and status bar in MainWindow  
![see GUI](https://github.com/Anaga/TARvg17/blob/master/HomeWorksData/DigitalClock/GUI.JPG "GUI designer")  
 
In MainWindow class header you have timer, dateTime, qsTemp and one function - tick()  
![see header](https://github.com/Anaga/TARvg17/blob/master/HomeWorksData/DigitalClock/mainWindows_h.JPG "MainWindow.h")  
 
In MainWindow class implementation in constructor you have to create new timer, connect it with function  tick()  
![see cpp](https://github.com/Anaga/TARvg17/blob/master/HomeWorksData/DigitalClock/mainWindows_cpp.PNG "MainWindow.cpp")  
and then - write (add some logic in ) function tick()   
  
Output shall be like:   
![see App1](https://github.com/Anaga/TARvg17/blob/master/HomeWorksData/DigitalClock/Application.PNG "Ood value")  
![see App2](https://github.com/Anaga/TARvg17/blob/master/HomeWorksData/DigitalClock/Application2.PNG "Even value")  


The debug output is:  
> Timer start, call the tick   
> "2018.12.05 23:34:01"  
> "2018.12.05 23 34 02"  
> "2018.12.05 23:34:03"  
> "2018.12.05 23 34 04"  
> "2018.12.05 23:34:05"  
> "2018.12.05 23 34 06"  
> "2018.12.05 23:34:07"  

