#!/bin/bash
# Выводим информацию о программе
echo "Image convereter"
echo "Software to change the format and resolution of images"
echo "Developer: Sermavkin Nikita"
PICTURE_DIR=/home/vboxuser/Desktop/docklab/pictures
# Основной цикл программы
while true; do
    # Запрашиваем имя файла
    read -p "Введите имя файла: " filename
    # Проверяем, что файл существует в папке examples и является изображением
    if ! file "$PICTURE_DIR/$filename" | grep -q 'image'; then
        echo "Ошибка: $filename не является изображением" >&2
        continue
    fi
    # Запрашиваем формат, в который нужно конвертировать изображение
    read -p "Введите формат конвертирования (например, jpg): " format
    # Запрашиваем размер нового изображения
    read -p "Введите размер нового изображения (например, 800x600): " size
    # Конвертируем изображение
    if ! mogrify -format "$format" -resize "$size" "$PICTURE_DIR/$filename"; then
        echo "Ошибка: не удалось конвертировать изображение" >&2
        continue
    fi
    # Выводим сообщение об успешной конвертации
    echo "Изображение успешно сконвертировано в формат $format с размером $size"
    # Предлагаем начать заново или выйти из программы
    read -p "Желаете продолжить работу? (y/n): " answer
    case $answer in
        [yY])
            continue
            ;;
        [nN])
            exit 0
            ;;
        *)
            echo "Некорректный ответ. Работа программы завершена" >&2
            exit 1
            ;;
    esac
done
