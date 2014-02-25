#!/bin/bash
OUTFILE="Samples/recording_$TIME.wav"

# Get sink monitor:
MONITOR=$(pactl list | grep -A2 '^Source #' | grep 'Name: .*\.monitor$' | awk '{print $NF}' | tail -n1)

parec -d "$MONITOR" | arecord -f cd -d180
