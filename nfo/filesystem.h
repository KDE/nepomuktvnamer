#ifndef _NFO_FILESYSTEM_H_
#define _NFO_FILESYSTEM_H_

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
 * A filesystem. Examples of filesystems include hard disk partitions, 
 * removable media, but also images thereof stored in files such 
 * as ISO. 
 */
class Filesystem : public NFO::DataContainer
{
public:
    Filesystem(Nepomuk::SimpleResource* res)
      : NFO::DataContainer(res), m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid. 
     * Universally unique identifier of the filesystem. In the future, 
     * this property may have its parent changed to a more generic class. 
     */
    QStringList uuids() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid. 
     * Universally unique identifier of the filesystem. In the future, 
     * this property may have its parent changed to a more generic class. 
     */
    void setUuids(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid. 
     * Universally unique identifier of the filesystem. In the future, 
     * this property may have its parent changed to a more generic class. 
     */
    void addUuid(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uuid", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace. 
     * Occupied storage space of the filesystem. 
     */
    QList<qint64> occupiedSpaces() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace. 
     * Occupied storage space of the filesystem. 
     */
    void setOccupiedSpaces(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace. 
     * Occupied storage space of the filesystem. 
     */
    void addOccupiedSpace(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#occupiedSpace", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType. 
     * Type of filesystem such as ext3 and ntfs. 
     */
    QStringList filesystemTypes() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType. 
     * Type of filesystem such as ext3 and ntfs. 
     */
    void setFilesystemTypes(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType. 
     * Type of filesystem such as ext3 and ntfs. 
     */
    void addFilesystemType(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#filesystemType", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace. 
     * Unoccupied storage space of the filesystem. 
     */
    QList<qint64> freeSpaces() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace. 
     * Unoccupied storage space of the filesystem. 
     */
    void setFreeSpaces(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace. 
     * Unoccupied storage space of the filesystem. 
     */
    void addFreeSpace(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#freeSpace", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace. 
     * Total storage space of the filesystem, which can be different 
     * from nie:contentSize because the latter includes filesystem 
     * format overhead. 
     */
    QList<qint64> totalSpaces() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace. 
     * Total storage space of the filesystem, which can be different 
     * from nie:contentSize because the latter includes filesystem 
     * format overhead. 
     */
    void setTotalSpaces(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace. 
     * Total storage space of the filesystem, which can be different 
     * from nie:contentSize because the latter includes filesystem 
     * format overhead. 
     */
    void addTotalSpace(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#totalSpace", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
