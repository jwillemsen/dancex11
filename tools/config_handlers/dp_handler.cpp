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

      ::XMLSchema::string<char> const* label = xsc_dp.label_if_set ();
      if (label)
        {
          idl_dp->label (*label);
        }

      ::XMLSchema::string<char> const* uuid = xsc_dp.UUID_if_set ();
      if (uuid)
        {
          idl_dp->UUID (*uuid);
        }

      std::transform(xsc_dp.dependsOn ().begin (),
                     xsc_dp.dependsOn ().end (),
                     std::back_inserter(idl_dp->dependsOn()),
                     DAnCEX11::Config_Handlers::convert_implementationdependency);

      std::transform(xsc_dp.infoProperty ().begin (),
                     xsc_dp.infoProperty ().end (),
                     std::back_inserter(idl_dp->infoProperty()),
                     DAnCEX11::Config_Handlers::convert_property);

      ::DAnCE::Config_Handlers::ComponentInterfaceDescription const* realizes = xsc_dp.realizes_if_set ();
      if (realizes)
        {
          idl_dp->realizes(DAnCEX11::Config_Handlers::convert_componentinterfacedescription (*realizes));
        }

      std::unordered_map<std::string, size_t> artifact_map;
      for (DAnCE::Config_Handlers::ArtifactDeploymentDescription const& src : xsc_dp.artifact ())
        {
          size_t const index = idl_dp->artifact ().size ();
          ::XMLSchema::ID<char> const* id = src.id_if_set ();
          if (id)
            artifact_map.insert ({*id, index});
          idl_dp->artifact ().push_back (
            DAnCEX11::Config_Handlers::convert_artifactdeploymentdescription (src));
        }

      std::unordered_map<std::string, size_t> monolithicdeploymentdescription_map;
      for (DAnCE::Config_Handlers::MonolithicDeploymentDescription const& src : xsc_dp.implementation ())
        {
          size_t const index = idl_dp->implementation ().size ();
          ::XMLSchema::ID<char> const* id = src.id_if_set ();
          if (id)
            monolithicdeploymentdescription_map.insert ({*id, index});
          idl_dp->implementation ().push_back (
            DAnCEX11::Config_Handlers::convert_monolithicdeploymentdescription (src, artifact_map));
        }

      std::unordered_map<std::string, size_t> instancedeploymentdescription_map;
      for (DAnCE::Config_Handlers::InstanceDeploymentDescription const& src : xsc_dp.instance ())
        {
          size_t const index = idl_dp->instance ().size ();
          ::XMLSchema::ID<char> const* id = src.id_if_set ();
          if (id)
            instancedeploymentdescription_map.insert ({*id, index});
          idl_dp->instance ().push_back (
            DAnCEX11::Config_Handlers::convert_instancedeploymentdescription (
              src, monolithicdeploymentdescription_map));
        }

      std::transform(xsc_dp.connection ().begin (),
                     xsc_dp.connection ().end (),
                     std::back_inserter(idl_dp->connection()),
                     [&](const DAnCE::Config_Handlers::PlanConnectionDescription& src)
                     {
                       return DAnCEX11::Config_Handlers::convert_planconnectiondescription (
                         src, instancedeploymentdescription_map);
                     });

      std::transform(xsc_dp.localityConstraint ().begin (),
                     xsc_dp.localityConstraint ().end (),
                     std::back_inserter(idl_dp->localityConstraint()),
                     [&](const DAnCE::Config_Handlers::PlanLocality& src)
                     {
                       return DAnCEX11::Config_Handlers::convert_planlocality(src, instancedeploymentdescription_map);
                     });

      return idl_dp;
    }
  }
}
