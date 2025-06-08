#!/bin/bash

# Проверка аргументов
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <количество чисел>"
    exit 1
fi

COUNT=$1

# Генерация уникальных случайных чисел
NUMBERS=$(shuf -i 1-1000 -n $COUNT | tr '\n' ' ')

echo "Сгенерировано $COUNT чисел:"
echo "$NUMBERS"

echo -e "\nЗапуск push_swap:"
./push_swap $NUMBERS

echo -e "\nПроверка сортировки:"
./push_swap $NUMBERS | ./checker_linux $NUMBERS

echo -e "\nКоличество операций:"
./push_swap $NUMBERS | wc -l