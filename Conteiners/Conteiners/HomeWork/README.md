# TARvg17

### Homework - Get Varaible type and number from inu file. 

# You need to write a console application, that read and search vaible from input ini text file. 
 
Application shall search vaible by in name, and dispay type and number of this vaible from ini file.
If no var with this name - notify user. 

Please use T_variable struct
```javascript
typedef struct {
    QString varName;
    QString varType;
    int varId;
} T_variable;
```

If we use dl_gsw.ini, and user start applicatin:  
> 
> Please enter name to search, or 0 to exit:   
> >PHASE_SM0   
> Vaible 'PHASE_SM0' have type 'U8' and number '42'   
>    
> Please enter name to search, or 0 to exit:   
> >TARGET_GAUGE2   
> Vaible 'TARGET_GAUGE2' have type 'U16' and number '58'   
>    
> Please enter name to search, or 0 to exit:   
> >TARGET_GAUGE4   
> Can't find vaible 'TARGET_GAUGE4' in file 'dl_gsw.ini'   
> 
> Please enter name to search, or 0 to exit:   
> >MAX_EXEC_LOGIC_PT   
> Vaible 'MAX_EXEC_LOGIC_PT' have type 'U32' and number '86'   
>    
> Please enter name to search, or 0 to exit:   
> >0   
> Good bay!   
> 

