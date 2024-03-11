#!/bin/bash

# Check if list.txt exists
if [ ! -f "output.txt" ]; then
    echo "Error: list.txt does not exist."
    exit 1
fi

# Read each line from list.txt and remove the corresponding file
while IFS= read -r file; do
    if [ -f "$file" ]; then
        rm -rf "$file"
        echo "Removed: $file"
    else
        echo "File does not exist: $file"
    fi
done < "output.txt"

