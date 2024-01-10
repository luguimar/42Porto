#!/bin/sh
ifconfig | grep 'ether' | awk '{print $2}'
#-ioE '([a-z0-9]{2}:){5}..'