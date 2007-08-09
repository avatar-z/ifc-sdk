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

#ifndef IFC2X3_IFCPROPERTYCONSTRAINTRELATIONSHIP_H
#define IFC2X3_IFCPROPERTYCONSTRAINTRELATIONSHIP_H
#include <ifc2x3/DefinedTypes.h>
#include <ifc2x3/ifc2x3DLL.h>

#include <Step/BaseVisitor.h>
#include <Step/Referenced.h>
#include <Step/BaseObject.h>
#include <Step/InstantiatableEntity.h>
#include <string>
#include <Step/SPFData.h>
#include <Step/Aggregation.h>
#include <Step/ClassType.h>
#include <Step/BaseObject.h>
#include <Step/BaseFactory.h>

namespace ifc2x3 {

  class IfcConstraint;
  class IfcProperty;
  class IfcPropertyConstraintRelationship_Factory;

  /**
   */
  class IFC2X3_DLL_DEF IfcPropertyConstraintRelationship : public Step::InstantiatableEntity, public Step::BaseObject {
  public:
    /**
     * Accepts a read/write DatatypeVisitor.
     * 
     * @param v the read/write DatatypeVisitor to accept
     */
    virtual bool acceptVisitor(Step::BaseVisitor *v);
    /**
     */
    virtual const char *type();
    /**
     */
    static Step::ClassType getClassType();
    /**
     */
    virtual Step::ClassType getType() const;
    /**
     * @param t
     */
    virtual bool isOfType(Step::ClassType t);
    /**
     * (non-const) Returns the value of the explicit attribute 'RelatingConstraint'.
     * 
     * @return the value of the explicit attribute 'RelatingConstraint'
     */
    IfcConstraint *getRelatingConstraint();
    /**
     * Sets the value of the explicit attribute 'RelatingConstraint'.
     * 
     * @param value
     */
    void setRelatingConstraint(const Step::RefPtr< IfcConstraint > &value);
    /**
     * (non-const) Returns the value of the explicit attribute 'RelatedProperties'.
     * 
     * @return the value of the explicit attribute 'RelatedProperties'
     */
    Step::StepSet< Step::RefPtr< IfcProperty > > &getRelatedProperties();
    /**
     * Sets the value of the explicit attribute 'RelatedProperties'.
     * 
     * @param value
     */
    void setRelatedProperties(const Step::StepSet< Step::RefPtr< IfcProperty > > &value);
    /**
     * (non-const) Returns the value of the explicit attribute 'Name'.
     * 
     * @return the value of the explicit attribute 'Name'
     */
    IfcLabel getName();
    /**
     * Sets the value of the explicit attribute 'Name'.
     * 
     * @param value
     */
    void setName(const IfcLabel &value);
    /**
     * (non-const) Returns the value of the explicit attribute 'Description'.
     * 
     * @return the value of the explicit attribute 'Description'
     */
    IfcText getDescription();
    /**
     * Sets the value of the explicit attribute 'Description'.
     * 
     * @param value
     */
    void setDescription(const IfcText &value);
    /**
     */
    virtual void release();
    /**
     */
    virtual bool init();
    friend class IfcPropertyConstraintRelationship_Factory;

  protected:
    /**
     * @param args
     */
    IfcPropertyConstraintRelationship(Step::SPFData *args);
    virtual ~IfcPropertyConstraintRelationship();

  private:
    static Step::ClassType s_type;
    Step::RefPtr< IfcConstraint > m_relatingConstraint;
    Step::StepSet< Step::RefPtr< IfcProperty > > m_relatedProperties;
    std::string m_name;
    std::string m_description;
    /**
     * @param c
     */
    IfcPropertyConstraintRelationship(const IfcPropertyConstraintRelationship &c);

  };

  class IfcPropertyConstraintRelationship;

  /**
   */
  class IFC2X3_DLL_DEF IfcPropertyConstraintRelationship_Factory : public Step::BaseFactory {
  public:
    /**
     */
    explicit IfcPropertyConstraintRelationship_Factory();
    virtual ~IfcPropertyConstraintRelationship_Factory();
    /**
     * @param b
     */
    void clear(bool b);
    /**
     */
    std::map<Step::StepId,Step::BaseObject*>::iterator begin();
    /**
     */
    std::map<Step::StepId,Step::BaseObject*>::iterator end();
    /**
     * @param id
     */
    IfcPropertyConstraintRelationship *get(Step::StepId id);
    /**
     */
    IfcPropertyConstraintRelationship *generate();
    /**
     * @param id
     */
    IfcPropertyConstraintRelationship *find(Step::StepId id);

  protected:
    /**
     * @param id
     */
    virtual Step::BaseObject *create(Step::StepId id);
    /**
     * @param it
     */
    virtual Step::BaseObject *create(STEP_MAP<Step::StepId, Step::BaseObjectPtr >::iterator it);
    /**
     * @param it
     */
    virtual Step::BaseObject *create(std::map<Step::StepId, Step::BaseObject*>::iterator it);

  };

}

#endif // IFC2X3_IFCPROPERTYCONSTRAINTRELATIONSHIP_H