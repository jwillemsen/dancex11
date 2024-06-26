/**
 * @file    xsc_xml_handlers_export.h
 * @author  Marijke Hengstmengel
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */
#ifndef XSC_XML_HANDLERS_EXPORT_H
#define XSC_XML_HANDLERS_EXPORT_H

#include "tao/x11/base/taox11_export_macros.h"

#if !defined (XSC_XML_HANDLERS_HAS_DLL)
#  define XSC_XML_HANDLERS_HAS_DLL 1
#endif /* ! XSC_XML_HANDLERS_HAS_DLL */

#if defined (XSC_XML_HANDLERS_HAS_DLL) && (XSC_XML_HANDLERS_HAS_DLL == 1)
#  if defined (XSC_XML_HANDLERS_BUILD_DLL)
#    define XSC_XML_Handlers_Export TAOX11_Proper_Export_Flag
#    define XSC_XML_HANDLERS_SINGLETON_DECLARATION(T) TAOX11_EXPORT_SINGLETON_DECLARATION (T)
#    define XSC_XML_HANDLERS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) TAOX11_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* XSC_XML_HANDLERS_BUILD_DLL */
#    define XSC_XML_Handlers_Export TAOX11_Proper_Import_Flag
#    define XSC_XML_HANDLERS_SINGLETON_DECLARATION(T) TAOX11_IMPORT_SINGLETON_DECLARATION (T)
#    define XSC_XML_HANDLERS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) TAOX11_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* XSC_XML_HANDLERS_BUILD_DLL */
#else /* XSC_XML_HANDLERS_HAS_DLL == 1 */
#  define XSC_XML_Handlers_Export
#  define XSC_XML_HANDLERS_SINGLETON_DECLARATION(T)
#  define XSC_XML_HANDLERS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* XSC_XML_HANDLERS_HAS_DLL == 1 */

#endif /* XSC_XML_HANDLERS_EXPORT_H */

