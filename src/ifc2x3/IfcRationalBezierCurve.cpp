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
#include <ifc2x3/IfcRationalBezierCurve.h>


#include <Step/BaseModel.h>
#include <Step/SPFFunctions.h>
#include <Step/logger.h>
#include <ifc2x3/Visitor.h>
#include <ifc2x3/ifc2x3DLL.h>

using namespace ifc2x3;

IfcRationalBezierCurve::IfcRationalBezierCurve(Step::SPFData *args) : IfcBezierCurve(args) {
  m_weightsData.setUnset(true);
}


IfcRationalBezierCurve::~IfcRationalBezierCurve() {
}

bool IfcRationalBezierCurve::acceptVisitor(Step::BaseVisitor *v) {
  return static_cast< Visitor * > (v)->visitIfcRationalBezierCurve(this);
}

const char *IfcRationalBezierCurve::type() {
  return "IfcRationalBezierCurve";
}

Step::ClassType IfcRationalBezierCurve::getClassType() {
  return IfcRationalBezierCurve::s_type;
}

Step::ClassType IfcRationalBezierCurve::getType() const {
  return IfcRationalBezierCurve::s_type;
}

bool IfcRationalBezierCurve::isOfType(Step::ClassType t) {
  return IfcRationalBezierCurve::s_type == t ? true : IfcBezierCurve::isOfType(t);
}

Step::StepList< Real > &IfcRationalBezierCurve::getWeightsData() {
  if (Step::BaseObject::inited()) {
    return m_weightsData;
  }
  else {
    m_weightsData.setUnset(true);
    return m_weightsData;
  }
}

void IfcRationalBezierCurve::setWeightsData(const Step::StepList< Real > &value) {
  m_weightsData = value;
}

void IfcRationalBezierCurve::release() {
  IfcBezierCurve::release();
  m_weightsData.clear();
}

bool IfcRationalBezierCurve::init() {
  bool status = IfcBezierCurve::init();
  std::string arg;
  if (!status) {
    return false;
  }
  arg = m_args->getNext();
  if (arg == "$" || arg == "*") {
    m_weightsData.setUnset(true);
  }
  else {
    m_weightsData.setUnset(false);
    while (true) {
      std::string str1;
      Step::getSubParameter(arg, str1);
      if (str1 != "") {
        Real attr2;
        attr2 = Step::spfToReal(str1);
        m_weightsData.push_back(attr2);
      }
      else {
        break;
      }
    }
  }
  return true;
}

IFC2X3_DLL_DEF Step::ClassType IfcRationalBezierCurve::s_type = new Step::ClassType_class("IfcRationalBezierCurve");
IfcRationalBezierCurve_Factory::IfcRationalBezierCurve_Factory() {
}

IfcRationalBezierCurve_Factory::~IfcRationalBezierCurve_Factory() {
  clear(true);
}

void IfcRationalBezierCurve_Factory::clear(bool b) {
}

std::map<Step::StepId,Step::BaseObject*>::iterator IfcRationalBezierCurve_Factory::begin() {
  return m_idMap.begin();
}

std::map<Step::StepId,Step::BaseObject*>::iterator IfcRationalBezierCurve_Factory::end() {
  return m_idMap.end();
}

IfcRationalBezierCurve *IfcRationalBezierCurve_Factory::get(Step::StepId id) {
  IfcRationalBezierCurve *value;
  std::map<Step::StepId,Step::BaseObject*>::iterator it = m_idMap.find(id);
  if (it != m_idMap.end()) {
    value = static_cast< IfcRationalBezierCurve * > (it->second);
  }
  else {
    LOG_ERROR("IfcRationalBezierCurve_Factory::get() : Key not found.");
    return NULL;
  }
  if (value) {
    return value;
  }
  else {
    return static_cast< IfcRationalBezierCurve * > (create(id));
  }
}

Step::BaseObject *IfcRationalBezierCurve_Factory::create(Step::StepId id) {
  IfcRationalBezierCurve *ret = new IfcRationalBezierCurve(m_model->getArgs(id));
  ret->set_key(id);
  m_model->registerObject(id, ret);
  m_idMap[id] = ret;
  return ret;
}

Step::BaseObject *IfcRationalBezierCurve_Factory::create(STEP_MAP<Step::StepId, Step::BaseObjectPtr >::iterator it) {
  IfcRationalBezierCurve *ret = new IfcRationalBezierCurve(it->second->getArgs());
  ret->set_key(it->first);
  m_model->registerObject(it->first, ret);
  m_idMap[it->first] = ret;
  return ret;
}

Step::BaseObject *IfcRationalBezierCurve_Factory::create(std::map<Step::StepId, Step::BaseObject*>::iterator it) {
  IfcRationalBezierCurve *ret = new IfcRationalBezierCurve(m_model->getArgs(it->first));
  ret->set_key(it->first);
  m_model->registerObject(it->first, ret);
  it->second = ret;
  return ret;
}

IfcRationalBezierCurve *IfcRationalBezierCurve_Factory::generate() {
  return static_cast< IfcRationalBezierCurve * > (create(m_model->getNewId()));
}

IfcRationalBezierCurve *IfcRationalBezierCurve_Factory::find(Step::StepId id) {
  std::map<Step::StepId,Step::BaseObject*>::iterator it = m_idMap.find(id);
  if (it != m_idMap.end()) {
    return static_cast< IfcRationalBezierCurve * > (it->second);
  }
  else {
    return NULL;
  }
}
