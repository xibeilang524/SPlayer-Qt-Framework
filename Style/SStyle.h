#ifndef SSTYLE_H
#define SSTYLE_H

class SStyle
{

public:
    SStyle();
    ~SStyle();

public:
    QString GetStyle();

private:
    QString m_styleStr;
};

#endif // SSTYLE_H
