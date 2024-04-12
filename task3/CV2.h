#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <omp.h>
#define BYTE uint8_t
#define WORD uint16_t
#define LONG int32_t
#define DWORD uint32_t
#pragma pack(1)
typedef struct FileHeadBitmap
{
    WORD bftype;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} BITMAPFILE;
typedef struct InforHeadBitmap
{
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOR;
typedef struct Color
{
    BYTE Blue;
    BYTE Green;
    BYTE Red;
} RGB;
class CV2
{
public:
    /*
        grepBitmap():
            Description: Create a grep photo from the original photo
            arg: null
    */
    void grepBitmap();
    void ac_grepBitmap();
    /*
        segmentBitmap(int beginCol, int beginRow,  int col, int row):
            Description: To segment a bitmap using the arg you provided
            arg:
                beginCol: Determine the col coordinates of the pixels in the upper left corner of the split photo
                beginRow: Determine the row coordinates of the pixels in the upper left corner of the split photo
                col: The line width of the photo
                row: The column length of the photo
    */
    void segmentBitmap(int beginCol, int beginRow, int _col, int _row);
    void ac_segmentBitmap(int beginCol, int beginRow, int _col, int _row);
    /*
        binaryzationBitmap(int value):
            Description: Binarize the photo
            arg:
                value: Threshold of binarization
    */
    void binaryzationBitmap(int value);
    void ac_binaryzationBitmap(int value);
    /*
        createBitmap():
            Description: Create a board for a photo in memory
    */
    void createBitmap();
    /*
        readBitmap(FILE *file_out):
            Description: Output your photo in the file you choose
    */
    void readBitmap(FILE *file_out);
    /*
        Follow is Basic Function
    */
    CV2(FILE *file);
    ~CV2();

private:
    /*
        Name from the Windows Learning
    */
    const BYTE BLACK = 0;
    const BYTE WHITE = 255;
    FILE *file_in;
    FILE *file_out;
    BITMAPFILE *Head;
    BITMAPINFOR *Tag;
    RGB *priex;
    int pictureSize;
    int pictureRow, pictureCol;
    int stride;
    void *bitmap;

    /*-------------------*/

    BITMAPFILE _Head;
    BITMAPINFOR _Tag;
    RGB *_priex;
    int _pictureSize;
    int _pictureRow, _pictureCol;
    int _stride;
    void *out;
};