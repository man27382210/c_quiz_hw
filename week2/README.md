### Use gdb with docker 

- docker build . -t gdb
- docker run -v `pwd`:/tmp --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -i -t gdb
