
/*!
    \file

    \author Igor Mironchik (igor.mironchik at gmail dot com).

    Copyright (c) 2012 Igor Mironchik

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/

// QtConfFile include.
#include <QtConfFile/private/Tag>

// Qt include.
#include <QtCore/QString>


namespace QtConfFile {

//
// Tag::TagPrivate
//

class Tag::TagPrivate {
public:
    TagPrivate( const QString & name, bool isMandatory )
        :   m_name( name )
        ,   m_isMandatory( isMandatory )
        ,   m_isDefined( false )
    {
    }

    QString m_name;
    bool m_isMandatory;
    bool m_isDefined;
    Tag::ChildTagsList m_childTags;
}; // class Tag::TagPrivate


//
// Tag
//

Tag::Tag( const QString & name, bool isMandatory )
    :   d( new TagPrivate( name, isMandatory ) )
{
}

Tag::Tag( Tag & owner, const QString & name, bool isMandatory )
    :   d( new TagPrivate( name, isMandatory ) )
{
    owner.addChild( *this );
}

Tag::~Tag()
{
}

void
Tag::addChild( Tag & tag )
{
    if( !d->m_childTags.contains( &tag ) )
        d->m_childTags.append( &tag );
}

void
Tag::removeChild( Tag & tag )
{
    d->m_childTags.removeOne( &tag );
}

const Tag::ChildTagsList &
Tag::children() const
{
    return d->m_childTags;
}

const QString &
Tag::name() const
{
    return d->m_name;
}

bool
Tag::isMandatory() const
{
    return d->m_isMandatory;
}

bool
Tag::isDefined() const
{
    return d->m_isDefined;
}

void
Tag::setDefined( bool on )
{
    d->m_isDefined = on;
}

} /* namespace QtConfFile */
