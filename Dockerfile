FROM      ubuntu:xenial

# update and install dependencies
RUN       apt-get update \
              && apt-get install -y make \
              && apt-get install -y cmake=3.5.1-1ubuntu3 \
              && apt-get install -y gcc-4.9 g++-4.9 gcc-4.9-base \
              && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.9 100


COPY ./build/./main.out /usr/app/
WORKDIR /usr/app

ENTRYPOINT ["./main.out", "encrypt", "123456ABCD132536", "AABB09182736CCDD"]
