#!/bin/bash



find /etc -mtime +14 -user "root" -regex "[^rap]" -perm -o+r
