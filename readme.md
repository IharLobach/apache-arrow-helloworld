# Instructions how to install apache-arrow with parquet support

Tested on Ubuntu 18.04 (WSL-2)

## Building apache-arrow

https://arrow.apache.org/docs/developers/cpp/building.html

```shell
git clone https://github.com/apache/arrow.git
cd arrow/cpp
mkdir release
cd release
cmake .. -DARROW_DATASET=ON -DARROW_FILESYSTEM=ON -DARROW_PARQUET=ON -DARROW_PLASMA=ON -DARROW_PYTHON=ON -DARROW_WITH_SNAPPY=ON -DARROW_WITH_ZLIB=ON 
make
sudo make install
```

## C++ compile command

http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html

```shell
g++ -g helloworld.cpp -o helloworld -I/usr/local/include -L/usr/local/lib -larrow -lparquet -lsnappy -lzlib
```

-- the libraries used in the code have to be specified, e.g., for `libarrow.so` you need to add the flag `-larrow`, etc. `-I/usr/local/include` is the location of header files (`.h`). `-L/usr/local/lib` is the location of `.so` files.

Then, just run the executable by using

```shell
./helloworld
```


## Setting up environment variables

http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html

Your executable needs to know the library path. To set it up, add this to your `~/.bashrc` file:

```
if [ -d \usr\local\lib ];
then
   LD_LIBRARY_PATH=\usr\local\lib:$LD_LIBRARY_PATH
fi


export LD_LIBRARY_PATH
```

`\usr\local\lib` is where the `.so` files are located.







