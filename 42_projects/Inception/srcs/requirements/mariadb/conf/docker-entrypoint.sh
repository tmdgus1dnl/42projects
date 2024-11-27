#!/bin/bash
set -e
mysqld_safe
bash /docker-entrypoint-initdb.d/init.sh
