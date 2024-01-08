
#include "../fractol.h"

t_color generate_color(int iteration)
{
    t_color color;
    double t = (double)iteration / MAX_IT;

    color.red = (unsigned char)(9 * (1 - t) * t * t * t * 255);
    color.green = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
    color.blue = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (color);
}

