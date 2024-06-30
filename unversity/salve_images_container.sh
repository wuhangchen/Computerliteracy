#!bin/bash

docker stop $(docker ps -a -q)
docker rm $(docker ps -a -q)
docker images
docker rmi $(docker images | grep "^<none>" | awk '{print $3}')

docker rm $(docker images -q)
docker info
