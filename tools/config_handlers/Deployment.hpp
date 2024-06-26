/*
 * This code was generated by the XML Schema Compiler.
 *
 * Changes made to this code will most likely be overwritten
 * when the handlers are recompiled.
 */
#ifndef DEPLOYMENT_HPP
#define DEPLOYMENT_HPP

#include "xsc_xml_handlers_export.h"
// Forward declarations.
namespace DAnCE
{
  namespace Config_Handlers
  {
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

#include "cdd.hpp"

#include "cdp.hpp"

#include "toplevel.hpp"

namespace DAnCE
{
  namespace Config_Handlers
  {
  }
}

namespace DAnCE
{
  namespace Config_Handlers
  {
    namespace reader
    {
      XSC_XML_Handlers_Export
      ::DAnCE::Config_Handlers::Domain
      domain (xercesc::DOMDocument const*);
    }


    namespace reader
    {
      XSC_XML_Handlers_Export
      ::DAnCE::Config_Handlers::deploymentPlan
      DeploymentPlan (xercesc::DOMDocument const*);
    }


    namespace reader
    {
      XSC_XML_Handlers_Export
      ::DAnCE::Config_Handlers::ImplementationArtifactDescription
      implementationArtifactDescription (xercesc::DOMDocument const*);
    }


    namespace reader
    {
      XSC_XML_Handlers_Export
      ::DAnCE::Config_Handlers::ComponentInterfaceDescription
      componentInterfaceDescription (xercesc::DOMDocument const*);
    }


    namespace reader
    {
      XSC_XML_Handlers_Export
      ::DAnCE::Config_Handlers::ComponentImplementationDescription
      componentImplementationDescription (xercesc::DOMDocument const*);
    }


    namespace reader
    {
      XSC_XML_Handlers_Export
      ::DAnCE::Config_Handlers::ComponentPackageDescription
      componentPackageDescription (xercesc::DOMDocument const*);
    }


    namespace reader
    {
      XSC_XML_Handlers_Export
      ::DAnCE::Config_Handlers::PackageConfiguration
      packageConfiguration (xercesc::DOMDocument const*);
    }


    namespace reader
    {
      XSC_XML_Handlers_Export
      ::DAnCE::Config_Handlers::TopLevelPackageDescription
      topLevelPackageDescription (xercesc::DOMDocument const*);
    }
  }
}

#endif // DEPLOYMENT_HPP
