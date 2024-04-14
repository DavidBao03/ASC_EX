#include "./CV2.h"
int main()
{
#ifdef _OPENMP
    std::cout << "//*****************************//" << std::endl;
    std::cout << "//    OpenMP is execuating     //" << std::endl; // jude the OpenMP is exsiting
    std::cout << "//*****************************//" << std::endl;
#endif
    FILE *file_in1, *file_in2, *file_in3, *file_out1, *file_out2, *file_out3;

    /*primary of your picture*/
    file_in1 = fopen("myphoto.bmp", "rb");
    file_in2 = fopen("myphoto.bmp", "rb");
    file_in3 = fopen("myphoto.bmp", "rb");
    file_out1 = fopen("out1.bmp", "wb");
    file_out2 = fopen("out2.bmp", "wb");
    file_out3 = fopen("out3.bmp", "wb");

    CV2 cv1(file_in1), cv2(file_in2), cv3(file_in3);

    /*your code put this*/
    cv1.grepBitmap();
    cv2.binaryzationBitmap(130);
    cv3.segmentBitmap(900, 400, 700, 400);
    cv1.readBitmap(file_out1);
    cv2.readBitmap(file_out2);
    cv3.readBitmap(file_out3);
    /*-------------------*/
    return 0;
}
