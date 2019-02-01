## Сlass work 30.01.2019 ##   
Тема урока - The Qt Resource System, QLabel, QIcon  
Цель - сделать приложение, которое покажет разные иконки в QLabel  



Примеры кода с урока:

```c++
MainWindow::MainWindow(QWidget *parent) :`
    `QMainWindow(parent),`
    `ui(new Ui::MainWindow)`
`{`
    `ui->setupUi(this);`
    `ui->pushButton_sun->setChecked(true);` //Разрешаем кнопке быть "зажатой"
    
    //выставляем иконку для кнопки из ресурса small
    `ui->pushButton_sun->setIcon(QIcon(":/small/icons/48x48/sun.png"));`  
    
    //выставляем размер иконки. Если это не сделать, то иконка сожмется под указанием 
    // Layout Manager до обычного размера кнопки.
    `ui->pushButton_sun->setIconSize(QSize(48,48));`
`}
```





```c++
void MainWindow::on_pushButton_snow_clicked(bool checked)
{
	// пишем в дебаг состояние кнопки
    qDebug() << "on_pushButton_snow_clicked(bool checked)" << checked;

    if (checked) { //И если кнопка "зажата"
    	// выставляем по центру текст и иконку из ресурсов
        ui->label_snow->setText("<center>Snow is falling! <br> <img src=':/big/icons/256x256/snow.png'> ");
    } else {
    	// иначе - оставляем только текст, иконку не ставим
        ui->label_snow->setText("<center>Snow stop falling!<br>");
    }
}
```



Документация:  
* Официальная, последняя версия Qt 5.12   

  ​	http://doc.qt.io/qt-5/resources.html     
* Не официальная, на русском, версия Qt 4.6  

  ​	http://doc.crossplatform.ru/qt/4.6.x/resources.html  
* Туториал на английском  

  ​	https://www.bogotobogo.com/Qt/Qt5_Resource_Files.php  



