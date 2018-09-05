


bool mainFunc(){

    QTextStream cin(stdin);

    qDebug() << "Hello from swith";
    char sex;
    cin >> sex;
    switch (sex) {
    case 'M':
        qDebug() << "Male";
        return true;
        break;
    case 'W':
        qDebug() << "Female";
        return true;
        break;

    default:
        qDebug() << "Alien";
        break;
    }

    return false;

}


