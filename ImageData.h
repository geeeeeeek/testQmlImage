#ifndef IMAGEDATA_H
#define IMAGEDATA_H

class QString;
class ImageData
{
public:
    static ImageData *instance();

    bool loadImage1(const QString &fileName);
    bool loadImage2(const QString &fileName);

    unsigned char *data1() const;
    unsigned char *data2() const;
private:
    ImageData();
    ~ImageData();

    bool loadImage(const QString &fileName, unsigned char* &data);
private:
    unsigned char *m_data1 = nullptr;
    unsigned char *m_data2 = nullptr;
    static ImageData *m_instance;
};

#endif // IMAGEDATA_H
