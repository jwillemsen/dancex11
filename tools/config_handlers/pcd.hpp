/*
 * This code was generated by the XML Schema Compiler.
 *
 * Changes made to this code will most likely be overwritten
 * when the handlers are recompiled.
 */
#ifndef PCD_HPP
#define PCD_HPP

#include "xsc_xml_handlers_export.h"
// Forward declarations.
namespace DAnCE
{
  namespace Config_Handlers
  {
    class ComponentPackageImport;
    class PackageConfiguration;
  }
}

#include <memory>
#include <string>
#include <vector>
#include "ace/XML_Utils/XMLSchema/Types.hpp"
#include "ace/XML_Utils/XMLSchema/id_map.hpp"
#include "tao/x11/base/stddef.h"
#include "Basic_Deployment_Data.hpp"

#include "cpd.hpp"

namespace DAnCE
{
  namespace Config_Handlers
  {
    class XSC_XML_Handlers_Export ComponentPackageImport : public ::XSCRT::Type
    {
      using Base = ::XSCRT::Type;

      // location
      public:
      using location_container_type = std::vector< ::XMLSchema::string<char>>;
      using location_const_iterator = location_container_type::const_iterator;
      location_const_iterator begin_location () const;
      location_const_iterator end_location () const;
      size_t count_location () const;

      protected:
      location_container_type location_;

      public:
      ComponentPackageImport ();

      explicit ComponentPackageImport (::XSCRT::XML::Element<char> const&);
      ComponentPackageImport (ComponentPackageImport const& s);
      ComponentPackageImport& operator= (ComponentPackageImport const& s);

      ComponentPackageImport (ComponentPackageImport&&) = default;
      ComponentPackageImport& operator= (ComponentPackageImport&&) = default;
    };


    class XSC_XML_Handlers_Export PackageConfiguration : public ::XSCRT::Type
    {
      using Base = ::XSCRT::Type;

      // label
      public:
      bool label_p () const;
      ::XMLSchema::string<char> const& label () const;
      void label (::XMLSchema::string<char> const&);

      protected:
      using label_type = std::unique_ptr<::XMLSchema::string<char>>;
      label_type label_;

      // UUID
      public:
      bool UUID_p () const;
      ::XMLSchema::string<char> const& UUID () const;
      void UUID (::XMLSchema::string<char> const&);

      protected:
      using UUID_type = std::unique_ptr<::XMLSchema::string<char>>;
      UUID_type UUID_;

      // basePackage
      public:
      bool basePackage_p () const;
      ::DAnCE::Config_Handlers::ComponentPackageDescription const& basePackage () const;
      void basePackage (::DAnCE::Config_Handlers::ComponentPackageDescription const&);

      protected:
      using basePackage_type = std::unique_ptr<::DAnCE::Config_Handlers::ComponentPackageDescription>;
      basePackage_type basePackage_;

      // specializedConfig
      public:
      bool specializedConfig_p () const;
      ::DAnCE::Config_Handlers::PackageConfiguration const& specializedConfig () const;
      void specializedConfig (::DAnCE::Config_Handlers::PackageConfiguration const&);

      protected:
      using specializedConfig_type = std::unique_ptr<::DAnCE::Config_Handlers::PackageConfiguration>;
      specializedConfig_type specializedConfig_;

      // importedPackage
      public:
      bool importedPackage_p () const;
      ::DAnCE::Config_Handlers::ComponentPackageImport const& importedPackage () const;
      void importedPackage (::DAnCE::Config_Handlers::ComponentPackageImport const&);

      protected:
      using importedPackage_type = std::unique_ptr<::DAnCE::Config_Handlers::ComponentPackageImport>;
      importedPackage_type importedPackage_;

      // referencedPackage
      public:
      bool referencedPackage_p () const;
      ::DAnCE::Config_Handlers::ComponentPackageReference const& referencedPackage () const;
      void referencedPackage (::DAnCE::Config_Handlers::ComponentPackageReference const&);

      protected:
      using referencedPackage_type = std::unique_ptr<::DAnCE::Config_Handlers::ComponentPackageReference>;
      referencedPackage_type referencedPackage_;

      // selectRequirement
      public:
      using selectRequirement_container_type = std::vector< ::DAnCE::Config_Handlers::Requirement>;
      using selectRequirement_const_iterator = selectRequirement_container_type::const_iterator;
      selectRequirement_const_iterator begin_selectRequirement () const;
      selectRequirement_const_iterator end_selectRequirement () const;
      size_t count_selectRequirement () const;

      protected:
      selectRequirement_container_type selectRequirement_;

      // configProperty
      public:
      using configProperty_container_type = std::vector< ::DAnCE::Config_Handlers::Property>;
      using configProperty_const_iterator = configProperty_container_type::const_iterator;
      configProperty_const_iterator begin_configProperty () const;
      configProperty_const_iterator end_configProperty () const;
      size_t count_configProperty () const;

      protected:
      configProperty_container_type configProperty_;

      // contentLocation
      public:
      bool contentLocation_p () const;
      ::XMLSchema::string<char> const& contentLocation () const;
      void contentLocation (::XMLSchema::string<char> const&);

      protected:
      using contentLocation_type = std::unique_ptr<::XMLSchema::string<char>>;
      contentLocation_type contentLocation_;

      public:
      PackageConfiguration ();

      explicit PackageConfiguration (::XSCRT::XML::Element<char> const&);
      PackageConfiguration (PackageConfiguration const& s);
      PackageConfiguration& operator= (PackageConfiguration const& s);

      PackageConfiguration (PackageConfiguration&&) = default;
      PackageConfiguration& operator= (PackageConfiguration&&) = default;
    };
  }
}

namespace DAnCE
{
  namespace Config_Handlers
  {
  }
}

#endif // PCD_HPP
