/************************************************************************
*
*  frame.cpp
*  Copyright (C) 2019, Herve Bessala
*
************************************************************************/
#include <stdio.h>
#include <cmath>

#include "frame.h"


bool Frame::readOneFrame420(FILE *pIn, const int frameNo)
{
    const int frameSizeY  = m_height*m_width;
    const int frameSizeUV = m_height*m_width/4;

    if (frameNo >= 0)
    {
        const long frameSize   = (long)( frameSizeY + 2*frameSizeUV );

        rewind (pIn);

        long unsigned int pos = (long)frameNo * frameSize;

        const int status  = fseek (pIn, pos, 0);

        if (status != 0)
        {
            printf("Error in seeking frame no: %d\n", frameNo);
            return false;
        }
    }

    byte *pData = &(m_image[0]);

    for (int i=0; i < frameSizeY; i++)
    {
        *pData++ = fgetc(pIn);
    }

    pData = &(m_image[frameSizeY+frameSizeUV]);
    for (int i=0; i < frameSizeUV; i++)
    {
        *pData++ = fgetc(pIn);
    }

    pData = &(m_image[frameSizeY]);
    for (int i=0; i < frameSizeUV; i++)
    {
        *pData++ = fgetc(pIn);
    }

    return true;
}

