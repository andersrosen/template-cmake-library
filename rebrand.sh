#!/bin/bash

NAME=myproject
NAME_MIXED_CASE=MyProject
NAME_FULL="My Project"
GITHUB_URL="https://github.com/andersrosen/myproject"
GITHUB_PAGES_URL="https://andersrosen.github.io/myproject"

sed -i -e "s/template/$NAME/g" .github/workflows/ubuntu.yml

sed -i -e "s/template/$NAME/g" -e "s/TEMPLATE/${NAME^^}/g" -e "s;\(CPACK_PROJECT_URL\) \".*\";\1 \"$GITHUB_URL\";" CMakeLists.txt
sed -i -e "s/template/$NAME/g" -e "s/TEMPLATE/${NAME^^}/g" docs/CMakeLists.txt
sed -i -e "s/template/$NAME/g" test/CMakeLists.txt

sed -i -e "s/template/$NAME/g" -e "s/Template/$NAME_MIXED_CASE/g" -e "s/TEMPLATE/${NAME^^}/g" test/test1.cpp

sed -i -e "s/template/$NAME/g" -e "s/Template/$NAME_MIXED_CASE/g" docs/examples/example1.cpp

sed -i -e "s/in the template/in the temmmplate/" -e "s/template/$NAME/g" -e "s/Template/$NAME_MIXED_CASE/g" -e "s/TEMPLATE/${NAME^^}/g" -e "s/in the temmmplate/in the template/" include/template/template.h
sed -i -e "s/template/$NAME/g" -e "s/Template/$NAME_MIXED_CASE/g" src/template.cpp

sed -i -e "s/template/$NAME/g" template-config.cmake.in
sed -i -e "s/project template/project temmmplate/" -e "s/template/$NAME/g" -e "s/project temmmplate/project template/" template.pc.in

sed -i -e "s/# template-cmake-library/# $NAME/" \
    -e "s;https://andersrosen\\.github\\.io/template-cmake-library;$GITHUB_PAGES_URL;g" \
    -e "s;https://github\\.com/andersrosen/template-cmake-library;$GITHUB_URL;g" \
    README.md

git mv include/template include/$NAME
git mv include/$NAME/template.h include/$NAME/$NAME.h
git mv template-config.cmake.in $NAME-config.cmake.in
git mv template.pc.in $NAME.pc.in
git mv src/template.cpp src/$NAME.cpp
