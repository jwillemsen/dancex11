/**
 * @file    datatype_handler.cpp
 * @author  Marijke Hengstmengel
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */

#include "datatype_handler.h"
#include "common.h"
#include "dynany_handler/dynany_handler.h"
#include "tao/x11/anytypecode/typecode.h"
#include "tao/x11/anytypecode/typecode_constants.h"
#include "tao/x11/anytypecode/ValueModifierC.h"
#include "tao/x11/anytypecode/VisibilityC.h"
#include "tao/x11/ifr_client/IFR_ExtendedC.h"
#include "dancex11/logger/log.h"
namespace DAnCEX11
{
  namespace Config_Handlers
  {
    IDL::traits<CORBA::TypeCode>::ref_type
    convert_datatype (const DAnCE::Config_Handlers::DataType& src)
    {
      DANCEX11_LOG_TRACE("DAnCEX11::Config_Handlers::convert_datatype");

      IDL::traits<CORBA::TypeCode>::ref_type dest;

      switch (src.kind().integral ())
      {
      case DAnCE::Config_Handlers::TCKind::tk_null:
        dest = CORBA::_tc_null;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_short:
        dest = CORBA::_tc_short;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_long:
        dest = CORBA::_tc_long;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_ushort:
        dest = CORBA::_tc_ushort;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_ulong:
        dest = CORBA::_tc_ulong;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_float:
        dest = CORBA::_tc_float;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_double:
        dest = CORBA::_tc_double;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_boolean:
        dest = CORBA::_tc_boolean;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_char:
        dest = CORBA::_tc_char;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_octet:
        dest = CORBA::_tc_octet;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_string:
      case DAnCE::Config_Handlers::TCKind::tk_enum:
      case DAnCE::Config_Handlers::TCKind::tk_struct:
      case DAnCE::Config_Handlers::TCKind::tk_sequence:
      case DAnCE::Config_Handlers::TCKind::tk_array:
      case DAnCE::Config_Handlers::TCKind::tk_alias:
        dest = DYNANY_HANDLER->create_typecode (src);
        break;
      case DAnCE::Config_Handlers::TCKind::tk_longlong:
        dest = CORBA::_tc_longlong;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_ulonglong:
        dest = CORBA::_tc_ulonglong;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_longdouble:
        dest = CORBA::_tc_longdouble;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_wchar:
        dest = CORBA::_tc_wchar;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_any:
        dest = CORBA::_tc_any;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_TypeCode:
        dest = CORBA::_tc_TypeCode;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_void:
        dest = CORBA::_tc_void;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_Principal:
        dest = CORBA::_tc_Principal;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_objref:
        dest = CORBA::_tc_Object;
        break;
      case DAnCE::Config_Handlers::TCKind::tk_value:
        {
          DAnCE::Config_Handlers::ValueType const* value = src.value_if_set ();
          if (!value)
            throw Config_Error ("", "Value type description required");

          CORBA::ValueModifier modifier {};
          if (value->modifier () == "none") modifier = CORBA::VM_NONE;
          else if (value->modifier () == "custom") modifier = CORBA::VM_CUSTOM;
          else if (value->modifier () == "abstract") modifier = CORBA::VM_ABSTRACT;
          else if (value->modifier () == "truncatable") modifier = CORBA::VM_TRUNCATABLE;
          else throw Config_Error (value->name (), "Invalid value type modifier");

          CORBA::ValueMemberSeq members;
          for (DAnCE::Config_Handlers::ValueMemberType const& source_member : value->member ())
            {
              CORBA::Visibility visibility {};
              if (source_member.visibility () == "public") visibility = CORBA::PUBLIC_MEMBER;
              else if (source_member.visibility () == "private") visibility = CORBA::PRIVATE_MEMBER;
              else throw Config_Error (source_member.name (), "Invalid value member visibility");

              members.emplace_back (source_member.name (), "", value->typeId (), "1.0",
                                    DYNANY_HANDLER->create_typecode (source_member.type ()),
                                    IDL::traits<CORBA::IDLType>::ref_type {}, visibility);
            }

          dest = DYNANY_HANDLER->orb ()->create_value_tc (
            value->typeId (), value->name (), modifier,
            DYNANY_HANDLER->create_typecode (value->baseType ()), members);
          DYNANY_HANDLER->register_typecode (value->typeId (), dest);
          break;
        }
      case DAnCE::Config_Handlers::TCKind::tk_wstring:
        {
          uint32_t bound {};
          DAnCE::Config_Handlers::BoundedStringType const* bounded = src.boundedString_if_set ();
          if (bounded && !bounded->bound ().empty ()) bound = bounded->bound ().front ();
          if (bounded && bounded->bound ().size () > 1)
            throw Config_Error ("", "A bounded wide string type can have at most one bound");
          dest = DYNANY_HANDLER->orb ()->create_wstring_tc (bound);
          break;
        }
      default:
        DANCEX11_LOG_ERROR ("DAnCEX11::Config_Handlers::convert_datatype, invalid typecode in any");
        throw Config_Error ("", "Invalid typecode in data type description");
      }

      return dest;
    }
  }
}
