/**
 * @file    mdd_handler.cpp
 * @author  Marijke Hengstmengel
 *
  * @copyright Copyright (c) Remedy IT Expertise BV
 */

#include "mdd_handler.h"
#include "add_handler.h"
#include "property_handler.h"
#include "req_handler.h"
#include "cdp.hpp"
#include "common.h"
#include "dancex11/logger/log.h"

namespace DAnCEX11
{
  namespace Config_Handlers
  {
    Deployment::MonolithicDeploymentDescription
    convert_monolithicdeploymentdescription (const DAnCE::Config_Handlers::MonolithicDeploymentDescription& src,
                                             const std::unordered_map<std::string, size_t>& artifact_map)
    {
      DANCEX11_LOG_TRACE("DAnCEX11::Config_Handlers::convert_monolithicdeploymentdescription");

      Deployment::MonolithicDeploymentDescription dest {};

      dest.name(src.name ());

      std::copy(src.source_values ().begin (),
                src.source_values ().end (),
                std::back_inserter(dest.source()));

      std::transform(src.artifact_values ().begin (),
                     src.artifact_values ().end (),
                     std::back_inserter(dest.artifactRef()),
                     [&](const DAnCE::Config_Handlers::IdRef& id)
                     {
                       auto const* idref = id.idref_if_set ();
                       if (!idref)
                         throw Config_Error ("", "Missing idref for artifact reference");

                       auto result = artifact_map.find (idref->id ());
                       if (result != artifact_map.end ())
                         return static_cast<uint32_t>(result->second);
                       else
                         return std::numeric_limits<uint32_t>::max();
                     });

      std::transform(src.execParameter_values ().begin (),
                     src.execParameter_values ().end (),
                     std::back_inserter(dest.execParameter()),
                     DAnCEX11::Config_Handlers::convert_property);

      std::transform(src.deployRequirement_values ().begin (),
                     src.deployRequirement_values ().end (),
                     std::back_inserter(dest.deployRequirement()),
                     DAnCEX11::Config_Handlers::convert_requirement);

      return dest;
    }
  }
}
