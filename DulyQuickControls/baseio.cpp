#include "link.h"
#include "baseio.h"
#include <QDebug>

BaseIo::BaseIo() : m_type(DulyResources::IOType::Int)
{

}

BaseIo::~BaseIo()
{

}

Link *BaseIo::connect(ALinkable *linkable, BezierCurve *curve)
{
    auto l = getLink(linkable);
    if (l == nullptr)
    {
        l = new Link(this, linkable);
        l->setCurve(curve);
        m_links.add(l);
		linkable->addLink(l);
        return l;
    }
    //TODO INSERT DEBUG "Link already exist"
    return l;
}

void BaseIo::unlink(ALinkable *linkable)
{
	const auto l = getLink(linkable);
    if (l != nullptr)
    {
		m_links.remove(l);
        linkable->removeLink(l);
    }
    //TODO INSERT DEBUG "Link doesn't exist"
}

void BaseIo::unlinkAll()
{
    auto l = m_links.rawList();
    for (auto i : l)
    {
        i->L2->unlink(this);
    }
    m_links.clear();
}

void BaseIo::addLink(Link *l)
{
	m_links.add(l);
}

void BaseIo::removeLink(Link *l)
{
	m_links.remove(l);
}

bool BaseIo::isLink()
{
    return m_links.empty();
}

void BaseIo::setType(DulyResources::IOType t)
{
    if (t == m_type)
        return;
    m_type = t;
}

DulyResources::IOType BaseIo::getType() const
{
	return m_type;
}

Link *BaseIo::getLink(ALinkable *linkable) const
{
    auto ref = m_links.rawList();
    const auto findFunc = [&](auto *l){
        return ((l->L1 == this && l->L2 == linkable) || (l->L1 == linkable && l->L2 == this));
    };
	const auto it = std::find_if(ref.begin(), ref.end(), findFunc);
    if (it == ref.end()) return nullptr;
    return (*it);
}