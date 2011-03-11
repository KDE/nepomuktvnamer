#ifndef _NFO_TRASH_H_
#define _NFO_TRASH_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/datacontainer.h"
namespace Nepomuk {
namespace NFO {
/**
 * Represents a container for deleted files, a feature common 
 * in modern operating systems. 
 */
class Trash : public NFO::DataContainer
{
public:
    Trash(Nepomuk::SimpleResource* res)
      : NFO::DataContainer(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
