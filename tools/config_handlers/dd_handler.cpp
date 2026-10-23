/**
 * @file    dd_handler.cpp
 * @author  Marijke Hengstmengel
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */

#include "dd_handler.h"
#include "node_handler.h"
#include "Deployment.hpp"
#include "dancex11/logger/log.h"

namespace DAnCEX11
{
  namespace Config_Handlers
  {
    std::unique_ptr<Deployment::Domain>
    DD_Handler::resolve_domain (const DAnCE::Config_Handlers::Domain &domain) const
    {
      DANCEX11_LOG_TRACE("DD_Handler::resolve_domain");

      std::unique_ptr<Deployment::Domain> idl_dd = std::make_unique<Deployment::Domain> ();

      auto const* label = domain.label_if_set ();
      if (label)
      {
        idl_dd->label(*label);
      }

      auto const* uuid = domain.UUID_if_set ();
      if (uuid)
      {
        idl_dd->UUID (*uuid);
      }

      std::transform(domain.node_values ().begin (),
                     domain.node_values ().end (),
                     std::back_inserter(idl_dd->node()),
                     DAnCEX11::Config_Handlers::convert_node);

      return idl_dd;
    }
  }
}

