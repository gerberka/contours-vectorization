# Автоматическая векторизация контуров строений на спутниковых снимках

## Основные методы
vectorizeImg - векторизует контуры на изображении с использованием одного набора параметров. \
Возвращает вектор найденных контуров.

vectorizeImgWithSeveralParameters - векторизует контуры на изображении с исползованием нескольких набором параметров. \
Возвращает вектор контуров, обладающих наилучшим IoU.

В параметры обоих методов передается путь к папке, в которой будут находиться результаты.

В результаты входят: 
- iou.txt - текстовый файл с результатами iou для различных набором параметров. \
Первая строка - начальный IoU между исходным изображением (предобрабатнным нейронной сетью) и размеченным изображением. \
Последующие строки - IoU между результатом работы алгоритма с различными параметрами и размеченным изображением в формате: \
eps 1 interval 1 ppc 2 iou 0.652971
- time.txt - текстовый файл с временем выполнения работы алгоритма на различных наборах параметров. \
В первой строке количество контуров на исходном изображении. \
Последующие строки - время выполнения в секундах в формате: \
eps 1 interval 1 ppc 2 duration 2.40052e+06
- \_dpEps_{dpEps}\_interval_{interval}\_ppc_{ppc}.jpg - контуры, найденные алгоритмом с закрашенной внутренней областью
- only_contours\_dpEps_{dpEps}\_interval_{interval}\_ppc_{ppc}.jpg - розовые контуры - с исходного изображения, зеленые - результат работы алгоритма
- with_marking\_dpEps_{dpEps}\_interval_{interval}\_ppc_{ppc}.jpg - белые области - разметка, розовые контуры - с исходного изображения, зеленые - результат работы алгоритма

Что можно исправить
- Возможно Алгоритм Дугласа-Пекера при уменьшении количества вершин срезает важные точки, обозначающие углы зданий.
- Использовать альтернативный способ нахождения ближайших вспомогательных вершин. 
Сейчас ближайшими вспомогательными точками являются ближайшая вспомогательная точка и восемь точек с сетки, окружающих ее.
- Коренным образом модернизировать алгоритм, используя кроме предобрабатанного нейронной сетью изображения, еще и исходный спутниковый снимок.
