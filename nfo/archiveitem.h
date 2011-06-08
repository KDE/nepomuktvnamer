#ifndef _NFO_ARCHIVEITEM_H_
#define _NFO_ARCHIVEITEM_H_

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
 * A file entity inside an archive. 
 */
class ArchiveItem : public NFO::EmbeddedFileDataObject
{
public:
    ArchiveItem(Nepomuk::SimpleResource* res)
      : NFO::EmbeddedFileDataObject(res), m_res(res)
    {}

    virtual ~ArchiveItem() {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#isPasswordProtected. 
     * States if a given resource is password-protected. 
     */
    QList<bool> isPasswordProtecteds() const {
        QList<bool> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#isPasswordProtected", QUrl::StrictMode)))
            value << v.value<bool>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#isPasswordProtected. 
     * States if a given resource is password-protected. 
     */
    void setIsPasswordProtecteds(const QList<bool>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const bool& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#isPasswordProtected", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#isPasswordProtected. 
     * States if a given resource is password-protected. 
     */
    void addIsPasswordProtected(const bool& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#isPasswordProtected", QUrl::StrictMode), value);
    }

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#ArchiveItem", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
