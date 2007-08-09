/*
// ////////////////////////////////////////////
// This File has been generated automaticaly //
// by Expressik modified generator           //
//  Powered by : Eve CSTB                    //
// ////////////////////////////////////////////

 * *************************************************************************
 *                                                                         *
 *     STEP Early Classes C++                                              *
 *                                                                         *
 *     Copyright (C) 2005 CSTB                                             *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the                 *
 *         Free Software Foundation, Inc.                                  *
 *         59 Temple Place, Suite 330                                      *
 *         Boston, MA  02111-1307                                          *
 *         USA                                                             *
 *                                                                         *
 *   For further information please contact                                *
 *                                                                         *
 *         eve@cstb.fr                                                     *
 *   or                                                                    *
 *         Eve, CSTB                                                       *
 *         290, route des Lucioles                                         *
 *         BP 209                                                          *
 *         06904 Sophia Antipolis, France                                  *
 *                                                                         *
 ***************************************************************************
*/

#include <MemoryLeak.h>
#include <ifc2x3/IfcGeometricSetSelect.h>

#include <Step/BaseObject.h>
#include <ifc2x3/IfcCurve.h>
#include <ifc2x3/IfcPoint.h>
#include <ifc2x3/IfcSurface.h>
#include <ifc2x3/Visitor.h>

using namespace ifc2x3;

IfcGeometricSetSelect::IfcGeometricSetSelect() : Step::BaseObject(0) {
  m_type = UNSET;
}

IfcGeometricSetSelect::IfcGeometricSetSelect(Step::SPFData *args) : Step::BaseObject(args) {
  m_type = UNSET;
}


IfcGeometricSetSelect::~IfcGeometricSetSelect() {
  deleteUnion();
}

bool IfcGeometricSetSelect::acceptVisitor(Step::BaseVisitor *v) {
  return static_cast< Visitor * > (v)->visitIfcGeometricSetSelect(this);
}

bool IfcGeometricSetSelect::init() {
  return false;
}

const char *IfcGeometricSetSelect::type() {
  return "IfcGeometricSetSelect";
}

Step::ClassType IfcGeometricSetSelect::getClassType() {
  return IfcGeometricSetSelect::s_type;
}

Step::ClassType IfcGeometricSetSelect::getType() const {
  return IfcGeometricSetSelect::s_type;
}

bool IfcGeometricSetSelect::isOfType(Step::ClassType t) {
  return IfcGeometricSetSelect::s_type == t ? true : Step::BaseObject::isOfType(t);
}

char *IfcGeometricSetSelect::currentTypeName() {
  switch(m_type) {
  case IFCPOINT:
    return "IfcPoint";
    break;
  case IFCCURVE:
    return "IfcCurve";
    break;
  case IFCSURFACE:
    return "IfcSurface";
    break;
  default:
    return "UNSET";
  }
}

IfcGeometricSetSelect::IfcGeometricSetSelect_select IfcGeometricSetSelect::currentType() {
  return m_type;
}

void IfcGeometricSetSelect::deleteUnion() {
  switch(m_type) {
  case IFCPOINT:
    m_IfcGeometricSetSelect_union.m_IfcPoint->unref();
    break;
  case IFCCURVE:
    m_IfcGeometricSetSelect_union.m_IfcCurve->unref();
    break;
  case IFCSURFACE:
    m_IfcGeometricSetSelect_union.m_IfcSurface->unref();
    break;
    }
  m_type = UNSET;
}

IfcPoint *IfcGeometricSetSelect::getIfcPoint() {
  return m_IfcGeometricSetSelect_union.m_IfcPoint;
}

void IfcGeometricSetSelect::setIfcPoint(IfcPoint *value) {
  deleteUnion();
  if (m_type != UNSET) {
    deleteUnion();
  }
  m_IfcGeometricSetSelect_union.m_IfcPoint = value;
  if (value) {
    value->ref();
    m_type = IFCPOINT;
  }
  else {
    m_type = UNSET;
  }
  m_type = IFCPOINT;
}

IfcCurve *IfcGeometricSetSelect::getIfcCurve() {
  return m_IfcGeometricSetSelect_union.m_IfcCurve;
}

void IfcGeometricSetSelect::setIfcCurve(IfcCurve *value) {
  deleteUnion();
  if (m_type != UNSET) {
    deleteUnion();
  }
  m_IfcGeometricSetSelect_union.m_IfcCurve = value;
  if (value) {
    value->ref();
    m_type = IFCCURVE;
  }
  else {
    m_type = UNSET;
  }
  m_type = IFCCURVE;
}

IfcSurface *IfcGeometricSetSelect::getIfcSurface() {
  return m_IfcGeometricSetSelect_union.m_IfcSurface;
}

void IfcGeometricSetSelect::setIfcSurface(IfcSurface *value) {
  deleteUnion();
  if (m_type != UNSET) {
    deleteUnion();
  }
  m_IfcGeometricSetSelect_union.m_IfcSurface = value;
  if (value) {
    value->ref();
    m_type = IFCSURFACE;
  }
  else {
    m_type = UNSET;
  }
  m_type = IFCSURFACE;
}

void IfcGeometricSetSelect::set(Step::BaseObject *v) {
  if (v->isOfType(IfcPoint::getClassType())) {
    setIfcPoint(static_cast< IfcPoint* > (v));
  }
  else if (v->isOfType(IfcCurve::getClassType())) {
    setIfcCurve(static_cast< IfcCurve* > (v));
  }
  else if (v->isOfType(IfcSurface::getClassType())) {
    setIfcSurface(static_cast< IfcSurface* > (v));
  }
}

IFC2X3_DLL_DEF Step::ClassType IfcGeometricSetSelect::s_type = new Step::ClassType_class("IfcGeometricSetSelect");