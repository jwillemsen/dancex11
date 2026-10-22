/**
 * @file    dp_handler.cpp
 * @author  Marijke Hengstmengel
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */

#include "dp_handler.h"
#include "ccd_handler.h"
#include "add_handler.h"
#include "mdd_handler.h"
#include "idd_handler.h"
#include "id_handler.h"
#include "pl_handler.h"
#include "property_handler.h"
#include "cdp.hpp"
#include "pcd_handler.h"
#include "dancex11/logger/log.h"
#include <unordered_map>

namespace DAnCEX11
{
  namespace Config_Handlers
  {
    std::unique_ptr<Deployment::DeploymentPlan>
    DP_Handler::resolve_plan (const DAnCE::Config_Handlers::deploymentPlan &xsc_dp) const
    {
      DANCEX11_LOG_TRACE ("DP_Handler::resolve_plan");

      std::unique_ptr<Deployment::DeploymentPlan> idl_dp = std::make_unique<Deployment::DeploymentPlan> ();

      auto const* label = xsc_dp.label_if_set ();
      if (label)
        {
          idl_dp->label (*label);
        }

      auto const* uuid = xsc_dp.UUID_if_set ();
      if (uuid)
        {
          idl_dp->UUID (*uuid);
        }

      std::transform(xsc_dp.begin_dependsOn (),
                     xsc_dp.end_dependsOn (),
                     std::back_inserter(idl_dp->dependsOn()),
                     DAnCEX11::Config_Handlers::convert_implementationdependency);

      std::transform(xsc_dp.begin_infoProperty (),
                     xsc_dp.end_infoProperty (),
                     std::back_inserter(idl_dp->infoProperty()),
                     DAnCEX11::Config_Handlers::convert_property);

      auto const* realizes = xsc_dp.realizes_if_set ();
      if (realizes)
        {
          idl_dp->realizes(DAnCEX11::Config_Handlers::convert_componentinterfacedescription (*realizes));
        }

      std::unordered_map<std::string, size_t> artifact_map;
      std::transform(xsc_dp.begin_artifact (),
                     xsc_dp.end_artifact (),
                     std::back_inserter(idl_dp->artifact()),
                     [&](const DAnCE::Config_Handlers::ArtifactDeploymentDescription& src)
                     {
                       auto const* id = src.id_if_set ();
                       if (id)
                       {
                         artifact_map.insert({*id, idl_dp->artifact().size () });
                       }
                       return DAnCEX11::Config_Handlers::convert_artifactdeploymentdescription(src);
                     });

      std::unordered_map<std::string, size_t> monolithicdeploymentdescription_map;
      std::transform(xsc_dp.begin_implementation (),
                     xsc_dp.end_implementation (),
                     std::back_inserter(idl_dp->implementation()),
                     [&](const DAnCE::Config_Handlers::MonolithicDeploymentDescription& src)
                     {
                       auto const* id = src.id_if_set ();
                       if (id)
                       {
                         monolithicdeploymentdescription_map.insert({*id, idl_dp->implementation().size () });
                       }
                       return DAnCEX11::Config_Handlers::convert_monolithicdeploymentdescription(src, artifact_map);
                     });

      std::unordered_map<std::string, size_t> instancedeploymentdescription_map;
      std::transform(xsc_dp.begin_instance (),
                     xsc_dp.end_instance (),
                     std::back_inserter(idl_dp->instance()),
                     [&](const DAnCE::Config_Handlers::InstanceDeploymentDescription& src)
                     {
                       auto const* id = src.id_if_set ();
                       if (id)
                       {
                         instancedeploymentdescription_map.insert({*id, idl_dp->instance().size () });
                       }
                       return DAnCEX11::Config_Handlers::convert_instancedeploymentdescription(src, monolithicdeploymentdescription_map);
                     });

      std::transform(xsc_dp.begin_connection (),
                     xsc_dp.end_connection (),
                     std::back_inserter(idl_dp->connection()),
                     [&](const DAnCE::Config_Handlers::PlanConnectionDescription& src)
                     {
                       return DAnCEX11::Config_Handlers::convert_planconnectiondescription(src, instancedeploymentdescription_map);
                     });

      std::transform(xsc_dp.begin_localityConstraint (),
                     xsc_dp.end_localityConstraint (),
                     std::back_inserter(idl_dp->localityConstraint()),
                     [&](const DAnCE::Config_Handlers::PlanLocality& src)
                     {
                       return DAnCEX11::Config_Handlers::convert_planlocality(src, instancedeploymentdescription_map);
                     });

      return idl_dp;
    }
  }
}
