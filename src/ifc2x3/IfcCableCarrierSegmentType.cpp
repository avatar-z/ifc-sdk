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
#include <ifc2x3/IfcCableCarrierSegmentType.h>


#include <Step/BaseModel.h>
#include <Step/logger.h>
#include <ifc2x3/Visitor.h>
#include <ifc2x3/ifc2x3DLL.h>

using namespace ifc2x3;

IfcCableCarrierSegmentType::IfcCableCarrierSegmentType(Step::SPFData *args) : IfcFlowSegmentType(args) {
  m_predefinedType = IfcCableCarrierSegmentTypeEnum_UNSET;
}


IfcCableCarrierSegmentType::~IfcCableCarrierSegmentType() {
}

bool IfcCableCarrierSegmentType::acceptVisitor(Step::BaseVisitor *v) {
  return static_cast< Visitor * > (v)->visitIfcCableCarrierSegmentType(this);
}

const char *IfcCableCarrierSegmentType::type() {
  return "IfcCableCarrierSegmentType";
}

Step::ClassType IfcCableCarrierSegmentType::getClassType() {
  return IfcCableCarrierSegmentType::s_type;
}

Step::ClassType IfcCableCarrierSegmentType::getType() const {
  return IfcCableCarrierSegmentType::s_type;
}

bool IfcCableCarrierSegmentType::isOfType(Step::ClassType t) {
  return IfcCableCarrierSegmentType::s_type == t ? true : IfcFlowSegmentType::isOfType(t);
}

IfcCableCarrierSegmentTypeEnum IfcCableCarrierSegmentType::getPredefinedType() {
  if (Step::BaseObject::inited()) {
    return m_predefinedType;
  }
  else {
    return IfcCableCarrierSegmentTypeEnum_UNSET;
  }
}

void IfcCableCarrierSegmentType::setPredefinedType(IfcCableCarrierSegmentTypeEnum value) {
  m_predefinedType = value;
}

void IfcCableCarrierSegmentType::release() {
  IfcFlowSegmentType::release();
}

bool IfcCableCarrierSegmentType::init() {
  bool status = IfcFlowSegmentType::init();
  std::string arg;
  if (!status) {
    return false;
  }
  arg = m_args->getNext();
  if (arg == "$" || arg == "*") {
    m_predefinedType = IfcCableCarrierSegmentTypeEnum_UNSET;
  }
  else {
    if (arg == ".CABLELADDERSEGMENT.") {
      m_predefinedType = IfcCableCarrierSegmentTypeEnum_CABLELADDERSEGMENT;
    }
    else if (arg == ".CABLETRAYSEGMENT.") {
      m_predefinedType = IfcCableCarrierSegmentTypeEnum_CABLETRAYSEGMENT;
    }
    else if (arg == ".CABLETRUNKINGSEGMENT.") {
      m_predefinedType = IfcCableCarrierSegmentTypeEnum_CABLETRUNKINGSEGMENT;
    }
    else if (arg == ".CONDUITSEGMENT.") {
      m_predefinedType = IfcCableCarrierSegmentTypeEnum_CONDUITSEGMENT;
    }
    else if (arg == ".USERDEFINED.") {
      m_predefinedType = IfcCableCarrierSegmentTypeEnum_USERDEFINED;
    }
    else if (arg == ".NOTDEFINED.") {
      m_predefinedType = IfcCableCarrierSegmentTypeEnum_NOTDEFINED;
    }
  }
  return true;
}

IFC2X3_DLL_DEF Step::ClassType IfcCableCarrierSegmentType::s_type = new Step::ClassType_class("IfcCableCarrierSegmentType");
IfcCableCarrierSegmentType_Factory::IfcCableCarrierSegmentType_Factory() {
}

IfcCableCarrierSegmentType_Factory::~IfcCableCarrierSegmentType_Factory() {
  clear(true);
}

void IfcCableCarrierSegmentType_Factory::clear(bool b) {
}

std::map<Step::StepId,Step::BaseObject*>::iterator IfcCableCarrierSegmentType_Factory::begin() {
  return m_idMap.begin();
}

std::map<Step::StepId,Step::BaseObject*>::iterator IfcCableCarrierSegmentType_Factory::end() {
  return m_idMap.end();
}

IfcCableCarrierSegmentType *IfcCableCarrierSegmentType_Factory::get(Step::StepId id) {
  IfcCableCarrierSegmentType *value;
  std::map<Step::StepId,Step::BaseObject*>::iterator it = m_idMap.find(id);
  if (it != m_idMap.end()) {
    value = static_cast< IfcCableCarrierSegmentType * > (it->second);
  }
  else {
    LOG_ERROR("IfcCableCarrierSegmentType_Factory::get() : Key not found.");
    return NULL;
  }
  if (value) {
    return value;
  }
  else {
    return static_cast< IfcCableCarrierSegmentType * > (create(id));
  }
}

Step::BaseObject *IfcCableCarrierSegmentType_Factory::create(Step::StepId id) {
  IfcCableCarrierSegmentType *ret = new IfcCableCarrierSegmentType(m_model->getArgs(id));
  ret->set_key(id);
  m_model->registerObject(id, ret);
  m_idMap[id] = ret;
  return ret;
}

Step::BaseObject *IfcCableCarrierSegmentType_Factory::create(STEP_MAP<Step::StepId, Step::BaseObjectPtr >::iterator it) {
  IfcCableCarrierSegmentType *ret = new IfcCableCarrierSegmentType(it->second->getArgs());
  ret->set_key(it->first);
  m_model->registerObject(it->first, ret);
  m_idMap[it->first] = ret;
  return ret;
}

Step::BaseObject *IfcCableCarrierSegmentType_Factory::create(std::map<Step::StepId, Step::BaseObject*>::iterator it) {
  IfcCableCarrierSegmentType *ret = new IfcCableCarrierSegmentType(m_model->getArgs(it->first));
  ret->set_key(it->first);
  m_model->registerObject(it->first, ret);
  it->second = ret;
  return ret;
}

IfcCableCarrierSegmentType *IfcCableCarrierSegmentType_Factory::generate() {
  return static_cast< IfcCableCarrierSegmentType * > (create(m_model->getNewId()));
}

IfcCableCarrierSegmentType *IfcCableCarrierSegmentType_Factory::find(Step::StepId id) {
  std::map<Step::StepId,Step::BaseObject*>::iterator it = m_idMap.find(id);
  if (it != m_idMap.end()) {
    return static_cast< IfcCableCarrierSegmentType * > (it->second);
  }
  else {
    return NULL;
  }
}
