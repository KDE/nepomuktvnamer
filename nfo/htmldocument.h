#ifndef _NFO_HTMLDOCUMENT_H_
#define _NFO_HTMLDOCUMENT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/plaintextdocument.h"
namespace Nepomuk {
namespace NFO {
/**
 * A HTML document, may contain links to other files. 
 */
class HtmlDocument : public NFO::PlainTextDocument
{
public:
    HtmlDocument(Nepomuk::SimpleResource* res)
      : NFO::PlainTextDocument(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
