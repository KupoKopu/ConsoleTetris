#ifndef CONSOLETETRIS_PLAYAREA_H
#define CONSOLETETRIS_PLAYAREA_H
class PlayArea {
private:
    int width_;
    int height_;
    int size_;
    wchar_t *area;
public:
    PlayArea(int width, int height);

    wchar_t *getArea() const;

    void setArea(wchar_t *area);

    int getWidth();

    int getHeight();

    int getSize() const;
};
#endif //CONSOLETETRIS_PLAYAREA_H
