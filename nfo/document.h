#ifndef _NFO_DOCUMENT_H_
#define _NFO_DOCUMENT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nie/informationelement.h"
namespace Nepomuk {
namespace NFO {
/**
 * A generic document. A common superclass for all documents on 
 * the desktop. 
 */
class Document : public NIE::InformationElement
{
public:
    Document(Nepomuk::SimpleResource* res)
      : NIE::InformationElement(res), m_res(res)
    {}

    virtual ~Document() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Document", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
