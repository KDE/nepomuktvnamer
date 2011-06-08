#ifndef _NFO_PLAINTEXTDOCUMENT_H_
#define _NFO_PLAINTEXTDOCUMENT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/textdocument.h"
namespace Nepomuk {
namespace NFO {
/**
 * A file containing plain text (ASCII, Unicode or other encodings). 
 * Examples may include TXT, HTML, XML, program source code etc. 
 */
class PlainTextDocument : public NFO::TextDocument
{
public:
    PlainTextDocument(Nepomuk::SimpleResource* res)
      : NFO::TextDocument(res), m_res(res)
    {}

    virtual ~PlainTextDocument() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PlainTextDocument", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
