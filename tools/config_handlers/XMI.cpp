/*
 * This code was generated by the XML Schema Compiler.
 *
 * Changes made to this code will most likely be overwritten
 * when the handlers are recompiled.
 */
#include "XMI.hpp"

namespace XMI
{
  // Extension

  Extension::Extension ()
  {
  }

  Extension::Extension (Extension const& s) :
  ::XSCRT::Type (s)
  , id_ (s.id_ ? std::make_unique<::XMLSchema::ID<char>> (*s.id_) : nullptr)
  , label_ (s.label_ ? std::make_unique<::XMLSchema::string<char>> (*s.label_) : nullptr)
  , uuid_ (s.uuid_ ? std::make_unique<::XMLSchema::string<char>> (*s.uuid_) : nullptr)
  , href_ (s.href_ ? std::make_unique<::XMLSchema::string<char>> (*s.href_) : nullptr)
  , idref_ (s.idref_ ? std::make_unique<::XMLSchema::IDREF<char>> (*s.idref_) : nullptr)
  , version_ (s.version_ ? std::make_unique<::XMLSchema::string<char>> (*s.version_) : nullptr)
  , extender_ (s.extender_ ? std::make_unique<::XMLSchema::string<char>> (*s.extender_) : nullptr)
  , extenderID_ (s.extenderID_ ? std::make_unique<::XMLSchema::string<char>> (*s.extenderID_) : nullptr)
  {
  }

  Extension&
  Extension::operator= (Extension const& s)
  {
    if (std::addressof(s) != this)
    {
      if (s.id_) id (*(s.id_));
      else id_.reset (nullptr);

      if (s.label_) label (*(s.label_));
      else label_.reset (nullptr);

      if (s.uuid_) uuid (*(s.uuid_));
      else uuid_.reset (nullptr);

      if (s.href_) href (*(s.href_));
      else href_.reset (nullptr);

      if (s.idref_) idref (*(s.idref_));
      else idref_.reset (nullptr);

      if (s.version_) version (*(s.version_));
      else version_.reset (nullptr);

      if (s.extender_) extender (*(s.extender_));
      else extender_.reset (nullptr);

      if (s.extenderID_) extenderID (*(s.extenderID_));
      else extenderID_.reset (nullptr);
    }

    return *this;
  }


  // Extension
  bool Extension::
  id_p () const
  {
    return !!id_;
  }

  ::XMLSchema::ID<char> const& Extension::
  id () const
  {
    return *id_;
  }

  ::XMLSchema::ID<char>& Extension::
  id ()
  {
    return *id_;
  }

  void Extension::
  id (::XMLSchema::ID<char> const& e)
  {
    if (id_)
    {
      *id_ = e;
    }

    else
    {
      id_ = std::make_unique<::XMLSchema::ID<char>> (e);
    }
  }

  // Extension
  bool Extension::
  label_p () const
  {
    return !!label_;
  }

  ::XMLSchema::string<char> const& Extension::
  label () const
  {
    return *label_;
  }

  ::XMLSchema::string<char>& Extension::
  label ()
  {
    return *label_;
  }

  void Extension::
  label (::XMLSchema::string<char> const& e)
  {
    if (label_)
    {
      *label_ = e;
    }

    else
    {
      label_ = std::make_unique<::XMLSchema::string<char>> (e);
    }
  }

  // Extension
  bool Extension::
  uuid_p () const
  {
    return !!uuid_;
  }

  ::XMLSchema::string<char> const& Extension::
  uuid () const
  {
    return *uuid_;
  }

  ::XMLSchema::string<char>& Extension::
  uuid ()
  {
    return *uuid_;
  }

  void Extension::
  uuid (::XMLSchema::string<char> const& e)
  {
    if (uuid_)
    {
      *uuid_ = e;
    }

    else
    {
      uuid_ = std::make_unique<::XMLSchema::string<char>> (e);
    }
  }

  // Extension
  bool Extension::
  href_p () const
  {
    return !!href_;
  }

  ::XMLSchema::string<char> const& Extension::
  href () const
  {
    return *href_;
  }

  ::XMLSchema::string<char>& Extension::
  href ()
  {
    return *href_;
  }

  void Extension::
  href (::XMLSchema::string<char> const& e)
  {
    if (href_)
    {
      *href_ = e;
    }

    else
    {
      href_ = std::make_unique<::XMLSchema::string<char>> (e);
    }
  }

  // Extension
  bool Extension::
  idref_p () const
  {
    return !!idref_;
  }

  ::XMLSchema::IDREF<char> const& Extension::
  idref () const
  {
    return *idref_;
  }

  ::XMLSchema::IDREF<char>& Extension::
  idref ()
  {
    return *idref_;
  }

  void Extension::
  idref (::XMLSchema::IDREF<char> const& e)
  {
    if (idref_)
    {
      *idref_ = e;
    }

    else
    {
      idref_ = std::make_unique<::XMLSchema::IDREF<char>> (e);
    }
  }

  // Extension
  bool Extension::
  version_p () const
  {
    return !!version_;
  }

  ::XMLSchema::string<char> const& Extension::
  version () const
  {
    return *version_;
  }

  ::XMLSchema::string<char>& Extension::
  version ()
  {
    return *version_;
  }

  void Extension::
  version (::XMLSchema::string<char> const& e)
  {
    if (version_)
    {
      *version_ = e;
    }

    else
    {
      version_ = std::make_unique<::XMLSchema::string<char>> (e);
    }
  }

  // Extension
  bool Extension::
  extender_p () const
  {
    return !!extender_;
  }

  ::XMLSchema::string<char> const& Extension::
  extender () const
  {
    return *extender_;
  }

  ::XMLSchema::string<char>& Extension::
  extender ()
  {
    return *extender_;
  }

  void Extension::
  extender (::XMLSchema::string<char> const& e)
  {
    if (extender_)
    {
      *extender_ = e;
    }

    else
    {
      extender_ = std::make_unique<::XMLSchema::string<char>> (e);
    }
  }

  // Extension
  bool Extension::
  extenderID_p () const
  {
    return !!extenderID_;
  }

  ::XMLSchema::string<char> const& Extension::
  extenderID () const
  {
    return *extenderID_;
  }

  ::XMLSchema::string<char>& Extension::
  extenderID ()
  {
    return *extenderID_;
  }

  void Extension::
  extenderID (::XMLSchema::string<char> const& e)
  {
    if (extenderID_)
    {
      *extenderID_ = e;
    }

    else
    {
      extenderID_ = std::make_unique<::XMLSchema::string<char>> (e);
    }
  }
}

namespace XMI
{
  // Extension

  Extension::
  Extension (::XSCRT::XML::Element<char> const& element)
  :Base (element)
  {

    ::XSCRT::Parser<char> p (element);

    while (p.more_attributes ())
    {
      ::XSCRT::XML::Attribute<char> a (p.next_attribute ());
      std::string n (::XSCRT::XML::uq_name (a.name ()));
      if (n ==  ("id"))
      {
        ::XMLSchema::ID<char> t (a);
        id (t);
      }

      else if (n ==  ("label"))
      {
        ::XMLSchema::string<char> t (a);
        label (t);
      }

      else if (n ==  ("uuid"))
      {
        ::XMLSchema::string<char> t (a);
        uuid (t);
      }

      else if (n ==  ("href"))
      {
        ::XMLSchema::string<char> t (a);
        href (t);
      }

      else if (n ==  ("idref"))
      {
        ::XMLSchema::IDREF<char> t (a);
        idref (t);
      }

      else if (n ==  ("version"))
      {
        ::XMLSchema::string<char> t (a);
        version (t);
      }

      else if (n ==  ("extender"))
      {
        ::XMLSchema::string<char> t (a);
        extender (t);
      }

      else if (n ==  ("extenderID"))
      {
        ::XMLSchema::string<char> t (a);
        extenderID (t);
      }

      else 
      {
      }
    }
  }
}

namespace XMI
{
  namespace reader
  {
    ::XMI::Extension
    extension (xercesc::DOMDocument const* d)
    {
      xercesc::DOMElement* dom_element = d->getDocumentElement ();
      if (!dom_element)
      {
        throw 1;
      }

      ::XSCRT::XML::Element<char> e (dom_element);
      if (e.name () == "extension")
      {
        ::XMI::Extension r (e);

        return r;
      }

      else
      {
        throw 1;
      }
    }
  }
}

