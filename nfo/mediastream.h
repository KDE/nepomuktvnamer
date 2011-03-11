#ifndef _NFO_MEDIASTREAM_H_
#define _NFO_MEDIASTREAM_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nie/dataobject.h"
namespace Nepomuk {
namespace NFO {
/**
 * A stream of multimedia content, usually contained within a 
 * media container such as a movie (containing both audio and video) 
 * or a DVD (possibly containing many streams of audio and video). 
 * Most common interpretations for such a DataObject include 
 * Audio and Video. 
 */
class MediaStream : public NIE::DataObject
{
public:
    MediaStream(Nepomuk::SimpleResource* res)
      : NIE::DataObject(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
