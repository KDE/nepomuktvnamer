#ifndef _NMM_MOVIE_H_
#define _NMM_MOVIE_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/video.h"
namespace Nepomuk {
namespace NMM {
/**
 * A Movie 
 */
class Movie : public NFO::Video
{
public:
    Movie(Nepomuk::SimpleResource* res)
      : NFO::Video(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
