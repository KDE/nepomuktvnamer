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

    virtual ~Trash() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Trash", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
