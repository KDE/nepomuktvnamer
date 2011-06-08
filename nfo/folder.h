#ifndef _NFO_FOLDER_H_
#define _NFO_FOLDER_H_

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
 * A folder/directory. Examples of folders include folders on 
 * a filesystem and message folders in a mailbox. 
 */
class Folder : public NFO::DataContainer
{
public:
    Folder(Nepomuk::SimpleResource* res)
      : NFO::DataContainer(res), m_res(res)
    {}

    virtual ~Folder() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Folder", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
