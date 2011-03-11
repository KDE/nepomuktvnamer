#ifndef _NFO_SPREADSHEET_H_
#define _NFO_SPREADSHEET_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/document.h"
namespace Nepomuk {
namespace NFO {
/**
 * A spreadsheet, created by a spreadsheet application. Examples 
 * might include Gnumeric, OpenOffice Calc or MS Excel. 
 */
class Spreadsheet : public NFO::Document
{
public:
    Spreadsheet(Nepomuk::SimpleResource* res)
      : NFO::Document(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
