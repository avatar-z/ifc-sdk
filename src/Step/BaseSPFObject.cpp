// IFC SDK : IFC2X3 C++ Early Classes  
// Copyright (C) 2009 CSTB
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full license is in Licence.txt file included with this 
// distribution or is available at :
//     http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

#include "Step/BaseSPFObject.h"
#include "Step/SPFData.h"
#include "Step/BaseVisitor.h"

#include "Step/logger.h"

using namespace Step;

typedef std::map<Step::AllocateFuncType, std::string> AllocateFunc2ClassName;
static AllocateFunc2ClassName s_AllocateFunc2ClassName;


ClassType_child_implementations(STEP_EXPORT,BaseSPFObject,BaseEntity);

BaseSPFObject::BaseSPFObject(Id id, SPFData* data) :
    BaseEntity(id, data), m_allocFuncType(0)
{
}

bool BaseSPFObject::init()
{
    LOG_WARNING("Tried to init a BaseSPFObject instance");
    return false;
}

BaseSPFObject::~BaseSPFObject()
{
}

AllocateFuncType BaseSPFObject::getAllocateFunction()
{
    return m_allocFuncType;
}

void BaseSPFObject::setAllocateFunction(AllocateFuncType type, const std::string &entityClassName)
{
    m_allocFuncType = type;
    s_AllocateFunc2ClassName[m_allocFuncType] = entityClassName;
}

const char *entityNames[] =
       {
        "IFCRELASSIGNSTOCONTROL",
        "IFCPARAMETERIZEDPROFILEDEF",
        "IFCTUBEBUNDLETYPE",
        "IFCCOMPLEXPROPERTY",
        "IFCLOCALPLACEMENT",
        "IFCSURFACESTYLERENDERING",
        "IFCRELNESTS",
        "IFCSHAPEREPRESENTATION",
        "IFCDISCRETEACCESSORYTYPE",
        "IFCPROPERTYBOUNDEDVALUE",
        "IFCMATERIAL",
        "IFCBEAMTYPE",
        "IFCBUILDINGELEMENTTYPE",
        "IFCREINFORCEMENTDEFINITIONPROPERTIES",
        "IFCCONNECTEDFACESET",
        "IFCFACE",
        "IFCSPACEHEATERTYPE",
        "IFCCONNECTIONPOINTGEOMETRY",
        "IFCBOOLEANRESULT",
        "IFCSWEPTDISKSOLID",
        "IFCSUBEDGE",
        "IFCPREDEFINEDPOINTMARKERSYMBOL",
        "IFCSURFACESTYLE",
        "IFCSTRUCTUREDDIMENSIONCALLOUT",
        "IFCSPACETYPE",
        "IFCPROJECTORDER",
        "IFCCONDENSERTYPE",
        "IFCHEATEXCHANGERTYPE",
        "IFCSTRUCTURALLOADSINGLEFORCEWARPING",
        "IFCFASTENER",
        "IFCOPENSHELL",
        "IFCOFFSETCURVE2D",
        "IFCCONDITION",
        "IFCBEAM",
        "IFCPROXY",
        "IFCPERSON",
        "IFCSTRUCTURALCURVEMEMBER",
        "IFCBOXEDHALFSPACE",
        "IFCQUANTITYAREA",
        "IFCEXTENDEDMATERIALPROPERTIES",
        "IFCOPTICALMATERIALPROPERTIES",
        "IFCCONSTRAINT",
        "IFCSLIPPAGECONNECTIONCONDITION",
        "IFCPROPERTYENUMERATEDVALUE",
        "IFCRELCONNECTSELEMENTS",
        "IFCOUTLETTYPE",
        "IFCTIMESERIES",
        "IFCIRREGULARTIMESERIES",
        "IFCSTRUCTURALPOINTREACTION",
        "IFCONEDIRECTIONREPEATFACTOR",
        "IFCPRODUCT",
        "IFCADDRESS",
        "IFCPRESENTATIONLAYERASSIGNMENT",
        "IFCSIUNIT",
        "IFCFEATUREELEMENTADDITION",
        "IFCCRANERAILASHAPEPROFILEDEF",
        "IFCFILTERTYPE",
        "IFCLINEARDIMENSION",
        "IFCWATERPROPERTIES",
        "IFCTYPEPRODUCT",
        "IFCEQUIPMENTELEMENT",
        "IFCIRREGULARTIMESERIESVALUE",
        "IFCVALVETYPE",
        "IFCROOF",
        "IFCREINFORCINGBAR",
        "IFCPRESENTATIONSTYLEASSIGNMENT",
        "IFCRELCOVERSBLDGELEMENTS",
        "IFCREINFORCINGELEMENT",
        "IFCACTUATORTYPE",
        "IFCSERVICELIFE",
        "IFCVECTOR",
        "IFCALARMTYPE",
        "IFCARBITRARYPROFILEDEFWITHVOIDS",
        "IFCDOCUMENTINFORMATION",
        "IFCSYMBOLSTYLE",
        "IFCRIBPLATEPROFILEPROPERTIES",
        "IFCWINDOW",
        "IFCROUNDEDEDGEFEATURE",
        "IFCSTRUCTURALCURVECONNECTION",
        "IFCLINE",
        "IFCSPACETHERMALLOADPROPERTIES",
        "IFCAXIS2PLACEMENT2D",
        "IFCPROPERTYCONSTRAINTRELATIONSHIP",
        "IFCTIMESERIESREFERENCERELATIONSHIP",
        "IFCPOLYGONALBOUNDEDHALFSPACE",
        "IFCSTYLEDITEM",
        "IFCDRAUGHTINGCALLOUT",
        "IFCOFFSETCURVE3D",
        "IFCTEXTUREVERTEX",
        "IFCRELSPACEBOUNDARY",
        "IFCLIGHTSOURCEPOSITIONAL",
        "IFCRELATIONSHIP",
        "IFCDATEANDTIME",
        "IFCTASK",
        "IFCFAILURECONNECTIONCONDITION",
        "IFCPREDEFINEDTERMINATORSYMBOL",
        "IFCCOSTITEM",
        "IFCCOLUMN",
        "IFCWORKPLAN",
        "IFCFURNITURETYPE",
        "IFCPROPERTYDEPENDENCYRELATIONSHIP",
        "IFCDOORLININGPROPERTIES",
        "IFCRELASSIGNSTASKS",
        "IFCRELAGGREGATES",
        "IFCELEMENTASSEMBLY",
        "IFCPIXELTEXTURE",
        "IFCTEXTUREMAP",
        "IFCSURFACEOFREVOLUTION",
        "IFCSPATIALSTRUCTUREELEMENTTYPE",
        "IFCQUANTITYWEIGHT",
        "IFCSTRUCTURALLOADLINEARFORCE",
        "IFCLIGHTSOURCEGONIOMETRIC",
        "IFCZONE",
        "IFCASYMMETRICISHAPEPROFILEDEF",
        "IFCLIGHTSOURCE",
        "IFCSPACE",
        "IFCRADIUSDIMENSION",
        "IFCCENTERLINEPROFILEDEF",
        "IFCDRAUGHTINGCALLOUTRELATIONSHIP",
        "IFCMECHANICALMATERIALPROPERTIES",
        "IFCCHAMFEREDGEFEATURE",
        "IFCUNITARYEQUIPMENTTYPE",
        "IFCDAMPERTYPE",
        "IFCRELOCCUPIESSPACES",
        "IFCNAMEDUNIT",
        "IFCCLASSIFICATIONITEM",
        "IFCINVENTORY",
        "IFCRELASSIGNSTORESOURCE",
        "IFCPATH",
        "IFCTENDONANCHOR",
        "IFCPREDEFINEDSYMBOL",
        "IFCGRIDPLACEMENT",
        "IFCCURVESTYLE",
        "IFCPRESENTATIONSTYLE",
        "IFCDOCUMENTINFORMATIONRELATIONSHIP",
        "IFCGEOMETRICCURVESET",
        "IFCRELCONNECTSWITHECCENTRICITY",
        "IFCEXTERNALLYDEFINEDTEXTFONT",
        "IFCVERTEXBASEDTEXTUREMAP",
        "IFCCIRCLEHOLLOWPROFILEDEF",
        "IFCSTRUCTURALLINEARACTIONVARYING",
        "IFCBUILDINGELEMENTPROXY",
        "IFCELECTRICTIMECONTROLTYPE",
        "IFCEXTERNALLYDEFINEDSURFACESTYLE",
        "IFCACTOR",
        "IFCEDGECURVE",
        "IFCELECTRICFLOWSTORAGEDEVICETYPE",
        "IFCTRANSPORTELEMENTTYPE",
        "IFCMANIFOLDSOLIDBREP",
        "IFCRELASSOCIATESCONSTRAINT",
        "IFCQUANTITYCOUNT",
        "IFCOBJECTPLACEMENT",
        "IFCEXTERNALREFERENCE",
        "IFCTEXTSTYLETEXTMODEL",
        "IFCVIBRATIONISOLATORTYPE",
        "IFCCONVERSIONBASEDUNIT",
        "IFCREGULARTIMESERIES",
        "IFCDIMENSIONALEXPONENTS",
        "IFCRELASSOCIATESLIBRARY",
        "IFCTYPEOBJECT",
        "IFCCOSTSCHEDULE",
        "IFCSUBCONTRACTRESOURCE",
        "IFCRELSEQUENCE",
        "IFCSYSTEMFURNITUREELEMENTTYPE",
        "IFCCALENDARDATE",
        "IFCSTRUCTURALLOAD",
        "IFCHYGROSCOPICMATERIALPROPERTIES",
        "IFCTSHAPEPROFILEDEF",
        "IFCFLOWTERMINALTYPE",
        "IFCHALFSPACESOLID",
        "IFCMATERIALLIST",
        "IFCRELASSOCIATESMATERIAL",
        "IFCFEATUREELEMENT",
        "IFCDISTRIBUTIONELEMENTTYPE",
        "IFCWINDOWPANELPROPERTIES",
        "IFCMAPPEDITEM",
        "IFCTEXTLITERAL",
        "IFCLIGHTDISTRIBUTIONDATA",
        "IFCTWODIRECTIONREPEATFACTOR",
        "IFCRELASSOCIATESAPPROVAL",
        "IFCRAILINGTYPE",
        "IFCPOINTONSURFACE",
        "IFCTENDON",
        "IFCSTRUCTURALACTION",
        "IFCRELDECOMPOSES",
        "IFCENERGYPROPERTIES",
        "IFCIMAGETEXTURE",
        "IFCFILLAREASTYLEHATCHING",
        "IFCDRAUGHTINGPREDEFINEDCOLOUR",
        "IFCOBJECTDEFINITION",
        "IFCPROJECTIONELEMENT",
        "IFCPROJECTORDERRECORD",
        "IFCDIMENSIONCURVEDIRECTEDCALLOUT",
        "IFCDOORPANELPROPERTIES",
        "IFCVERTEX",
        "IFCTRANSPORTELEMENT",
        "IFCCURVESTYLEFONTPATTERN",
        "IFCSTRUCTURALLOADSINGLEDISPLACEMENTDISTORTION",
        "IFCSPHERE",
        "IFCELEMENT",
        "IFCSURFACETEXTURE",
        "IFCSTRUCTURALPOINTACTION",
        "IFCRECTANGLEHOLLOWPROFILEDEF",
        "IFCTELECOMADDRESS",
        "IFCBEZIERCURVE",
        "IFCFACESURFACE",
        "IFCSCHEDULETIMECONTROL",
        "IFCLIGHTSOURCEAMBIENT",
        "IFCPROJECT",
        "IFCFLOWSTORAGEDEVICETYPE",
        "IFCDUCTSILENCERTYPE",
        "IFCCIRCLE",
        "IFCTEXTURECOORDINATEGENERATOR",
        "IFCCONTEXTDEPENDENTUNIT",
        "IFCRECTANGULARPYRAMID",
        "IFCGEOMETRICREPRESENTATIONSUBCONTEXT",
        "IFCMECHANICALSTEELMATERIALPROPERTIES",
        "IFCLIBRARYREFERENCE",
        "IFCELECTRICHEATERTYPE",
        "IFCWASTETERMINALTYPE",
        "IFCOCCUPANT",
        "IFCANNOTATIONFILLAREA",
        "IFCFLOWCONTROLLER",
        "IFCPERMIT",
        "IFCCONSTRUCTIONMATERIALRESOURCE",
        "IFCCARTESIANTRANSFORMATIONOPERATOR3D",
        "IFCELEMENTCOMPONENTTYPE",
        "IFCPROPERTYSET",
        "IFCDOOR",
        "IFCVERTEXLOOP",
        "IFCCARTESIANTRANSFORMATIONOPERATOR",
        "IFCBOUNDARYNODECONDITION",
        "IFCRAILING",
        "IFCPHYSICALSIMPLEQUANTITY",
        "IFCBUILDING",
        "IFCDERIVEDUNIT",
        "IFCPROFILEPROPERTIES",
        "IFCCHILLERTYPE",
        "IFCBUILDINGSTOREY",
        "IFCTERMINATORSYMBOL",
        "IFCFLOWTREATMENTDEVICE",
        "IFCWORKCONTROL",
        "IFCBOUNDARYEDGECONDITION",
        "IFCDISTRIBUTIONCONTROLELEMENT",
        "IFCFANTYPE",
        "IFCORIENTEDEDGE",
        "IFCEXTERNALLYDEFINEDHATCHSTYLE",
        "IFCPREDEFINEDTEXTFONT",
        "IFCCURVE",
        "IFCRELREFERENCEDINSPATIALSTRUCTURE",
        "IFCRELSCHEDULESCOSTITEMS",
        "IFCWALL",
        "IFCCOMPOSITEPROFILEDEF",
        "IFCMECHANICALFASTENERTYPE",
        "IFCTANKTYPE",
        "IFCOPENINGELEMENT",
        "IFCSTRUCTURALSTEELPROFILEPROPERTIES",
        "IFCRAMPFLIGHT",
        "IFCCOSTVALUE",
        "IFCSTRUCTURALSURFACECONNECTION",
        "IFCSTRUCTURALLOADSINGLEDISPLACEMENT",
        "IFCFILLAREASTYLETILESYMBOLWITHSTYLE",
        "IFCTOPOLOGYREPRESENTATION",
        "IFCARBITRARYOPENPROFILEDEF",
        "IFCANNOTATIONOCCURRENCE",
        "IFCACTORROLE",
        "IFCWALLTYPE",
        "IFCSTRUCTURALLINEARACTION",
        "IFCSHELLBASEDSURFACEMODEL",
        "IFCLSHAPEPROFILEDEF",
        "IFCLIGHTFIXTURETYPE",
        "IFCMECHANICALFASTENER",
        "IFCCOVERING",
        "IFCSWEPTSURFACE",
        "IFCCURTAINWALLTYPE",
        "IFCSERVICELIFEFACTOR",
        "IFCLAMPTYPE",
        "IFCCIRCLEPROFILEDEF",
        "IFCBSPLINECURVE",
        "IFCSECTIONPROPERTIES",
        "IFCPLACEMENT",
        "IFCREINFORCEMENTBARPROPERTIES",
        "IFCREPRESENTATIONITEM",
        "IFCPREDEFINEDDIMENSIONSYMBOL",
        "IFCMOTORCONNECTIONTYPE",
        "IFCCONDITIONCRITERION",
        "IFCPRESENTATIONLAYERWITHSTYLE",
        "IFCFLOWSTORAGEDEVICE",
        "IFCPROPERTYREFERENCEVALUE",
        "IFCGRIDAXIS",
        "IFCMEMBER",
        "IFCPROTECTIVEDEVICETYPE",
        "IFCMATERIALLAYERSETUSAGE",
        "IFCANNOTATIONFILLAREAOCCURRENCE",
        "IFCBUILDINGELEMENTPROXYTYPE",
        "IFCDISTRIBUTIONFLOWELEMENTTYPE",
        "IFCCURVESTYLEFONTANDSCALING",
        "IFCCARTESIANTRANSFORMATIONOPERATOR3DNONUNIFORM",
        "IFCRELFLOWCONTROLELEMENTS",
        "IFCTIMESERIESSCHEDULE",
        "IFCPROPERTYENUMERATION",
        "IFCMATERIALLAYERSET",
        "IFCORGANIZATIONRELATIONSHIP",
        "IFCAIRTERMINALTYPE",
        "IFCAPPLIEDVALUERELATIONSHIP",
        "IFCCONIC",
        "IFCMETRIC",
        "IFCELLIPSE",
        "IFCTHERMALMATERIALPROPERTIES",
        "IFCFLOWMOVINGDEVICE",
        "IFCCOVERINGTYPE",
        "IFCELLIPSEPROFILEDEF",
        "IFCSTRUCTURALANALYSISMODEL",
        "IFCENERGYCONVERSIONDEVICETYPE",
        "IFCSTRUCTURALLOADGROUP",
        "IFCREPRESENTATIONMAP",
        "IFCSURFACEOFLINEAREXTRUSION",
        "IFCCABLECARRIERSEGMENTTYPE",
        "IFCCONTROLLERTYPE",
        "IFCCOMPOSITECURVE",
        "IFCWINDOWLININGPROPERTIES",
        "IFCCURVEBOUNDEDPLANE",
        "IFCAPPROVALRELATIONSHIP",
        "IFCFUELPROPERTIES",
        "IFCPERFORMANCEHISTORY",
        "IFCDISTRIBUTIONCHAMBERELEMENTTYPE",
        "IFCDRAUGHTINGPREDEFINEDCURVEFONT",
        "IFCREPRESENTATIONCONTEXT",
        "IFCCURTAINWALL",
        "IFCCOORDINATEDUNIVERSALTIMEOFFSET",
        "IFCRELASSIGNSTOGROUP",
        "IFCVERTEXPOINT",
        "IFCRELAXATION",
        "IFCGRID",
        "IFCCLOSEDSHELL",
        "IFCRELCONNECTSWITHREALIZINGELEMENTS",
        "IFCLABORRESOURCE",
        "IFCFURNISHINGELEMENT",
        "IFCANGULARDIMENSION",
        "IFCGENERALMATERIALPROPERTIES",
        "IFCPOINTONCURVE",
        "IFCPERMEABLECOVERINGPROPERTIES",
        "IFCFACETEDBREP",
        "IFCQUANTITYLENGTH",
        "IFCCABLECARRIERFITTINGTYPE",
        "IFCISHAPEPROFILEDEF",
        "IFCEVAPORATORTYPE",
        "IFCSTRUCTURALACTIVITY",
        "IFCSTRUCTURALLOADTEMPERATURE",
        "IFCFEATUREELEMENTSUBTRACTION",
        "IFCANNOTATIONCURVEOCCURRENCE",
        "IFCFURNISHINGELEMENTTYPE",
        "IFCGEOMETRICREPRESENTATIONITEM",
        "IFCGROUP",
        "IFCLIGHTSOURCEDIRECTIONAL",
        "IFCMEMBERTYPE",
        "IFCTEXTSTYLE",
        "IFCCLASSIFICATIONNOTATIONFACET",
        "IFCREINFORCINGMESH",
        "IFCPHYSICALCOMPLEXQUANTITY",
        "IFCFLOWSEGMENT",
        "IFCBLOCK",
        "IFCDIMENSIONCURVE",
        "IFCSTAIR",
        "IFCRELASSOCIATESPROFILEPROPERTIES",
        "IFCRELCONNECTS",
        "IFCTEXTSTYLEWITHBOXCHARACTERISTICS",
        "IFCCSHAPEPROFILEDEF",
        "IFCFLOWCONTROLLERTYPE",
        "IFCRELCOVERSSPACES",
        "IFCPRODUCTDEFINITIONSHAPE",
        "IFCCONSTRAINTRELATIONSHIP",
        "IFCSTRUCTURALPROFILEPROPERTIES",
        "IFCCONSTRUCTIONPRODUCTRESOURCE",
        "IFCRELDEFINESBYTYPE",
        "IFCRELDEFINESBYPROPERTIES",
        "IFCSOUNDVALUE",
        "IFCRIGHTCIRCULARCYLINDER",
        "IFCPROCEDURE",
        "IFCAPPLICATION",
        "IFCSLAB",
        "IFCARBITRARYCLOSEDPROFILEDEF",
        "IFCMATERIALDEFINITIONREPRESENTATION",
        "IFCENERGYCONVERSIONDEVICE",
        "IFCWORKSCHEDULE",
        "IFCPROPERTYDEFINITION",
        "IFCSTRUCTURALITEM",
        "IFCPRODUCTSOFCOMBUSTIONPROPERTIES",
        "IFCSWITCHINGDEVICETYPE",
        "IFCCLASSIFICATIONREFERENCE",
        "IFCELECTRICAPPLIANCETYPE",
        "IFCSWEPTAREASOLID",
        "IFCRECTANGULARTRIMMEDSURFACE",
        "IFCQUANTITYVOLUME",
        "IFCRESOURCE",
        "IFCELECTRICGENERATORTYPE",
        "IFCSYSTEM",
        "IFCPERSONANDORGANIZATION",
        "IFCSTRUCTURALMEMBER",
        "IFCCONNECTIONSURFACEGEOMETRY",
        "IFCSTYLEMODEL",
        "IFCFLOWMOVINGDEVICETYPE",
        "IFCCONSTRUCTIONEQUIPMENTRESOURCE",
        "IFCCARTESIANTRANSFORMATIONOPERATOR2DNONUNIFORM",
        "IFCBOUNDARYNODECONDITIONWARPING",
        "IFCSTRUCTURALCONNECTIONCONDITION",
        "IFCVIRTUALGRIDINTERSECTION",
        "IFCSTYLEDREPRESENTATION",
        "IFCCONTROL",
        "IFCPREDEFINEDITEM",
        "IFCACTIONREQUEST",
        "IFCSURFACESTYLEWITHTEXTURES",
        "IFCPLANARBOX",
        "IFCMOVE",
        "IFCAPPROVALPROPERTYRELATIONSHIP",
        "IFCTABLE",
        "IFCRELASSIGNSTOACTOR",
        "IFCREFERENCESVALUEDOCUMENT",
        "IFCDOORSTYLE",
        "IFCSTRUCTURALLOADSINGLEFORCE",
        "IFCQUANTITYTIME",
        "IFCCRANERAILFSHAPEPROFILEDEF",
        "IFCSTRUCTURALPLANARACTIONVARYING",
        "IFCTRANSFORMERTYPE",
        "IFCTIMESERIESVALUE",
        "IFCDUCTFITTINGTYPE",
        "IFCPLATETYPE",
        "IFCPORT",
        "IFCOBJECT",
        "IFCCOOLINGTOWERTYPE",
        "IFCANNOTATIONSURFACE",
        "IFCBUILDINGELEMENTCOMPONENT",
        "IFCFLOWMETERTYPE",
        "IFCFURNITURESTANDARD",
        "IFCCOMPRESSORTYPE",
        "IFCFILLAREASTYLE",
        "IFCDERIVEDUNITELEMENT",
        "IFCSTRUCTURALCONNECTION",
        "IFCOBJECTIVE",
        "IFCPLANE",
        "IFCCREWRESOURCE",
        "IFCELECTRICALCIRCUIT",
        "IFCELEMENTCOMPONENT",
        "IFCANNOTATIONTEXTOCCURRENCE",
        "IFCSTRUCTURALREACTION",
        "IFCSOUNDPROPERTIES",
        "IFCDERIVEDPROFILEDEF",
        "IFCPOLYLOOP",
        "IFCDUCTSEGMENTTYPE",
        "IFCAPPROVAL",
        "IFCREPRESENTATION",
        "IFCAPPROVALACTORRELATIONSHIP",
        "IFCPIPEFITTINGTYPE",
        "IFCTRAPEZIUMPROFILEDEF",
        "IFCREVOLVEDAREASOLID",
        "IFCPROPERTY",
        "IFCEDGELOOP",
        "IFCTRIMMEDCURVE",
        "IFCRELCONNECTSPORTTOELEMENT",
        "IFCSTRUCTURALSURFACEMEMBERVARYING",
        "IFCPRODUCTREPRESENTATION",
        "IFCDIMENSIONCURVETERMINATOR",
        "IFCROOT",
        "IFCPROPERTYLISTVALUE",
        "IFCRELASSOCIATES",
        "IFCDOCUMENTREFERENCE",
        "IFCFLUIDFLOWPROPERTIES",
        "IFCEXTERNALLYDEFINEDSYMBOL",
        "IFCORDERACTION",
        "IFCRELOVERRIDESPROPERTIES",
        "IFCSTACKTERMINALTYPE",
        "IFCPOINT",
        "IFCPREDEFINEDCOLOUR",
        "IFCCLASSIFICATIONITEMRELATIONSHIP",
        "IFCFACEBASEDSURFACEMODEL",
        "IFCCONNECTIONPORTGEOMETRY",
        "IFCFOOTING",
        "IFCSPATIALSTRUCTUREELEMENT",
        "IFCDIMENSIONPAIR",
        "IFCRELSERVICESBUILDINGS",
        "IFCELECTRICALBASEPROPERTIES",
        "IFCRECTANGLEPROFILEDEF",
        "IFCRELASSIGNSTOPROJECTORDER",
        "IFCPIPESEGMENTTYPE",
        "IFCGEOMETRICSET",
        "IFCSPACEPROGRAM",
        "IFCUSHAPEPROFILEDEF",
        "IFCCOOLEDBEAMTYPE",
        "IFCMATERIALCLASSIFICATIONRELATIONSHIP",
        "IFCELEMENTQUANTITY",
        "IFCCLASSIFICATION",
        "IFCRELASSIGNSTOPROCESS",
        "IFCPROJECTIONCURVE",
        "IFCGEOMETRICREPRESENTATIONCONTEXT",
        "IFCLIGHTINTENSITYDISTRIBUTION",
        "IFCDIRECTION",
        "IFCDISCRETEACCESSORY",
        "IFCPUMPTYPE",
        "IFCDOCUMENTELECTRONICFORMAT",
        "IFCSIMPLEPROPERTY",
        "IFCDISTRIBUTIONELEMENT",
        "IFCPROPERTYSINGLEVALUE",
        "IFCRELASSIGNSTOPRODUCT",
        "IFCSTRUCTURALPLANARACTION",
        "IFCCOLOURSPECIFICATION",
        "IFCENVIRONMENTALIMPACTVALUE",
        "IFCZSHAPEPROFILEDEF",
        "IFCOWNERHISTORY",
        "IFCFACETEDBREPWITHVOIDS",
        "IFCFILLAREASTYLETILES",
        "IFCBOUNDARYFACECONDITION",
        "IFCHUMIDIFIERTYPE",
        "IFCSITE",
        "IFCANNOTATIONSYMBOLOCCURRENCE",
        "IFCPLATE",
        "IFCEDGEFEATURE",
        "IFCSTRUCTURALRESULTGROUP",
        "IFCRELCONNECTSPATHELEMENTS",
        "IFCCSGSOLID",
        "IFCFLOWFITTING",
        "IFCFLOWINSTRUMENTTYPE",
        "IFCELECTRICDISTRIBUTIONPOINT",
        "IFCTOPOLOGICALREPRESENTATIONITEM",
        "IFCEXTRUDEDAREASOLID",
        "IFCAXIS2PLACEMENT3D",
        "IFCSURFACE",
        "IFCPROPERTYSETDEFINITION",
        "IFCSECTIONREINFORCEMENTPROPERTIES",
        "IFCSECTIONEDSPINE",
        "IFCSTRUCTURALSURFACEMEMBER",
        "IFCMATERIALPROPERTIES",
        "IFCCURVESTYLEFONT",
        "IFCRELCONNECTSSTRUCTURALELEMENT",
        "IFCCABLESEGMENTTYPE",
        "IFCLOOP",
        "IFCRELASSOCIATESDOCUMENT",
        "IFCPLANAREXTENT",
        "IFCCONSTRUCTIONRESOURCE",
        "IFCSHAPEMODEL",
        "IFCFLOWFITTINGTYPE",
        "IFCPHYSICALQUANTITY",
        "IFCBOUNDEDCURVE",
        "IFCBUILDINGELEMENTPART",
        "IFCRATIONALBEZIERCURVE",
        "IFCSURFACECURVESWEPTAREASOLID",
        "IFCBOOLEANCLIPPINGRESULT",
        "IFCVIRTUALELEMENT",
        "IFCELEMENTTYPE",
        "IFCTEXTURECOORDINATE",
        "IFCASSET",
        "IFCCLASSIFICATIONNOTATION",
        "IFCBOUNDINGBOX",
        "IFCFASTENERTYPE",
        "IFCRELCONNECTSSTRUCTURALACTIVITY",
        "IFCELECTRICMOTORTYPE",
        "IFCRELINTERACTIONREQUIREMENTS",
        "IFCSHAPEASPECT",
        "IFCRELDEFINES",
        "IFCAIRTOAIRHEATRECOVERYTYPE",
        "IFCSTRUCTURALLOADPLANARFORCE",
        "IFCDISTRIBUTIONCHAMBERELEMENT",
        "IFCCONSTRAINTCLASSIFICATIONRELATIONSHIP",
        "IFCAXIS1PLACEMENT",
        "IFCJUNCTIONBOXTYPE",
        "IFCCONNECTIONCURVEGEOMETRY",
        "IFCSTRUCTURALPOINTCONNECTION",
        "IFCAPPLIEDVALUE",
        "IFCFLOWSEGMENTTYPE",
        "IFCRELASSIGNS",
        "IFCPROCESS",
        "IFCBOILERTYPE",
        "IFCRELPROJECTSELEMENT",
        "IFCTEXTLITERALWITHEXTENT",
        "IFCBUILDINGELEMENT",
        "IFCSURFACESTYLEREFRACTION",
        "IFCRELCONNECTSPORTS",
        "IFCCURRENCYRELATIONSHIP",
        "IFCLIBRARYINFORMATION",
        "IFCCARTESIANTRANSFORMATIONOPERATOR2D",
        "IFCAIRTERMINALBOXTYPE",
        "IFCDIAMETERDIMENSION",
        "IFCCOLOURRGB",
        "IFCPROFILEDEF",
        "IFCCOMPOSITECURVESEGMENT",
        "IFCANNOTATION",
        "IFCDRAUGHTINGPREDEFINEDTEXTFONT",
        "IFCBLOBTEXTURE",
        "IFCSURFACESTYLESHADING",
        "IFCCONSTRAINTAGGREGATIONRELATIONSHIP",
        "IFCTABLEROW",
        "IFCTEXTSTYLEFORDEFINEDFONT",
        "IFCFLOWTERMINAL",
        "IFCSANITARYTERMINALTYPE",
        "IFCRIGHTCIRCULARCONE",
        "IFCSENSORTYPE",
        "IFCDISTRIBUTIONCONTROLELEMENTTYPE",
        "IFCRAMPFLIGHTTYPE",
        "IFCEVAPORATIVECOOLERTYPE",
        "IFCLOCALTIME",
        "IFCGENERALPROFILEPROPERTIES",
        "IFCLIGHTSOURCESPOT",
        "IFC2DCOMPOSITECURVE",
        "IFCEQUIPMENTSTANDARD",
        "IFCSTRUCTURALCURVEMEMBERVARYING",
        "IFCRELCONNECTSSTRUCTURALMEMBER",
        "IFCSLABTYPE",
        "IFCCSGPRIMITIVE3D",
        "IFCPREDEFINEDCURVEFONT",
        "IFCCONNECTIONGEOMETRY",
        "IFCSTAIRFLIGHTTYPE",
        "IFCEDGE",
        "IFCGASTERMINALTYPE",
        "IFCSURFACESTYLELIGHTING",
        "IFCCOILTYPE",
        "IFCPROPERTYTABLEVALUE",
        "IFCORGANIZATION",
        "IFCMATERIALLAYER",
        "IFCBOUNDEDSURFACE",
        "IFCDISTRIBUTIONFLOWELEMENT",
        "IFCRELFILLSELEMENT",
        "IFCWALLSTANDARDCASE",
        "IFCSOLIDMODEL",
        "IFCDEFINEDSYMBOL",
        "IFCMONETARYUNIT",
        "IFCCOLUMNTYPE",
        "IFCRELCONTAINEDINSPATIALSTRUCTURE",
        "IFCFIRESUPPRESSIONTERMINALTYPE",
        "IFCRELASSOCIATESAPPLIEDVALUE",
        "IFCRELASSOCIATESCLASSIFICATION",
        "IFCCARTESIANPOINT",
        "IFCSTAIRFLIGHT",
        "IFCELECTRICALELEMENT",
        "IFCTEXTSTYLEFONTMODEL",
        "IFCMEASUREWITHUNIT",
        "IFCRAMP",
        "IFCBOUNDARYCONDITION",
        "IFCELEMENTARYSURFACE",
        "IFCDISTRIBUTIONPORT",
        "IFCROUNDEDRECTANGLEPROFILEDEF",
        "IFCMECHANICALCONCRETEMATERIALPROPERTIES",
        "IFCUNITASSIGNMENT",
        "IFCDIMENSIONCALLOUTRELATIONSHIP",
        "IFCFACEOUTERBOUND",
        "IFCPILE",
        "IFCCONNECTIONPOINTECCENTRICITY",
        "IFCPOSTALADDRESS",
        "IFCANNOTATIONSURFACEOCCURRENCE",
        "IFCFACEBOUND",
        "IFCWINDOWSTYLE",
        "IFCRELVOIDSELEMENT",
        "IFCSTRUCTURALLOADSTATIC",
        "IFCPOLYLINE",
        "IFCFLOWTREATMENTDEVICETYPE"
        };

// end is just a template so you don't have to write entityNames+653
// and keep it up to date if the length changes later. Define it as:
template<typename T, size_t N>
T * end(T (&ra)[N]) {
    return ra + N;
}

// vector of entity name
static const std::vector<std::string> s_EntityVector(entityNames, end(entityNames)); // definition

// map to find entity code (index in entity name vector) from entity name
typedef std::map< std::string, int> Entity2Code;
Entity2Code s_Entity2Code;
// initialize this map
bool InitMap()
{
    for(int i = 0; i < s_EntityVector.size(); ++i)
    {
        s_Entity2Code[s_EntityVector[i]] = i;
    }
    return true;
}
// anonymous namespace, execution is done when library has just loaded
namespace
{
    int res = InitMap();
}


static const std::string sEmptyString;
const std::string &BaseSPFObject::getEntityClassName() const
{
    AllocateFunc2ClassName::const_iterator it = s_AllocateFunc2ClassName.find(m_allocFuncType);
    if (it != s_AllocateFunc2ClassName.end())
    {
        return it->second;
    }
    else
        return sEmptyString;
}

int BaseSPFObject::entityTypeCode(const std::string& s)
{
    Entity2Code::const_iterator it = s_Entity2Code.find(s);
    if (it == s_Entity2Code.end()) {
        return -1;
    }
    else {
        return it->second;
    }
}

const std::string &BaseSPFObject::entityTypeName(int code) {
    if (code < s_EntityVector.size())
        return s_EntityVector[code];
    else
        return sEmptyString;
}
