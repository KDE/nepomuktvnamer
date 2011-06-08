#ifndef _NFO_FILEDATAOBJECT_H_
#define _NFO_FILEDATAOBJECT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nie/dataobject.h"
namespace Nepomuk {
namespace NFO {
/**
 * A resource containing a finite sequence of bytes with arbitrary 
 * information, that is available to a computer program and is 
 * usually based on some kind of durable storage. A file is durable 
 * in the sense that it remains available for programs to use after 
 * the current program has finished. 
 */
class FileDataObject : public NIE::DataObject
{
public:
    FileDataObject(Nepomuk::SimpleResource* res)
      : NIE::DataObject(res), m_res(res)
    {}

    virtual ~FileDataObject() {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash. 
     * Links the file with it's hash value. 
     */
    QList<QUrl> hasHashs() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash. 
     * Links the file with it's hash value. 
     */
    void setHasHashs(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash. 
     * Links the file with it's hash value. 
     */
    void addHasHash(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasHash", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified. 
     * last modification date 
     */
    QList<QDateTime> fileLastModifieds() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified. 
     * last modification date 
     */
    void setFileLastModifieds(const QList<QDateTime>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified. 
     * last modification date 
     */
    void addFileLastModified(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastModified", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName. 
     * Name of the file, together with the extension 
     */
    QString fileName() const {
        QString value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName", QUrl::StrictMode)).first().value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName. 
     * Name of the file, together with the extension 
     */
    void setFileName(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName. 
     * Name of the file, together with the extension 
     */
    void addFileName(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileName", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner. 
     * The owner of the file as defined by the file system access rights 
     * feature. 
     */
    QList<QUrl> fileOwners() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner. 
     * The owner of the file as defined by the file system access rights 
     * feature. 
     */
    void setFileOwners(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner. 
     * The owner of the file as defined by the file system access rights 
     * feature. 
     */
    void addFileOwner(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileOwner", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated. 
     * File creation date 
     */
    QList<QDateTime> fileCreateds() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated. 
     * File creation date 
     */
    void setFileCreateds(const QList<QDateTime>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated. 
     * File creation date 
     */
    void addFileCreated(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileCreated", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize. 
     * The size of the file in bytes. For compressed files it means the 
     * size of the packed file, not of the contents. For folders it means 
     * the aggregated size of all contained files and folders 
     */
    QList<qint64> fileSizes() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize. 
     * The size of the file in bytes. For compressed files it means the 
     * size of the packed file, not of the contents. For folders it means 
     * the aggregated size of all contained files and folders 
     */
    void setFileSizes(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize. 
     * The size of the file in bytes. For compressed files it means the 
     * size of the packed file, not of the contents. For folders it means 
     * the aggregated size of all contained files and folders 
     */
    void addFileSize(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileSize", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions. 
     * A string containing the permissions of a file. A feature common 
     * in many UNIX-like operating systems. 
     */
    QStringList permissionses() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions. 
     * A string containing the permissions of a file. A feature common 
     * in many UNIX-like operating systems. 
     */
    void setPermissionses(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions. 
     * A string containing the permissions of a file. A feature common 
     * in many UNIX-like operating systems. 
     */
    void addPermissions(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#permissions", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl. 
     * URL of the file. It points at the location of the file. In cases 
     * where creating a simple file:// or http:// URL for a file is difficult 
     * (e.g. for files inside compressed archives) the applications 
     * are encouraged to use conventions defined by Apache Commons 
     * VFS Project at http://jakarta.apache.org/ commons/ vfs/ 
     * filesystems.html. 
     */
    QList<QUrl> fileUrls() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl. 
     * URL of the file. It points at the location of the file. In cases 
     * where creating a simple file:// or http:// URL for a file is difficult 
     * (e.g. for files inside compressed archives) the applications 
     * are encouraged to use conventions defined by Apache Commons 
     * VFS Project at http://jakarta.apache.org/ commons/ vfs/ 
     * filesystems.html. 
     */
    void setFileUrls(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl. 
     * URL of the file. It points at the location of the file. In cases 
     * where creating a simple file:// or http:// URL for a file is difficult 
     * (e.g. for files inside compressed archives) the applications 
     * are encouraged to use conventions defined by Apache Commons 
     * VFS Project at http://jakarta.apache.org/ commons/ vfs/ 
     * filesystems.html. 
     */
    void addFileUrl(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileUrl", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed. 
     * Time when the file was last accessed. 
     */
    QList<QDateTime> fileLastAccesseds() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed. 
     * Time when the file was last accessed. 
     */
    void setFileLastAccesseds(const QList<QDateTime>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed. 
     * Time when the file was last accessed. 
     */
    void addFileLastAccessed(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#fileLastAccessed", QUrl::StrictMode), value);
    }

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FileDataObject", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
