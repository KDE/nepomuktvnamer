#ifndef _NFO_ATTACHMENT_H_
#define _NFO_ATTACHMENT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/embeddedfiledataobject.h"
namespace Nepomuk {
namespace NFO {
/**
 * A file attached to another data object. Many data formats allow 
 * for attachments: emails, vcards, ical events, id3 and exif... 
 */
class Attachment : public NFO::EmbeddedFileDataObject
{
public:
    Attachment(Nepomuk::SimpleResource* res)
      : NFO::EmbeddedFileDataObject(res), m_res(res)
    {}

    virtual ~Attachment() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Attachment", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
