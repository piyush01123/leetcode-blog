# Read from the file words.txt and output the word frequency list to stdout.
# python - c "words = open('words.txt').read().replace('\n', ' ').split();fq = {w:words.count(w) for w in words};fqs = sorted(fq.items(), key=lambda kv: kv[1], reverse =  True);tpr = '\n'.join([x[0]+ ' ' + str(x[1]) for x in fqs]);print(tpr)"

cat words.txt | tr -s [:space:] ' ' | tr '  ' '\n' | sort | uniq -c | sort -rn | awk '{print $2" "$1}'