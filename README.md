Equivalent implementations in Java and C++ to compare a language with embedded Garbage Collector, and a language that allow that task for the programmer. 
Maximum heap size has been se to be proportional to machine's memory. 

# Case A: Java faster, C++ slower
To make C++ slower compared to the same implementation in Java, we construct objects in memory with big gaps between them, to make the locality as bad as it gets. 

g++ -O2 ac++.cpp -o ac++; ./ac++ || javac AJava.java; java -Xmx8G AJava 

# Case B: Java slower, C++ faster
To make Garbage Collector slower, we construct object of total size to be proportional to machine's memory, and constantly delete them in order to force continuous garbage collection. 

g++ -O2 bc++.cpp -o bc++; ./bc++ || javac BJava.java; java -Xmx8G BJava

