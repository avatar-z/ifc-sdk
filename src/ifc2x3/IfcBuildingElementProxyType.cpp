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
#include <ifc2x3/IfcBuildingElementProxyType.h>


#include <Step/BaseModel.h>
#include <Step/logger.h>
#include <ifc2x3/Visitor.h>
#include <ifc2x3/ifc2x3DLL.h>

using namespace ifc2x3;

IfcBuildingElementProxyType::IfcBuildingElementProxyType(Step::SPFData *args) : IfcBuildingElementType(args) {
  m_predefinedType = IfcBuildingElementProxyTypeEnum_UNSET;
}


IfcBuildingElementProxyType::~IfcBuildingElementProxyType() {
}

bool IfcBuildingElementProxyType::acceptVisitor(Step::BaseVisitor *v) {
  return static_cast< Visitor * > (v)->visitIfcBuildingElementProxyType(this);
}

const char *IfcBuildingElementProxyType::type() {
  return "IfcBuildingElementProxyType";
}

Step::ClassType IfcBuildingElementProxyType::getClassType() {
  return IfcBuildingElementProxyType::s_type;
}

Step::ClassType IfcBuildingElementProxyType::getType() const {
  return IfcBuildingElementProxyType::s_type;
}

bool IfcBuildingElementProxyType::isOfType(Step::ClassType t) {
  return IfcBuildingElementProxyType::s_type == t ? true : IfcBuildingElementType::isOfType(t);
}

IfcBuildingElementProxyTypeEnum IfcBuildingElementProxyType::getPredefinedType() {
  if (Step::BaseObject::inited()) {
    return m_predefinedType;
  }
  else {
    return IfcBuildingElementProxyTypeEnum_UNSET;
  }
}

void IfcBuildingElementProxyType::setPredefinedType(IfcBuildingElementProxyTypeEnum value) {
  m_predefinedType = value;
}

void IfcBuildingElementProxyType::release() {
  IfcBuildingElementType::release();
}

bool IfcBuildingElementProxyType::init() {
  bool status = IfcBuildingElementType::init();
  std::string arg;
  if (!status) {
    return false;
  }
  arg = m_args->getNext();
  if (arg == "$" || arg == "*") {
    m_predefinedType = IfcBuildingElementProxyTypeEnum_UNSET;
  }
  else {
    if (arg == ".USERDEFINED.") {
      m_predefinedType = IfcBuildingElementProxyTypeEnum_USERDEFINED;
    }
    else if (arg == ".NOTDEFINED.") {
      m_predefinedType = IfcBuildingElementProxyTypeEnum_NOTDEFINED;
    }
  }
  return true;
}

IFC2X3_DLL_DEF Step::ClassType IfcBuildingElementProxyType::s_type = new Step::ClassType_class("IfcBuildingElementProxyType");
IfcBuildingElementProxyType_Factory::IfcBuildingElementProxyType_Factory() {
}

IfcBuildingElementProxyType_Factory::~IfcBuildingElementProxyType_Factory() {
  clear(true);
}

void IfcBuildingElementProxyType_Factory::clear(bool b) {
}

std::map<Step::StepId,Step::BaseObject*>::iterator IfcBuildingElementProxyType_Factory::begin() {
  return m_idMap.begin();
}

std::map<Step::StepId,Step::BaseObject*>::iterator IfcBuildingElementProxyType_Factory::end() {
  return m_idMap.end();
}

IfcBuildingElementProxyType *IfcBuildingElementProxyType_Factory::get(Step::StepId id) {
  IfcBuildingElementProxyType *value;
  std::map<Step::StepId,Step::BaseObject*>::iterator it = m_idMap.find(id);
  if (it != m_idMap.end()) {
    value = static_cast< IfcBuildingElementProxyType * > (it->second);
  }
  else {
    LOG_ERROR("IfcBuildingElementProxyType_Factory::get() : Key not found.");
    return NULL;
  }
  if (value) {
    return value;
  }
  else {
    return static_cast< IfcBuildingElementProxyType * > (create(id));
  }
}

Step::BaseObject *IfcBuildingElementProxyType_Factory::create(Step::StepId id) {
  IfcBuildingElementProxyType *ret = new IfcBuildingElementProxyType(m_model->getArgs(id));
  ret->set_key(id);
  m_model->registerObject(id, ret);
  m_idMap[id] = ret;
  return ret;
}

Step::BaseObject *IfcBuildingElementProxyType_Factory::create(STEP_MAP<Step::StepId, Step::BaseObjectPtr >::iterator it) {
  IfcBuildingElementProxyType *ret = new IfcBuildingElementProxyType(it->second->getArgs());
  ret->set_key(it->first);
  m_model->registerObject(it->first, ret);
  m_idMap[it->first] = ret;
  return ret;
}

Step::BaseObject *IfcBuildingElementProxyType_Factory::create(std::map<Step::StepId, Step::BaseObject*>::iterator it) {
  IfcBuildingElementProxyType *ret = new IfcBuildingElementProxyType(m_model->getArgs(it->first));
  ret->set_key(it->first);
  m_model->registerObject(it->first, ret);
  it->second = ret;
  return ret;
}

IfcBuildingElementProxyType *IfcBuildingElementProxyType_Factory::generate() {
  return static_cast< IfcBuildingElementProxyType * > (create(m_model->getNewId()));
}

IfcBuildingElementProxyType *IfcBuildingElementProxyType_Factory::find(Step::StepId id) {
  std::map<Step::StepId,Step::BaseObject*>::iterator it = m_idMap.find(id);
  if (it != m_idMap.end()) {
    return static_cast< IfcBuildingElementProxyType * > (it->second);
  }
  else {
    return NULL;
  }
}
