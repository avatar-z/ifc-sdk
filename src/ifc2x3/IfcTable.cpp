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
#include <ifc2x3/IfcTable.h>


#include <Step/BaseModel.h>
#include <Step/SPFFunctions.h>
#include <Step/logger.h>
#include <ifc2x3/IfcTableRow.h>
#include <ifc2x3/Visitor.h>
#include <ifc2x3/ifc2x3DLL.h>

using namespace ifc2x3;

IfcTable::IfcTable(Step::SPFData *args) : Step::BaseObject(args) {
  m_name = getUnset(m_name);
  m_rows.setUnset(true);
}


IfcTable::~IfcTable() {
}

bool IfcTable::acceptVisitor(Step::BaseVisitor *v) {
  return static_cast< Visitor * > (v)->visitIfcTable(this);
}

const char *IfcTable::type() {
  return "IfcTable";
}

Step::ClassType IfcTable::getClassType() {
  return IfcTable::s_type;
}

Step::ClassType IfcTable::getType() const {
  return IfcTable::s_type;
}

bool IfcTable::isOfType(Step::ClassType t) {
  return IfcTable::s_type == t ? true : Step::BaseObject::isOfType(t);
}

std::string IfcTable::getName() {
  if (Step::BaseObject::inited()) {
    return m_name;
  }
  else {
    return getUnset(m_name);
  }
}

void IfcTable::setName(const std::string &value) {
  m_name = value;
}

Step::StepList< Step::RefPtr< IfcTableRow > > &IfcTable::getRows() {
  if (Step::BaseObject::inited()) {
    return m_rows;
  }
  else {
    m_rows.setUnset(true);
    return m_rows;
  }
}

void IfcTable::setRows(const Step::StepList< Step::RefPtr< IfcTableRow > > &value) {
  m_rows = value;
}

void IfcTable::release() {
  m_rows.clear();
}

bool IfcTable::init() {
  std::string arg;
  arg = m_args->getNext();
  if (arg == "$" || arg == "*") {
    m_name = getUnset(m_name);
  }
  else {
    m_name = Step::spfToString(arg);
  }
  arg = m_args->getNext();
  if (arg == "$" || arg == "*") {
    m_rows.setUnset(true);
  }
  else {
    m_rows.setUnset(false);
    while (true) {
      std::string str1;
      Step::getSubParameter(arg, str1);
      if (str1 != "") {
        Step::RefPtr< IfcTableRow > attr2;
        attr2 = static_cast< IfcTableRow * > (m_model->getObjectById(atoi(str1.c_str() + 1)));
        m_rows.push_back(attr2);
      }
      else {
        break;
      }
    }
  }
  return true;
}

IFC2X3_DLL_DEF Step::ClassType IfcTable::s_type = new Step::ClassType_class("IfcTable");
IfcTable_Factory::IfcTable_Factory() {
}

IfcTable_Factory::~IfcTable_Factory() {
  clear(true);
}

void IfcTable_Factory::clear(bool b) {
}

std::map<Step::StepId,Step::BaseObject*>::iterator IfcTable_Factory::begin() {
  return m_idMap.begin();
}

std::map<Step::StepId,Step::BaseObject*>::iterator IfcTable_Factory::end() {
  return m_idMap.end();
}

IfcTable *IfcTable_Factory::get(Step::StepId id) {
  IfcTable *value;
  std::map<Step::StepId,Step::BaseObject*>::iterator it = m_idMap.find(id);
  if (it != m_idMap.end()) {
    value = static_cast< IfcTable * > (it->second);
  }
  else {
    LOG_ERROR("IfcTable_Factory::get() : Key not found.");
    return NULL;
  }
  if (value) {
    return value;
  }
  else {
    return static_cast< IfcTable * > (create(id));
  }
}

Step::BaseObject *IfcTable_Factory::create(Step::StepId id) {
  IfcTable *ret = new IfcTable(m_model->getArgs(id));
  ret->set_key(id);
  m_model->registerObject(id, ret);
  m_idMap[id] = ret;
  return ret;
}

Step::BaseObject *IfcTable_Factory::create(STEP_MAP<Step::StepId, Step::BaseObjectPtr >::iterator it) {
  IfcTable *ret = new IfcTable(it->second->getArgs());
  ret->set_key(it->first);
  m_model->registerObject(it->first, ret);
  m_idMap[it->first] = ret;
  return ret;
}

Step::BaseObject *IfcTable_Factory::create(std::map<Step::StepId, Step::BaseObject*>::iterator it) {
  IfcTable *ret = new IfcTable(m_model->getArgs(it->first));
  ret->set_key(it->first);
  m_model->registerObject(it->first, ret);
  it->second = ret;
  return ret;
}

IfcTable *IfcTable_Factory::generate() {
  return static_cast< IfcTable * > (create(m_model->getNewId()));
}

IfcTable *IfcTable_Factory::find(Step::StepId id) {
  std::map<Step::StepId,Step::BaseObject*>::iterator it = m_idMap.find(id);
  if (it != m_idMap.end()) {
    return static_cast< IfcTable * > (it->second);
  }
  else {
    return NULL;
  }
}
