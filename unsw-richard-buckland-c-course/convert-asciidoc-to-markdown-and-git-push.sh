#!/bin/bash
# Convert asciidoc to docbook
asciidoc -b docbook Richard-Buckland-UNSW-Computing-1917-C-course.asciidoc

# Convert docbook to markdown
pandoc -f docbook -t markdown_strict Richard-Buckland-UNSW-Computing-1917-C-course.xml -o Richard-Buckland-UNSW-Computing-1917-C-course.md

# Clean up
rm Richard-Buckland-UNSW-Computing-1917-C-course.xml

# git stuff
git add Richard-Buckland-UNSW-Computing-1917-C-course.md
git commit -m "Added new notes from lectures."
git push
