#!/bin/bash

# Define the log file
LOG_FILE="daemon_log.txt"

# Get the current date and time
CURRENT_TIME=$(date)

# Write a message to the log file
echo "Script executed by daemon at: $CURRENT_TIME" >> "$LOG_FILE"

