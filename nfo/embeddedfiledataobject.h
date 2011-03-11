#ifndef _NFO_EMBEDDEDFILEDATAOBJECT_H_
#define _NFO_EMBEDDEDFILEDATAOBJECT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/filedataobject.h"
namespace Nepomuk {
namespace NFO {
/**
 * A file embedded in another data object. There are many ways in 
 * which a file may be embedded in another one. Use this class directly 
 * only in cases if none of the subclasses gives a better description 
 * of your case. 
 */
class EmbeddedFileDataObject : public NFO::FileDataObject
{
public:
    EmbeddedFileDataObject(Nepomuk::SimpleResource* res)
      : NFO::FileDataObject(res), m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding. 
     * The encoding used for the Embedded File. Examples might include 
     * BASE64 or UUEncode 
     */
    QStringList encodings() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding. 
     * The encoding used for the Embedded File. Examples might include 
     * BASE64 or UUEncode 
     */
    void setEncodings(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#EmbeddedFileDataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding. 
     * The encoding used for the Embedded File. Examples might include 
     * BASE64 or UUEncode 
     */
    void addEncoding(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#EmbeddedFileDataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encoding", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
