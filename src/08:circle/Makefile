testStdin: Circle.java CircleDemo.java
	javac -encoding UTF-8 CircleDemo.java
	java CircleDemo

testArgs: Circle.java CircleDemo.java
	javac -encoding UTF-8 CircleDemo.java
	java CircleDemo 1 4.13 666.0

format: Circle.java CircleDemo.java
	astyle -Oo --convert-tabs --max-code-length=90 --remove-braces \
	--delete-empty-lines --pad-header *.java

deformat:
	rename '.orig' '' *.java.orig
