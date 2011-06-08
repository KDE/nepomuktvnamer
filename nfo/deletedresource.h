#ifndef _NFO_DELETEDRESOURCE_H_
#define _NFO_DELETEDRESOURCE_H_

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
 * A file entity that has been deleted from the original source. 
 * Usually such entities are stored within various kinds of 'Trash' 
 * or 'Recycle Bin' folders. 
 */
class DeletedResource : public NFO::FileDataObject
{
public:
    DeletedResource(Nepomuk::SimpleResource* res)
      : NFO::FileDataObject(res), m_res(res)
    {}

    virtual ~DeletedResource() {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#originalLocation. 
     * The original location of the deleted resource. 
     */
    QStringList originalLocations() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#originalLocation", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#originalLocation. 
     * The original location of the deleted resource. 
     */
    void setOriginalLocations(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#originalLocation", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#originalLocation. 
     * The original location of the deleted resource. 
     */
    void addOriginalLocation(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#originalLocation", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#deletionDate. 
     * The date and time of the deletion. 
     */
    QList<QDateTime> deletionDates() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#deletionDate", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#deletionDate. 
     * The date and time of the deletion. 
     */
    void setDeletionDates(const QList<QDateTime>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#deletionDate", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#deletionDate. 
     * The date and time of the deletion. 
     */
    void addDeletionDate(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#deletionDate", QUrl::StrictMode), value);
    }

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#DeletedResource", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
