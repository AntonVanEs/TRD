#!/bin/bash
find "$1" -depth -print0 | while read -r -d $'\0' f; do
	d=$(dirname "$f"); B=$(basename "$f"); b=$(echo "$B" | tr A-Z a-z)
	[ "$B" != "$b" ] && mv "$d/$B" "$d/$b"
done
