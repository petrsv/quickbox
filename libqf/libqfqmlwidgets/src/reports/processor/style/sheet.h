#ifndef QF_QMLWIDGETS_REPORTS_STYLE_SHEET_H
#define QF_QMLWIDGETS_REPORTS_STYLE_SHEET_H

#include "color.h"
#include "pen.h"
#include "istyled.h"

#include "../../../qmlwidgetsglobal.h"

#include <qf/core/utils.h>

#include <QObject>
#include <QString>
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QQmlListProperty>

namespace qf {
namespace qmlwidgets {
namespace reports {
namespace style {

class QFQMLWIDGETS_DECL_EXPORT Sheet : public QObject
{
	Q_OBJECT
	/// set name of prototype or prototype itself here
	Q_PROPERTY(QVariant basedOn READ basedOn WRITE setBasedOn)
	Q_PROPERTY(QQmlListProperty<qf::qmlwidgets::reports::style::Color> colors READ colors)
	Q_PROPERTY(QQmlListProperty<qf::qmlwidgets::reports::style::Pen> pens READ pens)
public:
	explicit Sheet(QObject *parent = nullptr);
	~Sheet() Q_DECL_OVERRIDE;
public:
	QF_PROPERTY_IMPL(QVariant, b, B, asedOn)
public:
    QObject* styleObjectForName(IStyled::StyleGroup style_object_group, const QString &name, bool should_exist);
    void setStyleObjectForName(IStyled::StyleGroup style_object_group, const QString &name, QObject *o);
private:
	QQmlListProperty<Color> colors();
	QQmlListProperty<Pen> pens();
private:
	QList<Color*> m_colors;
	QList<Pen*> m_pens;
    typedef QMap<QString, QObject*> ObjectMap;
    QMap<IStyled::StyleGroup, ObjectMap> m_definedStyles;
};

}}}}

#endif // QF_QMLWIDGETS_REPORTS_STYLE_SHEET_H