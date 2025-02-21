#ifndef CUSTOMTEXTNODE_H
#define CUSTOMTEXTNODE_H

#include <QQuickPaintedItem>
#include <QFont>

class CustomTextNode : public QQuickPaintedItem  // Changed from QQuickItem to QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QFont font READ font WRITE setFont NOTIFY fontChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(Qt::Alignment alignment READ alignment WRITE setAlignment NOTIFY alignmentChanged)
    Q_PROPERTY(qreal padding READ padding WRITE setPadding NOTIFY paddingChanged)
    Q_PROPERTY(qreal lineHeight READ lineHeight WRITE setLineHeight NOTIFY lineHeightChanged)
    Q_PROPERTY(Qt::TextElideMode elideMode READ elideMode WRITE setElideMode NOTIFY elideModeChanged)
    Q_PROPERTY(bool clip READ clip WRITE setClip NOTIFY clipChanged)

public:
    explicit CustomTextNode(QQuickItem *parent = 0);
    
    QString text() const { return m_text; }
    QFont font() const { return m_font; }
    QColor color() const { return m_color; }
    Qt::Alignment alignment() const { return m_alignment; }
    qreal padding() const { return m_padding; }
    qreal lineHeight() const { return m_lineHeight; }
    Qt::TextElideMode elideMode() const { return m_elideMode; }
    bool clip() const { return m_clip; }

    void setText(const QString &text);
    void setFont(const QFont &font);
    void setColor(const QColor &color);
    void setAlignment(Qt::Alignment alignment);
    void setPadding(qreal padding);
    void setLineHeight(qreal lineHeight);
    void setElideMode(Qt::TextElideMode mode);
    void setClip(bool clip);

    // Add paint method declaration
    void paint(QPainter *painter) override;

signals:
    void textChanged();
    void fontChanged();
    void colorChanged();
    void alignmentChanged();
    void paddingChanged();
    void lineHeightChanged();
    void elideModeChanged();
    void clipChanged();

private:
    QString m_text;
    QFont m_font;
    QColor m_color;
    Qt::Alignment m_alignment;
    qreal m_padding;
    qreal m_lineHeight;
    Qt::TextElideMode m_elideMode;
    bool m_clip;
};

#endif // CUSTOMTEXTNODE_H
