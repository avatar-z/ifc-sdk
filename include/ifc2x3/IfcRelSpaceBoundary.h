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

#ifndef IFC2X3_IFCRELSPACEBOUNDARY_H
#define IFC2X3_IFCRELSPACEBOUNDARY_H
#include <ifc2x3/DefinedTypes.h>
#include <ifc2x3/ifc2x3DLL.h>

#include <Step/BaseVisitor.h>
#include <Step/Referenced.h>
#include <Step/InstantiatableEntity.h>
#include <Step/SPFData.h>
#include <ifc2x3/IfcRelConnects.h>
#include <Step/ClassType.h>
#include <Step/BaseObject.h>
#include <Step/BaseFactory.h>

namespace ifc2x3 {

  class IfcConnectionGeometry;
  class IfcElement;
  class IfcRelSpaceBoundary_Factory;
  class IfcSpace;

  /**
   */
  class IFC2X3_DLL_DEF IfcRelSpaceBoundary : public Step::InstantiatableEntity, public IfcRelConnects {
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
     * (non-const) Returns the value of the explicit attribute 'RelatingSpace'.
     * 
     * @return the value of the explicit attribute 'RelatingSpace'
     */
    IfcSpace *getRelatingSpace();
    /**
     * Sets the value of the explicit attribute 'RelatingSpace'.
     * 
     * @param value
     */
    void setRelatingSpace(const Step::RefPtr< IfcSpace > &value);
    /**
     * (non-const) Returns the value of the explicit attribute 'RelatedBuildingElement'.
     * 
     * @return the value of the explicit attribute 'RelatedBuildingElement'
     */
    IfcElement *getRelatedBuildingElement();
    /**
     * Sets the value of the explicit attribute 'RelatedBuildingElement'.
     * 
     * @param value
     */
    void setRelatedBuildingElement(const Step::RefPtr< IfcElement > &value);
    /**
     * (non-const) Returns the value of the explicit attribute 'ConnectionGeometry'.
     * 
     * @return the value of the explicit attribute 'ConnectionGeometry'
     */
    IfcConnectionGeometry *getConnectionGeometry();
    /**
     * Sets the value of the explicit attribute 'ConnectionGeometry'.
     * 
     * @param value
     */
    void setConnectionGeometry(const Step::RefPtr< IfcConnectionGeometry > &value);
    /**
     * (non-const) Returns the value of the explicit attribute 'PhysicalOrVirtualBoundary'.
     * 
     * @return the value of the explicit attribute 'PhysicalOrVirtualBoundary'
     */
    IfcPhysicalOrVirtualEnum getPhysicalOrVirtualBoundary();
    /**
     * Sets the value of the explicit attribute 'PhysicalOrVirtualBoundary'.
     * 
     * @param value
     */
    void setPhysicalOrVirtualBoundary(IfcPhysicalOrVirtualEnum value);
    /**
     * (non-const) Returns the value of the explicit attribute 'InternalOrExternalBoundary'.
     * 
     * @return the value of the explicit attribute 'InternalOrExternalBoundary'
     */
    IfcInternalOrExternalEnum getInternalOrExternalBoundary();
    /**
     * Sets the value of the explicit attribute 'InternalOrExternalBoundary'.
     * 
     * @param value
     */
    void setInternalOrExternalBoundary(IfcInternalOrExternalEnum value);
    /**
     */
    virtual void release();
    /**
     */
    virtual bool init();
    friend class IfcRelSpaceBoundary_Factory;

  protected:
    /**
     * @param args
     */
    IfcRelSpaceBoundary(Step::SPFData *args);
    virtual ~IfcRelSpaceBoundary();

  private:
    static Step::ClassType s_type;
    Step::RefPtr< IfcSpace > m_relatingSpace;
    Step::RefPtr< IfcElement > m_relatedBuildingElement;
    Step::RefPtr< IfcConnectionGeometry > m_connectionGeometry;
    IfcPhysicalOrVirtualEnum m_physicalOrVirtualBoundary;
    IfcInternalOrExternalEnum m_internalOrExternalBoundary;
    /**
     * @param c
     */
    IfcRelSpaceBoundary(const IfcRelSpaceBoundary &c);

  };

  class IfcRelSpaceBoundary;

  /**
   */
  class IFC2X3_DLL_DEF IfcRelSpaceBoundary_Factory : public Step::BaseFactory {
  public:
    /**
     */
    explicit IfcRelSpaceBoundary_Factory();
    virtual ~IfcRelSpaceBoundary_Factory();
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
    IfcRelSpaceBoundary *get(Step::StepId id);
    /**
     */
    IfcRelSpaceBoundary *generate();
    /**
     * @param id
     */
    IfcRelSpaceBoundary *find(Step::StepId id);

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

#endif // IFC2X3_IFCRELSPACEBOUNDARY_H