#ifndef FRAME_H
#define FRAME_H

#include <stdlib.h>
#include <string.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


typedef unsigned char byte;

class Frame
{
public:
    Frame(unsigned w, unsigned h)
    {
        m_width  = w;
        m_height = h;

        m_image.resize( w * h * 3 / 2 );// For 4:2:0
    };

    ~Frame()
    {
    };

    int get_width() const
    {
        return m_width;
    }

    int get_height() const
    {
        return m_height;
    }

