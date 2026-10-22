/**
 * @file    ccd_handler.cpp
 * @author  Marijke Hengstmengel
 *
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */
#include "ccd_handler.h"
#include "property_handler.h"
#include "cpd_handler.h"
#include "componentpropertydescription_handler.h"
#include "dancex11/logger/log.h"

namespace DAnCEX11
{
  namespace Config_Handlers
  {
    Deployment::ComponentInterfaceDescription
    convert_componentinterfacedescription (const DAnCE::Config_Handlers::ComponentInterfaceDescription& src)
    {
      DANCEX11_LOG_TRACE("DAnCEX11::Config_Handlers::convert_componentinterfacedescription");

      Deployment::ComponentInterfaceDescription dest {};

      auto const* uuid = src.UUID_if_set ();
      if (uuid)
      {
        dest.UUID (*uuid);
      }

      auto const* label = src.label_if_set ();
      if (label)
      {
        dest.label (*label);
      }

      auto const* specific_type = src.specificType_if_set ();
      if (specific_type)
      {
        dest.specificType (*specific_type);
      }

      std::copy(src.begin_supportedType (),
                src.end_supportedType (),
                std::back_inserter(dest.supportedType()));

      std::copy(src.begin_idlFile (),
                src.end_idlFile (),
                std::back_inserter(dest.idlFile()));

      std::transform(src.begin_configProperty (),
                     src.begin_configProperty (),
                     std::back_inserter(dest.configProperty()),
                     DAnCEX11::Config_Handlers::convert_property);

      std::transform(src.begin_port (),
                     src.end_port (),
                     std::back_inserter(dest.port()),
                     DAnCEX11::Config_Handlers::convert_componentportdescription);

      std::transform(src.begin_property (),
                     src.end_property (),
                     std::back_inserter(dest.property()),
                     DAnCEX11::Config_Handlers::convert_componentpropertydescription);

      std::transform(src.begin_infoProperty (),
                     src.end_infoProperty (),
                     std::back_inserter(dest.infoProperty()),
                     DAnCEX11::Config_Handlers::convert_property);

      return dest;
    }
  }
}
