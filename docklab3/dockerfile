# Используем образ с нужным окружением
FROM ubuntu:latest
# Устанавливаем нужные пакеты
RUN apt-get update && \
    apt-get install -y build-essential nasm
# Копируем исходный код в контейнер
COPY . /app
# Переходим в директорию с исходным кодом
WORKDIR /app
RUN g++ -c main.cpp -o main.o
# Компилируем исполняемый файл
RUN g++ main.o -o program
# Запускаем исполняемый файл при запуске контейнера
CMD ["./program"]
