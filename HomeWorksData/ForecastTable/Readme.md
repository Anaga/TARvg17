### Homework - Forcast table    
Start: 16.01.2019, deadline: 30.01.2018    
Задача: Сделать приложение, которое пошлет запрос прогноза погоды на сервер, указав ИД города  
и получив в отвте большой JSON с прогнозом на каждые 3 часа, выберет нужную информацию о времени, температуре и погоде
вывести результаты в виде таблички:

Вам нужно в первой колонке показать время
"dt_txt":"2019-02-01 12:00:00"

Во второй - температуру
"temp":-2.47

В третьей колонке - описание погоды  
"description":"light snow"

API call:
api.openweathermap.org/data/2.5/forecast?id={city ID}
Parameters:
id city ID
Examples of API calls:
https://api.openweathermap.org/data/2.5/forecast?id=524901

Пример ответа от сервера
> 
> {"dt":1549022400,"main":{"temp":-2.47,"temp_min":-2.47,"temp_max":-2.47,"pressure":1022.03,"sea_level":1025.73,"grnd_level":1022.03,"humidity":100,"temp_kf":0},"weather":[{"id":600,"main":"Snow","description":"light snow","icon":"13d"}],"clouds":{"all":92},"wind":{"speed":8.71,"deg":94.0035},"snow":{"3h":0.34875},"sys":{"pod":"d"},"dt_txt":"2019-02-01 12:00:00"},
> {"dt":1549033200,"main":{"temp":-1.7, "temp_min":-1.7, "temp_max":-1.7, "pressure":1021.69,"sea_level":1025.33,"grnd_level":1021.69,"humidity":100,"temp_kf":0},"weather":[{"id":600,"main":"Snow","description":"light snow","icon":"13n"}],"clouds":{"all":92},"wind":{"speed":8.36,"deg":98.5043},"snow":{"3h":0.59},   "sys":{"pod":"n"},"dt_txt":"2019-02-01 15:00:00"},
> {"dt":1549044000,"main":{"temp":-1.4, "temp_min":-1.4, "temp_max":-1.4, "pressure":1021.3, "sea_level":1024.97,"grnd_level":1021.3, "humidity":100,"temp_kf":0},"weather":[{"id":600,"main":"Snow","description":"light snow","icon":"13n"}],"clouds":{"all":92},"wind":{"speed":8.26,"deg":104.001},"snow":{"3h":0.4675}, "sys":{"pod":"n"},"dt_txt":"2019-02-01 18:00:00"},
> {"dt":1549054800,"main":{"temp":-0.97,"temp_min":-0.97,"temp_max":-0.97,"pressure":1021.52,"sea_level":1025.13,"grnd_level":1021.52,"humidity":100,"temp_kf":0},"weather":[{"id":600,"main":"Snow","description":"light snow","icon":"13n"}],"clouds":{"all":92},"wind":{"speed":7.27,"deg":111.509},"snow":{"3h":0.51},   "sys":{"pod":"n"},"dt_txt":"2019-02-01 21:00:00"},
> {"dt":1549065600,"main":{"temp":-0.59,"temp_min":-0.59,"temp_max":-0.59,"pressure":1021.3, "sea_level":1024.9, "grnd_level":1021.3, "humidity":100,"temp_kf":0},"weather":[{"id":600,"main":"Snow","description":"light snow","icon":"13n"}],"clouds":{"all":92},"wind":{"speed":6.21,"deg":117.001},"snow":{"3h":0.63},   "sys":{"pod":"n"},"dt_txt":"2019-02-02 00:00:00"},
> {"dt":1549076400,"main":{"temp":-0.25,"temp_min":-0.25,"temp_max":-0.25,"pressure":1020.77,"sea_level":1024.4, "grnd_level":1020.77,"humidity":100,"temp_kf":0},"weather":[{"id":600,"main":"Snow","description":"light snow","icon":"13n"}],"clouds":{"all":92},"wind":{"speed":5.92,"deg":117.503},"snow":{"3h":0.265},  "sys":{"pod":"n"},"dt_txt":"2019-02-02 03:00:00"},
> {"dt":1549087200,"main":{"temp":-0.01,"temp_min":-0.01,"temp_max":-0.01,"pressure":1021.1, "sea_level":1024.74,"grnd_level":1021.1, "humidity":100,"temp_kf":0},"weather":[{"id":600,"main":"Snow","description":"light snow","icon":"13n"}],"clouds":{"all":92},"wind":{"speed":5.81,"deg":120.503},"snow":{"3h":0.4525}, "sys":{"pod":"n"},"dt_txt":"2019-02-02 06:00:00"},
> 

У вас должно быть в табличке

> | 2019-02-01 12:00:00 | -2.47 | light snow |
> | 2019-02-01 15:00:00 | -1.7  | light snow |
> | 2019-02-01 18:00:00 | -1.4  | light snow |
> | 2019-02-01 21:00:00 | -0.97 | light snow |
> | 2019-02-02 00:00:00 | -0.59 | light snow |
> | 2019-02-02 03:00:00 | -0.25 | light snow |
> | 2019-02-02 06:00:00 | -0.01 | light snow |

Пример ответа от сервера
> {"dt":1549184400,"main":{"temp":1.05,"temp_min":1.05,"temp_max":1.05,"pressure":1015.21,"sea_level":1018.79,"grnd_level":1015.21,"humidity":98,"temp_kf":0},"weather":[{"id":601,"main":"Snow","description":"snow"         ,"icon":"13d"}],"clouds":{"all":92},"wind":{"speed":8   ,"deg":105}                       ,"snow":{"3h":2.37}  ,"sys":{"pod":"d"},"dt_txt":"2019-02-03 09:00:00"},
> {"dt":1549195200,"main":{"temp":1.36,"temp_min":1.36,"temp_max":1.36,"pressure":1014.57,"sea_level":1018.24,"grnd_level":1014.57,"humidity":93,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain"   ,"icon":"10d"}],"clouds":{"all":92},"wind":{"speed":6.79,"deg":110.501},"rain":{"3h":1.15},"snow":{"3h":3.165} ,"sys":{"pod":"d"},"dt_txt":"2019-02-03 12:00:00"},
> {"dt":1549206000,"main":{"temp":1.97,"temp_min":1.97,"temp_max":1.97,"pressure":1014.2, "sea_level":1017.92,"grnd_level":1014.2, "humidity":90,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain"   ,"icon":"10n"}],"clouds":{"all":92},"wind":{"speed":5.99,"deg":126.001},"rain":{"3h":1.16},"snow":{"3h":0.455} ,"sys":{"pod":"n"},"dt_txt":"2019-02-03 15:00:00"},
> {"dt":1549216800,"main":{"temp":2.02,"temp_min":2.02,"temp_max":2.02,"pressure":1014.02,"sea_level":1017.6, "grnd_level":1014.02,"humidity":92,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain"   ,"icon":"10n"}],"clouds":{"all":92},"wind":{"speed":5.37,"deg":143.502},"rain":{"3h":1.69},"snow":{}           ,"sys":{"pod":"n"},"dt_txt":"2019-02-03 18:00:00"},
> {"dt":1549227600,"main":{"temp":1.85,"temp_min":1.85,"temp_max":1.85,"pressure":1013.83,"sea_level":1017.41,"grnd_level":1013.83,"humidity":93,"temp_kf":0},"weather":[{"id":501,"main":"Rain","description":"moderate rain","icon":"10n"}],"clouds":{"all":92},"wind":{"speed":4.92,"deg":151.001},"rain":{"3h":4.28},"snow":{}           ,"sys":{"pod":"n"},"dt_txt":"2019-02-03 21:00:00"},
> {"dt":1549238400,"main":{"temp":1.38,"temp_min":1.38,"temp_max":1.38,"pressure":1014.38,"sea_level":1018.03,"grnd_level":1014.38,"humidity":96,"temp_kf":0},"weather":[{"id":501,"main":"Rain","description":"moderate rain","icon":"10n"}],"clouds":{"all":92},"wind":{"speed":4.57,"deg":184.501},"rain":{"3h":3.51},"snow":{"3h":0.0075},"sys":{"pod":"n"},"dt_txt":"2019-02-04 00:00:00"},
> {"dt":1549249200,"main":{"temp":0.94,"temp_min":0.94,"temp_max":0.94,"pressure":1015.56,"sea_level":1019.12,"grnd_level":1015.56,"humidity":97,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain"   ,"icon":"10n"}],"clouds":{"all":80},"wind":{"speed":5.67,"deg":195.002},"rain":{"3h":0.41},"snow":{"3h":0.105} ,"sys":{"pod":"n"},"dt_txt":"2019-02-04 03:00:00"},
> {"dt":1549260000,"main":{"temp":1.04,"temp_min":1.04,"temp_max":1.04,"pressure":1016.73,"sea_level":1020.3, "grnd_level":1016.73,"humidity":96,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain"   ,"icon":"10n"}],"clouds":{"all":88},"wind":{"speed":6.12,"deg":201}    ,"rain":{"3h":0.02},"snow":{"3h":0.15}  ,"sys":{"pod":"n"},"dt_txt":"2019-02-04 06:00:00"},
> {"dt":1549270800,"main":{"temp":0.97,"temp_min":0.97,"temp_max":0.97,"pressure":1018.4, "sea_level":1022.1, "grnd_level":1018.4, "humidity":97,"temp_kf":0},"weather":[{"id":500,"main":"Rain","description":"light rain"   ,"icon":"10d"}],"clouds":{"all":92},"wind":{"speed":6.06,"deg":204.006},"rain":{"3h":0.08},"snow":{"3h":0.1125},"sys":{"pod":"d"},"dt_txt":"2019-02-04 09:00:00"},
> {"dt":1549281600,"main":{"temp":0.9, "temp_min":0.9, "temp_max":0.9, "pressure":1019.37,"sea_level":1023.07,"grnd_level":1019.37,"humidity":97,"temp_kf":0},"weather":[{"id":600,"main":"Snow","description":"light snow"   ,"icon":"13d"}],"clouds":{"all":88},"wind":{"speed":6.31,"deg":209.001},"rain":{}         ,"snow":{"3h":0.1225},"sys":{"pod":"d"},"dt_txt":"2019-02-04 12:00:00"},


У вас должно быть в табличке
> | 2019-02-03 09:00:00 | +1.05 | snow          |
> | 2019-02-03 12:00:00 | +1.36 | light rain    |
> | 2019-02-03 15:00:00 | +1.97 | light rain    |
> | 2019-02-03 18:00:00 | +2.02 | light rain    |
> | 2019-02-03 21:00:00 | +1.85 | moderate rain |
> | 2019-02-04 00:00:00 | +1.38 | moderate rain |
> | 2019-02-04 03:00:00 | +0.94 | light rain    |
> | 2019-02-04 06:00:00 | +1.04 | light rain    |
> | 2019-02-04 09:00:00 | +0.97 | light rain    |
> | 2019-02-04 12:00:00 | +0.9  | light snow    |

Документация:
https://openweathermap.org/forecast5