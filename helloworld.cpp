#include <iostream>
#include <arrow/io/file.h>
#include <parquet/stream_reader.h>


int main () {
    std::shared_ptr<arrow::io::ReadableFile> infile;

    PARQUET_ASSIGN_OR_THROW(
        infile,
        arrow::io::ReadableFile::Open("test.parquet"));

    parquet::StreamReader os{parquet::ParquetFileReader::Open(infile)};

    int64_t size;
    double price;

    while (!os.eof())
    {
        os >> size >> price >> parquet::EndRow;
        std::cout << "SIZE: " << size << " PRICE: " << price << std::endl;
    }

    return 0;
}