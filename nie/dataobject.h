#ifndef _NIE_DATAOBJECT_H_
#define _NIE_DATAOBJECT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

namespace Nepomuk {
namespace NIE {
/**
 * A unit of data that is created, annotated and processed on the 
 * user desktop. It represents a native structure the user works 
 * with. The usage of the term 'native' is important. It means that 
 * a DataObject can be directly mapped to a data structure maintained 
 * by a native application. This may be a file, a set of files or a 
 * part of a file. The granularity depends on the user. This class 
 * is not intended to be instantiated by itself. Use more specific 
 * subclasses. 
 */
class DataObject
{
public:
    DataObject(Nepomuk::SimpleResource* res)
      : m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description. 
     * A non-technical textual annotation for a resource 
     */
    QStringList descriptions() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description. 
     * A non-technical textual annotation for a resource 
     */
    void setDescriptions(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description. 
     * A non-technical textual annotation for a resource 
     */
    void addDescription(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isPartOf. 
     * Generic property used to express containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of DataObjects to use those specific subproperties. 
     * Note to the developers: Please be aware of the distinction between 
     * containment relation and provenance. The isPartOf relation 
     * models physical containment, a nie:DataObject (e.g. an nfo:Attachment) 
     * is a 'physical' part of an nie:InformationElement (a nmo:Message). 
     * Also, please note the difference between physical containment 
     * (isPartOf) and logical containment (isLogicalPartOf) the 
     * former has more strict meaning. They may occur independently 
     * of each other. 
     */
    QList<QUrl> isPartOfs() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isPartOf", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isPartOf. 
     * Generic property used to express containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of DataObjects to use those specific subproperties. 
     * Note to the developers: Please be aware of the distinction between 
     * containment relation and provenance. The isPartOf relation 
     * models physical containment, a nie:DataObject (e.g. an nfo:Attachment) 
     * is a 'physical' part of an nie:InformationElement (a nmo:Message). 
     * Also, please note the difference between physical containment 
     * (isPartOf) and logical containment (isLogicalPartOf) the 
     * former has more strict meaning. They may occur independently 
     * of each other. 
     */
    void setIsPartOfs(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isPartOf", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isPartOf. 
     * Generic property used to express containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of DataObjects to use those specific subproperties. 
     * Note to the developers: Please be aware of the distinction between 
     * containment relation and provenance. The isPartOf relation 
     * models physical containment, a nie:DataObject (e.g. an nfo:Attachment) 
     * is a 'physical' part of an nie:InformationElement (a nmo:Message). 
     * Also, please note the difference between physical containment 
     * (isPartOf) and logical containment (isLogicalPartOf) the 
     * former has more strict meaning. They may occur independently 
     * of each other. 
     */
    void addIsPartOf(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isPartOf", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#pluralPrefLabel. 
     * The plural form of the preferred label for a resource 
     */
    QStringList pluralPrefLabels() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#pluralPrefLabel", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#pluralPrefLabel. 
     * The plural form of the preferred label for a resource 
     */
    void setPluralPrefLabels(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#pluralPrefLabel", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#pluralPrefLabel. 
     * The plural form of the preferred label for a resource 
     */
    void addPluralPrefLabel(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#pluralPrefLabel", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#score. 
     * An authoritative score for an item valued between 0 and 1 
     */
    QList<double> scores() const {
        QList<double> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#score", QUrl::StrictMode)))
            value << v.value<double>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#score. 
     * An authoritative score for an item valued between 0 and 1 
     */
    void setScores(const QList<double>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const double& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#score", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#score. 
     * An authoritative score for an item valued between 0 and 1 
     */
    void addScore(const double& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#score", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels. 
     * Number of side channels 
     */
    QList<qint64> sideChannelses() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels. 
     * Number of side channels 
     */
    void setSideChannelses(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels. 
     * Number of side channels 
     */
    void addSideChannels(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#sideChannels", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends. 
     * Dependency relation. A piece of content depends on another 
     * piece of data in order to be properly understood/used/interpreted. 
     */
    QList<QUrl> dependses() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends. 
     * Dependency relation. A piece of content depends on another 
     * piece of data in order to be properly understood/used/interpreted. 
     */
    void setDependses(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends. 
     * Dependency relation. A piece of content depends on another 
     * piece of data in order to be properly understood/used/interpreted. 
     */
    void addDepends(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#belongsToContainer. 
     * Models the containment relations between Files and Folders 
     * (or CompressedFiles). 
     */
    QList<QUrl> belongsToContainers() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#belongsToContainer", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#belongsToContainer. 
     * Models the containment relations between Files and Folders 
     * (or CompressedFiles). 
     */
    void setBelongsToContainers(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#belongsToContainer", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#belongsToContainer. 
     * Models the containment relations between Files and Folders 
     * (or CompressedFiles). 
     */
    void addBelongsToContainer(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#belongsToContainer", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#interpretedAs. 
     * Links the DataObject with the InformationElement it is interpreted 
     * as. 
     */
    QList<QUrl> interpretedAses() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#interpretedAs", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#interpretedAs. 
     * Links the DataObject with the InformationElement it is interpreted 
     * as. 
     */
    void setInterpretedAses(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#interpretedAs", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#interpretedAs. 
     * Links the DataObject with the InformationElement it is interpreted 
     * as. 
     */
    void addInterpretedAs(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#interpretedAs", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#numericRating. 
     * Annotation for a resource in the form of a numeric rating (float 
     * value), allowed values are between 1 and 10 whereas 0 is interpreted 
     * as not set 
     */
    qint64 numericRating() const {
        qint64 value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#numericRating", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#numericRating", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#numericRating. 
     * Annotation for a resource in the form of a numeric rating (float 
     * value), allowed values are between 1 and 10 whereas 0 is interpreted 
     * as not set 
     */
    void setNumericRating(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#numericRating", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#numericRating. 
     * Annotation for a resource in the form of a numeric rating (float 
     * value), allowed values are between 1 and 10 whereas 0 is interpreted 
     * as not set 
     */
    void addNumericRating(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#numericRating", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels. 
     * Number of Low Frequency Expansion (subwoofer) channels. 
     */
    QList<qint64> lfeChannelses() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels. 
     * Number of Low Frequency Expansion (subwoofer) channels. 
     */
    void setLfeChannelses(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels. 
     * Number of Low Frequency Expansion (subwoofer) channels. 
     */
    void addLfeChannels(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#lfeChannels", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altLabel. 
     * An alternative label alongside the preferred label for a resource 
     */
    QStringList altLabels() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altLabel", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altLabel. 
     * An alternative label alongside the preferred label for a resource 
     */
    void setAltLabels(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altLabel", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altLabel. 
     * An alternative label alongside the preferred label for a resource 
     */
    void addAltLabel(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altLabel", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#contributor. 
     * Refers to a single or a group of individuals that contributed 
     * to a resource 
     */
    QList<QUrl> contributors() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#contributor", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#contributor. 
     * Refers to a single or a group of individuals that contributed 
     * to a resource 
     */
    void setContributors(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#contributor", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#contributor. 
     * Refers to a single or a group of individuals that contributed 
     * to a resource 
     */
    void addContributor(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#contributor", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#personalIdentifier. 
     * Defines a personal string identifier for a resource 
     */
    QStringList personalIdentifiers() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#personalIdentifier", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#personalIdentifier. 
     * Defines a personal string identifier for a resource 
     */
    void setPersonalIdentifiers(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#personalIdentifier", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#personalIdentifier. 
     * Defines a personal string identifier for a resource 
     */
    void addPersonalIdentifier(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#personalIdentifier", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#url. 
     * URL of a DataObject. It points to the location of the object. 
     * A typial usage is FileDataObject. In cases where creating a 
     * simple file:// or http:// URL for a file is difficult (e.g. for 
     * files inside compressed archives) the applications are encouraged 
     * to use conventions defined by Apache Commons VFS Project at 
     * http://jakarta.apache.org/ commons/ vfs/ filesystems.html. 
     */
    QList<QUrl> urls() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#url", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#url. 
     * URL of a DataObject. It points to the location of the object. 
     * A typial usage is FileDataObject. In cases where creating a 
     * simple file:// or http:// URL for a file is difficult (e.g. for 
     * files inside compressed archives) the applications are encouraged 
     * to use conventions defined by Apache Commons VFS Project at 
     * http://jakarta.apache.org/ commons/ vfs/ filesystems.html. 
     */
    void setUrls(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#url", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#url. 
     * URL of a DataObject. It points to the location of the object. 
     * A typial usage is FileDataObject. In cases where creating a 
     * simple file:// or http:// URL for a file is difficult (e.g. for 
     * files inside compressed archives) the applications are encouraged 
     * to use conventions defined by Apache Commons VFS Project at 
     * http://jakarta.apache.org/ commons/ vfs/ filesystems.html. 
     */
    void addUrl(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#url", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastRefreshed. 
     * Date when information about this data object was retrieved 
     * (for the first time) or last refreshed from the data source. 
     * This property is important for metadata extraction applications 
     * that don't receive any notifications of changes in the data 
     * source and have to poll it regularly. This may lead to information 
     * becoming out of date. In these cases this property may be used 
     * to determine the age of data, which is an important element of 
     * it's dependability. 
     */
    QDateTime lastRefreshed() const {
        QDateTime value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastRefreshed", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastRefreshed", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastRefreshed. 
     * Date when information about this data object was retrieved 
     * (for the first time) or last refreshed from the data source. 
     * This property is important for metadata extraction applications 
     * that don't receive any notifications of changes in the data 
     * source and have to poll it regularly. This may lead to information 
     * becoming out of date. In these cases this property may be used 
     * to determine the age of data, which is an important element of 
     * it's dependability. 
     */
    void setLastRefreshed(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastRefreshed", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastRefreshed. 
     * Date when information about this data object was retrieved 
     * (for the first time) or last refreshed from the data source. 
     * This property is important for metadata extraction applications 
     * that don't receive any notifications of changes in the data 
     * source and have to poll it regularly. This may lead to information 
     * becoming out of date. In these cases this property may be used 
     * to determine the age of data, which is an important element of 
     * it's dependability. 
     */
    void addLastRefreshed(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastRefreshed", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer. 
     * A disclaimer 
     */
    QStringList disclaimers() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer. 
     * A disclaimer 
     */
    void setDisclaimers(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer. 
     * A disclaimer 
     */
    void addDisclaimer(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#creator. 
     * Refers to the single or group of individuals that created the 
     * resource 
     */
    QList<QUrl> creators() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#creator", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#creator. 
     * Refers to the single or group of individuals that created the 
     * resource 
     */
    void setCreators(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#creator", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#creator. 
     * Refers to the single or group of individuals that created the 
     * resource 
     */
    void addCreator(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#creator", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#created. 
     * Date of creation of the DataObject. Note that this date refers 
     * to the creation of the DataObject itself (i.e. the physical 
     * representation). Compare with nie:contentCreated. 
     */
    QList<QDateTime> nieCreateds() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#created", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#created. 
     * Date of creation of the DataObject. Note that this date refers 
     * to the creation of the DataObject itself (i.e. the physical 
     * representation). Compare with nie:contentCreated. 
     */
    void setNieCreateds(const QList<QDateTime>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#created", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#created. 
     * Date of creation of the DataObject. Note that this date refers 
     * to the creation of the DataObject itself (i.e. the physical 
     * representation). Compare with nie:contentCreated. 
     */
    void addNieCreated(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#created", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels. 
     * Number of rear channels. 
     */
    QList<qint64> rearChannelses() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels. 
     * Number of rear channels. 
     */
    void setRearChannelses(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels. 
     * Number of rear channels. 
     */
    void addRearChannels(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSuperResource. 
     * Defines a relationship between a resource and one or more super 
     * resources 
     */
    QList<QUrl> hasSuperResources() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSuperResource", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSuperResource. 
     * Defines a relationship between a resource and one or more super 
     * resources 
     */
    void setHasSuperResources(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSuperResource", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSuperResource. 
     * Defines a relationship between a resource and one or more super 
     * resources 
     */
    void addHasSuperResource(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSuperResource", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTopic. 
     * Defines a relationship between two resources, where the object 
     * is a topic of the subject 
     */
    QList<QUrl> hasTopics() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTopic", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTopic. 
     * Defines a relationship between two resources, where the object 
     * is a topic of the subject 
     */
    void setHasTopics(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTopic", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTopic. 
     * Defines a relationship between two resources, where the object 
     * is a topic of the subject 
     */
    void addHasTopic(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTopic", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license. 
     * Terms and intellectual property rights licensing conditions. 
     */
    QStringList licenses() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license. 
     * Terms and intellectual property rights licensing conditions. 
     */
    void setLicenses(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license. 
     * Terms and intellectual property rights licensing conditions. 
     */
    void addLicense(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels. 
     * Number of front channels. 
     */
    QList<qint64> frontChannelses() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels. 
     * Number of front channels. 
     */
    void setFrontChannelses(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels. 
     * Number of front channels. 
     */
    void addFrontChannels(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#coreGraph. 
     * Connects the data object with the graph that contains information 
     * about it. Deprecated in favor of a more generic nao:isDataGraphFor. 
     */
    QList<QUrl> coreGraphs() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#coreGraph", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#coreGraph. 
     * Connects the data object with the graph that contains information 
     * about it. Deprecated in favor of a more generic nao:isDataGraphFor. 
     */
    void setCoreGraphs(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#coreGraph", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#coreGraph. 
     * Connects the data object with the graph that contains information 
     * about it. Deprecated in favor of a more generic nao:isDataGraphFor. 
     */
    void addCoreGraph(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#coreGraph", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#dataSource. 
     * Marks the provenance of a DataObject, what source does a data 
     * object come from. 
     */
    QList<QUrl> dataSources() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#dataSource", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#dataSource. 
     * Marks the provenance of a DataObject, what source does a data 
     * object come from. 
     */
    void setDataSources(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#dataSource", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#dataSource. 
     * Marks the provenance of a DataObject, what source does a data 
     * object come from. 
     */
    void addDataSource(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#dataSource", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSubResource. 
     * Defines a relationship between a resource and one or more sub 
     * resources 
     */
    QList<QUrl> hasSubResources() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSubResource", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSubResource. 
     * Defines a relationship between a resource and one or more sub 
     * resources 
     */
    void setHasSubResources(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSubResource", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSubResource. 
     * Defines a relationship between a resource and one or more sub 
     * resources 
     */
    void addHasSubResource(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSubResource", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#userVisible. 
     * Mark a property, class, or even resource as user visible or not. 
     * Non-user-visible entities should never be presented to the 
     * user. By default everything is user-visible. 
     */
    bool userVisible() const {
        bool value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#userVisible", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#userVisible", QUrl::StrictMode)).first().value<bool>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#userVisible. 
     * Mark a property, class, or even resource as user visible or not. 
     * Non-user-visible entities should never be presented to the 
     * user. By default everything is user-visible. 
     */
    void setUserVisible(const bool& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#userVisible", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#userVisible. 
     * Mark a property, class, or even resource as user visible or not. 
     * Non-user-visible entities should never be presented to the 
     * user. By default everything is user-visible. 
     */
    void addUserVisible(const bool& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#userVisible", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefLabel. 
     * A preferred label for a resource 
     */
    QStringList prefLabels() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefLabel", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefLabel. 
     * A preferred label for a resource 
     */
    void setPrefLabels(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefLabel", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefLabel. 
     * A preferred label for a resource 
     */
    void addPrefLabel(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefLabel", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified. 
     * States the last modification time for a resource 
     */
    QDateTime naoLastModified() const {
        QDateTime value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified. 
     * States the last modification time for a resource 
     */
    void setNaoLastModified(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified. 
     * States the last modification time for a resource 
     */
    void addNaoLastModified(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created. 
     * States the creation, or first modification time for a resource 
     */
    QDateTime naoCreated() const {
        QDateTime value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created. 
     * States the creation, or first modification time for a resource 
     */
    void setNaoCreated(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created. 
     * States the creation, or first modification time for a resource 
     */
    void addNaoCreated(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isRelated. 
     * Defines an annotation for a resource in the form of a relationship 
     * between the subject resource and another resource 
     */
    QList<QUrl> isRelateds() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isRelated", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isRelated. 
     * Defines an annotation for a resource in the form of a relationship 
     * between the subject resource and another resource 
     */
    void setIsRelateds(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isRelated", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isRelated. 
     * Defines an annotation for a resource in the form of a relationship 
     * between the subject resource and another resource 
     */
    void addIsRelated(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isRelated", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isTopicOf. 
     * Defines a relationship between two resources, where the subject 
     * is a topic of the object 
     */
    QList<QUrl> isTopicOfs() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isTopicOf", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isTopicOf. 
     * Defines a relationship between two resources, where the subject 
     * is a topic of the object 
     */
    void setIsTopicOfs(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isTopicOf", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isTopicOf. 
     * Defines a relationship between two resources, where the subject 
     * is a topic of the object 
     */
    void addIsTopicOf(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isTopicOf", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altSymbol. 
     * An alternative symbol representation for a resource 
     */
    QList<QUrl> altSymbols() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altSymbol", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altSymbol. 
     * An alternative symbol representation for a resource 
     */
    void setAltSymbols(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altSymbol", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altSymbol. 
     * An alternative symbol representation for a resource 
     */
    void addAltSymbol(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altSymbol", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastModified. 
     * Last modification date of the DataObject. Note that this date 
     * refers to the modification of the DataObject itself (i.e. the 
     * physical representation). Compare with nie:contentLastModified. 
     */
    QList<QDateTime> nieLastModifieds() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastModified", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastModified. 
     * Last modification date of the DataObject. Note that this date 
     * refers to the modification of the DataObject itself (i.e. the 
     * physical representation). Compare with nie:contentLastModified. 
     */
    void setNieLastModifieds(const QList<QDateTime>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastModified", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastModified. 
     * Last modification date of the DataObject. Note that this date 
     * refers to the modification of the DataObject itself (i.e. the 
     * physical representation). Compare with nie:contentLastModified. 
     */
    void addNieLastModified(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#lastModified", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSymbol. 
     * Annotation for a resource in the form of a symbol representation 
     */
    QList<QUrl> hasSymbols() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSymbol", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSymbol. 
     * Annotation for a resource in the form of a symbol representation 
     */
    void setHasSymbols(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSymbol", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSymbol. 
     * Annotation for a resource in the form of a symbol representation 
     */
    void addHasSymbol(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSymbol", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#modified. 
     * States the modification time for a resource 
     */
    QList<QDateTime> modifieds() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#modified", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#modified. 
     * States the modification time for a resource 
     */
    void setModifieds(const QList<QDateTime>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#modified", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#modified. 
     * States the modification time for a resource 
     */
    void addModified(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#modified", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#deprecated. 
     * If this property is assigned, the subject class, property, 
     * or resource, is deprecated and should not be used in production 
     * systems any longer. It may be removed without further notice. 
     */
    QList<QUrl> deprecateds() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#deprecated", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#deprecated. 
     * If this property is assigned, the subject class, property, 
     * or resource, is deprecated and should not be used in production 
     * systems any longer. It may be removed without further notice. 
     */
    void setDeprecateds(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#deprecated", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#deprecated. 
     * If this property is assigned, the subject class, property, 
     * or resource, is deprecated and should not be used in production 
     * systems any longer. It may be removed without further notice. 
     */
    void addDeprecated(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#deprecated", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTag. 
     * Defines an existing tag for a resource 
     */
    QList<QUrl> hasTags() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTag", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTag. 
     * Defines an existing tag for a resource 
     */
    void setHasTags(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTag", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTag. 
     * Defines an existing tag for a resource 
     */
    void addHasTag(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTag", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType. 
     * The type of the license. Possible values for this field may include 
     * "GPL", "BSD", "Creative Commons" etc. 
     */
    QStringList licenseTypes() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType. 
     * The type of the license. Possible values for this field may include 
     * "GPL", "BSD", "Creative Commons" etc. 
     */
    void setLicenseTypes(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType. 
     * The type of the license. Possible values for this field may include 
     * "GPL", "BSD", "Creative Commons" etc. 
     */
    void addLicenseType(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#byteSize. 
     * The overall size of the data object in bytes. That means the space 
     * taken by the DataObject in its container, and not the size of 
     * the content that is of interest to the user. For cases where the 
     * content size is different (e.g. in compressed files the content 
     * is larger, in messages the content excludes headings and is 
     * smaller) use more specific properties, not necessarily subproperties 
     * of this one. 
     */
    qint64 byteSize() const {
        qint64 value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#byteSize", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#byteSize", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#byteSize. 
     * The overall size of the data object in bytes. That means the space 
     * taken by the DataObject in its container, and not the size of 
     * the content that is of interest to the user. For cases where the 
     * content size is different (e.g. in compressed files the content 
     * is larger, in messages the content excludes headings and is 
     * smaller) use more specific properties, not necessarily subproperties 
     * of this one. 
     */
    void setByteSize(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#byteSize", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#byteSize. 
     * The overall size of the data object in bytes. That means the space 
     * taken by the DataObject in its container, and not the size of 
     * the content that is of interest to the user. For cases where the 
     * content size is different (e.g. in compressed files the content 
     * is larger, in messages the content excludes headings and is 
     * smaller) use more specific properties, not necessarily subproperties 
     * of this one. 
     */
    void addByteSize(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#byteSize", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#scoreParameter. 
     * A marker property to mark selected properties which are input 
     * to a mathematical algorithm to generate scores for resources. 
     * Properties are marked by being defined as subproperties of 
     * this property 
     */
    QList<double> scoreParameters() const {
        QList<double> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#scoreParameter", QUrl::StrictMode)))
            value << v.value<double>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#scoreParameter. 
     * A marker property to mark selected properties which are input 
     * to a mathematical algorithm to generate scores for resources. 
     * Properties are marked by being defined as subproperties of 
     * this property 
     */
    void setScoreParameters(const QList<double>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const double& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#scoreParameter", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#scoreParameter. 
     * A marker property to mark selected properties which are input 
     * to a mathematical algorithm to generate scores for resources. 
     * Properties are marked by being defined as subproperties of 
     * this property 
     */
    void addScoreParameter(const double& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#scoreParameter", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefSymbol. 
     * A unique preferred symbol representation for a resource 
     */
    QList<QUrl> prefSymbols() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefSymbol", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefSymbol. 
     * A unique preferred symbol representation for a resource 
     */
    void setPrefSymbols(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefSymbol", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefSymbol. 
     * A unique preferred symbol representation for a resource 
     */
    void addPrefSymbol(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefSymbol", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright. 
     * Content copyright 
     */
    QStringList copyrights() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright. 
     * Content copyright 
     */
    void setCopyrights(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright. 
     * Content copyright 
     */
    void addCopyright(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#DataObject", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
