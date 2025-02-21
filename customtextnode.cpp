#include "customtextnode.h"
#include <QPainter>

CustomTextNode::CustomTextNode(QQuickItem *parent)
    : QQuickPaintedItem(parent)
    , m_alignment(Qt::AlignLeft | Qt::AlignTop)
    , m_padding(0)
    , m_lineHeight(1.0)
    , m_elideMode(Qt::ElideNone)
    , m_clip(false)
{
    setAntialiasing(true);
}

void CustomTextNode::paint(QPainter *painter)
{
    painter->save();
    painter->setPen(m_color);
    painter->setFont(m_font);

    QString displayText = m_text;
    if (m_elideMode != Qt::ElideNone) {
        displayText = painter->fontMetrics().elidedText(
            m_text,
            m_elideMode,
            width() - 2 * m_padding
        );
    }

    painter->drawText(
        QRectF(m_padding, m_padding,
               width() - 2 * m_padding,
               height() - 2 * m_padding),
        m_alignment,
        displayText
    );

    painter->restore();
}

// Setter implementations
void CustomTextNode::setText(const QString &text) {
    if (m_text != text) {
        m_text = text;
        emit textChanged();
        update();
    }
}

void CustomTextNode::setFont(const QFont &font)
{
    if (m_font != font) {
        m_font = font;
        emit fontChanged();
        update();
    }
}

void CustomTextNode::setColor(const QColor &color)
{
    if (m_color != color) {
        m_color = color;
        emit colorChanged();
        update();
    }
}

void CustomTextNode::setAlignment(Qt::Alignment alignment)
{
    if (m_alignment != alignment) {
        m_alignment = alignment;
        emit alignmentChanged();
        update();
    }
}

void CustomTextNode::setPadding(qreal padding)
{
    if (m_padding != padding) {
        m_padding = padding;
        emit paddingChanged();
        update();
    }
}

void CustomTextNode::setLineHeight(qreal lineHeight)
{
    if (m_lineHeight != lineHeight) {
        m_lineHeight = lineHeight;
        emit lineHeightChanged();
        update();
    }
}

void CustomTextNode::setElideMode(Qt::TextElideMode mode)
{
    if (m_elideMode != mode) {
        m_elideMode = mode;
        emit elideModeChanged();
        update();
    }
}

void CustomTextNode::setClip(bool clip)
{
    if (m_clip != clip) {
        m_clip = clip;
        QQuickPaintedItem::setClip(clip);
        emit clipChanged();
        update();
    }
}
