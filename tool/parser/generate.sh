#!/bin/bash

cd $(dirname "$0");
rm -rf ./out;
mkdir -p ./out;
./v8adk execute ./generate.js > ./out/bindings.cpp;

