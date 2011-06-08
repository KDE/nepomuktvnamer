#ifndef _NFO_SOURCECODE_H_
#define _NFO_SOURCECODE_H_

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
 * Code in a compilable or interpreted programming language. 
 */
class SourceCode : public NFO::PlainTextDocument
{
public:
    SourceCode(Nepomuk::SimpleResource* res)
      : NFO::PlainTextDocument(res), m_res(res)
    {}

    virtual ~SourceCode() {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass. 
     * Name of a class defined in the source code file. 
     */
    QStringList definesClasses() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass. 
     * Name of a class defined in the source code file. 
     */
    void setDefinesClasses(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass. 
     * Name of a class defined in the source code file. 
     */
    void addDefinesClass(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable. 
     * Name of a global variable defined within the source code file. 
     */
    QStringList definesGlobalVariables() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable. 
     * Name of a global variable defined within the source code file. 
     */
    void setDefinesGlobalVariables(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable. 
     * Name of a global variable defined within the source code file. 
     */
    void addDefinesGlobalVariable(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction. 
     * A name of a function/method defined in the given source code 
     * file. 
     */
    QStringList definesFunctions() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction. 
     * A name of a function/method defined in the given source code 
     * file. 
     */
    void setDefinesFunctions(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction. 
     * A name of a function/method defined in the given source code 
     * file. 
     */
    void addDefinesFunction(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage. 
     * Indicates the name of the programming language this source 
     * code file is written in. Examples might include 'C', 'C++', 
     * 'Java' etc. 
     */
    QStringList programmingLanguages() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage. 
     * Indicates the name of the programming language this source 
     * code file is written in. Examples might include 'C', 'C++', 
     * 'Java' etc. 
     */
    void setProgrammingLanguages(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage. 
     * Indicates the name of the programming language this source 
     * code file is written in. Examples might include 'C', 'C++', 
     * 'Java' etc. 
     */
    void addProgrammingLanguage(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount. 
     * The amount of character in comments i.e. characters ignored 
     * by the compiler/interpreter. 
     */
    QList<qint64> commentCharacterCounts() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount. 
     * The amount of character in comments i.e. characters ignored 
     * by the compiler/interpreter. 
     */
    void setCommentCharacterCounts(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount. 
     * The amount of character in comments i.e. characters ignored 
     * by the compiler/interpreter. 
     */
    void addCommentCharacterCount(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount", QUrl::StrictMode), value);
    }

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
