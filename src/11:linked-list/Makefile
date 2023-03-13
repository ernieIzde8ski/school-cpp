run: *.java
	javac -encoding UTF-8 -Xlint:unchecked *.java
	java LinkedListDemo

format: *.java
	astyle -Oo --convert-tabs --max-code-length=90 --remove-braces \
	--pad-header *.java
