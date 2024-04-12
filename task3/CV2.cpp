#include "./CV2.h"
void CV2::grepBitmap()
{
    /*
        process the grep picture
    */
    double t1, t2;
    _pictureCol = pictureCol;
    _pictureRow = pictureRow;
    createBitmap(); // creat the blank picture board
    RGB *piont[pictureRow], *_piont[pictureRow];

    /*-------the primary of piont and _piont----------*/
    for (int i = 0; i < pictureRow; i++)
    {
        piont[i] = (RGB *)((char *)priex + i * stride);    // piont
        _piont[i] = (RGB *)((char *)_priex + i * _stride); //_piont
    }
    /*-----------------------------------------------*/

    t1 = omp_get_wtime();
    for (int i = 0; i < _pictureRow; i++)
    {
        for (int j = 0; j < _pictureCol; j++)
        {
            BYTE base = (BYTE)(piont[i][j].Blue * 0.33 + piont[i][j].Green * 0.33 + piont[i][j].Red * 0.33); // the vital
            _piont[i][j].Blue = base;
            _piont[i][j].Green = base;
            _piont[i][j].Red = base;
        }
    }
    t2 = omp_get_wtime();
    std::cout << std::endl;
    std::cout << "//*****************************//" << std::endl;
    std::cout << "// grep is: " << (t2 - t1) << "//" << std::endl;
    std::cout << "//*****************************//" << std::endl;
    std::cout << std::endl;
}
void CV2::ac_grepBitmap() {}
void CV2::binaryzationBitmap(int value)
{
    /*
        process the piture's binaryzation
    */
    double t1, t2;
    _pictureCol = pictureCol;
    _pictureRow = pictureRow;
    RGB *piont[pictureRow], *_piont[pictureRow];
    createBitmap(); // creat the blank picture board

    /*-------the primary of piont and _piont----------*/
    for (int i = 0; i < pictureRow; i++)
    {
        piont[i] = (RGB *)((char *)priex + i * stride);    // piont
        _piont[i] = (RGB *)((char *)_priex + i * _stride); //_piont
    }
    /*-----------------------------------------------*/
    t1 = omp_get_wtime();
    for (int i = 0; i < pictureRow; i++)
    {
        for (int j = 0; j < pictureCol; j++)
        {
            BYTE base = (BYTE)(piont[i][j].Blue * 0.33 + piont[i][j].Green * 0.33 + piont[i][j].Red * 0.33);
            if (base > value)
                base = WHITE; // the vital
            else
                base = BLACK;
            _piont[i][j].Blue = base;
            _piont[i][j].Green = base;
            _piont[i][j].Red = base;
        }
    }
    t2 = omp_get_wtime();
    std::cout << std::endl;
    std::cout << "//*****************************//" << std::endl;
    std::cout << "// binaryzation is: " << (t2 - t1) << "//" << std::endl;
    std::cout << "//*****************************//" << std::endl;
    std::cout << std::endl;
}
void CV2::ac_binaryzationBitmap(int value) {}
void CV2::segmentBitmap(int beginCol, int beginRow, int _col, int _row)
{
    /*
        to segment your picture
    */
    double t1, t2;
    _pictureRow = _row;
    _pictureCol = _col;
    createBitmap(); // creat the blank picture board
    RGB *piont[pictureRow], *_piont[pictureRow];
    for (int i = 0; i < pictureRow; i++)
    {
        piont[i] = (RGB *)((char *)priex + i * stride);    // piont
        _piont[i] = (RGB *)((char *)_priex + i * _stride); //_piont
    }
    int Clen = beginCol + _pictureCol;
    int Rlen = beginRow + _pictureRow;
    t1 = omp_get_wtime();
    for (int i = beginRow; i < Rlen; i++)
    {
        for (int j = beginCol; j < Clen; j++)
        {
            _piont[i - beginRow][j - beginCol] = piont[i][j]; // the vital
        }
    }
    t2 = omp_get_wtime();
    std::cout << std::endl;
    std::cout << "//*****************************//" << std::endl;
    std::cout << "// segment is: " << (t2 - t1) << "//" << std::endl;
    std::cout << "//*****************************//" << std::endl;
    std::cout << std::endl;
}
void CV2::ac_segmentBitmap(int beginCol, int beginRow, int _col, int _row) {}
void CV2::createBitmap()
{
    /*
        to creat the blank picture board
    */
    _Tag = *Tag;
    _Head = *Head;
    _Tag.biWidth = _pictureCol;                                      // change of the picture col
    _Tag.biHeight = _pictureRow;                                     // change of the picture row
    _Head.bfSize = Head->bfOffBits + _pictureRow * stride;           // change of the head and tag
    out = malloc(_Head.bfSize);                                      // call some room of the new picture
    _stride = (((_pictureCol * (Tag->biBitCount) + 31) & ~31) >> 3); // change of the new stride
    _pictureSize = _Head.bfSize;
    *(BITMAPFILE *)out = _Head;                      // introduce the new Head
    *(BITMAPINFOR *)((char *)out + 14) = _Tag;       // introduce the new Tag
    _priex = (RGB *)((char *)out + Head->bfOffBits); // locate the out(pionter)
}
CV2::CV2(FILE *file)
{
    /*
        jude the picture whether exsit and get the basic information of the picture
    */
    if (file == NULL)
        std::cout << "The file does not exit" << std::endl;
    file_in = file;
    fseek(file, 0, SEEK_END);
    pictureSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    bitmap = (void *)malloc(pictureSize);
    fread(bitmap, pictureSize, 1, file);                             // put your picture to your memory
    Head = (FileHeadBitmap *)bitmap;                                 // creat the Head
    Tag = (BITMAPINFOR *)(Head + 1);                                 // creat the Tag
    priex = (RGB *)((char *)Head + (Head->bfOffBits));               // creat the priex
    stride = (((Tag->biWidth * (Tag->biBitCount) + 31) & ~31) >> 3); // the size of stride
    pictureRow = Tag->biHeight;                                      // the size of row;
    pictureCol = Tag->biWidth;                                       // the size of col
    std::cout << "//*****************************//" << std::endl;
    std::cout << "//      Get the picture        //" << std::endl; // make sure the picture is gotten
    std::cout << "//*****************************//" << std::endl;
}
CV2::~CV2()
{
    // release the the old and new picture in your memory
    // and release the file pionter
    std::cout << "//*****************************//" << std::endl;
    std::cout << "//The room of memory is release//" << std::endl;
    std::cout << "//*****************************//" << std::endl;
    free(bitmap);
    free(out);
    fclose(file_in);
    fclose(file_out);
}
void CV2::readBitmap(FILE *file)
{
    /*
        put out your picture that has been processed
    */
    file_out = file;
    fwrite(out, _pictureSize, 1, file);
}