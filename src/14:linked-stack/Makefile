run: *.java
	javac -encoding UTF-8 *.java
	java LinkedStackDemo.java

format: *.java
	astyle -Oo --convert-tabs --max-code-length=90 --remove-braces \
	--delete-empty-lines --pad-header *.java
