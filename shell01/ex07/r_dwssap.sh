cut -d: -f1 /etc/passwd | grep -v '#' | sed -n 'n;p' | rev | sort -r | head -n $FT_LINE2 | tail -n $FT_LINE1 | xargs | sed -e 's/ /, /g' | sed '$s/$/ ./' | tr -d '\n'
