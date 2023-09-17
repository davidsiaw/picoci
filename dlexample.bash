#!/bin/bash
[[ -z "$1" ]] && { echo "Please specify a directory"; exit 1; }

curl -s https://api.github.com/repos/davidsiaw/picoci/releases/latest \
| grep "example.tar.gz" \
| cut -d : -f 2,3 \
| tr -d \" \
| wget -qi -
mkdir -p .example-tmp
cd .example-tmp
tar xvf ../example.tar.gz
cd ..
mv .example-tmp/example ./$@
rm -rf .example-tmp
rm example.tar.gz
