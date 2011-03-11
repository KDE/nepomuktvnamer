#ifndef _NFO_MINDMAP_H_
#define _NFO_MINDMAP_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/document.h"
namespace Nepomuk {
namespace NFO {
/**
 * A MindMap, created by a mind-mapping utility. Examples might 
 * include FreeMind or mind mapper. 
 */
class MindMap : public NFO::Document
{
public:
    MindMap(Nepomuk::SimpleResource* res)
      : NFO::Document(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
