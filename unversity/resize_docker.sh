#!/bin/bash

DATA_SIZE=$1
METADATA_SIZE=$2

if [ "$DATA_SIZE" = "" ]; then
    DATA_SIZE=1000
fi

if [ "$METADATA_SIZE" = "" ]; then
    METADATA_SIZE=10
fi

# Stop docker service
systemctl stop docker

# Resize docker data space
dd if=/dev/zero of=/var/lib/docker/devicemapper/devicemapper/data bs=1G count=0 seek=$DATA_SIZE

# Resize docker metadata space
dd if=/dev/zero of=/var/lib/docker/devicemapper/devicemapper/metadata bs=1G count=0 seek=$METADATA_SIZE

# Start docker service
systemctl start docker
