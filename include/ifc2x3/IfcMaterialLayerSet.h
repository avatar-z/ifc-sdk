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

#ifndef IFC2X3_IFCMATERIALLAYERSET_H
#define IFC2X3_IFCMATERIALLAYERSET_H
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

  class IfcMaterialLayer;
  class IfcMaterialLayerSet_Factory;

  /**
   */
  class IFC2X3_DLL_DEF IfcMaterialLayerSet : public Step::InstantiatableEntity, public Step::BaseObject {
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
     * (non-const) Returns the value of the explicit attribute 'MaterialLayers'.
     * 
     * @return the value of the explicit attribute 'MaterialLayers'
     */
    Step::StepList< Step::RefPtr< IfcMaterialLayer > > &getMaterialLayers();
    /**
     * Sets the value of the explicit attribute 'MaterialLayers'.
     * 
     * @param value
     */
    void setMaterialLayers(const Step::StepList< Step::RefPtr< IfcMaterialLayer > > &value);
    /**
     * (non-const) Returns the value of the explicit attribute 'LayerSetName'.
     * 
     * @return the value of the explicit attribute 'LayerSetName'
     */
    IfcLabel getLayerSetName();
    /**
     * Sets the value of the explicit attribute 'LayerSetName'.
     * 
     * @param value
     */
    void setLayerSetName(const IfcLabel &value);
    /**
     */
    virtual void release();
    /**
     */
    virtual bool init();
    friend class IfcMaterialLayerSet_Factory;

  protected:
    /**
     * @param args
     */
    IfcMaterialLayerSet(Step::SPFData *args);
    virtual ~IfcMaterialLayerSet();

  private:
    static Step::ClassType s_type;
    Step::StepList< Step::RefPtr< IfcMaterialLayer > > m_materialLayers;
    std::string m_layerSetName;
    /**
     * @param c
     */
    IfcMaterialLayerSet(const IfcMaterialLayerSet &c);

  };

  class IfcMaterialLayerSet;

  /**
   */
  class IFC2X3_DLL_DEF IfcMaterialLayerSet_Factory : public Step::BaseFactory {
  public:
    /**
     */
    explicit IfcMaterialLayerSet_Factory();
    virtual ~IfcMaterialLayerSet_Factory();
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
    IfcMaterialLayerSet *get(Step::StepId id);
    /**
     */
    IfcMaterialLayerSet *generate();
    /**
     * @param id
     */
    IfcMaterialLayerSet *find(Step::StepId id);

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

#endif // IFC2X3_IFCMATERIALLAYERSET_H