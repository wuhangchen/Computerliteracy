#!/bin/bash

CID=$1
SIZE=$2

if [ "$CID" != "" ] && [ "$SIZE" != "" ]; then
    DEV=$(basename $(echo /dev/mapper/docker-*-$CID));
    dmsetup table $DEV | sed "s/0 [0-9]* thin/0 $(($SIZE*1024*1024*1024/512)) thin/" | dmsetup load $DEV;
    dmsetup resume $DEV;
    resize2fs /dev/mapper/$DEV;
  echo "Resize $CID completed."
else
    echo "Usage: sh resize_container 459fd505311ad364309940ac24dcdb2bdfc68e3c3b0f291c9153fb54fbd46771 100";
fi
