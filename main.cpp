#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "frame.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
    int first,last,nx,ny;

    std::string nameIn;
    std::string nameOut;

    /* process input arguments */
    if(argc == 7)
    {
        nameIn  = std::string( argv[1] );
        nameOut = std::string( argv[2] );
        first           = atoi(argv[3]);
        last            = atoi(argv[4]);
        nx              = atoi(argv[5]);
        ny              = atoi(argv[6]);
    }
    else
    {
        std::cout << "Usage: " << argv[0] << " name_in  name_out first  last  nx  ny" << std::endl;
        exit(-1);
    }

    FILE *input;
    FILE *output;

    if ((input=fopen(nameIn.c_str(),"rb"))==NULL)
    {
      std::cout << "Input file " << nameIn.c_str() << " cannot be opened" << std::endl;
      exit(-1);
    }
    if ((output=fopen(nameOut.c_str(),"wb"))==NULL)
    {
      std::cout << "Output file " << nameOut.c_str() << " cannot be opened" << std::endl;
      exit(-1);
    }

    Frame frame(nx,ny);


    for (int i=first;i<=last;i++)
    {
        frame.readOneFrame420(input, i==first ? i:-1);


        //Example function
        frame.makeDark();



        frame.showImage("Sequence");

        std::cout << "Processing frame number " << i;
        std::cout << std::endl;
        fflush(NULL);

        frame.writeOneFrame420(output);
    }

    fclose(input);

    return (1);
}


