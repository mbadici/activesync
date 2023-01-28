#!/bin/bash
cp bin/Debug/activesync bin/Debug/activesync.cgi
rm log
rm state
touch state;touch log
chmod 777 log;chmod 777 state
