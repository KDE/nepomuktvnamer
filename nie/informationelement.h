#ifndef _NIE_INFORMATIONELEMENT_H_
#define _NIE_INFORMATIONELEMENT_H_

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
 * A unit of content the user works with. This is a superclass for 
 * all interpretations of a DataObject. 
 */
class InformationElement
{
public:
    InformationElement(Nepomuk::SimpleResource* res)
      : m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version. 
     * The current version of the given data object. Exact semantics 
     * is unspecified at this level. Use more specific subproperties 
     * if needed. 
     */
    QStringList versions() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version. 
     * The current version of the given data object. Exact semantics 
     * is unspecified at this level. Use more specific subproperties 
     * if needed. 
     */
    void setVersions(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version. 
     * The current version of the given data object. Exact semantics 
     * is unspecified at this level. Use more specific subproperties 
     * if needed. 
     */
    void addVersion(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#version", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf. 
     * Generic property used to express 'logical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (isPartOf) and logical containment (isLogicalPartOf) 
     */
    QList<QUrl> isLogicalPartOfs() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf. 
     * Generic property used to express 'logical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (isPartOf) and logical containment (isLogicalPartOf) 
     */
    void setIsLogicalPartOfs(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf. 
     * Generic property used to express 'logical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (isPartOf) and logical containment (isLogicalPartOf) 
     */
    void addIsLogicalPartOf(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isLogicalPartOf", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#pluralPrefLabel", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart. 
     * Generic property used to express 'logical' containment relationships 
     * between InformationElements. NIE extensions are encouraged 
     * to provide more specific subproperties of this one. It is advisable 
     * for actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (hasPart) and logical containment (hasLogicalPart) 
     */
    QList<QUrl> hasLogicalParts() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart. 
     * Generic property used to express 'logical' containment relationships 
     * between InformationElements. NIE extensions are encouraged 
     * to provide more specific subproperties of this one. It is advisable 
     * for actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (hasPart) and logical containment (hasLogicalPart) 
     */
    void setHasLogicalParts(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart. 
     * Generic property used to express 'logical' containment relationships 
     * between InformationElements. NIE extensions are encouraged 
     * to provide more specific subproperties of this one. It is advisable 
     * for actual instances of InformationElement to use those specific 
     * subproperties. Note the difference between 'physical' containment 
     * (hasPart) and logical containment (hasLogicalPart) 
     */
    void addHasLogicalPart(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasLogicalPart", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasSymbol", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#depends", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altSymbol", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart. 
     * Generic property used to express 'physical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of DataObjects to use those specific subproperties. 
     * Note to the developers: Please be aware of the distinction between 
     * containment relation and provenance. The hasPart relation 
     * models physical containment, an InformationElement (a nmo:Message) 
     * can have a 'physical' part (an nfo:Attachment). Also, please 
     * note the difference between physical containment (hasPart) 
     * and logical containment (hasLogicalPart) the former has more 
     * strict meaning. They may occur independently of each other. 
     */
    QList<QUrl> hasParts() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart. 
     * Generic property used to express 'physical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of DataObjects to use those specific subproperties. 
     * Note to the developers: Please be aware of the distinction between 
     * containment relation and provenance. The hasPart relation 
     * models physical containment, an InformationElement (a nmo:Message) 
     * can have a 'physical' part (an nfo:Attachment). Also, please 
     * note the difference between physical containment (hasPart) 
     * and logical containment (hasLogicalPart) the former has more 
     * strict meaning. They may occur independently of each other. 
     */
    void setHasParts(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart. 
     * Generic property used to express 'physical' containment relationships 
     * between DataObjects. NIE extensions are encouraged to provide 
     * more specific subproperties of this one. It is advisable for 
     * actual instances of DataObjects to use those specific subproperties. 
     * Note to the developers: Please be aware of the distinction between 
     * containment relation and provenance. The hasPart relation 
     * models physical containment, an InformationElement (a nmo:Message) 
     * can have a 'physical' part (an nfo:Attachment). Also, please 
     * note the difference between physical containment (hasPart) 
     * and logical containment (hasLogicalPart) the former has more 
     * strict meaning. They may occur independently of each other. 
     */
    void addHasPart(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#hasPart", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs. 
     * Links the information element with the DataObject it is stored 
     * in. 
     */
    QList<QUrl> isStoredAses() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs. 
     * Links the information element with the DataObject it is stored 
     * in. 
     */
    void setIsStoredAses(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs. 
     * Links the information element with the DataObject it is stored 
     * in. 
     */
    void addIsStoredAs(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#isStoredAs", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description. 
     * A textual description of the resource. This property may be 
     * used for any metadata fields that provide some meta-information 
     * or comment about a resource in the form of a passage of text. This 
     * property is not to be confused with nie:plainTextContent. 
     * Use more specific subproperties wherever possible. 
     */
    QStringList nieDescriptions() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description. 
     * A textual description of the resource. This property may be 
     * used for any metadata fields that provide some meta-information 
     * or comment about a resource in the form of a passage of text. This 
     * property is not to be confused with nie:plainTextContent. 
     * Use more specific subproperties wherever possible. 
     */
    void setNieDescriptions(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description. 
     * A textual description of the resource. This property may be 
     * used for any metadata fields that provide some meta-information 
     * or comment about a resource in the form of a passage of text. This 
     * property is not to be confused with nie:plainTextContent. 
     * Use more specific subproperties wherever possible. 
     */
    void addNieDescription(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#description", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefLabel", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#altLabel", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#license", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#personalIdentifier", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment. 
     * A user comment about an InformationElement. 
     */
    QStringList comments() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment. 
     * A user comment about an InformationElement. 
     */
    void setComments(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment. 
     * A user comment about an InformationElement. 
     */
    void addComment(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#comment", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links. 
     * A linking relation. A piece of content links/mentions a piece 
     * of data 
     */
    QList<QUrl> linkses() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links. 
     * A linking relation. A piece of content links/mentions a piece 
     * of data 
     */
    void setLinkses(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links. 
     * A linking relation. A piece of content links/mentions a piece 
     * of data 
     */
    void addLinks(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#links", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#disclaimer", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language. 
     * Language the InformationElement is expressed in. This property 
     * applies to the data object in its entirety. If the data object 
     * is divisible into parts expressed in multiple languages - more 
     * specific properties should be used. Users are encouraged to 
     * use the two-letter code specified in the RFC 3066 
     */
    QStringList languages() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language. 
     * Language the InformationElement is expressed in. This property 
     * applies to the data object in its entirety. If the data object 
     * is divisible into parts expressed in multiple languages - more 
     * specific properties should be used. Users are encouraged to 
     * use the two-letter code specified in the RFC 3066 
     */
    void setLanguages(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language. 
     * Language the InformationElement is expressed in. This property 
     * applies to the data object in its entirety. If the data object 
     * is divisible into parts expressed in multiple languages - more 
     * specific properties should be used. Users are encouraged to 
     * use the two-letter code specified in the RFC 3066 
     */
    void addLanguage(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#language", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus. 
     * The status of the encryption of the InformationElement. 
     */
    QList<QUrl> encryptionStatuses() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus. 
     * The status of the encryption of the InformationElement. 
     */
    void setEncryptionStatuses(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus. 
     * The status of the encryption of the InformationElement. 
     */
    void addEncryptionStatus(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#encryptionStatus", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#creator", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent. 
     * Plain-text representation of the content of a InformationElement 
     * with all markup removed. The main purpose of this property is 
     * full-text indexing and search. Its exact content is considered 
     * application-specific. The user can make no assumptions about 
     * what is and what is not contained within. Applications should 
     * use more specific properties wherever possible. 
     */
    QStringList plainTextContents() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent. 
     * Plain-text representation of the content of a InformationElement 
     * with all markup removed. The main purpose of this property is 
     * full-text indexing and search. Its exact content is considered 
     * application-specific. The user can make no assumptions about 
     * what is and what is not contained within. Applications should 
     * use more specific properties wherever possible. 
     */
    void setPlainTextContents(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent. 
     * Plain-text representation of the content of a InformationElement 
     * with all markup removed. The main purpose of this property is 
     * full-text indexing and search. Its exact content is considered 
     * application-specific. The user can make no assumptions about 
     * what is and what is not contained within. Applications should 
     * use more specific properties wherever possible. 
     */
    void addPlainTextContent(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#plainTextContent", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#score", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#rearChannels", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description. 
     * A non-technical textual annotation for a resource 
     */
    QStringList naoDescriptions() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description. 
     * A non-technical textual annotation for a resource 
     */
    void setNaoDescriptions(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description. 
     * A non-technical textual annotation for a resource 
     */
    void addNaoDescription(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#description", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTopic", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType. 
     * The mime type of the resource, if available. Example: "text/plain". 
     * See http://www.iana.org/assignments/media-types/. This 
     * property applies to data objects that can be described with 
     * one mime type. In cases where the object as a whole has one mime 
     * type, while it's parts have other mime types, or there is no mime 
     * type that can be applied to the object as a whole, but some parts 
     * of the content have mime types - use more specific properties. 
     */
    QStringList mimeTypes() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType. 
     * The mime type of the resource, if available. Example: "text/plain". 
     * See http://www.iana.org/assignments/media-types/. This 
     * property applies to data objects that can be described with 
     * one mime type. In cases where the object as a whole has one mime 
     * type, while it's parts have other mime types, or there is no mime 
     * type that can be applied to the object as a whole, but some parts 
     * of the content have mime types - use more specific properties. 
     */
    void setMimeTypes(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType. 
     * The mime type of the resource, if available. Example: "text/plain". 
     * See http://www.iana.org/assignments/media-types/. This 
     * property applies to data objects that can be described with 
     * one mime type. In cases where the object as a whole has one mime 
     * type, while it's parts have other mime types, or there is no mime 
     * type that can be applied to the object as a whole, but some parts 
     * of the content have mime types - use more specific properties. 
     */
    void addMimeType(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#mimeType", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title. 
     * Name given to an InformationElement 
     */
    QStringList titles() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title. 
     * Name given to an InformationElement 
     */
    void setTitles(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title. 
     * Name given to an InformationElement 
     */
    void addTitle(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#title", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified. 
     * States the last modification time for a resource 
     */
    QDateTime lastModified() const {
        QDateTime value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified. 
     * States the last modification time for a resource 
     */
    void setLastModified(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified. 
     * States the last modification time for a resource 
     */
    void addLastModified(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#lastModified", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#frontChannels", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated. 
     * The date of the content creation. This may not necessarily be 
     * equal to the date when the DataObject (i.e. the physical representation) 
     * itself was created. Compare with nie:created property. 
     */
    QDateTime contentCreated() const {
        QDateTime value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated. 
     * The date of the content creation. This may not necessarily be 
     * equal to the date when the DataObject (i.e. the physical representation) 
     * itself was created. Compare with nie:created property. 
     */
    void setContentCreated(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated. 
     * The date of the content creation. This may not necessarily be 
     * equal to the date when the DataObject (i.e. the physical representation) 
     * itself was created. Compare with nie:created property. 
     */
    void addContentCreated(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentCreated", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified. 
     * The date of the last modification of the original content (not 
     * its corresponding DataObject or local copy). Compare with 
     * nie:lastModified. 
     */
    QDateTime contentLastModified() const {
        QDateTime value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified. 
     * The date of the last modification of the original content (not 
     * its corresponding DataObject or local copy). Compare with 
     * nie:lastModified. 
     */
    void setContentLastModified(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified. 
     * The date of the last modification of the original content (not 
     * its corresponding DataObject or local copy). Compare with 
     * nie:lastModified. 
     */
    void addContentLastModified(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentLastModified", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#userVisible", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier. 
     * An unambiguous reference to the InformationElement within 
     * a given context. Recommended best practice is to identify the 
     * resource by means of a string conforming to a formal identification 
     * system. 
     */
    QStringList identifiers() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier. 
     * An unambiguous reference to the InformationElement within 
     * a given context. Recommended best practice is to identify the 
     * resource by means of a string conforming to a formal identification 
     * system. 
     */
    void setIdentifiers(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier. 
     * An unambiguous reference to the InformationElement within 
     * a given context. Recommended best practice is to identify the 
     * resource by means of a string conforming to a formal identification 
     * system. 
     */
    void addIdentifier(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#identifier", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#prefSymbol", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword. 
     * Adapted DublinCore: The topic of the content of the resource, 
     * as keyword. No sentences here. Recommended best practice is 
     * to select a value from a controlled vocabulary or formal classification 
     * scheme. 
     */
    QStringList keywords() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword. 
     * Adapted DublinCore: The topic of the content of the resource, 
     * as keyword. No sentences here. Recommended best practice is 
     * to select a value from a controlled vocabulary or formal classification 
     * scheme. 
     */
    void setKeywords(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword. 
     * Adapted DublinCore: The topic of the content of the resource, 
     * as keyword. No sentences here. Recommended best practice is 
     * to select a value from a controlled vocabulary or formal classification 
     * scheme. 
     */
    void addKeyword(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#keyword", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf. 
     * DataObjects extracted from a single data source are organized 
     * into a containment tree. This property links the root of that 
     * tree with the datasource it has been extracted from 
     */
    QList<QUrl> rootElementOfs() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf. 
     * DataObjects extracted from a single data source are organized 
     * into a containment tree. This property links the root of that 
     * tree with the datasource it has been extracted from 
     */
    void setRootElementOfs(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf. 
     * DataObjects extracted from a single data source are organized 
     * into a containment tree. This property links the root of that 
     * tree with the datasource it has been extracted from 
     */
    void addRootElementOf(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#rootElementOf", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created. 
     * States the creation, or first modification time for a resource 
     */
    QDateTime created() const {
        QDateTime value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created", QUrl::StrictMode)).first().value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created. 
     * States the creation, or first modification time for a resource 
     */
    void setCreated(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/08/15/nao#created. 
     * States the creation, or first modification time for a resource 
     */
    void addCreated(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#isTopicOf", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo. 
     * A common superproperty for all relations between a piece of 
     * content and other pieces of data (which may be interpreted as 
     * other pieces of content). 
     */
    QList<QUrl> relatedTos() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo. 
     * A common superproperty for all relations between a piece of 
     * content and other pieces of data (which may be interpreted as 
     * other pieces of content). 
     */
    void setRelatedTos(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo. 
     * A common superproperty for all relations between a piece of 
     * content and other pieces of data (which may be interpreted as 
     * other pieces of content). 
     */
    void addRelatedTo(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#relatedTo", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate. 
     * A point or period of time associated with an event in the lifecycle 
     * of an Information Element. A common superproperty for all date-related 
     * properties of InformationElements in the NIE Framework. 
     */
    QList<QDateTime> informationElementDates() const {
        QList<QDateTime> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate", QUrl::StrictMode)))
            value << v.value<QDateTime>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate. 
     * A point or period of time associated with an event in the lifecycle 
     * of an Information Element. A common superproperty for all date-related 
     * properties of InformationElements in the NIE Framework. 
     */
    void setInformationElementDates(const QList<QDateTime>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QDateTime& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate. 
     * A point or period of time associated with an event in the lifecycle 
     * of an Information Element. A common superproperty for all date-related 
     * properties of InformationElements in the NIE Framework. 
     */
    void addInformationElementDate(const QDateTime& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#informationElementDate", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#hasTag", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#scoreParameter", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#licenseType", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize. 
     * The size of the content. This property can be used whenever the 
     * size of the content of an InformationElement differs from the 
     * size of the DataObject. (e.g. because of compression, encoding, 
     * encryption or any other representation issues). The contentSize 
     * in expressed in bytes. 
     */
    QList<qint64> contentSizes() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize. 
     * The size of the content. This property can be used whenever the 
     * size of the content of an InformationElement differs from the 
     * size of the DataObject. (e.g. because of compression, encoding, 
     * encryption or any other representation issues). The contentSize 
     * in expressed in bytes. 
     */
    void setContentSizes(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize. 
     * The size of the content. This property can be used whenever the 
     * size of the content of an InformationElement differs from the 
     * size of the DataObject. (e.g. because of compression, encoding, 
     * encryption or any other representation issues). The contentSize 
     * in expressed in bytes. 
     */
    void addContentSize(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#contentSize", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject. 
     * An overall topic of the content of a InformationElement 
     */
    QStringList subjects() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject. 
     * An overall topic of the content of a InformationElement 
     */
    void setSubjects(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject. 
     * An overall topic of the content of a InformationElement 
     */
    void addSubject(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#subject", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet. 
     * Characterset in which the content of the InformationElement 
     * was created. Example: ISO-8859-1, UTF-8. One of the registered 
     * character sets at http://www.iana.org/assignments/character-sets. 
     * This characterSet is used to interpret any textual parts of 
     * the content. If more than one characterSet is used within one 
     * data object, use more specific properties. 
     */
    QStringList characterSets() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet. 
     * Characterset in which the content of the InformationElement 
     * was created. Example: ISO-8859-1, UTF-8. One of the registered 
     * character sets at http://www.iana.org/assignments/character-sets. 
     * This characterSet is used to interpret any textual parts of 
     * the content. If more than one characterSet is used within one 
     * data object, use more specific properties. 
     */
    void setCharacterSets(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet. 
     * Characterset in which the content of the InformationElement 
     * was created. Example: ISO-8859-1, UTF-8. One of the registered 
     * character sets at http://www.iana.org/assignments/character-sets. 
     * This characterSet is used to interpret any textual parts of 
     * the content. If more than one characterSet is used within one 
     * data object, use more specific properties. 
     */
    void addCharacterSet(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#characterSet", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/08/15/nao#numericRating", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal. 
     * A common superproperty for all properties that point at legal 
     * information about an Information Element 
     */
    QStringList legals() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal. 
     * A common superproperty for all properties that point at legal 
     * information about an Information Element 
     */
    void setLegals(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal. 
     * A common superproperty for all properties that point at legal 
     * information about an Information Element 
     */
    void addLegal(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#legal", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator. 
     * Software used to "generate" the contents. E.g. a word processor 
     * name. 
     */
    QStringList generators() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator. 
     * Software used to "generate" the contents. E.g. a word processor 
     * name. 
     */
    void setGenerators(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator. 
     * Software used to "generate" the contents. E.g. a word processor 
     * name. 
     */
    void addGenerator(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#generator", QUrl::StrictMode), value);
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
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
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#InformationElement", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/01/19/nie#copyright", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
