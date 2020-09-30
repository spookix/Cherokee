FROM debian:buster

RUN apt-get update -y && apt-get install git g++ cmake -y

COPY CMakeLists.txt /app/
COPY Criterion /app/Criterion
COPY include/ /app/include
COPY src/ /app/src
COPY test/ app/test

WORKDIR /app
RUN cmake . && make && make install

EXPOSE 8080

ENTRYPOINT ["cherokee"]
