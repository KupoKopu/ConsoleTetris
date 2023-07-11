#include "PlayArea.h"

PlayArea::PlayArea(int width, int height) : width_(width), height_(height)
{
    size_ = width * height;

    area = new wchar_t [size_];
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            area[y*width + x] =  ( x == 0 || x == width - 1 || y == height - 1) ? 9 : 0;
        }
    }
}

int PlayArea::getWidth() {
    return width_;
}

int PlayArea::getHeight() {
    return height_;
}

wchar_t *PlayArea::getArea() const {
    return area;
}

void PlayArea::setArea(wchar_t *area) {
    PlayArea::area = area;
}

int PlayArea::getSize() const {
    return size_;
}
