#!/bin/bash

find examples/* -maxdepth 0 -type d  | parallel ./run.py "$@" "{}"
./summarize.py