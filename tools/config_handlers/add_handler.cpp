/**
 * @file    add_handler.cpp
 * @author  Marijke Hengstmengel
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */
#include "add_handler.h"
#include "rdd_handler.h"
#include "req_handler.h"
#include "property_handler.h"
#include "dancex11/logger/log.h"

namespace DAnCEX11
{
  namespace Config_Handlers
  {
    Deployment::ArtifactDeploymentDescription
    convert_artifactdeploymentdescription (const DAnCE::Config_Handlers::ArtifactDeploymentDescription& src)
    {
      DANCEX11_LOG_TRACE("DAnCEX11::Config_Handlers::convert_artifactdeploymentdescriptions");

      Deployment::ArtifactDeploymentDescription dest {};

      dest.name (src.name ());
      dest.node (src.node ());

      std::copy(src.location_values ().begin (),
                src.location_values ().end (),
                std::back_inserter(dest.location()));

      std::copy(src.source_values ().begin (),
                src.source_values ().end (),
                std::back_inserter(dest.source()));

      std::transform(src.execParameter_values ().begin (),
                     src.execParameter_values ().end (),
                     std::back_inserter(dest.execParameter()),
                     DAnCEX11::Config_Handlers::convert_property);

      std::transform(src.deployedResource_values ().begin (),
                     src.deployedResource_values ().end (),
                     std::back_inserter(dest.deployedResource()),
                     DAnCEX11::Config_Handlers::convert_resourcedeploymentdescription);

      std::transform(src.deployRequirement_values ().begin (),
                     src.deployRequirement_values ().end (),
                     std::back_inserter(dest.deployRequirement()),
                     DAnCEX11::Config_Handlers::convert_requirement);

      return dest;
    }
  }
}
