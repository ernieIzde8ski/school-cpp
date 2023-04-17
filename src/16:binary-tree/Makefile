.PHONY: format

BinaryTreeDemo.class: *.java
	javac -encoding UTF-8 *.java
	java BinaryTreeDemo.java

format: *.java
	astyle -Oo --convert-tabs --max-code-length=90 --remove-braces \
	--pad-header *.java
