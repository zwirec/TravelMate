#!/usr/bin/env bash

INPUT=""
OUTPUT=""

while getopts ":i:o:" opt; do
  case $opt in
    i)
      INPUT=$OPTARG
      ;;
    o)
      OUTPUT=$OPTARG
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
    :)
      echo "Option -$OPTARG requires an argument." >&2
      exit 1
      ;;
  esac
done

# копируем файлик конфигурации в папку билда
cp $INPUT/config.json $OUTPUT
cp -R $INPUT/static $OUTPUT

# сюда пишем все шаблоны
TEMPLATES="$INPUT/templates/master.tmpl"
TEMPLATES="$TEMPLATES $INPUT/templates/news.tmpl"

# прожевываем шаблоны в срр-шник
cppcms_tmpl_cc $TEMPLATES -o $INPUT/all_tmpl.cpp

# собираем шаблоны в библиотеку
g++ -shared -fPIC -DPIC $INPUT/all_tmpl.cpp -o $OUTPUT/libcpp_defskin.so -lcppcms -lbooster