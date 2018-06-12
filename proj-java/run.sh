#!/bin/bash

rm -rf *.txt target/

mvn clean package -Dpath=$@

mycommand="java -jar target/project2-1.0-SNAPSHOT-jar-with-dependencies.jar "$@
echo $mycommand
$mycommand
