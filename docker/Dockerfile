FROM ubuntu:24.04 AS base

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update  && \
    apt-get install -y sudo fish zsh nano python3-psutil vim \
    g++ clang lld wget git ninja-build build-essential \
    python3 parallel lldb gdb python3-pygments
RUN userdel -r ubuntu && useradd bench -u 1000 -m -s /bin/bash && echo "bench ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

RUN mkdir exec-tmp/ && chmod 777 exec-tmp/

USER bench

RUN git clone https://github.com/AFLplusplus/AFLplusplus.git ~/afl && cd ~/afl && make -j8
ENV PATH="$PATH:/home/bench/afl/"

ENV NEEDLE="DUMMYNEEDLEVALUE"
